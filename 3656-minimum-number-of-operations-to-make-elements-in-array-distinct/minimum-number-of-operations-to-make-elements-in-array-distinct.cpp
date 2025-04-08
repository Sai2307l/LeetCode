class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int> freq;
        int i;
        for(i=nums.size()-1;i>=0;i--){
            if(freq[nums[i]]==1) break;
            freq[nums[i]]++;
        }
        int size=(i+1)/3;
        if((i+1)%3!=0) size+=1;
        return size;
    }
};