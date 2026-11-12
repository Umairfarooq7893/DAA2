#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& arr, int k) {

    // Create a min-heap: smallest element stays at the top
    priority_queue<int, vector<int>, greater<int>> pq;

    // Traverse each element in the array
    for (int x : arr) {

        // Insert to min-heap
        pq.push(x);

        // Keep only the k largest elements in the heap
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // The smallest among the k largest elements is the kth largest
    return pq.top();
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Kth Largest Element = "
         << findKthLargest(arr, k);

    return 0;
}

