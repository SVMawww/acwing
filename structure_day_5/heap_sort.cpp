#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, std::greater<int>> hp;
    int i;
    while(n--) {
        cin >> i;
        hp.push(i);
    }
    while(m--) {
        cout << hp.top() << " ";
        hp.pop();
    }
    return 0;
}