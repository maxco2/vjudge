#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
int t, n;
struct Axis
{
    int x;
    int y;
    Axis() : x(0), y(0) {}
    bool operator<(const Axis &that) const
    {
        if (x != that.x)
            return x < that.x;
        else
            return y < that.y;
    }
    bool operator<=(Axis &that) { return x <= that.x && y <= that.y; }
    bool isect(Axis &that) { return !(*this <= that || that <= *this); }
    bool equal(Axis &that) { return x == that.x && y == that.y; }
};
Axis stick[5000];
void solve();
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
        {
            cin >> n;
            RFOR(i, n) { cin >> stick[i].x >> stick[i].y; }
            sort(stick, stick + n);
            solve();
        }
}
bool intersect(Axis &a1, Axis &a2, Axis &res1, Axis &res2)
{
    if (a1.isect(a2))
        {
            if (a1.x > a2.x)
                {
                    if (res1.x < a2.x) res1.x = a2.x;
                    res1.y = a1.y;
                    return true;
                }
            else
                {
                    res2.x = a1.x;
                    if (res2.y < a2.y) res2.y = a2.y;
                    return true;
                }
        }
    return false;
}
vector<Axis> points;
void solve()
{
    points.clear();
    RFOR(i, n)
    {
        Axis poy;
        Axis pox;
        RFOR(j, i) { intersect(stick[i], stick[j], poy, pox); }

        bool tmp1 = true;
        bool tmp2 = true;
        if (poy.y != 0)
            {
                for (vector<Axis>::iterator st = points.begin();
                     st != points.end(); st++)
                    {
                        bool isect = poy.isect(*st);
                        if (!isect)
                            {
                                *st = *st <= poy ? poy : *st;
                                tmp1 = false;
                                break;
                            }
                    }
                if (tmp1) points.push_back(poy);
            }
        if (pox.x != 0)
            {
                for (vector<Axis>::iterator st = points.begin();
                     st != points.end(); st++)
                    {
                        bool isect = pox.isect(*st);
                        if (!isect)
                            {
                                *st = *st <= pox ? pox : *st;
                                tmp2 = false;
                                break;
                            }
                    }
                if (tmp2) points.push_back(pox);
            }
    }
    cout << points.size() + 1 << endl;
}

