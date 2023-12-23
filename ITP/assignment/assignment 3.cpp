#include <iostream>
#include <iomanip>
#include<cstdlib>
using namespace std;

int main(){
    srand((unsigned) time(NULL));
    const int r = 4; // row
    const int c = 6; // column
    int matrix[r][c];int opt1;int opt2;
    cout << "1: for Manually Entering value \n2: for Automatic insertion" <<endl;
    cout << "enter choice: ";
    cin >> opt1;
  
        switch (opt1) {
            case 1: // for manual entering
                for(int i = 0; i < r ; i++){
                    for (int j = 0 ; j < c; j++) {
                        cout << "enter value in {" << i+1 << "} {" << j+1 << "}:";
                        cin >> matrix[i][j];
                    }
                }
                break;
            case 2: // for automatic
                for(int i = 0; i < r ; i++){
                    for (int j = 0 ; j < c; j++) {
                        int random = (rand() % 101);
                        matrix[i][j] = random;
                    }
                }
                break;
            default:
                cout << "input 1 or 2";
                break;
        }
    // for dispalying out the matrix
    cout <<  "---------------------------"<< endl;
    for(int i = 0; i < r ; i++){
        for (int j = 0 ; j < c; j++) {
            cout << setw(5)<< matrix[i][j] << setw(1) <<"|" ;
            
        }
        cout << endl;
    }
    cout <<  "---------------------------"<< endl;
    
    // Q part b
    cout << "1. Multiply each element of the first row by 10" << endl;
    cout <<"2. Subtract the column 3 values from column 4" << endl;
    cout << "3. Sum the values of all the rows and columns" <<endl;
    cout << "enter choice : ";
    cin >> opt2;
    int mat10[r][c];
    int mat34[r][c];
    int sum=0;
    switch (opt2) {
        case 1:
            cout <<  "-----------------------------"<< endl;
            for (int j = 0; j < c; ++j) {
                mat10[0][j] = matrix[0][j] * 10;
                cout << "{"<< mat10[0][j] << "}" ;
            }
            cout << endl;
            cout <<  "-----------------------------"<< endl;
            break;
        case 2:
            cout <<  "-------------------"<< endl;
            for(int i = 0;i < r; i++){
                mat34[i][0]= matrix[i][4]-matrix[i][3];
                cout << "{"<< mat34[i][0] << "}" ;
            }
            cout << endl;
            cout <<  "-------------------"<< endl;
            
            break;
        case 3:
            
            cout <<  "-----------------------------"<< endl;
            for (int i = 0; i < r; i++){
                int row_sum = 0;
                for(int j =0; j<c;j++){
                    row_sum += matrix[i][j];
                }
                cout << "sum of row {"<< i+1 <<"}: " << row_sum << " | ";
            }
            cout << endl;
            cout <<  "-----------------------------"<< endl;
            
            for (int j = 0; j < c; j++){
                int row_col = 0;
                for(int i = 0; i<r;i++){
                    row_col += matrix[i][j];
                }
                cout << "sum of col {"<< j+1 <<"}: " << row_col << " | ";
            }
            cout << endl;
            cout <<  "-----------------------------"<< endl;
            
            for(int i = 0; i < r ; i++){
                for (int j = 0 ; j < c; j++) {
                    sum += matrix[i][j];
                }
            }
            
            cout << " sum of the matrix :" << sum <<endl;
            cout <<  "-----------------------------"<< endl;
            break;
        default:
            cout << "enter between 1 to 3: ";
            break;
    }

}


