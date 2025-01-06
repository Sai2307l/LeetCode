class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size(),sum=0;
        vector<int> sol(n),left(n,0),right(n,0);
        if(n==1) return {0};
        for(int i=1;i<n;i++)left[i]=left[i]+boxes[i-1]=='1'?1+left[i-1]:left[i-1];
        for(int i=n-2;i>=0;i--)right[i]=right[i]+boxes[i+1]=='1'?1+right[i+1]:right[i+1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+left[i];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i]+right[i+1];
        }
        for(int i=0;i<n;i++)sol[i]=left[i]+right[i];
        return sol;
    }
};