@2080524785

# ```Introduction```

> ## This project just contains the course of my studyings of ***datastruct***

# ```Algorithm Template```

> ## ***String***
>
* ### **KMP**

```C++
#include<iostream>
using namespace std;

const int N = 1e6+10;
const int M = 1e5+10;
int n,m,ne[M];
char s[N],p[M];

int main(){
    cin>>n>>s+1>>m>>p+1;
    for(int i=2,j=0;i<=m;i++){
        while(j&&p[i]!=p[j+1]) j = ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
    for(int i=1,j=0;i<=n;i++){
        while(j&&s[i]!=p[j+1]) j = ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==m){
            // TODO:
            j = ne[j];
        }
    }

}
```

> ## ***Tree***
>
* ### Trie

```C++
// Trie 树
#include<iostream>
using namespace std;
const int N = 1e5+10;

int q[N][M],idx;
void fun_I(param c){
    int h=0;
    for(int i=0;i<c.size();i++){
        // TODO: x=? , the second index in array
        if(!q[h][x]) q[h][x] = ++idx;
        h = q[h][x];
    }
}
int fun_Q(param c){
    int h=0;
    for(int i=0;i<c.size();i++){
        // TODO: x=? , the second index in array, usually it is same with the previous TODO;
        if(!q[h][x]) return 0;
        h = q[h][x];
    }
    //TODO: return result
}
int main(){
    int n;
    cin>>n;
    while(n--){
        //TODO: input params,and carry out the previous function
    }
    return 0;
}
```

> ## ***Disjoint Set Union***
>
* ### Connected Set

```cpp
// 2023年7月23日 18点18分
// 连通块中点的数量
#include<iostream>
using namespace std;
const int N = 1e5+10;
int p[N],size[N];
int n,m;
int find(int x){
    if(x!=p[x]) p[x] = find(p[x]); // for path compression
    return p[x];
}
void merge(int a,int b){
    int pa = find(a),pb = find(b);
    if(pa!=pb){
        p[pa] = pb;
        size[pb]+=size[pa];
    }
}
void query(int a,int b){
    cout<<(find(a)==find(b)?"Yes":"No")<<endl;
}
void init(){
    for(int i=1;i<=n;i++) p[i]=i,size[i]=1;
}
int main(){
    cin>>n>>m;
    init();
    while(m--){
        // TODO: implement
    }
    return 0;
}
```

* ### Zjnu Stadium

作者：YY_ocean

链接：https://juejin.cn/post/7181755545844449317
```cpp
//三合一的并查集模板：
//1、朴素版的并查集
//2、维护size【即维护集合中点的数量】
//3、维护集合内的节点到根节点的距离
struct UF {

    std::vector<int> p, _dist, _size;

    UF(int n) 
    : p(n)        //存储每个点的祖宗节点
    , _dist(n, 0) //维护当前到祖宗节点距离的数组
    , _size(n, 1) //维护当前的集合中的点的个数的数组（1是因为已经有自己了）
    { 
        //初始化并查集
        //假定节点编号为：1~n
        for(int i = 1; i <= n; i++) p[i] = i;
    }
    
    //路径压缩优化
    //顺带维护距离
    int find(int x) 
    {
        if (x == p[x]) return p[x];

        //先记录祖宗
        int root = find(p[x]);

        //加上父亲的距离
        _dist[x] += _dist[p[x]];

        //指向祖宗
        return p[x] = root;
    }

    //判断祖宗节点是否为同一个
    //即 判断是否为同一个祖宗
    bool same(int x, int y) 
    { 
        return find(x) == find(y); 
    }

    //合并并查集
    bool merge(int x, int y) 
    {
        x = find(x);
        y = find(y);

        if (x == y) return false;

        //本来d[y]（即 祖宗节点 到 祖宗节点的距离）等于0
        //现在它指向新祖宗的距离 就是 合并到新集合中 的 新集合中的元素个数
        _dist[y] += _size[x];

        _size[x] += _size[y];

        //将 y节点所在的集合 合并到 x节点的集合上
        //【即 将y节点的祖宗 变为 x节点的祖宗】
        p[y] = x;

        return true;
    }

    //表示祖宗节点所在集合中的点的数量
    int size(int x) 
    { 
        return _size[find(x)]; 
    }

    //查询两点之间相差几个人，不在一列返回-1
    int dist(int x, int y) 
    {
        if (!same(x, y)) return -1;

        return abs(p[x] - p[y]) - 1;
    }
};
```

