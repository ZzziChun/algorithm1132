#include <iostream>
#include <locale.h>
using namespace std;

int counter = 0;

// iterative
unsigned long long fibonacci2(int n)
{
    if (n <= 1) {
        counter++;
        return n;
    }

    unsigned long long previous = 0, current = 1;
    for (int i = 2; i <= n; i++) {
        counter++;
        unsigned long long next = (previous + current);
        previous = current;
        current = next;
    }
    return current;
}

int main()
{
    // 設定 locale 為當地區設置, default is America.
    setlocale(LC_NUMERIC, "");

    printf("using iterative approach\n");
    printf("n = ");

    int n;
    cin >> n;

    printf("F(%d) = %'llu\n", n, fibonacci2(n));
    printf("run times = %'d\n", counter);

    return 0;
}
