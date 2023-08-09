#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 510, M = 1e5 + 10;
int n1, n2, m;
int h[M], e[N], ne[N], idx;
int match[M];
bool st[M];
int res = 0;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int k = e[i];
        if (!st[k])
        {
            st[k] = 1;
            if (match[k] == 0 || find(match[k]))
            {
                match[k] = x;
                return true;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n1; i++)
    {
        memset(st, 0, sizeof(st));
        if (find(i))
            res++;
    }
    cout << res++;
    return 0;
}