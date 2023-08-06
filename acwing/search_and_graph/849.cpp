#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1e5 + 10;
const int M = 510;
int h[M], e[N], ne[N], idx, w[N];
int n, m, num = 0;
int dist[M], st[M];
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
int q[N], hh = 0, tt = -1;

void Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        st[t] = 1;
        for (int j = h[t]; j != -1; j = ne[j])
        {
            int r = e[j];
            dist[r] = min(dist[r], dist[t] + w[j]);
        }
    }
}

int main()
{

    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    Dijkstra();
    if (dist[n] != 0x3f3f3f3f)
    {
        cout << dist[n];
    }
    else
    {
        cout << -1;
    }

    return 0;
}