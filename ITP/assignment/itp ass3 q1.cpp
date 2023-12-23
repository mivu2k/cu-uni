// Question 1:  (Marks = 05)
// Write a C++ function that takes a string as input and returns the reverse of the string. 
// •	Your function should handle both uppercase and lowercase letters, and any leading or trailing whitespace in the input string should be preserved in the reversed string.
// •	Additionally, explain any assumptions you make about the input and any considerations in your implementation.




#include <iostream>
#include <string>
using namespace std;
string reverseString(string& input) {
   string reversed;
    for (int i = input.length() - 1; i >= 0; --i) {
        reversed += input[i];
    }
    return reversed;
}

int main() {
    // Example of using the reverseString function
   string original;
    cout<< "enter an sentence to be reversed: ";
    getline(cin,original);
   string reversed = reverseString(original);

   cout << "Reversed string: " << reversed <<endl;

    return 0;
}
