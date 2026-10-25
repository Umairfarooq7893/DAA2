#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    for (int x : arr) {
        freq[x]++;
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    for (auto p : freq) {
        pq.push({p.second, p.first});

        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;

    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ans = topKFrequent(arr, k);

    cout << "Top K Frequent Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
