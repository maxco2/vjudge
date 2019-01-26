#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#ifdef _DEBUG
#include <iostream>
#define DEBUG(x) cout << #x << x << endl;
#else
#define DEBUG(x)
#endif
#define RANGE_FOR(v, st, ed) for (int v = st; v < ed; ++v)
#define RUP(v, st, ed) for (int v = st; v <= ed; ++v)
#define RDO(v, st, ed) for (int v = st; v >= ed; --v)
#define RFOR(v, ed) for (int v = 0; v < ed; ++v)
using namespace std;
int m[5][5];
void solve();

int main()
{
    //    ios::sync_with_stdio(false);
    RUP(i, 0, 4)
    RUP(j, 0, 4)
    scanf("%d", &m[i][j]);
    solve();
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
set<int> s;
void dfs(int x, int y, int num, int hop)
{
    if (hop == 0)
        {
            s.insert(num);
            return;
        }
    num = num * 10 + m[x][y];
    int nx, ny;
    RUP(i, 0, 3)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4) dfs(nx, ny, num, hop - 1);
    }
}

void solve()
{
    RUP(i, 0, 4)
    RUP(j, 0, 4)
    dfs(i, j, 0, 6);
    cout << s.size() << endl;
}
