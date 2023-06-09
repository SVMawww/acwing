#include <iostream>
using namespace std;
const int N = 12;
int sovle[N];
int state[N];
int n;

int safe(int i, int j)
{
    int res = 1;
    for(int iter = 1; iter < i; iter++) {
        if((i + j) == (iter + sovle[iter])) res = 0;
        if((i - j) == (iter - sovle[iter])) res = 0;
    }
    return res;
}

void dfs(int u)
{
    if(u > n) {
        for(int it = 1; it <= n; it++) {
            for(int jt = 1; jt <= n; jt++) {
                if(sovle[it] != jt) putchar('.');
                else putchar('Q');
            }
            putchar('\n');
        }
        putchar('\n');
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(!state[i] && safe(u, i)) {
                sovle[u] = i;
                state[i] = 1;
                dfs(u+1);
                state[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
}