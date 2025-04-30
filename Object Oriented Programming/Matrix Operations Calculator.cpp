#include <iostream>
using namespace std;

class Matrix {
protected:
    int rows, cols;
    int** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0; 
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    Matrix transpose() const;
};

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()) {
        cout << "Error: Matrices have different dimensions. Cannot add them.\n";
        return Matrix(0, 0);  // Return an empty matrix to indicate an error
    }

    Matrix result(m1.getRows(), m1.getCols());
    for (int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m1.getCols(); ++j) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    if (m1.getCols() != m2.getRows()) {
        cout << "Error: Matrices have incompatible dimensions for multiplication.\n";
        return Matrix(0, 0);  // Return an empty matrix to indicate an error
    }

    Matrix result(m1.getRows(), m2.getCols());
    for (int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1.getCols(); ++k) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

int main() {
    int choice, rows, cols;
    
    cout << "Matrix Operations Calculator\n";
    
    do {
        cout << "\n1. Add Matrices\n";
        cout << "2. Multiply Matrices\n";
        cout << "3. Transpose Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter rows and columns for Matrix 1: ";
            cin >> rows >> cols;
            Matrix matrix1(rows, cols);
            matrix1.input();

            cout << "Enter rows and columns for Matrix 2: ";
            cin >> rows >> cols;
            Matrix matrix2(rows, cols);
            matrix2.input();

            Matrix result(0, 0);
            bool validOperation = true;
            
            switch (choice) {
                case 1:
                    result = matrix1 + matrix2;
                    break;
                case 2:
                    result = matrix1 * matrix2;
                    break;
                default:
                    validOperation = false;
                    break;
            }

            // Display the result only if the operation was valid
            if (validOperation && result.getRows() > 0 && result.getCols() > 0) {
                cout << "\nResulting Matrix:\n";
                result.display();
            } else {
                cout << "Invalid matrix operation due to incompatible dimensions.\n";
            }

        } else if (choice == 3) {
            cout << "Enter rows and columns for Matrix: ";
            cin >> rows >> cols;
            Matrix matrix(rows, cols);
            matrix.input();

            Matrix result = matrix.transpose();
            cout << "\nTranspose of Matrix:\n";
            result.display();

        } else if (choice == 4) {
            cout << "Exiting calculator..." << endl;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
