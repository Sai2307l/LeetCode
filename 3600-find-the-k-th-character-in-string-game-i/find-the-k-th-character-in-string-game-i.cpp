class Solution {
public:
    char transform_string(string word,int limit){
        if(word.size()>=limit) return word[limit-1];
        string newword=word;
        for(auto i:word)newword+=i=='z'?'a':i+1;
        return transform_string(newword,limit);
    }
    char kthCharacter(int k) {
        string sol="a";
        return transform_string(sol,k);
    }
};