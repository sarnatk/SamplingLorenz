#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

// inverse function for Lorenz CDF
double F(double x, double x0 = 0, double gamma = 1) {
    x = x0 + gamma * tan(M_PI * (x - 0.5));
    return x;
}

vector<double> sample_lorenz(int n, double x0 = 0, double gamma = 1) {
    vector<double> values;
    values.reserve(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> d(0, 1);

    for (int i = 0; i < n; i++) {
        values.push_back(F(d(gen), x0, gamma));
    }
    return values;
}

int main() {

    // usage example
    for (auto x: sample_lorenz(100, 0, 0.5)) {
        cout << x << '\n';
    }
}
