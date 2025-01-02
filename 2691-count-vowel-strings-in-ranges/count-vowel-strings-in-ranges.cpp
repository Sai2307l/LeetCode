class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans,sol;
        ans=is_k(words);
        for(auto i:queries){
            int l=i[0]-1;
            int r=i[1];
            sol.push_back(l==-1?ans[r]:ans[r]-ans[l]);
        }
        return sol;
    }

private:
    vector<int> is_k(vector<string>& words){
        vector<int> is_ok;
        int val=0;
        for(auto i:words){
            bool left= i[0]=='a'|| i[0]=='e'|| i[0]=='i'|| i[0]=='o'|| i[0]=='u';
            bool right= i[i.size()-1]=='a' || i[i.size()-1]=='e'|| i[i.size()-1]=='i'|| i[i.size()-1]=='o'|| i[i.size()-1]=='u';
            if(left && right){
                val++;
                is_ok.push_back(val);
            }
            else is_ok.push_back(val);
        }
        for(auto i:is_ok) cout<<i<<" ";
        return is_ok;
    }

};