#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 150010;
const int M = 510;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], idx, w[N];
int n, m, num = 0;
int dist[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}


void Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    heap.push({0, 1});
    while (heap.size())
    {
        PII k = heap.top();
        heap.pop();
        int ver = k.second, distance = k.first;
        if(st[ver]) continue;
        st[ver] = 1;
        for (int j = h[ver]; j != -1; j = ne[j])
        {
            int r = e[j];
            if (dist[r] > distance + w[j])
            {
                dist[r] = distance + w[j];
                heap.push({dist[r], r});
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
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