#include <bits/stdc++.h> // Include all standard libraries
using namespace std;

// Class implementing Newton Forward Interpolation
class Newton_Forward_Interpolation {
private:
    float value; // The value at which we want to estimate the function

    // Function to compute the p term in the formula
    float find_p(float p, int n) {
        float temp = p;
        for (int i = 1; i < n; i++)
            temp = temp * (p - i);
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
    Newton_Forward_Interpolation(float val) : value(val) {}

    // Function to compute and print the interpolation table and result
    void find() {
        int n = 5; // Number of data points
        float x[] = {1891, 1901, 1911, 1921, 1931}; // Known x values
        float ini_y[] = {46, 66, 81, 93, 101};     // Corresponding y values

        float y[n][n]; // Table to store forward differences

        // Initialize the first column of y with given y values
        for (int i = 0; i < n; i++) {
            y[i][0] = ini_y[i];
        }

        // Calculate the forward difference table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
            }
        }

        // Print the forward difference table
        cout << "Forward Difference Table:" << endl;
        for (int i = 0; i < n; i++) {
            cout << setw(6) << x[i] << "\t";
            for (int j = 0; j < n - i; j++) {
                cout << setw(6) << y[i][j] << "\t";
            }
            cout << endl;
        }

        // Estimate the value at the given point
        float sum = y[0][0]; // Start with the first value in the first column
        float p = (value - x[0]) / (x[1] - x[0]); // Calculate p

        // Add terms of the interpolation formula
        for (int i = 1; i < n; i++) {
            sum = sum + (find_p(p, i) * y[0][i]) / fact(i);
        }

        // Print the estimated value
        cout << "Value at " << value << " is " << sum << endl;
    }
};

int main() {
    float value = 1895; // The x value at which we want to estimate y

    // Create an instance of Newton_Forward_Interpolation
    Newton_Forward_Interpolation newton_Forward_Interpolation(value);

    // Perform the interpolation and print results
    newton_Forward_Interpolation.find();

    return 0;
}