#include <string>
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    string str = "China";
    const char * strch = str.c_str();
    cout << strch <<endl;
    cout << strlen(strch) <<endl; // 5
    
    string str1 = "aaa.bbb.ccc.ddd";
    string::size_type pos = str1.rfind("."); // rfind: reverse find
    if(pos != string::npos)
    {
        str1.insert(pos, "HH"); // insert(pos, insertedstring)
        cout<<str1 <<endl; // aaa.bbb.cccHH.ddd
        cout<<"pos = " <<pos <<endl; // 11, after insert, pos is the 1st H
    }
  
    string substr = str1.substr(0, pos); // substr(begin, size)
    cout<<substr <<endl; // aaa.bbb.ccc
    
    pos = substr.find("b"); //find("dest string")
    cout << "pos = " << pos << endl;  // pos = 4
    
    substr.erase(3, 4); // erase(begin, size)
    cout<<substr << endl; // aaa.ccc
    
    // the following codes to filter the words
    string dest = "$123$456$789$abc";
    cout <<dest <<endl;
    
    while((pos = dest.rfind("$")) != string::npos)
    {
        substr = dest.substr(pos, dest.size()-pos);
        cout<<substr <<endl;
        dest.erase(pos, dest.size()-pos);
    }
    
    return 0;
}
