#include <bits/stdc++.h>
using namespace std;

// Class to implement the False Position Method
class FalsePositionMethod {
public:
    // Constructor to initialize tolerance and maximum iterations, and generate a valid random interval
    FalsePositionMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {
        generateRandomInterval();
    }

    // Function to find the root using the False Position Method
    double findRoot() {
        double c = 0; // Initialize variable to hold the current estimate of the root
        for (int i = 0; i < maxIterations; ++i) {
            // Calculate the new estimate using the False Position formula
            c = a - (func(a) * (b - a)) / (func(b) - func(a));
            double f_c = func(c); // Evaluate the function at the estimated root

            cout << "Iteration " << i + 1 << " = " << c << endl;

            // Check if the estimated root satisfies the tolerance
            if (fabs(f_c) < tolerance) {
                return c; // Return the root if it's accurate enough
            }

            // Update the interval based on the sign of the function at the endpoints
            if (func(a) * f_c < 0) {
                b = c; // Root is in the left subinterval [a, c]
            } else {
                a = c; // Root is in the right subinterval [c, b]
            }
        }

        // Return the last estimate if the root wasn't found within maxIterations
        return c;
    }

private:
    double a, b, tolerance;  // Endpoints of the interval, and tolerance for convergence
    int maxIterations;       // Maximum number of iterations allowed

    // Function to evaluate the mathematical equation whose root is being found
    double func(double x) {
        return x * x * x - 2 * x - 5; // Example: f(x) = x^3 - 2x - 5
    }

    // Generate a random valid interval [a, b] such that f(a) * f(b) < 0
    void generateRandomInterval() {
        srand(static_cast<unsigned>(time(0))); // Seed the random number generator

        do {
            // Generate random numbers between -10 and 10 for a and b
            a = (rand() % 200 - 100) / 10.0;
            b = (rand() % 200 - 100) / 10.0;
        } while (func(a) * func(b) > 0); // Ensure that the interval contains a root
    }
};

// Main function
int main() {
    // Desired accuracy and maximum number of iterations
    double tolerance = 1e-6;
    int maxIterations = 100;

    // Create an instance of the FalsePositionMethod class
    FalsePositionMethod falsePosition(tolerance, maxIterations);

    // Use the method to find the root
    double root = falsePosition.findRoot();

    // Output the root
    cout << "Root: " << root << endl;

    return 0;
}
