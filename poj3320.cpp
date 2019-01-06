#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
    "-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", \
    3)
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#ifdef _DEBUG
#define DEBUG(x) cout << #x " " << x << endl;
#else
#define DEBUG(x)
#endif

using namespace std;
int size = 0;
map<int, int> cs;
int a[1000000];

void solve(int n)
{
    if (size == 1) cout << 1 << endl;
    int sz = 0;
    int res = n + 2;
    int l = 0, r = 0;
    while (true)
        {
            while (l <= r && r < n && sz < size)
                {
                    if (cs[a[r]] == 0)
                        {
                            sz++;
                        }
                    cs[a[r]] += 1;
                    ++r;
                }
            if (sz < size) break;
            {
                DEBUG(l);
                DEBUG(r);
                res = min(res, r - l);
                if (--cs[a[l++]] == 0) sz -= 1;
                DEBUG(sz);
            }
        }
    cout << res << endl;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
        {
            for (int i = 0; i < n; ++i)
                {
                    scanf("%d", a + i);
                    cs[a[i]] = 0;
                }
            size = cs.size();
            DEBUG(size);
            DEBUG(n);
            solve(n);
        }
}

