#include<bits/stdc++.h>
using namespace std;

vector<int> tkf(vector<int>& arr,int k){
    unordered_map<int ,int> freq;
    for(int x : arr){
        freq[x]++;
    }
    priority_queue<pair<int, int>,
                    vector<pair<int , int >>,
                    greater<pair<int , int>>> pq;
    for(auto p : freq){
        pq.push({p.second,p.first});
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);

    }



}
