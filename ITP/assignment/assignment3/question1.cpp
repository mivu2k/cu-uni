#include <iostream>
#include <string>
using namespace std;

int main()
{
    string reg;
    string name;
    int total_course;
    string course_name[10];

    cout << "enter your name: ";
    getline(cin, name);

    cout << "enter your Reg no : ";
    getline(cin, reg);

    cout << "Enter total courses :";
    cin >> total_course;

    for (int i = 0; i < total_course; i++)
    {
        cout << "course " << i + 1 << " : ";
        cin >> course_name[i];
    }

    // part 1

    cout << "------------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Reg: " << reg << endl;
    cout << "------------------------------------------" << endl;
    // part 2

    for (int i = 0; i < total_course; i++)
    {
        cout << "course " << i + 1 << " : " << course_name[i] << endl;
    }
    cout << "------------------------------------------" << endl;
    // part 3

    char last = reg.at(reg.length() - 1);
    int con = int(last - '0');
    int sum = 0;
    sum= con + total_course; 
   
    cout << "sum :" << sum  << endl;
    
    cout << "------------------------------------------" << endl;
    // part 4

    int j = 0;
    while (j < sum)
    {
        cout << "\"Welcome to CS1133-Introduction to Programming\"" << endl;
        j++;
    }
    cout << "------------------------------------------" << endl;

    return 0;
}