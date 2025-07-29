class Solution {
public:
    int collectP(int l,int r,string s){
        if(l==r) return 1;
        if(r<l) return 0;
        string left="",right="";
        while(l<r){
            left.push_back(s[l]);
            right.insert(right.begin(),s[r]);
            if(left == right)
            return collectP(l+1,r-1,s)+2;
            l++;
            r--;
        }
        return 1;
    }
    int longestDecomposition(string text) {
        return collectP(0,text.length()-1,text);
    }
};