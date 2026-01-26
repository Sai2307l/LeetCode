/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if(nums.length===0) return init;
    for(var i=0;i<nums.length;i++){
        var num = fn(init,nums[i]);
        init = num;
    }
    return num;
};