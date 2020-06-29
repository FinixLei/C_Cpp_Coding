/*
   map - 键值对（关联容器）
   
   at() - at(key) is value 
   
   count()
   find()  - iterator(成功) or end() (失败，没找到)
   
   insert() - 返回pair<iterator, bool> , true-成功；false,失败（已存在）
   emplace()
   erase()
   
   clear()
   empty()
   max_size()
   size()
   
   equal_range()
   swap()
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;


void test_swap()
{
    std::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;
    
    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    
    foo.swap(bar);
    
    std::cout << "foo contains:\n";
    for (auto it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << endl;
    
    std::cout << "bar contains:\n";
    for (auto it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << endl;
}

int main()
{
    map<string, int> mymap;
    mymap.insert(make_pair("aaa", 100));
    mymap.insert(pair<string, int>("bbb", 200));
    
    for (auto it=mymap.begin(); it!=mymap.end(); ++it) {
        cout << it->first <<": " << it->second << endl;
    }
    
    // const iterator
    for (auto it=mymap.cbegin(); it!=mymap.cend(); ++it) {
        cout << (*it).first <<": " << it->second << endl;
    }
    
    if (mymap.find("aaa") != mymap.end()) {
        cout << "Get aaa = " << mymap["aaa"] << endl;
    }
    else {
        cout << "Cannot get aaa" << endl;
    }
    
    // Remove all
    mymap.clear();
    
    // insert some values:
    mymap["a"]=10;
    mymap["b"]=20;
    mymap["c"]=30;
    mymap["d"]=40;
    mymap["e"]=50;
    mymap["f"]=60;

    // erasing by iterator
    auto it=mymap.find("b");
    mymap.erase (it);

    // erasing by key
    mymap.erase ("c");

    // erasing by range
    it=mymap.find ("e");
    mymap.erase(it, mymap.end() );

    // show content:
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        cout << it->first << " => " << it->second << endl;
    
    // emplace 
    mymap.clear();  // not necessary
    mymap.emplace("x", 100);
    mymap.emplace("y", 200);
    mymap.emplace("z", 300);
    auto result = mymap.emplace("x", 300);    // pair<iterator, false>, because "x" is alreay there. 
    cout << "result = " << result.second << endl;  // 0

    std::cout << "mymap contains:" << endl;
    for (auto& x: mymap)
      std::cout << "[" << x.first << ':' << x.second << ']' << endl; 
  
    // test swap
    test_swap();

    return 0;
}