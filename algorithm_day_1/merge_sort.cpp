#include <iostream>
using namespace std;
#define MAX 100005

int a[MAX];
int temp[MAX];

void merge_sort(int arr[], int begin, int end)
{
    if(begin == end) return;
    int mid = begin + end >> 1;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    int ptr_1 = begin;
    int ptr_2 = mid + 1;
    int i = 0;
    while(ptr_1 <= mid && ptr_2 <= end)
    {
        if(arr[ptr_1] <= arr[ptr_2]) {
            temp[i++] = arr[ptr_1++];
        }
        else {
            temp[i++] = arr[ptr_2++];
        }
    }
    while(ptr_1 <= mid) {
        temp[i++] = arr[ptr_1++];
    }
    while(ptr_2 <= end) {
        temp[i++] = arr[ptr_2++];
    }
    for(ptr_1 = begin, ptr_2 = 0; ptr_1 <= end; ptr_1++, ptr_2++) {
        arr[ptr_1] = temp[ptr_2];
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}