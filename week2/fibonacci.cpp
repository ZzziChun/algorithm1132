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
