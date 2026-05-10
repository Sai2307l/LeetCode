function twoSum(nums: number[], target: number): number[] {
    const idx: Map<number,number> = new Map();
    for(let i:number = 0;i<nums.length;i++){
        if(idx.has(target-nums[i])){
            return [i,idx.get(target-nums[i])];
        }
        idx.set(nums[i],i);
    }
    return [];
};