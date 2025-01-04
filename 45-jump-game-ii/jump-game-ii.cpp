static const int _ =[]{
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}();
class Solution { 
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int farthest = 0;
        int jumps = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                jumps++;
                end = farthest;
                if (farthest >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};