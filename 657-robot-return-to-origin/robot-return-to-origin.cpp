class Solution {
public:
    bool judgeCircle(string moves) {
        int hor=0,ver=0;
        for(auto i:moves){
            if(i=='U'){
                ver++;
            }else if(i=='D'){
ver--;
            }else if(i=='L'){
hor--;
            }else{
hor++;
            }
        }
        return hor==0&&ver==0;
    }
};