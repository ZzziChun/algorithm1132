#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int k;
        cin >> k;
        vector<int> items(k);
        int total = 0;

        for (int i = 0; i < k; i++)
        {
            cin >> items[i];
            total += items[i];
        }

        // 背包上限設為 total / 2
        int maxWeight = total / 2;
        vector<int> dp(maxWeight + 1, 0);

        // 0/1 背包
        for (int i = 0; i < k; ++i)
        {
            for (int w = maxWeight; w >= items[i]; --w)
                dp[w] = max(dp[w], dp[w - items[i]] + items[i]);

            // // see the process of dp
            // for (int num : dp)
            //     cout << num << " ";
            // cout << endl;
        }

        int s1 = dp[maxWeight];
        int s2 = total - s1;
        cout << abs(s1 - s2) << '\n';
    }
}