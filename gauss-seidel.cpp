/* Here's my reference for further study:
 * http://www.sanfoundry.com/cpp-program-implement-gauss-seidel-method/
*/

#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
    float equation_factors[100][100],
            equations_value[100],
            initial_x[100],
            results[100];


    int max_degree= 0,
            number_of_iters = 0,
            first_iterator = 0,
            second_iterator = 0;
    cout << "Enter size of 2d array (Square matrix): ";
    cin >> max_degree;


    // get the elements of the n*n square matrix corresponded with the equation factors
    for (first_iterator = 0; first_iterator < max_degree; first_iterator++)
    {
        for (second_iterator = 0; second_iterator < max_degree; second_iterator++)
        {
            cout << "[" << first_iterator << ", " << second_iterator << "]: ";
            cin >> equation_factors[first_iterator][second_iterator];
        }
    }


    // the values of the right side of the equality equation as in ax + b = c where we get the c
    cout << "\nEnter Values to the right side of equation\n";
    for (first_iterator = 0; first_iterator < max_degree; first_iterator++)
    {
        cout << "[" << first_iterator << ", " << second_iterator << "]: ";
        cin >> equations_value[first_iterator];
    }


    // the x's for x^0 which will be used in the next iterations formula
    cout << "\nEnter initial values of x\n";
    for (first_iterator = 0; first_iterator < max_degree; first_iterator++)
    {
        cout << "x[" << first_iterator << "]: ";
        cin >> initial_x[first_iterator];
    }


    // how much further?
    cout << "\nEnter the no. of iteration : ";
    cin >> number_of_iters;
    while (number_of_iters > 0)
    {
        for (first_iterator = 0; first_iterator < max_degree; first_iterator++)
        {

            results[first_iterator] = (equations_value[first_iterator] / equation_factors[first_iterator][first_iterator]);
            for (second_iterator = 0; second_iterator < max_degree; second_iterator++)
            {
                if (second_iterator == first_iterator) // not for diagonals
                    continue;
                // the real deal happens below
                results[first_iterator] = results[first_iterator] - ((equation_factors[first_iterator][second_iterator] / equation_factors[first_iterator][first_iterator]) * initial_x[second_iterator]);
                initial_x[first_iterator] = results[first_iterator];
            }

            // print the result of the i'th iteration
            cout << "x" << first_iterator + 1 << " = " << setprecision(5) << results[first_iterator] << setw(5);
        }

        // for niceness in the print
        cout << "\n";

        // loop condition manipulation
        number_of_iters--;
    }
    return 0;
}
