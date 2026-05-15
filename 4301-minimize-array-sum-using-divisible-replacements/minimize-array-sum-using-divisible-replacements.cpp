class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(),nums.end());
        vector<int> arr(max_ele+1);
        for(int i=0;i<=max_ele;i++) arr[i] = i;

        set<int> S(nums.begin(), nums.end());
        for (int a : S) {
            if (arr[a] == a) {
                for (int b = a; b <= max_ele; b += a) {
                    if (arr[b] == b) {
                        arr[b] = a;
                    }
                }
            }
        }

        long long res = 0;
        for (int a : nums) {
            res += arr[a];
        }
        return res;
        
    }
};