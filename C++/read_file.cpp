#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;


int main(int argc, char ** argv) {
    const int size = 4096;
    char line[size]; 
    
    char path[] = "./read_file.cpp";
    
    ifstream fin(path, ios::in); 
    // Or: 
    // ifstream fin;
    // fin.open("./read_file.cpp");
    
    if (!fin.good()) {
        cout << "Error happened when trying to open: " << path << endl; 
        return -1;
    }
    
    while(!fin.eof()) {
        memset(line, 0, size);
        fin.getline(line, size);
        cout << line <<endl; 
    }
    
    fin.clear();  // 清除文件流的指针位置
    fin.seekg(0, ios::beg);  // 重新定位到文件开始位置
    
    // 打印第二遍
    while(!fin.eof()) {
        memset(line, 0, size);
        fin.getline(line, size);
        cout << line <<endl; 
    }
    
    fin.close(); 
    
    return 0;
}
