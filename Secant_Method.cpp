#include <bits/stdc++.h> // Include all standard libraries

using namespace std;

// Class implementing the Secant Method
class SecantMethod {
private:
    double tolerance;       // Convergence threshold
    int maxIterations;      // Maximum number of iterations allowed

    // Function to find the root of
    double function(double x) {
        return x * x * x - x * x + 2; // f(x) = x^3 - x^2 + 2
    }

public:
    // Constructor to initialize tolerance and maximum iterations
    SecantMethod(double tol = 1e-6, int maxIter = 1000) : tolerance(tol), maxIterations(maxIter) {}

    // Method to find the root starting from two initial guesses
    double findRoot(double x0, double x1) {
        for (int i = 0; i < maxIterations; ++i) {
            double f_x0 = function(x0); // Compute f(x0)
            double f_x1 = function(x1); // Compute f(x1)

            // Check if the denominator is too small to prevent division by zero
            if (fabs(f_x1 - f_x0) < 1e-10) {
                cerr << "Difference between function values is too small. No convergence." << endl;
                return x1; // Exit with the current approximation
            }

            // Compute the next approximation using the Secant Method formula
            double x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);

            // Print the current iteration and the new approximation
            cout << "Iteration " << i + 1 << " = " << x2 << endl;

            // Check for convergence: if the change is smaller than the tolerance
            if (fabs(x2 - x1) < tolerance) {
                cout << "Converged in " << i + 1 << " iterations." << endl;
                return x2; // Return the root
            }

            // Update the previous two points for the next iteration
            x0 = x1;
            x1 = x2;
        }

        // If maximum iterations are reached, warn the user
        cout << "Max iterations reached. Solution may not have converged." << endl;
        return x1; // Return the last computed value
    }
};

int main() {
    // Create an instance of the SecantMethod solver with default tolerance and max iterations
    SecantMethod solver(1e-6, 100);

    // Define two initial guesses
    double x0 = -2.0; // First initial guess
    double x1 = 3.0;  // Second initial guess

    // Print the initial guesses
    cout << "Using initial guesses: x0 = " << x0 << ", x1 = " << x1 << endl;

    // Find the root starting from the initial guesses
    double root = solver.findRoot(x0, x1);

    // Print the estimated root
    cout << "Estimated root: " << root << endl;

    return 0;
}