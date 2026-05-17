class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        queue<int> bfs;
        bfs.push(start);
        while(!bfs.empty()){
            int idx = bfs.front();
            bfs.pop();
            if(arr[idx]==0) return true;
            vis[idx] = true;
            int l = idx - arr[idx];
            int r = idx + arr[idx];
            if(l<n && l>=0 && !vis[l]) bfs.push(l);
            if(r<n && r>=0 && !vis[r]) bfs.push(r);
        }
        return false;

    }
};