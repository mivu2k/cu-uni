#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "Albama", str2 ="Al bama" ;
    
    string result = (str1 == str2)? "equal":"not equal";
  
    cout << result << endl;
    return 0;
}
