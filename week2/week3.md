## 方法一：

**code :**

```cpp
#include <iostream>
using namespace std;

const int mod = 1000000;
int counter = 0;

// using Recursive
long long fibonacci(int n)
{
    counter++;
    if (n <= 1) {
        return n;
    } else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    printf("using recursive\n");
    cin >> n;
    // printf("%06lld\n", fibonacci(n) % mod); // for etutor answer
    printf("last 6 digits : %lld\n", fibonacci(n) % mod);
    printf("run times : %d", counter);

    return 0;
}
```

使用遞迴方式跑 n = 36 的 Fibonnaccic Sequence 是最耗時的, 整整了將近五千多萬次 function, 他的時間複雜度爲 `O(2^n)`

## 方法二：

**code :**

```cpp
#include <iostream>
using namespace std;

const int mod = 1000000;
int counter = 0;

// using iterative
long long fibonacci2(int n)
{
    if (n <= 1) {
        counter++;
        return n;
    }

    int previous = 0, current = 1;
    for (int i = 2; i <= n; i++) {
        counter++;
        int next = (previous + current) % mod;
        previous = current;
        current = next;
    }
    return current;
}

int main()
{
    int n;
    printf("using iterative\n");
    cin >> n;
    // printf("%06lld\n", fibonacci2(n) % mod); // for etutor answer
    printf("last 6 digits : %lld\n", fibonacci2(n) % mod);
    printf("run times : %d", counter);

    return 0;
}
```

而使用迴圈跑 n = 36 的 Fibonnaccic Sequence 僅僅呼叫了 function 35 次, 時間複雜度爲`O(n)`

## 方法三：

**code :**

```cpp

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
    printf("run times : %d", counter);

    return 0;
}
```

最後, 第三種方式採用了矩陣平方的方式, 使用起來非常有效率, 時間複雜度爲`O(log N)`
