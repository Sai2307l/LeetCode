class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        map<char,int> freq;
        for(auto i:text) freq[i]++;
        vector<char> letter = {'a','b','l','n','o'};
        int ans = INT_MAX;
        for(auto i:letter){
            if(i=='l' || i=='o')ans = min(freq[i]/2,ans);
            else ans = min(freq[i],ans);
            cout<<ans<<endl;
        }
        return ans;
    }
};