#include <iostream>
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

