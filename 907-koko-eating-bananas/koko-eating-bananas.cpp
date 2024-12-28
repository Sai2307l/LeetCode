class Solution {
public:
    bool can_eat(vector<int> piles,int h,int x){
        long long time=0;
        for(auto i:piles) time+=i%x==0?i/x:(i/x)+1;
        if(time<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j= *max_element(piles.begin(), piles.end());
        int res=j;
        while (i<=j){
            int mid=(i+j)/2;
            if(can_eat(piles,h,mid)){
                res=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return res;
    }
};