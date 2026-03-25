class Solution {
public:
    bool check(vector<long long>& arr,long long sum){
        long long half = 0,n = arr.size();
        for(int i=0;i<n-1;i++){
            half+=arr[i];
            if(half*2 == sum)return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> n_sums(n,0),m_sums(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                n_sums[i]+=grid[i][j];
                m_sums[j]+=grid[i][j];
            }
        }
        long long tot_n = accumulate(n_sums.begin(),n_sums.end(),(long long)0);
        long long tot_m = accumulate(m_sums.begin(),m_sums.end(),(long long)0);
        if(tot_n%2==1 && tot_m%2==1) return false;
        if(tot_n%2==1 && tot_m%2==0) return check(m_sums,tot_m);
        if(tot_n%2==0 && tot_m%2==1) return check(n_sums,tot_n);
        return check(m_sums,tot_m)||check(n_sums,tot_n);
    }
};