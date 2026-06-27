class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;
        for(auto i:nums) freq[i]++;
        int ans = 1;
        if(freq.count(1)){
            int cnt = freq[1];
            ans = max(ans,cnt % 2?cnt:cnt-1);
        }

        for(auto &[num,f]:freq){
            if(num == 1) continue;

            long long x = num;
            int len = 0;

            while(freq.count(x) && freq[x] >= 2){
                len += 2;
                if(x>1e9) break;
                x = x*x;
            }
            if(freq.count(x)) len++;
            else len--;
            ans = max(ans,len);
        }
        return ans;
    }
};