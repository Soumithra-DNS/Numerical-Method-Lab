#include<bits/stdc++.h>
using namespace std;

// Class to perform Lagrange Interpolation
class LagrangeInterpolator {
public:
    // Known data points (x, y)
    vector<double> x = {1, 2, 3}; // Example x values
    vector<double> y = {2, 3, 4}; // Corresponding y values

    // Method to interpolate and find y for a given x (targetX)
    double interpolate(double targetX) {
        int n = x.size();  // Number of known data points
        double ans = 0.0;  // Final interpolated value

        // Loop over each term in the Lagrange polynomial
        for (int i = 0; i < n; i++) {
            double Maxterm = y[i];  // Initialize with y[i]

            // Calculate the product of terms for the Lagrange polynomial
            for (int j = 0; j < n; j++) {
                if (i != j) { // Skip the current index
                    Maxterm *= (targetX - x[j]) / (x[i] - x[j]);
                }
            }

            // Add the term to the final result
            ans += Maxterm;
        }

        return ans; // Return the interpolated value
    }
};

int main() {
    // Create an instance of the LagrangeInterpolator
    LagrangeInterpolator interpolator;

    // Target x value where we want to estimate y
    double value = 2.5;

    // Perform interpolation
    double expectedValueForY = interpolator.interpolate(value);

    // Print the result
    cout << "Interpolated value at x = " << value << " is " << expectedValueForY << endl;

    return 0;
}
