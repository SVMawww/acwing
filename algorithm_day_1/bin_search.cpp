#include <iostream>
using namespace std;
#define MAX 100005
int arr[MAX];

int main()
{
    int n=0,c=0;
    int left = 0, right = n-1;
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x=0;
    for(int i=0;i<c;i++)
    {
        left = 0, right = n-1;
        cin>>x;
        while(left<right){    // binary search
            while(left<right){
                int mid = left+right >> 1; // 注意每次while循环应更新mid，此处不可加一防止死循环
                if(arr[mid] >= x) right = mid;
                else left = mid+1;
            }
            if(arr[left] != x) cout<<"-1 -1"<<endl;
            else {
                cout<<left<<" ";
                left = 0, right = n-1;
                while(left<right){    // binary search  
                    int mid = left+right+1 >> 1; // 注意每次while循环应更新mid，此处必须加一防止死循环
                    if(arr[mid] <= x) left = mid;
                    else right = mid-1;
                }
                cout<<right<<endl;
            }
        }
    }
    return 0;
}
