class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int> freq;
        for(auto i:grid){
            for(auto j:i){
                freq[j]++;
            }
        }
        int a=0,b=0,n=grid.size();
        for(int i=1;i<=n*n;i++){
            if(freq[i]==0) b=i;
            if(freq[i]==2) a=i;
            if(a!=0 && b!=0) break;
        }
        return {a,b};
    }
};