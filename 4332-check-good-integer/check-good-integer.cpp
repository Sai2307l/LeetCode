class Solution {
public:
    vector<int> toDigits(int num){
        vector<int> digits;
        while(num>0){
            if(num%10!=0) digits.push_back(num%10);
            num/=10;
        }
        return digits;
    }
    bool checkGoodInteger(int n) {
        vector<int> digits = toDigits(n);
        int squareSum = 0,digitSum = 0;
        for(auto i:digits){
            squareSum+=i*i;
            digitSum+=i;
        }
        return squareSum - digitSum >= 50;
    }
};