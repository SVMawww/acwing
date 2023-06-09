#include <iostream>
using namespace std;
#define MAX 1000005
int q[MAX];
void quick_sort(int arr[], int begin, int end)
{
    if(begin == end) return;
    int left = begin-1;
    int right = end+1;
    int mid = arr[(begin + end)/2];
    while (left < right)
    {
        do left++ ;  while (arr[left] < mid);
        do right--; while (arr[right] > mid);
        if (left < right){
            std::swap(arr[left], arr[right]);
        }
    }
    quick_sort(arr, begin, right);
    quick_sort(arr, right+1, end);
}

int main()
{
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf((i==n-1)?"%d\n":"%d ",q[i]);
    }
    return 0;
}