#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define FILL(n, value) std::fill(std::begin(n), std::end(n), value)
using namespace std;
bool m[200000][200000];
int maxsum = 0;
bool visited[200000];
// void bfs(int pos, int &sum, int dist)
//{
// std::queue<int> q;
// q.push(pos);
// while (!q.empty())
//{
// pos = q.front();
// q.pop();

// visited[pos] = true;
// for (int i = 0; i < n; ++i)
// if (m[pos][i] && !visited[i])
//{
// q.push(i);
//}
//}
//}

int main()
{
    std::vector<int> vertex(200000, -1);
    int n;
    cin >> n;
    FILL(vertex, -1);
    for (int i = 0; i < n; ++i)
        {
            int d;
            cin >> d;
            vertex[i] = d;
        }
    for (int i = 0; i < n - 1; ++i)
        {
            int st, ed;
            cin >> st >> ed;
            m[st - 1][ed - 1] = 1;
            m[ed - 1][st - 1] = 1;
        }
    for (int i = 0; i < n; ++i)
        {
            FILL(visited, false);
            int sum = 0;
            // bfs(i, sum, 0);
            maxsum = sum > maxsum ? sum : maxsum;
        }
    cout << maxsum << endl;
}
