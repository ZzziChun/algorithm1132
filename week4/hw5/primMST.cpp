#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const int INF = 100000;

int primMST(vector<vector<int>>& graph, int n)
{
    vector<int> minCost(n, INF);
    vector<bool> visited(n, false);
    int totalCost = 0;

    minCost[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, minEdge = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && minCost[j] < minEdge) {
                minEdge = minCost[j];
                u = j;
            }
        }
        visited[u] = true;
        totalCost += minEdge;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] < minCost[v]) {
                minCost[v] = graph[u][v];
            }
        }
    }
    return totalCost;
}

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> graph(k + 1, vector<int>(k + 1));

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            cin >> graph[i][j];
        }
    }

    cout << primMST(graph, k + 1) << endl;

    return 0;
}
