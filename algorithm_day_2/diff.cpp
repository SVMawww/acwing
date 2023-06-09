#include <iostream>
using namespace std;
#define N 100010
int a[N];
int d[N];
int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i-1];
    }
    while(m--) {
        int l,r,c;
        cin >> l >> r >> c;
        d[l] += c;
        d[r+1] -= c;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = a[i-1] + d[i];
        cout << a[i] << " ";
    }
    return 0;
}