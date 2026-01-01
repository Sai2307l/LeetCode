class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() , idx = n - 1;
        bool con = true;
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
            digits.resize(n+1);
            rotate(digits.begin(),digits.end()-1,digits.end());
            digits[0] = 1;
            return digits;
        }else{
            return digits;
        }
    }
};