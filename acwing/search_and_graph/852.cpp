#include <iostream>
#include <cstring>
#include<queue>
using namespace std;

const int N = 10010,M=2010;
int n, m;
int h[M], e[N], ne[N], w[N], idx;
int d[M],cnt[M];
bool st[M];
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    
    h[a] = idx++;
}

bool spfa()
{
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
        st[i] = true;
    }
    while(q.size()){
        int a = q.front();q.pop();
        st[a] = false;
        for(int i=h[a];i!=-1;i=ne[i]){
            int b = e[i];
            if(d[b]>d[a]+w[i]){
                d[b] = d[a]+w[i];
                cnt[b] =cnt[a]++;
                if(cnt[b]>=n) return true;
                if(!st[b]){
                    q.push(b);
                    st[b] = true;
                }
            }
        }
    } 
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if(spfa()) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}