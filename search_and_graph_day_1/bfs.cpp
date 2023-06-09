#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using PII = std::pair<int, int>;
int mp[110][110];
int dis[110][110];
int n,m;
queue<PII> que;
int bfs();

int main()
{
    memset(dis, -1, sizeof(dis));
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= m; j++)
            cin >> mp[i][j];
    que.push({1,1});
    dis[1][1] = 0;
    cout << bfs() << endl;
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j++){
    //         cout <<  dis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

int bfs(){
    // 0,1  0,-1  1,0  -1,0
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while(!que.empty()){
        auto [a,b] = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            auto x = a + dx[i];
            auto y = b + dy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && dis[x][y] == -1 && mp[x][y] == 0) {
                dis[x][y] = dis[a][b] + 1;
                que.push({x,y});
            }
        }
    }
    return dis[n][m];
}