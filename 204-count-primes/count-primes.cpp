class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        int count=0;
        for(int i=2;i<n;i++){
            if(prime[i]) count++;
            if(prime[i] && (long long)i*i<=n){
                for(int j=i*i;j<=n;j+=i) prime[j]=false;
            }
        }
        return count;
    }
};