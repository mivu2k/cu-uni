#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
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
