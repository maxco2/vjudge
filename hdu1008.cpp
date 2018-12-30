#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int e[100];
    int f;
    int cur = 0;
    int sum;
    while (cin >> f)
        {
            if (f == 0) return 0;
            sum = 0;
            cur = 0;
            for (int i = 0; i < f; ++i)
                cin >> e[i];
            for (int i = 0; i < f; ++i)
                {
                    if (e[i] - cur > 0)
                        sum += (e[i] - cur) * 6;
                    else
                        sum += (cur - e[i]) * 4;
                    sum += 5;
                    cur = e[i];
                }
            printf("%d\n", sum);
        }
}
