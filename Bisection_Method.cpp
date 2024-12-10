#include <bits/stdc++.h> // Includes all necessary C++ libraries
using namespace std;

// Class definition for Bisection Method
class BisectionMethod {
public:
    // Constructor initializes tolerance and maximum iterations and generates a random interval
    BisectionMethod(double tolerance, int maxIterations)
        : tolerance(tolerance), maxIterations(maxIterations) {
        generateRandomInterval();
    }

    // Function to find the root using the Bisection Method
    double findRoot() {
        double c; // Midpoint of the interval
        for (int i = 0; i < maxIterations; ++i) {
            c = (a + b) / 2; // Calculate midpoint
            cout << "Iteration " << i + 1 << " = " << c << endl;

            double f_c = func(c); // Evaluate the function at the midpoint

            // Check stopping criteria:
            // 1. If |f(c)| is smaller than the tolerance, we've found the root
            // 2. If the interval width is smaller than the tolerance, stop
            if (fabs(f_c) < tolerance || (b - a) / 2 < tolerance) {
                return c;
            }

            // Update the interval based on the sign of f(c)
            if (func(a) * f_c < 0) {
                b = c; // Root is in the left subinterval [a, c]
            } else {
                a = c; // Root is in the right subinterval [c, b]
            }
        }
        return c; // Return the estimated root after max iterations
    }

    // Function to define the equation whose root we are finding
    double func(double x) {
        return x * x * x - 2 * x - 5; // Example: f(x) = x^3 - 2x - 5
    }

private:
    double a, b, tolerance;  // Interval endpoints, tolerance
    int maxIterations;       // Maximum iterations allowed

    // Function to generate a valid random interval [a, b] where f(a) * f(b) < 0
    void generateRandomInterval() {
        srand(static_cast<unsigned>(time(0))); // Seed the random number generator

        do {
            // Generate random numbers between -10 and 10 for a and b
            a = (rand() % 200 - 100) / 10.0;
            b = (rand() % 200 - 100) / 10.0;

            // Ensure a < b by swapping if necessary
            if (a >= b)
                swap(a, b);
        } while (func(a) * func(b) > 0); // Repeat until f(a) * f(b) < 0
    }
};

// Main function
int main() {
    double tolerance = 1e-6; // Desired accuracy
    int maxIterations = 100; // Maximum iterations allowed

    // Create an object of the BisectionMethod class
    BisectionMethod bisection(tolerance, maxIterations);

    // Find the root using the Bisection Method
    double root = bisection.findRoot();

    // Output the estimated root
    cout << "Root: " << root << endl;

    return 0;
}
