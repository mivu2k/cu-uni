#include <iostream>
#include <string>
using namespace std;

int main()
{
    string y = "defied";
    
    for (int i = y.length(); i >= 0; i--) {
        cout << y[i];
    }
    cout << endl;
  
    return 0;
}
