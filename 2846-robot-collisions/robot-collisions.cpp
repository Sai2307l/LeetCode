class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        // sort by position
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;

        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push(id);
            } 
            else {
                // L robot
                while (!st.empty() && directions[st.top()] == 'R' && healths[id] > 0) {
                    int top = st.top();

                    if (healths[top] < healths[id]) {
                        st.pop();
                        healths[id]--;
                    } 
                    else if (healths[top] > healths[id]) {
                        healths[top]--;
                        healths[id] = 0;
                    } 
                    else {
                        st.pop();
                        healths[id] = 0;
                    }
                }

                if (healths[id] > 0) {
                    st.push(id);
                }
            }
        }

        // collect survivors
        vector<pair<int,int>> survivors;
        while (!st.empty()) {
            int id = st.top();
            st.pop();
            survivors.push_back({id, healths[id]});
        }

        // sort by original index
        sort(survivors.begin(), survivors.end());

        vector<int> ans;
        for (auto &p : survivors) {
            ans.push_back(p.second);
        }

        return ans;
    }
};