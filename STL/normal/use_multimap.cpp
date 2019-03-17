/* 
    multimap - 一个key可以对应多个value 
    
    rbegin()
    rend()
    
    erase()
    insert() - 返回 iterator
    
    count()
    find()
    
    emplace()
    
    clear()
    empty()
    
    equal_range()
    swap()
*/

#include <iostream>
#include <map>

int main ()
{
    std::multimap<char,int> mymm;
    
    mymm.insert(std::pair<char,int>('a',10));
    mymm.insert(std::pair<char,int>('b',20));
    mymm.insert(std::pair<char,int>('b',30));
    mymm.insert(std::pair<char,int>('b',40));
    mymm.insert(std::pair<char,int>('c',50));
    mymm.insert(std::pair<char,int>('c',60));
    mymm.insert(std::pair<char,int>('d',60));
    
    std::cout << "mymm contains:\n";
    for (char ch='a'; ch<='d'; ch++)
    {
        std::pair <std::multimap<char,int>::iterator, std::multimap<char,int>::iterator> ret;
        ret = mymm.equal_range(ch);
        
        std::cout << ch << " =>";
        
        for (std::multimap<char,int>::iterator it=ret.first; it!=ret.second; ++it)
            std::cout << ' ' << it->second;
        std::cout << std::endl;
    }
    
    return 0;
}

/* output: 
    mymm contains:
    a => 10
    b => 20 30 40
    c => 50 60
    d => 60
*/