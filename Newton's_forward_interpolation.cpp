#include <bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for (ll i = j; i < k; i++)
using namespace std;

// Function to calculate factorial
double factorial(int n) {
    double fact = 1.0;
    forr(i, 2, n + 1) {
        fact *= i;
    }
    return fact;
}

void newtonForward(int x[], double y[][10], int n) {
    double h = x[1] - x[0];

    // Construct the forward difference table
    forr(i, 1, n) {
        forr(j, 0, n - i) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Display the forward difference table
    cout << "\nForward Difference Table:\n";
    forr(i, 0, n) {
        cout << setw(5) << x[i];
        forr(j, 0, n - i) {
            cout << setw(10) << y[i][j];
        }
        cout << endl;
    }

    // Input value of x for which y needs to be calculated
    cout << "Enter the value of x for which you want to find the value of y: ";
    double x0;
    cin >> x0;

    // Calculate u
    double u = (x0 - x[0]) / h;
    double sum = y[0][0];
    double uProduct = 1.0;

    // Calculate y using Newton's Forward formula
    forr(i, 1, n) {
        uProduct *= (u - (i - 1));
        sum += (uProduct * y[0][i]) / factorial(i);
    }

    cout << "\nThe value of y at x = " << x0 << " is " << sum << endl;
}

int main() {
    int x[10], n;
    double y[10][10] = {0};

    cout << "Enter the number of data points: ";
    cin >> n;

    cout << "Enter the data points (x and y):\n";
    forr(i, 0, n) {
        cin >> x[i] >> y[i][0];
    }

    newtonForward(x, y, n);

    return 0;
}
