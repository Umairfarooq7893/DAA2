#include <bits/stdc++.h>
using namespace std;

// Function to find the k most frequent elements
vector<int> topKFrequent(vector<int>& arr, int k) {

    // Store each element and its frequency
    unordered_map<int, int> freq;

    // Count how many times each element appears
    for (int x : arr) {
        freq[x]++;
    }
    // Min-heap storing pairs: {frequency, element}
    // The pair with the smallest frequency stays at the top
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    // Traverse all unique elements and their frequencies
    for (auto p : freq) {

        // Insert {frequency, element} into the min-heap
        pq.push({p.second, p.first});

        // Keep only the k most frequent elements
        if (pq.size() > k) {
            pq.pop();  // Remove the element with the smallest frequency
        }
    }

    // Store the final k elements
    vector<int> ans;

    // Extract elements from the heap
    while (!pq.empty()) {
        ans.push_back(pq.top().second); // Get the element, not its frequency
        pq.pop();
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ans = topKFrequent(arr, k);

    // Print the result
    cout << "Top K Frequent Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

