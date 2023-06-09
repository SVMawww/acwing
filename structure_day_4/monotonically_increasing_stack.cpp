
#include <iostream>
#include <stack>
using namespace std;
#define N 100005
int a[N];
stack<int> s;
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(s.empty()) {
            cout << "-1 ";
        }
        else {
            while(!s.empty() && s.top() >= a[i]) s.pop(); // 当栈顶的元素大于当前元素，栈顶元素就出栈
        if(!s.empty()) cout << s.top() << " ";  // 此时已经确保题目条件
        else cout << "-1 ";
        }
        s.push(a[i]);
    }
    return 0;
}