class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> arr(size+1,0);
        for(auto i:queries){
            int left = i[0];
            int right = i[1];
            arr[left]++;
            arr[right+1]--;
        }
        int val=0;
        for(int i=0;i<size;i++){
            val+=arr[i];
            if(val<nums[i]){
                return false;
            }
        }
        return true;
    }
};