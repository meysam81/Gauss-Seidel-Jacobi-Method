/* Here's my reference for further study:
    http://www.dreamincode.net/forums/topic/94775-jacobi-iterative-method/
*/

#include <math.h> // for use of absolute in the computation
#include <stdlib.h> // for the use of exit
#include <iostream> // cin & cout
#include <iomanip> // setprecision

using namespace std;

int main()
{
    float factor_matrix[100][100],
            initial_x[20],
            upper_bound,
            big,
            temp,
            relative_error,
            sum;

    int max_degree,
            first_iterator,
            second_iterator,
            number_of_iters,
            third_iterator;
    char ch;

    cout << "Enter max degree of the equation: ";
    cin >> max_degree;

    for (first_iterator = 1; first_iterator <= max_degree; first_iterator++)
    {
        cout << "Enter the coefficients of row " << first_iterator << " and its corresponding RHS:\n";
        for (second_iterator = 1; second_iterator <= max_degree + 1; second_iterator++)
        cin >> factor_matrix[first_iterator][second_iterator];
    }

    cout << "Relative error: ";
    cin >> relative_error;

    cout << "Number of iteration: ";
    cin >> number_of_iters;

    for (first_iterator = 1; first_iterator <= max_degree; first_iterator++)
        initial_x[first_iterator] = 0;


    for (third_iterator = 1; third_iterator <= number_of_iters; third_iterator++)
    {
        big = 0;
        for (first_iterator = 1; first_iterator <= max_degree; first_iterator++)
        {
            sum = 0;
            for (second_iterator = 1; second_iterator <= max_degree; second_iterator++)
            {
                if (first_iterator != second_iterator)
                    sum = sum + factor_matrix[first_iterator][second_iterator] *
                            initial_x[second_iterator];
            }

            temp = (factor_matrix[first_iterator][max_degree+1] - sum) /
                    factor_matrix[first_iterator][first_iterator];

            relative_error = fabs((initial_x[first_iterator] - temp) /
                                  temp);

            if (relative_error > big)
                big = relative_error;

            initial_x[first_iterator] = temp;
        }

        if(big <= upper_bound)
        {
            cout << "Converges to a solution in " << third_iterator << "th iteration\n";
            for (first_iterator = 1; first_iterator <= max_degree;first_iterator++)
                cout << setprecision(4) << initial_x[first_iterator] << "\t";
            exit(1);
        }
    }
    cout << "Does not converge in " << number_of_iters << " iteration.\nHere are the x's:\n";
    for (first_iterator = 1; first_iterator <= max_degree;first_iterator++)
        cout << "x[" << first_iterator << "] = " << setprecision(4) << initial_x[first_iterator] << "\n";
    return 0;
}
