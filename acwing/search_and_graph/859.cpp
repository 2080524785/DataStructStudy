#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
struct E
{
    int x;
    int y;
    int w;
    bool operator<(const E &rhs)
    {
        return this->w < rhs.w;
    }
} e[N * 2];
int n, m, res, cnt;
int g[N];
int find(int i)
{
    if (i != g[i])
        g[i] = find(g[i]);
    return g[i];
}
void klskr()
{
    for (int i = 1; i <= m; i++)
    {
        int a = find(e[i].x);
        int b = find(e[i].y);
        if (a != b)
        {
            res += e[i].w;
            g[a] = b;
            cnt++;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e[i].x = x;
        e[i].y = y;
        e[i].w = w;
    }
    sort(e + 1, e + m + 1);
    klskr();
    if (cnt < n - 1)
    {
        cout << "impossible";
    }
    else
        cout << res;

    return 0;
}
