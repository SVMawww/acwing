#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int path[10];
int state[10];
int n;

void dfs(int u);

int main()
{
    // int n;
    // cin >> n;
    // vector<int> v;
    // v.resize(n);
    // for(int i=0;i<n;i++) v[i]=i+1;
    // do{
    //     for(int i=0;i<n;i++) cout << v[i] << ' ';
    //     cout << endl;
    // }while(std::next_permutation(v.begin(),v.end()));
    cin >> n;
    dfs(1);
}

void dfs(int u)                                             // u代表树的层数(深度)
{
    if(u > n) {                                             // 输出
        for(int i = 1; i <= n; i++) cout << path[i] << ' ';
        cout << endl;
    }
    else {
        for(int i = 1; i <= n; i++) {                       // 对于n个数
            if(!state[i]) {                                 // 如果该数没有被访问
                path[u] = i;                                // 第u层(即全排列的第u个位置)置为i
                state[i] = 1;                               // 标记i被访问过
                dfs(u+1);                                   // dfs下一层
                state[i] = 0;                               // 此时退出一种排列的递归，回溯
            }
        }
    }
}