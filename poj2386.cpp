#include <functional>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAXM 101
#define MAXN 101
char f[MAXN][MAXM];
int m, n;
void dfs(int x, int y)
{
    f[x][y] = '.';
    for (int dx = -1; dx <= 1; ++dx)
        for (int dy = -1; dy <= 1; ++dy)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx <= n && ny <= m && 1 <= nx && 1 <= ny &&
                    f[nx][ny] == 'W')
                    dfs(nx, ny);
            }
}
int main()
{
    scanf("%d %d", &n, &m);
    {
        memset(f, '\0', MAXM * MAXN);
        for (int i = 1; i <= n; ++i)
            {
                scanf("%s", f[i] + 1);
            }
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (f[i][j] == 'W')
                    {
                        dfs(i, j);
                        res += 1;
                    }
        cout << res << endl;
    }
}

