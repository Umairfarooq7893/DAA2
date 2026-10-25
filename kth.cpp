
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr) {
        pq.push(x);

        if (pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Kth Largest Element = "
         << findKthLargest(arr, k);

    return 0;
}
