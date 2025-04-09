#include <iostream>
using namespace std;

int josephus(int N, int K)
{
    int result = 0;
    for (int i = 2; i <= N; i++)
    {
        result = (result + K) % i;
    }
    return result + 1;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int N, K;
        cin >> N >> K;
        cout << josephus(N, K) << endl;
    }

    return 0;
}