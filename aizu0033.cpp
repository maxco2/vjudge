#ifdef _DEBUG
#define DEBUG(x) cout << #x " " << x << endl;
#else
#define DEBUG(x)
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
static int data[10];

bool dfs(int B, int C, int i)
{
    bool res = false;
    if (i == 10) return true;
    if (data[i] > B)
        {
            res = dfs(data[i], C, i + 1);
            if (res) return res;
        }
    if (data[i] > C)
        {
            res = dfs(B, data[i], i + 1);
            if (res) return res;
        }
    return false;
}
int main()
{
    int n;
    (scanf("%d", &n));
    RFOR(t, n)
    {
        for (int i = 0; i < 10; ++i)
            {
                scanf("%d", data + i);
            }
        puts(dfs(INT_MIN, INT_MIN, 0) ? "YES" : "NO");
    }
}

