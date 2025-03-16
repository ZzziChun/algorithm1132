#include <gmpxx.h>
#include <iostream>
#include <locale.h>
using namespace std;

typedef mpz_class Matrix[2][2];
Matrix base = { { 0, 1 }, { 1, 1 } };

int counter = 0;

void matrix_multiplication(Matrix A, Matrix B)
{
    counter++;

    mpz_class x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    mpz_class y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    mpz_class z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    mpz_class w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

void power(Matrix A, long long fib)
{
    if (fib == 0 || fib == 1)
        return;

    power(A, fib / 2);
    matrix_multiplication(A, A);

    // odd case
    if (fib % 2 == 1)
        matrix_multiplication(A, base);
}

mpz_class fibonacciGMP(long long n)
{
    if (n == 0) {
        counter++;
        return 0;
    }
    if (n == 1) {
        counter++;
        return 1;
    }

    Matrix A = { { 0, 1 }, { 1, 1 } };
    power(A, n);

    return A[0][1];
}

int main()
{
    // 設定 locale 為當地區設置, default is America.
    setlocale(LC_NUMERIC, "");
    cout.imbue(locale(""));

    long long n;
    cout << "n = ";
    cin >> n;

    mpz_class result = fibonacciGMP(n);
    cout << "F(" << n << ") = " << result << endl;
    printf("run times (do matrix_multiplication) = %d\n", counter);

    // Calculate and display the number of digits in the result
    size_t digits = result.get_str().size();
    printf("Number of digits in F(%'lld) = %'zu\n", n, digits);

    return 0;
}
