/*
    unordered_map - 哈希表
    
    at()
    
    bucket()
    bucket_count()
    bucket_size()
    max_bucket_count()
    
    clear()
    count()
    find()
    empty()
    size()
    max_size()
    
    insert()
    emplace()
    erase()
    
    equal_range()
    
    swap()
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


void test_insert()
{
    unordered_map<std::string,double> myrecipe;
    unordered_map<std::string,double> mypantry = {{"milk",2.0},{"flour",1.5}};
    
    std::pair<std::string,double> myshopping ("baking powder",0.3);
    
    // copy insertion
    myrecipe.insert (myshopping); 
    
    // move insertion
    myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0));
    
    // range insertion
    myrecipe.insert (mypantry.begin(), mypantry.end());
    
    // initializer list insertion
    myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );
    
    cout << "myrecipe contains:" << endl;
    for (auto& x: myrecipe)
      std::cout << x.first << ": " << x.second << std::endl;
    
    cout << endl;
}


int main()
{
    test_insert();
}

/*
myrecipe contains:
salt: 0.1
sugar: 0.8
baking powder: 0.3
eggs: 6
flour: 1.5
milk: 2
*/
