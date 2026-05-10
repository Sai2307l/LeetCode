func twoSum(nums []int, target int) []int {
    idx := make(map[int]int)
    for i:=0 ; i<len(nums) ; i++{
        if id,ok:=idx[target-nums[i]];ok{
            return []int{i,id}
        }
        idx[nums[i]] = i
    }
    return []int{}
}