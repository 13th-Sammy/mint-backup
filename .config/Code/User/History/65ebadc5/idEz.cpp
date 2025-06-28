#include<iostream>
#include<vector>

class MinHeap {
    std::vector<int> heap;

    void heapifyUp(int i) {
        if(i==0) return;
        int parent=(i-1)/2;
        if(heap[parent]>heap[i]) {
            std::swap(heap[parent],heap[i]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int i) {
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<heap.size() && heap[left]<heap[smallest])
            smallest=left;
        if(right<heap.size() && heap[right]<heap[smallest])
            smallest=right;
        if(smallest!=i) {
            std::swap(heap[i],heap[smallest]);
            heapifyDown(smallest);
        }
    }

    public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }

    int getMin() {
        if(heap.empty()) return -1;
        return heap[0];
    }

    void popMin() {
        if(heap.empty()) return;
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap() {
        for(int i=0; i<heap.size(); i++)
            std::cout << heap[i] << ' ';
        std::cout << '\n';
    }
};

int main() {
    MinHeap mheap;
    mheap.insert(6);
    mheap.insert(2);
    mheap.insert(8);
    mheap.insert(1);
    mheap.insert(3);
    std::cout << mheap.getMin() << '\n';
    mheap.popMin();
    std::cout << mheap.getMin() << '\n';
    mheap.printHeap();
    
    return 0;
}