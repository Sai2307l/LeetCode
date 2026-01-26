class Solution {
public:
    static vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int n=arr.size();
        int minD=1e9+7;
        for(int i=1; i<n; i++){
            minD=min(minD, arr[i]-arr[i-1]);
        }
        vector<vector<int>> ans;
        for(int i=1; i<n; i++){
            if (arr[i]-arr[i-1]==minD)
                ans.push_back({arr[i-1], arr[i]});
        }
        return ans;
    }
};