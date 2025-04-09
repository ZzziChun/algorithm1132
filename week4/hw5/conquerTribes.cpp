#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

const int INF = 10000;

void conquerTribes(int n, int k, vector<vector<int>> &graph)
{
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> result; // Store the order of conquests
    pq.push({0, k});    // Start attacking from tribe k
    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curTribe = pq.top().second;
        pq.pop();

        if (visited[curTribe])
            continue;
        visited[curTribe] = true;
        result.push_back(curTribe); // Add to conquest order

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && graph[curTribe][i] != INF)
            {
                pq.push({graph[curTribe][i], i});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    conquerTribes(n, k, graph);
    return 0;
}
