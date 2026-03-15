class Solution {
public:
    int countCommas(int n) {
        int coms=0;
        for(int i=1000;i<=n;i++){
            int num = i;
            while(num/1000>=1){
                coms++;
                num=num/1000;
            }
        }
        return coms;
    }
};