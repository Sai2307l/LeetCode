class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> Points;

        for(auto &i:rectangles){
            Points[{i[0],i[1]}]++;
            Points[{i[2],i[3]}]++;
            Points[{i[0],i[3]}]--;
            Points[{i[2],i[1]}]--;
        }

        int numMarks = 0;
        for(auto it:Points){
            if(it.second!=0){
                if(abs(it.second)!=1) return false;
                numMarks++;
            }
        }
        return numMarks == 4;
    }
};