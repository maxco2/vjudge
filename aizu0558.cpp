#ifdef _DEBUG
#define DEBUG(x) cout << #x " " << x << endl;
#else
#define DEBUG(x)
#endif
#include <algorithm>
#include <cstdio>
#include <cstring>
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

static char room[1001][1001];
static bool v[1001][1001];
static int dis[1001][1001];
static int mx, my;
static int n;
void reset()
{
    memset(v, 0, sizeof(bool) * 1001 * 1001);
    memset(dis, 0, sizeof(int) * 1001 * 1001);
}

int bfs(int x, int y)
{
    reset();
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    char hp = '1';
    int res = 0;
    v[x][y] = 1;
    while (!q.empty())
        {
        a:
            pair<int, int> pos = q.front();
            q.pop();
            RANGE_FOR(dx, -1, 2)
            RANGE_FOR(dy, -1, 2)
            {
                if (dx != dy && dx != -dy)
                    {
                        int nx = pos.first + dx;
                        int ny = pos.second + dy;
                        if (nx < mx && ny < my && 0 <= nx && 0 <= ny &&
                            !v[nx][ny])
                            {
                                if (room[nx][ny] == hp)
                                    {
                                        DEBUG(nx);
                                        DEBUG(ny);
                                        hp++;
                                        res += dis[pos.first][pos.second] + 1;
                                        DEBUG(res);
                                        if (hp > char('0' + n)) return res;
                                        reset();
                                        v[nx][ny] = 1;
                                        q = queue<pair<int, int>>();
                                        q.push({nx, ny});
                                        goto a;
                                    }
                                else if (room[nx][ny] != 'X')
                                    {
                                        v[nx][ny] = 1;
                                        dis[nx][ny] =
                                            dis[pos.first][pos.second] + 1;
                                        DEBUG(dis[nx][ny]);
                                        q.push({nx, ny});
                                    }
                            }
                    }
            }
        }
    return res;
}
void solve()
{
    RFOR(x, mx)
    RFOR(y, my)
    {
        if (room[x][y] == 'S')
            {
                DEBUG(x);
                DEBUG(y);
                printf("%d\n", bfs(x, y));
                return;
            }
    }
}
int main()
{
    while (cin >> mx >> my >> n)
        {
            DEBUG(mx);
            DEBUG(my);
            DEBUG(n);
            for (int i = 0; i < mx; ++i)
                {
                    scanf("%s", room[i]);
                }
            solve();
            return 0;
        }
}

