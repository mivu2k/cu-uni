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

    cout << "Enter size of matrix :";
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
    cout << "Matrix A" << endl;
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
    cout << "Matrix B" << endl;
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
    cout << "Matrix A + Matrix B" << endl;
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

