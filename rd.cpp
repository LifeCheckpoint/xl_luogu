#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int N, k, T;
const int NMAX=1005,KMAX=300,TMAX=2005;

inline int dis(int* v1, int* v2){
    int d=0.0;
    for(int i=0;i<k;i++) d += (v1[i]-v2[i])*(v1[i]-v2[i]);
    return d;
}

int main()
{
    int data[NMAX][KMAX];
    int fi[TMAX][KMAX];
    scanf("%d %d %d",&N,&k,&T);
    for(int i=0;i<N;i++){
        for(int j=0;j<k;j++){
            data[i][j]=read();
        }
    }
    for(int i=0;i<T;i++){
        for(int j=0;j<k;j++){
            fi[i][j]=read();
        }
    }
    
    int d[NMAX],bis[TMAX];
    for(int i=0;i<T;i++){
        memset(d, 0x3f, sizeof(d));
        for(int j=0;j<N;j++){
            d[j]=dis(fi[i], data[j]);
        }
        int mind=40000*k+1;
        int bi=0;
        for(int p=0;p<k;p++){
            if(mind>d[p]){
                mind=d[p];
                bi=p;
            }
        }
        bis[i]=bi;
    }
    for(int i=0;i<T;i++){
        for(int j=0;j<k;j++){
            printf("%d ",data[bis[i]][j]);
        }
        printf("\n");
    }
    return 0;
}