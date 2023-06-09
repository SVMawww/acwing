/*
https://www.bilibili.com/video/BV1yA4y1Z74t/?spm_id_from=333.337.search-card.all.click&vd_source=1959c23811d1242efdc854fdc81357b8
*/

#include <iostream>
#include <string>
using namespace std;
#define N 100010
int son[N][26], cnt[N], idx;
char s[N];
void insert(const char *s) 
{
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

void query(const char *s) 
{
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if(!son[p][u]) {
            cout << '0' << endl;
            return;
        }
        p = son[p][u];
    }
    cout << cnt[p] << endl;
}

int main()
{
    int n;
    char x;
    cin >> n;
    while(n--) {
        getchar();
        x = getchar();
        getchar();
        scanf("%s", s);
        if(x == 'I') insert(s);
        else query(s);
    }
    return 0;
}