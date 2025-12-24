class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> arr(26,0);
        long long total=0;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a'] += cost[i];
            total+=cost[i];
        }
        long long min_cost = LLONG_MAX;
        for(int i=0;i<26;i++){
            min_cost = min(total-arr[i],min_cost);
        }
        return min_cost;
    }
};