#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<vector<int>> matriz = {{1, 2}, {3, 4}};

    // 1 2
    // 3 4

    // 1 3
    // 2 4

    // 00 10
    // 01 11

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matriz[j][i];
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == j)
            {
                cout << matriz[i][j];
            } else
                cout << " ";
        }
        cout << endl;
    }

    cout << endl;
    
   // 00 01 02
   // 10 11 12
   // 20 21 22

    return 0;
}
