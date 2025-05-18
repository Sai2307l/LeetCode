class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int arr[3]={0,0,0};
        for(auto i:nums) arr[i]++;
        nums.clear();
        while(arr[0]){
            nums.push_back(0);
            arr[0]--;
        }
        while(arr[1]){
            nums.push_back(1);
            arr[1]--;
        }
        while(arr[2]){
            nums.push_back(2);
            arr[2]--;
        }
        return nums;
    }
};