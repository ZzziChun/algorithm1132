#include <iostream>
#include <locale.h>
using namespace std;

int counter = 0;

// recursive
unsigned long long fibonacci(int n)
{
    counter++;
    if (n <= 1) {
        return n;
    } else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // 設定 locale 為當地區設置, default is America.
    setlocale(LC_NUMERIC, "");

    printf("using recursive approach\n");
    printf("n : ");

    int n;
    cin >> n;

    printf("f(n) : %'llu\n", fibonacci(n));
    printf("run times : %'d\n", counter);

    return 0;
}
