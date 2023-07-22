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
