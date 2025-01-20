class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        int rem_block_sz = 1;

        for(int i=1; i<n; i++){
            rem_block_sz *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        --k;

        while(true){
            ans = ans + to_string(nums[k/rem_block_sz]);
            nums.erase(nums.begin() + k/rem_block_sz);

            if(nums.size() == 0){
                break;
            }

            k = k % rem_block_sz;
            rem_block_sz = rem_block_sz / nums.size();
        }

        return ans;
    }
};