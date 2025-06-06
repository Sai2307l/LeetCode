class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> freq(100,0);
        int sum=0;
        for(auto i:dominoes){
            int a = i[0];
            int b = i[1];
            a>b?freq[b*10+a]++:freq[a*10+b]++; 
        }
        for(auto i:freq) sum+=(i*(i-1))/2;
        return sum;
    }
};