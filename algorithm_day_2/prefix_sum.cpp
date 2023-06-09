#include <cstdio>
#define N 100005

int a[N];
int s[N];
int main()
{
    int n,m,l,r;
    a[0] = 0;
    s[0] = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        s[i] = s[i-1]+a[i];
    while(m--){
        scanf("%d %d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}