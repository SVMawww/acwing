#include <iostream>
// #include <string>
using namespace std;
const int N = 1e5+10;
unsigned long long h[N], p[N];
const int P = 131;
char str[N];

bool get(int l1,int r1,int l2,int r2)
{
    return ((h[r1] - h[l1 - 1] * p[r1 - l1 + 1]) == (h[r2] - h[l2 - 1] * p[r2 - l2 + 1]));
}

int main()
{
    int n, m;
    cin >> n >> m;
    scanf("%s",str+1);
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    while(m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(get(l1, r1, l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}