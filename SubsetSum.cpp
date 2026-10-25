
#include <bits/stdc++.h>
using namespace std;
 
bool subsetSum(vector<int> &arr, int index, int remaining) {
    if (remaining == 0) return true;                       // found a valid subset
    if (index == arr.size() || remaining < 0) return false; // prune
 
    // choice 1: include arr[index]
    if (subsetSum(arr, index + 1, remaining - arr[index])) return true;
 
    // choice 2: exclude arr[index]
    return subsetSum(arr, index + 1, remaining);
}
 
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
 
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    int target;
    cout << "Enter target sum: ";
    cin >> target;
 
    bool result = subsetSum(arr, 0, target);
 
    cout << (result ? "A subset with the given sum exists." : "No such subset exists.") << endl;
 
    return 0;
}
