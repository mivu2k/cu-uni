#include <iostream>
#include <string>
using namespace std;

int main()
{
    string y = "quick",z = "lazy",
    x ="The quick brown fox jumped over the lazy dog, but the quick brown dog also jumped over the lazy fox",last;
    
    int position =0;
    while ((position = x.find(y, position)) != -1) {
        x.replace(position, y.length(), z);
        position += z.length();
    }
    position =0;
    while ((position = x.find(z, position)) != -1) {
        x.replace(position, z.length(), y);
        position += y.length();
    }
    
    cout << x << endl;
    return 0;
}
