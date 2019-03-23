#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>
using namespace boost::xpressive;
using namespace std; 

int main()
{
    string pattern("a.c");
    cregex reg = cregex::compile(pattern);
    if (regex_match("abc", reg)) {
        std::cout << "abc matches " << pattern << endl;
    }
    
    // To do:
    // regex_serach()
    // regex_replace()
    // ......
    
    return 0;
}
