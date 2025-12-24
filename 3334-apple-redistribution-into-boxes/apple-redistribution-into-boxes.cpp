class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum = 0;
        for(int i=0;i<apple.size();i++){
            sum += apple[i];
        }
        int j = 0,count=0;
        while(sum>0){
            sum-=capacity[j];
            count++;
            j++;
        }
        return count;
    }
};