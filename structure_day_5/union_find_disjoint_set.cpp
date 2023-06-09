#include <iostream>
using namespace std;
#define N 100010
int p[N];
int find(int x) // 返回x的祖宗节点，即x属于的集合
{
    if(p[x] != x) p[x] = find(p[x]); // 如果p[x]不等于x，那么就让p[x]为x的祖宗节点
    return p[x];
}

int main()
{
    int n,m;
    cin >> n >> m;
    char c;
    int a,b;
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--) {
        cin >> c >> a >> b;
        if(c == 'M') p[find(a)] = find(b);
        else if(c == 'Q') {
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } 
    }
    return 0;
}