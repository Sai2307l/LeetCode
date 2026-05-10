/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const idx = new Map();
    for(let i = 0; i< nums.length;i++){
        if(idx.has(target - nums[i])) return [i,idx.get(target - nums[i])];
        idx.set(nums[i],i)
    }
    return [];
};