#include<iostream>
#include<vector>
#include<queue>

int kthLargest(int arr[], int n, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for(int i=0; i<n; i++)
    {
        if(minHeap.size()<k)
            minHeap.push(arr[i]);
        else if(arr[i]>minHeap.top())
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}

int main()
{
    int arr[]={1,2,4,42,4,35,5,5,7,58,46,5,64,5,6,4,42,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    int ans=kthLargest(arr, n, 2);

    std::cout << ans << '\n';

    return 0;
}