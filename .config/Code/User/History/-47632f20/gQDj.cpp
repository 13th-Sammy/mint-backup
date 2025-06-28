#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

std::vector<int> kFrequent(int arr[], int n, int k)
{
    std::unordered_map<int, int> freq;
    for(int i=0; i<n; i++)
        freq[arr[i]]++;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> minHeap;
    for(auto it=freq.begin(); it!=freq.end(); it++)
    {
        int num=it->first;
        int f=it->second;
        if(minHeap.size()<k)
            minHeap.push({f, num});
        else if(f>minHeap.top().first)
        {
            minHeap.pop();
            minHeap.push({f, num});
        }
    } 
    std::vector<int> res;
    while(!minHeap.empty())
    {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;
}

int main()
{
    int arr[]={1,2,4,42,4,35,5,5,7,58,46,5,64,5,6,4,42,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::vector<int> res=kFrequent(arr, n, 3);

    for(int i=0; i<res.size(); i++)
        std::cout << res[i] << " ";
    std::cout << std::endl;

    return 0;
}