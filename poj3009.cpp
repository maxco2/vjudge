#ifdef _DEBUG
#define DEBUG(x) cout << #x " " << x << endl;
#define DEBUG_MSG(msg, x) cout << msg #x " " << x << endl;
#else
#define DEBUG(x)
#define DEBUG_MSG(msg, x)
#endif
#include <algorithm>
#include <climits>
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

static char room[21][21];
static int w, h;
static int gx, gy;
static int sx, sy;

void dfs(int x, int y, int &res, int curres)
{
    if (curres > 10) return;
    DEBUG(x);
    DEBUG(y);
    RANGE_FOR(dx, -1, 2)
    RANGE_FOR(dy, -1, 2)
    {
        if (dx != dy && dx != -dy)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < h && ny < w && nx >= 0 && ny >= 0)
                    {
                        if (room[nx][ny] == '3')
                            {
                                curres += 1;
                                res = min(res, curres);
                                return;
                            }
                        else if (room[nx][ny] != '1')
                            {
                                // dx  dy
                                //-1   0  left
                                // 0   -1  down
                                // 1   0  right
                                // 0   1   up
                                if (dx != 0)
                                    {
                                        while (nx < h && nx >= 0 &&
                                               room[nx][y] != '3' &&
                                               room[nx][y] != '1')
                                            nx += dx;
                                        if (nx >= h || nx < 0)
                                            continue;
                                        else if (room[nx][y] == '3')
                                            {
                                                // hit  goal;
                                                curres += 1;
                                                res = min(res, curres);
                                                return;
                                            }
                                        else if (room[nx][y] == '1')
                                            {
                                                DEBUG(dx);
                                                DEBUG(dy);
                                                DEBUG_MSG("hit  stone  at ",
                                                          nx);
                                                DEBUG_MSG("hit  stone  at ", y);
                                                room[nx][y] = '0';
                                                if (curres + 1 < res &&
                                                    curres + 1 < 10)
                                                    dfs(nx - dx, y, res,
                                                        curres + 1);
                                                room[nx][y] = '1';
                                                continue;
                                            }
                                    }

                                if (dy != 0)
                                    {
                                        while (ny < w && ny >= 0 &&
                                               room[x][ny] != '3' &&
                                               room[x][ny] != '1')
                                            ny += dy;
                                        if (ny >= w || ny < 0)
                                            continue;
                                        else if (room[x][ny] == '3')
                                            {
                                                // hit  goal;
                                                curres += 1;
                                                res = min(res, curres);
                                                return;
                                            }
                                        else if (room[x][ny] == '1')
                                            {
                                                DEBUG(dx);
                                                DEBUG(dy);
                                                DEBUG_MSG("hit  stone  at ", x);
                                                DEBUG_MSG("hit  stone  at ",
                                                          ny);
                                                room[x][ny] = '0';
                                                if (curres + 1 < res &&
                                                    curres + 1 < 10)
                                                    dfs(x, ny - dy, res,
                                                        curres + 1);
                                                room[x][ny] = '1';
                                                continue;
                                            }
                                    }
                            }
                    }
            }
    }
}
void solve()
{
    RFOR(x, h)
    RFOR(y, w)
    {
        if (room[x][y] == '2')
            {
                DEBUG_MSG("start at ", x);
                DEBUG_MSG("start at ", y);
                int res = INT_MAX;
                room[x][y] = '0';
                dfs(x, y, res, 0);
                printf("%d\n", res > 10 ? -1 : res);
                return;
            }
    }
}
int main()
{
    while (~scanf("%d %d", &w, &h))
        {
            DEBUG(w);
            DEBUG(h);
            if (w == 0 && h == 0) return 0;
            RFOR(x, h)
            RFOR(y, w) { scanf(" %c", room[x] + y); }
            solve();
        }
}

