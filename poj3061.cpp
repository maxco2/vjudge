#include <cstdio>
#include <iostream>
#ifdef _DEBUG
#define DEBUG(x) cout << #x << x << endl;
#else
#define DEBUG(x)
#endif

using namespace std;
int a[100000] = {0};
void solve(int N, int S)
{
    // dp[n]=min({j-i|sum(i,j)>n})
    int l = 0, r = 0, sum = 0;
    int res = N + 2;
    while (true)
        {
            while (r - l < N && sum < S && r - l >= 0 && r < N)
                {
                    sum += a[r++];
                }
            if (sum < S)
                {
                    break;
                }
            else
                {
                    DEBUG(l);
                    DEBUG(r);
                    DEBUG(sum);
                    // push left
                    res = min(res, r - l);
                    sum -= a[l++];
                }
        }
    res = res > N ? 0 : res;
    cout << res << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        {
            int N, S;
            cin >> N >> S;
            DEBUG(N);
            DEBUG(S);
            for (int j = 0; j < N; ++j)
                cin >> a[j];
            solve(N, S);
        }
}
