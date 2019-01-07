#ifdef _DEBUG
#define DEBUG(x) cout << #x " " << x << endl;
#else
#define DEBUG(x)
#endif
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
#define MAXN 1000
#define FILL(container, value, size)                                           \
    std::fill(std::begin(container), std::end(container), value);
#define FILL_RESIZE(container, value, size)                                    \
    std::fill(std::begin(container), std::end(container), value);              \
    container.resize(size)
#define RANGE_FOR(v, st, ed) for (int v = st; v < ed; ++v)
#define RFOR(v, ed) for (int v = 0; v < ed; ++v)
using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using vint = vector<int>;
// using mii = map<int, int>;
// template <typename T>
// using uptr = unique_ptr<T>;

static char room[101][101];
static int w, h;

void dfs(int x, int y, char c)
{
    DEBUG(x);
    DEBUG(y);
    room[x][y] = '1';
    RANGE_FOR(dx, -1, 2)
    RANGE_FOR(dy, -1, 2)
    {
        int nx = x + dx;
        int ny = y + dy;
        if (dx != -dy && dx != dy && nx < h && ny < w && 0 <= nx && 0 <= ny)
            {
                if (room[nx][ny] == c) dfs(x + dx, y + dy, c);
            }
    }
}
void solve()
{
    int cc = 0;
    RFOR(x, h)
    RFOR(y, w)
    {
        if (room[x][y] != '1')
            {
                DEBUG(x);
                DEBUG(y);
                dfs(x, y, room[x][y]);
                cc += 1;
            }
    }
    printf("%d\n", cc);
}
int main()
{
    while (~scanf("%d %d", &h, &w))
        {
            DEBUG(w);
            DEBUG(h);
            if (w == 0 && h == 0) return 0;
            if (w == 0 || h == 0) continue;
            for (int i = 0; i < h; ++i)
                {
                    scanf("%s", room[i]);
                }
            solve();
        }
}

