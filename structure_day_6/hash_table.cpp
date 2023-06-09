#include <iostream>
#include <set>
using namespace std;
const int N = 1e5+10;
int main()
{
    multiset<int> s;
    int n;
    cin >> n;
    while(n--) {
        char c;
        getchar();
        c = getchar();
        if(c == 'I') {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if(c == 'Q') {
            int x;
            cin >> x;
            auto it = s.find(x);
            cout << (it == s.end() ? "No\n" : "Yes\n");
        }
    }
    return 0;
}