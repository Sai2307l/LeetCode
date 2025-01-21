class Solution {
public:

    bool checkWin(int val,int tot){
        return val>=tot-val;
    }
    int maxScore(vector<int>& nums,int total,int i,int j){
        if(i>j) return 0;
        return total-min(maxScore(nums,total-nums[i],i+1,j),maxScore(nums,total-nums[j],i,j-1));
    }
    bool predictTheWinner(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0); 
        return checkWin(maxScore(nums,total,0,nums.size()-1),total);
    }
};