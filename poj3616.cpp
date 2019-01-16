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
int n, m, r;
#define MAXN 1001
struct Interval
{
    int st;
    int ed;
    int ef;
    Interval() : st(0), ed(0), ef(0) {}
    Interval(int s, int d, int f) : st(s), ed(d), ef(f) {}
    bool operator<(const Interval &that) const { return ed < that.ed; }
    int length() { return ed - st; }
    int realed() { return ed + r; }
};
Interval interval[MAXN];
void solve();
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    RFOR(i, m)
    {
        int st, ed, ef;
        scanf(" %d%d%d", &interval[i].st, &interval[i].ed, &interval[i].ef);
    }
    sort(interval, interval + m);
    solve();
}
// int dp[2000001];//dp[j]  当前时间可挤奶最大值
// void solve()//800+ms  //O(m*n+r)=10^9 常数很小,险过
//{
// int now = 0, pre = 1;
// RUP(i, 0, m - 1)
//{
// int realed = interval[i].realed();
// RUP(j, realed, n + r)
//{
// dp[j] = max(dp[j], dp[interval[i].st] + interval[i].ef);
//}
// swap(pre, now);
//}
// printf("%d\n", dp[n + r]);
//}

// if j.ed+r<=i.st
// dp[i]=max(dp[j]+ef)
// else  dp[i]=max(dp[j],ef)  //dp[i]第i个时间段一定挤奶最大值
int dp[MAXN];
void solve() // 0ms
{
    RUP(i, 0, m - 1)
    {
        dp[i] = interval[i].ef;
        RUP(j, 0, i - 1)
        {
            if (interval[j].realed() <= interval[i].st)
                dp[i] = max(dp[i], dp[j] + interval[i].ef);
        }
    }
    printf("%d\n", dp[m - 1]);
}
