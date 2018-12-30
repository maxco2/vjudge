#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 2000
static char cow[MAXN];
void solve(int head, int end)
{
    int ans = 0;
    while (head <= end)
        {
            if (cow[head] < cow[end])
                putchar(cow[head++]);
            else if (cow[head] > cow[end])
                putchar(cow[end--]);
            else
                {
                    int left = head + 1;
                    int right = end - 1;
                    while (left < right && cow[left] == cow[right])
                        {
                            left++;
                            right--;
                        }
                    if (left >= right)
                        putchar(cow[head++]);
                    else if (cow[left] < cow[right])
                        putchar(cow[head++]);
                    else
                        putchar(cow[end--]);
                }
            ans++;
            if (ans == 80) putchar('\n'), ans = 0;
        }
    putchar('\n');
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        cin >> cow[i];
    solve(0, n - 1);
}

