// -1 means no found 
int findFirstLarger(vector<int>& array, int val)
{
    int beg = 0;
    int end = array.size() - 1;
    
    if (array[beg] > val) return beg;
    if (array[end] <= val) return -1;
    
    int mid = beg + (end-beg)/2;   // [0,1,2]->1, [0,1]->0
    
    while (mid < end) {
        if (array[mid] > val) {
            if (array[mid-1] <= val) 
                return mid;
            else {  // array[mid-1] > val
                end = mid - 1; 
                mid = beg + (end-beg)/2;
            }
        }
        else { // array[mid] <= val 
            beg = mid; 
            mid = beg + (end-beg)/2;
            if (mid == beg) mid += 1;
        }
    }
    return mid; 
}

