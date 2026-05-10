class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> idx = new HashMap<>();
        int n = nums.length;

        for(int i= 0; i<n ;i++){
            if(idx.containsKey(target - nums[i])){
                return new int[] {i, idx.get(target-nums[i])};
            }
            idx.put(nums[i],i);
        }
        return new int[]{};
    }
}