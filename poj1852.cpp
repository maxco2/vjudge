#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#ifdef _DEBUG
#include <iostream>
#define DEBUG(x) cout << #x << x << endl;
#else
#define DEBUG(x)
#endif

using namespace std;
int len;
int n;
int ants;
int mint = -1;
int maxt = -1;
int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
        {
            scanf(" %d%d", &len, &n);
            for (int i = 0; i < n; ++i)
                {
                    scanf(" %d", &ants);
                    mint = max(mint, min(ants, len - ants));
                    maxt = max(maxt, max(ants, len - ants));
                }
            printf("%d %d\n", mint, maxt);
            mint = maxt = -1;
        }
}
