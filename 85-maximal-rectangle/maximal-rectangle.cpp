class Solution {
public:
    int histo(int n, vector<int>&arr){
        stack<int>st;
        int maxArea = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int ind = st.top();
                st.pop();

                int height = arr[ind];
                int width = 1;
                if(i==n) width = n;
                if(st.empty()) width = i;
                else width = i-st.top()-1;

                maxArea = max(maxArea, height*width);
                cout<<height*width<<" ";
            }
            st.push(i);
        }
        cout<<endl;
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix[0].size();
        int m = matrix.size();
        vector<int>area(n, 0);

        int maxArea = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') area[j]++;
                else area[j] = 0;
            }
            maxArea = max(maxArea, histo(n, area));
        }

        return maxArea;
    }
};