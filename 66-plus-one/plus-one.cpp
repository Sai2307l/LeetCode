class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size()+1);
        ans[0] = 1;
        bool con = true;
        int idx = digits.size()-1;
        while(con && idx>=0){
            if(digits[idx]==9 && con){
                digits[idx] = 0;
            }else if(con){
                digits[idx]++;
                con = false;
            }else{
                break;
            }
            idx--;
        }
        if(con==true){
            for(int i=0;i<digits.size();i++){
                ans[i+1] = digits[i];
            }
            return ans;
        }else{
            return digits;
        }
    }
};