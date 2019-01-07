#ifdef _DEBUG
#define DEBUG(x) cout << #x " " << x << endl;
#else
#define DEBUG(x)
#endif
#include <algorithm>
#include <climits>
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
#define FILL(container, value)                                                 \
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
#define MAXX 401
#define MAXY 401
static int room[MAXX][MAXY];
static bool v[MAXX][MAXY];
static int dis[MAXX][MAXY];
static int mx = MAXX, my = MAXY;
static int n;
void reset()
{
    memset(v, 0, sizeof(bool) * MAXX * MAXY);
    memset(dis, 0, sizeof(int) * MAXX * MAXY);
    RANGE_FOR(i, 0, MAXX)
    RANGE_FOR(j, 0, MAXY)
    room[i][j] = INT_MAX;
}
typedef pair<int, int> pii;
int bfs(int x, int y)
{
    queue<pii> q;
    q.push(make_pair(x, y));
    int res = -1;
    v[x][y] = 1;
    int time = 0;
    while (!q.empty())
        {
            pair<int, int> pos = q.front();
            time = dis[pos.first][pos.second];
            DEBUG(pos.first);
            DEBUG(pos.second);
            DEBUG(time);
            q.pop();
            if (time >= room[pos.first][pos.second]) return -1;
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
                                if (room[nx][ny] == INT_MAX)
                                    {
                                        DEBUG(nx);
                                        DEBUG(ny);
                                        DEBUG(room[nx][ny]);
                                        return time + 1;
                                    }
                                else if (time + 1 < room[nx][ny])
                                    {
                                        v[nx][ny] = 1;
                                        dis[nx][ny] =
                                            dis[pos.first][pos.second] + 1;
                                        q.push(make_pair(nx, ny));
                                    }
                            }
                    }
            }
        }
    return res;
}
void solve() { printf("%d\n", bfs(0, 0)); }
int main()
{
    reset();
    while (cin >> n)
        {
            DEBUG(n);
            RFOR(i, n)
            {
                int x, y, t;
                scanf(" %d%d%d", &x, &y, &t);
                room[x][y] = min(t, room[x][y]);
                RANGE_FOR(dx, -1, 2)
                RANGE_FOR(dy, -1, 2)
                {
                    if (dx != dy && dx != -dy)
                        {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx < mx && ny < my && nx >= 0 && ny >= 0)
                                {
                                    room[nx][ny] = min(t, room[nx][ny]);
                                }
                        }
                }
            }
            solve();
            return 0;
        }
}

