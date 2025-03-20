#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 7; // Number of nodes

vector<vector<int>> graph = {
    { 0, 0, 1, 0, 1, 0, 1 },
    { 0, 0, 0, 1, 1, 0, 0 },
    { 1, 0, 0, 1, 0, 1, 1 },
    { 0, 1, 1, 0, 0, 1, 0 },
    { 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 1, 0 }
};

// BFS to compute the shortest path
int shortestPath(int start, int end)
{
    if (start == end)
        return 0;

    queue<pair<int, int>> q;
    vector<bool> visited(N, false);

    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        int currentNode = q.front().first;
        int currentSteps = q.front().second;
        q.pop(); // 處理當前的搜尋

        for (int neighbor = 0; neighbor < N; neighbor++) {
            // 當前 node 與 neighbor 相鄰 && 該 neighbor 未被放問過
            if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                if (neighbor == end)
                    return currentSteps + 1;            // find the target
                q.push({ neighbor, currentSteps + 1 }); // 加入為下次尋找的起始點
                visited[neighbor] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0))
        cout << shortestPath(a, b) << endl;

    return 0;
}
