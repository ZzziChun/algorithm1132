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
