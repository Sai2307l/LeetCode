class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> freq;
        for(auto i:dominoes){
            int a=i[0];
            int b=i[1];
            auto ptr1 = freq.find(make_pair(a,b));
            if(ptr1!=freq.end()){
                freq[make_pair(a,b)]++;
                continue;
            }
            auto ptr2 = freq.find(make_pair(b,a));
            if(ptr2!=freq.end()){
                freq[make_pair(b,a)]++;
                continue;
            }
            freq[make_pair(a,b)]++;
        }
        int sum=0;
        for(auto i:freq){
            if(i.second>1) cout<<i.second<<endl;
        }
        for(auto i:freq){
            if(i.second>1) sum+=(i.second*(i.second-1))/2;
        }
        return sum;
    }
};