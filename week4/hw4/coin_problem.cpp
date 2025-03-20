#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

void find_change(int k, int category, int quantity)
{
    map<int, int> prices = { { 1, 17 }, { 2, 25 } };
    int total_cost = prices[category] * quantity;
    int change = k - total_cost;

    if (change < 0)
        return;

    vector<int> denominations = { 50, 10, 5, 1 };
    map<int, int> coins;

    for (int coin : denominations) {
        coins[coin] = change / coin;
        change %= coin;
    }

    bool first = true;
    for (int coin : { 1, 5, 10, 50 }) {
        if (coins[coin] > 0) {
            if (!first)
                cout << ",";
            cout << "Coin " << coin << ":" << coins[coin];
            first = false;
        }
    }
    cout << endl;
}

int main()
{
    int k, category, quantity;
    char comma;
    cin >> k >> comma >> category >> comma >> quantity;

    find_change(k, category, quantity);

    return 0;
}
