class Solution {
public:
    long long dp[17][11][2];
    vector<int> pathIdx;

    long long solve(string &s, int pos, int prev, bool tight){
        if(pos == 16) return 1;

        long long &res = dp[pos][prev][tight];
        if(res != -1) return res;

        res = 0;
        int limit = tight ? s[pos] - '0' : 9;

        for(int d = 0; d <= limit; d++){
            bool ntight = tight && (d == limit);

            if(pathIdx[pos]){ //pos is in path so take if current digit >=prev
                if(d >= prev) res += solve(s, pos + 1, d, ntight);
            }else{ //not in path
                res += solve(s, pos + 1, prev, ntight);
            }
        }
        return res;
    }

    long long count(long long x, string &directions){
        string s = to_string(x);
        while(s.size() < 16) s = "0" + s; //convert to 16 digits

        pathIdx.assign(16, 0);

        int r = 0, c = 0;
        pathIdx[0] = 1; //pathIdx[i] = 1, means it is present in the path

        for(char ch : directions){
            if(ch == 'D') r++;
            else c++;
            pathIdx[r * 4 + c] = 1; //index = r*4+c
        }

        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0, true);
    }
    
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        return count(r, directions) - count(l - 1, directions);
    }
};