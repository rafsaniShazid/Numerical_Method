#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to display a matrix
void displayMatrix(const vector<vector<double>>& mat) {
    for (const auto& row : mat) {
        for (const auto& elem : row) {
            cout << setw(10) << elem << " ";
        }
        cout << endl;
    }
}

// Function to invert a matrix
bool invertMatrix(vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> identity(n, vector<double>(n, 0));

    // Create identity matrix
    for (int i = 0; i < n; ++i) {
        identity[i][i] = 1;
    }

    // Apply Gaussian elimination
    for (int i = 0; i < n; ++i) {
        // Make the diagonal element 1
        double diagElement = matrix[i][i];
        if (diagElement == 0) {
            cerr << "Matrix is singular and cannot be inverted." << endl;
            return false;
        }

        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= diagElement;
            identity[i][j] /= diagElement;
        }

        // Make the rest of the column 0
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    identity[k][j] -= factor * identity[i][j];
                }
            }
        }
    }

    // Replace original matrix with inverted matrix
    matrix = identity;
    return true;
}

int main() {
    // Example matrix (3x3)
    vector<vector<double>> matrix = {
        {4, 7, 2},
        {3, 6, 1},
        {2, 5, 9}
    };

    cout << "Original Matrix:" << endl;
    displayMatrix(matrix);

    if (invertMatrix(matrix)) {
        cout << "\nInverted Matrix:" << endl;
        displayMatrix(matrix);
    } else {
        cout << "\nMatrix inversion failed." << endl;
    }

    return 0;
}
