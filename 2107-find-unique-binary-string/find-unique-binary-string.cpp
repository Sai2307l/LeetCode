class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
     int n = nums.size();
     set<string> set;
     for(auto i:nums) set.insert(i);
     vector<char> ans(n,'0');
     int size=set.size();
     for(int i=0;i<n+1;i++){
        string val(ans.begin(),ans.end());
        set.insert(val);
        if(size!=set.size()) return val;
        else{
            if(i!=n)ans[i]='1';
            else ans[0]='0';
        }
     }
     return "hello";
    }
};