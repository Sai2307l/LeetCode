class Solution {
public:
    void digits(int num,vector<int>& ans){
        stack<int> st;
        while(num>0){
            st.push(num%10);
            num/=10;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums) digits(i,ans);
        return ans;
    }
};