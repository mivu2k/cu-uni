# Assignment 3 

##### Question 1
 Write a C++ program that performs the following tasks: 
1-	Print your name and Registration number.
2-	Print the names of all courses you have selected in the current semester.
3-	Add the last numeric digit of your CUST registration id to the total number of courses selected.
4-	Display the result of sum on the screen. 
5-	Print “Welcome to CS1133-Introduction to Programming” by using WHILE loop. Number of iterations of WHILE loop must be equal to sum calculated in point 4.  
For example, suppose the student id is BC12345678. Then by adding last digit of CUST registration=8, with number of courses (suppose =5), we get sum= 13. Sum = (last digit of CUST registration) 8 + number of courses 5 = 8+5.  In this case, your program should print 13 times. 
“Welcome to CS1133-Introduction to Programming”  

```c++
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


```
##### Question 2

Write a user defined function named Upper-half() which takes a two dimensional array A, with size N rows and N columns as argument and prints the upper half of the array.
e.g.,
```
2 3 1 5 0        2 3 1  5 0
7 1 5 3 1           1 5 3 1
2 5 7 8 1             7 8 1
0 1 5 0 1               0 1
3 4 9 1 5                 5

```


```c++
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int max = 10;
void upper_half(int matrix[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i; ++j)
        {
            cout << setw(6) << "" << setw(6);
        }

        for (int j = i; j < c; j++)
        {
            cout << setw(5) << matrix[i][j] << setw(5);
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    const int max = 10;
    int matrix[max][max];
    int r;
    int c;
    cout << "Enter size of matrix r * c : ";
    cin >> r >> c;
    int opt1;
    cout << "1: for Manually Entering value \n2: for Automatic insertion" << endl;
    cout << "enter choice: ";
    cin >> opt1;

    switch (opt1)
    {
    case 1: // for manual entering
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << "enter value in {" << i + 1 << "} {" << j + 1 << "}:";
                cin >> matrix[i][j];
            }
        }
        break;
    case 2: // for automatic
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int random = (rand() % 10);
                matrix[i][j] = random;
            }
        }
        break;
    default:
        cout << "input 1 or 2";
        break;
    }
    // for dispalying out the matrix
    cout << "---------------------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << setw(5) << matrix[i][j] << setw(5);
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;

    upper_half(matrix, r, c);
}

```
##### Question 3

Write a function in C++:
•	Which accepts a 2D array of integers and its size as arguments.
•	And displays the elements of middle row and the elements of middle column.  
•	And display sum of elements of middle row and the elements of middle column.  
[Assuming the 2D Array to be a square matrix with odd dimension i.e. 3x3, 5x5, 7x7, 9x9, etc...] 
Example, if the array contents is
3	5	4 
7	6	2 
2	1	8
Output through the function should be : 
Middle Row : 	7	6	2 
Middle column: 	5	6 	1
Middle Row Sum:  	15
Middle Column Sum:	12

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

void mid_row_col(int matrix[][10], int r){
    int row_sum = 0;
    cout << "---------------------------" << endl;
  
  for (int i = 0; i < r; i++)
  {
      for (int j = 0; j < r; j++)
      {
          if(i == r/2){
              cout << setw(5) << matrix[i][j] << setw(5);
              row_sum = row_sum+ matrix[i][j];
          }
      }
      cout << endl;
  }
  cout << "---------------------------" << endl;
  
  int col_sum = 0;
  for (int i = 0; i < r; i++)
  {
      for (int j = 0; j < r; j++)
      {
          if(j == r/2){
              cout << setw(5) << matrix[i][j] << setw(5);
              col_sum = col_sum+ matrix[i][j];
          }
      }
      cout << endl;
  }
  cout << "---------------------------" << endl;
  
  
  cout << "col sum : "<< col_sum<< endl;
  cout << "row sum : "<< row_sum <<  endl;
}

int main()
{
    srand((unsigned)time(NULL));

    const int max = 10;
    int matrix[max][max];
    int r;

    cout << "Enter size of matrix in odd";
    cin >> r;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int random = (rand() % 10);
            matrix[i][j] = random;
        }
    }
    
    // for dispalying out the matrix
    cout << "---------------------------" << endl;

      for (int i = 0; i < r; i++)
      {
          for (int j = 0; j < r; j++)
          {
              cout << setw(5) << matrix[i][j] << setw(5);
          }
          cout << endl;
      }
    
    mid_row_col(matrix, r);
}

```
##### Question 4

Write a program to add two array A and B of size m x n.

```cpp
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    const int max = 10;
    int matrixA[max][max];
    int matrixB[max][max];
    int result[max][max];
    int r;

    cout << "Enter size of matrix in odd";
    cin >> r;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int random = (rand() % 10);
            matrixA[i][j] = random;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int random = (rand() % 10);
            matrixB[i][j] = random;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // for dispalying out the matrixA
    cout << "---------------------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << setw(5) << matrixA[i][j] << setw(5);
        }
        cout << endl;
    }
    // for dispalying out the matrixB
    cout << "---------------------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << setw(5) << matrixB[i][j] << setw(5);
        }
        cout << endl;
    }
    // for dispalying out the Result
    cout << "---------------------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << setw(5) << result[i][j] << setw(5);
        }
        cout << endl;
    }

    cout << "---------------------------" << endl;
}

```

###### Question 5

Write a program to multiply array A and B of order NxL and LxM.

```cpp
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    const int max = 10;
    int matrixA[max][max];
    int matrixB[max][max];
    int result[max][max];
    int r;

    cout << "Enter size of matrix in odd";
    cin >> r;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int random = (rand() % 10);
            matrixA[i][j] = random;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int random = (rand() % 10);
            matrixB[i][j] = random;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < r; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // for dispalying out the matrixA
    cout << "---------------------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << setw(5) << matrixA[i][j] << setw(5);
        }
        cout << endl;
    }
    // for dispalying out the matrixB
    cout << "---------------------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << setw(5) << matrixB[i][j] << setw(5);
        }
        cout << endl;
    }
    // for dispalying out the Result
    cout << "---------------------------" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << setw(5) << result[i][j] << setw(5);
        }
        cout << endl;
    }

    cout << "---------------------------" << endl;
}


```