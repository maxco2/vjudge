#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
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
int n, m;
#define MAXN 100001
using vint = vector<int>;
vint nd;
vint value;
int dp[MAXN];
vint perm;
void naiveSolve();
void solve();
void bfssolve();
int main()
{
    scanf("%d%d", &n, &m);
    int newn = 0;
    nd.push_back(0);
    value.push_back(0);
    RFOR(i, n)
    {
        int need, va;
        scanf(" %d%d", &need, &va);
        int no = m / need;
        RUP(i, 1, no)
        {
            newn++;
            nd.push_back(need);
            value.push_back(va);
        }
    }
    n = newn;
    // naiveSolve();
    // solve();
    bfssolve();
}
void bfssolve()
{
    perm = vint(n + 1, 0);
    RUP(i, 1, n) perm[i] = i;
    sort(perm.begin() + 1, perm.end(), [](int t1, int t2) {
        return value[t1] * nd[t2] > value[t2] * nd[t1];
    });
    struct St
    {
        int allvalue = 0;
        int left = m;
        int cur = 1;
        St() {}
        St(int a, int l, int c) : allvalue(a), left(l), cur(c) {}
        bool operator<(const St &that) const
        {
            return allvalue < that.allvalue;
        }
        int trygetmost()
        {
            St that{*this};
            while (that.cur <= n && that.left > nd[perm[that.cur]])
                {
                    that.left -= nd[perm[that.cur]];
                    that.allvalue += value[perm[that.cur++]];
                }
            if (that.cur <= n)
                that.allvalue +=
                    that.left * value[perm[that.cur]] / nd[perm[that.cur]];
            return that.allvalue;
        }
    };
    priority_queue<St> q;
    q.push(St{});
    int res = 0;
    while (!q.empty())
        {
            auto curst = q.top();
            q.pop();
            if (curst.cur == n + 1) // finish  choose
                {
                    res = max(res, curst.allvalue);
                    continue;
                }
            if (curst.left >= nd[perm[curst.cur]])
                q.push(St{curst.allvalue + value[perm[curst.cur]],
                          curst.left - nd[perm[curst.cur]], curst.cur + 1});
            if (curst.trygetmost() > res)
                {
                    curst.cur += 1;
                    q.push(curst);
                }
        }
    printf("%d\n", res);
}
