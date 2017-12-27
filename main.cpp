/* Here's my reference for further study:
 * http://www.sanfoundry.com/cpp-program-implement-gauss-seidel-method/
*/

#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a[100][100], b[100], x[100], y[100];
    int n = 0, m = 0, i = 0, j = 0;
    cout << "Enter size of 2d array (Square matrix): ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "[" << i << ", " << j << "]: ";
            cin >> a[i][j];
        }
    }
    cout << "\nEnter Values to the right side of equation\n";
    for (i = 0; i < n; i++)
    {
        cout << "[" << i << ", " << j << "]: ";
        cin >> b[i];
    }
    cout << "\nEnter initial values of x\n";
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i << "]: ";
        cin >> x[i];
    }
    cout << "\nEnter the no. of iteration : ";
    cin >> m;
    while (m > 0)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            cout << "x" << i + 1 << " = " << setprecision(5) << y[i] << setw(5);
        }
        cout << "\n";
        m--;
    }
    return 0;
}
