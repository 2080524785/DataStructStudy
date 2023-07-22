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
