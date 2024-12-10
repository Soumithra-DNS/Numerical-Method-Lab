#include <bits/stdc++.h> // Include all standard libraries

using namespace std;

// Class implementing the Newton-Raphson method
class NewtonRaphson {
private:
    double tolerance;       // Convergence threshold
    int maxIterations;      // Maximum iterations allowed

    // Function to find the root of
    double function(double x) {
        return x * x * x - x * x + 2; // f(x) = x^3 - x^2 + 2
    }

    // Derivative of the function
    double derivative(double x) {
        return 3 * x * x - 2 * x; // f'(x) = 3x^2 - 2x
    }

public:
    // Constructor to initialize tolerance and maximum iterations
    NewtonRaphson(double tol = 1e-6, int maxIter = 1000) : tolerance(tol), maxIterations(maxIter) {}

    // Method to find the root starting from an initial guess
    double findRoot(double x) {
        for (int i = 0; i < maxIterations; ++i) {
            double fx = function(x);       // Compute f(x)
            double fPrimeX = derivative(x); // Compute f'(x)

            // Check if the derivative is too small
            if (fabs(fPrimeX) < 1e-10) {
                cout << "Derivative is too small. No convergence." << endl;
                return x; // Exit with the current approximation
            }

            // Compute the next approximation using Newton-Raphson formula
            double xNew = x - fx / fPrimeX;

            // Print the iteration number and the new value of x
            cout << "Iteration " << i + 1 << " = " << xNew << endl;

            // Check for convergence: if the change is smaller than the tolerance
            if (fabs(xNew - x) < tolerance) {
                cout << "Converged in " << i + 1 << " iterations." << endl;
                return xNew; // Return the root
            }

            // Update x for the next iteration
            x = xNew;
        }

        // If maximum iterations are reached, warn the user
        cout << "Max iterations reached. Solution may not have converged." << endl;
        return x; // Return the last computed value
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    // Generate a random initial guess between -5 and 4
    double initialGuess = rand() % 10 - 5;

    // Print the initial guess
    cout << "Using initial guess: " << initialGuess << endl;

    // Create an instance of the NewtonRaphson solver with default tolerance and max iterations
    NewtonRaphson solver(1e-6, 100);

    // Find the root starting from the random initial guess
    double root = solver.findRoot(initialGuess);

    // Print the estimated root
    cout << "Estimated root: " << root << endl;

    return 0;
}