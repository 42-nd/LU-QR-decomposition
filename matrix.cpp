#include "matrix.h"


Matrix::Matrix(int dim) : dim(dim){
    data.resize(dim, vector<double>(dim, 0));
}

void Matrix::print() const {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::dotProduct(const Matrix& other) const {
    Matrix result(dim);
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            for (int k = 0; k < dim; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

vector<double> Matrix::vecProduct(const vector<double>& vec) const {
    vector<double> result(dim, 0);
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            result[i] += data[i][j] * vec[j];
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix transposed(dim);
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            transposed.data[j][i] = data[i][j];
        }
    }
    return transposed;
}