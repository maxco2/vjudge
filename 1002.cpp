#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#define REV(a) reverse(a.begin(), a.end())
#define LEN 1000
#define M(a, l)                                                                \
    do                                                                         \
        {                                                                      \
            memset(a, '\0', l);                                                \
        }                                                                      \
    while (0)
using namespace std;

int main()
{
    char c[LEN];
    int n;
    cin >> n;
    for (int x = 1; x <= n; ++x)
        {
            string a;
            string b;
            cin >> a >> b;
            M(c, LEN);
            printf("Case %d:\n%s + %s = ", x, a.data(), b.data());
            REV(a);
            REV(b);
            int in = 0;
            int i = 0;
            for (i = 0; i < a.size() && i < b.size(); ++i)
                {
                    int an = a[i] - '0';
                    int bn = b[i] - '0';
                    int cn = an + bn + in;
                    c[i] = (cn % 10) + '0';
                    in = cn / 10;
                }
            while (i < a.size())
                {
                    int an = a[i] - '0';
                    int cn = an + in;
                    c[i] = (cn % 10) + '0';
                    in = cn / 10;
                    ++i;
                }
            while (i < b.size())
                {
                    int bn = b[i] - '0';
                    int cn = bn + in;
                    c[i] = (cn % 10) + '0';
                    in = cn / 10;
                    ++i;
                }
            if (in != 0) c[i] = in + '0';
            for (i = LEN - 1; i >= 1; --i)
                if (c[i] != '\0' && c[i] != '0') break;
            for (; i >= 0; --i)
                printf("%c", c[i]);
            if (n != x)
                printf("\n\n");
            else
                printf("\n");
        }
}

