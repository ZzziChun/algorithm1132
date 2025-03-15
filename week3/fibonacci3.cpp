#include <iostream>
using namespace std;

typedef long long Matrix[2][2];
Matrix base = { { 0, 1 }, { 1, 1 } };
const int mod = 1000000;
int counter = 0;

void matrix_multiplication(Matrix a, Matrix b)
{
    counter++;
    Matrix result = { 0 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += (a[i][k] * b[k][j]) % mod;
            }
        }
    }

    // copy to a
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = result[i][j];
        }
    }
}

void power(Matrix A, int fib)
{
    if (fib == 0 || fib == 1)
        return;

    power(A, fib / 2);
    matrix_multiplication(A, A);

    // odd case
    if (fib % 2 == 1)
        matrix_multiplication(A, base);
}

// using matrix exponentiation
long long fibonacci3(int n)
{
    if (n == 0) {
        counter++;
        return 0;
    }

    Matrix A = { { 0, 1 }, { 1, 1 } };
    power(A, n - 1);

    return A[1][1];
}

int main()
{
    long long n;
    printf("using matrix exponentiation\n");
    cin >> n;
    // printf("%06lld\n", fibonacci3(n) % mod); // for etutor answer
    printf("last 6 digits : %lld\n", fibonacci3(n) % mod);
    printf("run times : %d\n", counter);

    return 0;
}
