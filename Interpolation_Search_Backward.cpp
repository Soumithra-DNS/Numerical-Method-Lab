#include <bits/stdc++.h> // Include all standard libraries
using namespace std;

// Class implementing Newton Backward Interpolation
class Newton_Backward_Interpolation {
private:
    float value; // The value at which we want to estimate the function

    // Function to compute the p term in the formula
    float find_p(float p, int n) {
        float temp = p;
        for (int i = 1; i < n; i++)
            temp = temp * (p + i);
        return temp;
    }

    // Function to compute factorial of a number
    int fact(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }

public:
    // Constructor to initialize the value
    Newton_Backward_Interpolation(float val) : value(val) {}

    // Function to compute and print the interpolation table and result
    void find() {
        int n = 5; // Number of data points
        float x[] = {1891, 1901, 1911, 1921, 1931}; // Known x values
        float ini_y[] = {46, 66, 81, 93, 101};     // Corresponding y values

        float y[n][n]; // Table to store backward differences

        // Initialize the first column of y with given y values
        for (int i = 0; i < n; i++) {
            y[i][0] = ini_y[i];
        }

        // Calculate the backward difference table
        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
            }
        }

        // Print the backward difference table
        cout << "Backward Difference Table:" << endl;
        for (int i = 0; i < n; i++) {
            cout << setw(6) << x[i] << "\t";
            for (int j = 0; j < n - i; j++) {
                cout << setw(6) << y[i][j] << "\t";
            }
            cout << endl;
        }

        // Estimate the value at the given point
        float sum = y[n - 1][0]; // Start with the last value in the first column
        float p = (value - x[n - 1]) / (x[1] - x[0]); // Calculate p

        // Add terms of the interpolation formula
        for (int i = 1; i < n; i++) {
            sum = sum + (find_p(p, i) * y[n - 1][i]) / fact(i);
        }

        // Print the estimated value
        cout << "Value at " << value << " is " << sum << endl;
    }
};

int main() {
    float value = 1895; // The x value at which we want to estimate y

    // Create an instance of Newton_Backward_Interpolation
    Newton_Backward_Interpolation newton_Backward_Interpolation(value);

    // Perform the interpolation and print results
    newton_Backward_Interpolation.find();

    return 0;
}