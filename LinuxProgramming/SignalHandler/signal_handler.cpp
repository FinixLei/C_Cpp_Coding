#include "signal_handler.h"

static struct sigaction old_sigterm_info;

// This size is big enough so don't need strncpy 
#define PROC_PATH_LENGTH 32

struct ProcessInfo {
    int pid; 
    char comm[32];  // suppose one command's name will not exceeds 31 characters
}; 

/*
    Parameters: 
         value   - always > 0, as it's normal pid 
         buf     - char array to store result 
    Return: 
         the character number of the figure, not including '\0'
    Support only decimal
*/
int uitoa(unsigned int value, char * buf)
{
    int i=0;
    while (value > 0) {
        buf[i++] = '0' + value % 10; 
        if (i==10) break;
        value /= 10; 
    }
    buf[i--] = 0;
    int len = i+1; 
    
    int j = 0;
    while (j < i) {
        buf[i] ^= buf[j]; 
        buf[j] ^= buf[i];
        buf[i--] ^= buf[j++];
    }
    return len; 
}

/*
    Return Value:
    <ppid>  > 0
    -1      Fail
*/
int atoppid(char * buf, int len)
{
    if (len > 5 || len <= 0) return -1;
    
    int ppid = 0;
    for (int i=0; i<len; i++) {
        if ('0' <= buf[i] && buf[i] <= '9') {
            ppid = ppid * 10 + buf[i] - '0';
        }
        else {
            return -1;
        }
    }
    return ppid > 0 ? ppid : -1;
}

/*
    Given pid, output ppid and comm 
    
    Parameters:
        In      pid 
        Out     comm 
        In      comm_size  (max size of comm) 
    Return:
        <ppid>  > 0
        -1      Fail
*/
int get_ppid_and_comm(int pid, char * comm, int comm_size)
{
    int ERROR = -1;
    int ppid = -1;
    const int BUF_LEN = 1024;
    char buf[BUF_LEN]; 
    
    char proc_stat_path[PROC_PATH_LENGTH];
    memset(proc_stat_path, 0, PROC_PATH_LENGTH);
    
    strcpy(proc_stat_path, "/proc/");
    int pid_len = uitoa(pid, &proc_stat_path[6]);
    strcpy(&proc_stat_path[6+pid_len], "/stat");
    
    int fd = open(proc_stat_path, O_RDONLY);    
    if (fd <= 0) return ERROR; 
    
    int count = read(fd, buf, BUF_LEN);
    if (count == -1) {
        close(fd);
        return ERROR;
    }
    else if (count == BUF_LEN) {
        buf[BUF_LEN-1] = 0;
    }
    else {
        buf[count] = 0;
    }
    close(fd);
    
    int s1=0, s2=0, e1=0, e2=0, pos=0, space_count=0;
    while (buf[pos] != 0) {
        if (buf[pos] == ' ') {
            space_count ++;
            
            if (space_count == 1) {
                s1 = pos+2; 
            }
            else if (space_count == 2) {
                e1 = pos-1;
            }
            else if (space_count == 3) {
                s2 = pos+1;
            }
            else if (space_count == 4) {
                e2 = pos;
                break;
            }
        }
        pos ++;
    }
    
    int i=s1, k=0;
    while ( i < e1 && k < comm_size-1 ) {
        comm[k++] = buf[i++];
    }
    comm[k] = 0;
    
    if (s2 > 0 && e2 > 0) {
        ppid = atoppid(&buf[s2], e2-s2);
    }
    return ppid > 0 ? ppid : ERROR;
}

void log_all_process_info(ProcessInfo * pinfo, int len)
{
    char buf[2048];
    memset(buf, 0, 2048);
    
    int pos = 0;
    for (int i=0; i<len; i++) {
        buf[pos++] = '('; 
        pos += uitoa(pinfo[i].pid, &buf[pos]);
        
        buf[pos++] = ',';
        strcpy(&buf[pos], pinfo[i].comm);
        pos += strlen(&buf[pos]);
        
        buf[pos++] = ')'; 
        if (i < len-1){
            buf[pos++] = '<';
            buf[pos++] = '-';
        }
    }
    buf[pos++] = '\n';
    
    // write to STDIO. printf is not async-signal-safe. 
    write(0, buf, pos);
}

void signal_handler(int signo, siginfo_t * info, void * context)
{
    const int MAX_NUM = 20;
    ProcessInfo pinfo[MAX_NUM];
    
    pinfo[0].pid = info->si_pid;
    int pid = pinfo[0].pid;
    int ppid  = -1;
    int count = 0;
    
    while ( true ) {
        ppid = get_ppid_and_comm(pid, pinfo[count].comm, 
                                 sizeof(pinfo[count].comm));
        if ( ppid < 0 ) break;
        if ( ++count >= MAX_NUM ) break;
        pid = pinfo[count].pid = ppid;
    }
    log_all_process_info(pinfo, count);
    
    sigaction(signo, &old_sigterm_info, NULL);
    pid_t myself = getpid();
    kill(myself, signo);
}

void set_signal_handler(int signo, signal_handler_t handler)
{
    struct sigaction sigaction_info;
    memset(&sigaction_info, 0, sizeof(sigaction_info));
    
    sigset_t sigset_info;
    sigemptyset(&sigset_info);
    
    sigaction_info.sa_handler = NULL;
    sigaction_info.sa_sigaction = handler;
    sigaction_info.sa_mask = sigset_info;
    sigaction_info.sa_flags = SA_SIGINFO;

    switch (signo)
    {
    case SIGTERM:
        sigaction(signo, &sigaction_info, &old_sigterm_info);
        break;
    default:
        break;
    }
}
