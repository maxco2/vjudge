#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> state;
string legal = "01234567";
string s(8, '0');

inline bool find(string &s) { return state.find(s) != state.end(); }
queue<string> q;
void solve()
{
    if (s == legal)
        {
            cout << 0 << endl;
            return;
        }
    if (find(s))
        {
            cout << state[s] << endl;
            return;
        }
    auto addstate = [](bool b, int pos1, int pos2, string &str) {
        if (b)
            {
                int dis = state[str];
                swap(str[pos1], str[pos2]);
                if (!find(str))
                    {
                        state[str] = dis + 1;
                        q.push(str);
                    }
                swap(str[pos1], str[pos2]);
            }
    };
    while (!q.empty())
        {
            auto str = q.front();
            int pos0 = str.find('0', 0);
            if (str == s)
                {
                    cout << state[str] << endl;
                    return;
                }
            addstate(pos0 / 4 == 0, pos0, pos0 + 4, str);
            addstate(pos0 / 4 == 1, pos0, pos0 - 4, str);
            addstate(pos0 != 3 && pos0 != 7, pos0, pos0 + 1, str);
            addstate(pos0 != 0 && pos0 != 4, pos0, pos0 - 1, str);
            q.pop();
        }
}

int main()
{
    ios::sync_with_stdio(false);
    int i = 0;
    q.push(legal);
    state[legal] = 0;
    while (cin >> s[i])
        {
            i = (i + 1) % 8;
            if (i == 0) solve();
        }
    return 0;
}
