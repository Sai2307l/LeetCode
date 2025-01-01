class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int rz=0, ro=0, lz=0, lo=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                rz++;
            }else{
                ro++;
            }

        }
        int mx=INT_MIN;

        for(int i=0; i<n-1; i++){
            if(s[i]=='0'){
                lz++;
                rz--;
            }else{
                ro--;
                lo++;
            }
            mx=max(mx, lz+ro);

        }

        return mx;
        
    }
};