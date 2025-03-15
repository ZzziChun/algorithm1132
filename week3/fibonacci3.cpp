#include <iostream>
#include <locale.h>
using namespace std;

typedef unsigned long long Matrix[2][2];
Matrix base = { { 0, 1 }, { 1, 1 } };

int counter = 0;

void matrix_multiplication(Matrix a, Matrix b)
{
    counter++;
    Matrix result = { 0 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += (a[i][k] * b[k][j]);
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

// matrix exponentiation
unsigned long long fibonacci3(int n)
{
    if (n == 0)
        return 0;

    Matrix A = { { 0, 1 }, { 1, 1 } };
    power(A, n - 1);

    return A[1][1];
}

int main()
{
    // 設定 locale 為當地區設置, default is America.
    setlocale(LC_NUMERIC, "");

    printf("using matrix exponentiation approach\n");
    printf("n : ");

    int n;
    cin >> n;

    printf("f(n) : %'llu\n", fibonacci3(n));
    printf("run times : %'d\n", counter);

    return 0;
}
