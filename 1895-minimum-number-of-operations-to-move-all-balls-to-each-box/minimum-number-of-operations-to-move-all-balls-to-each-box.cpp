class Solution {
public:
    vector<int> minOperations(string boxes) {
       int n=boxes.size(),sum=0;
       vector<int> sol(n);
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val = boxes[j]=='0'?0:1;
            sol[i]+=(j-i)*(val);
        }
       }
       for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            int val = boxes[j]=='0'?0:1;
            sol[i]+=(i-j)*(val);
        }
       }  
       return sol;
    }
};