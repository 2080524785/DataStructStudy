#include <iostream>
#include <cstring>

using namespace std;
int n, m;
const int N = 100010;
int h[N], e[N], ne[N], w[N], idx,d[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    
    h[a] = idx++;
}
int q[N],tt=-1,hh=0;
void spfa()
{
    q[++tt] = 1;
    d[1] = 0;
    st[1] = 1;
    while(tt>=hh){
        int a = q[hh++];
        st[a] = 0;
        for(int i=h[a];i!=-1;i=ne[i]){
            int b = e[i],dis = w[i];
            if(d[b]>d[a]+dis){
                d[b] = d[a]+dis;
                if(!st[b]){
                    q[++tt] = b;
                    st[b] = 1;
                }
            }
        }
    } 
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(d, 0x3f, sizeof(d));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa();
    if(d[n] == 0x3f3f3f3f) cout<<"impossible";
    else cout<<d[n];
    return 0;
}