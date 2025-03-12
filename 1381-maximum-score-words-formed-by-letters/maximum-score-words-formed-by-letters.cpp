class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
       vector<int> freq(26,0),word_score;
       vector<vector<int>> word_freq;
        // frequency of letters
       for(auto i:letters) freq[i-'a']++;

        // frequency of words
       for(auto i:words){
        vector<int> word(26,0);
        for(auto j:i) word[j-'a']++;
        word_freq.push_back(word);
       }

       // score of each word
       for(auto i:word_freq){
        int val=0;
        for(int j=0;j<26;j++){
            val+=i[j]*score[j];
        }
        word_score.push_back(val);
       }

       int answer = take_or_not(word_freq,word_score,freq,0);

        return answer;
    }
private:
    int take_or_not(vector<vector<int>> words,vector<int> scores,vector<int> letters,int index){
        if(index==words.size()) return 0;
        for(int i=0;i<26;i++){
            if(words[index][i]>letters[i]) return take_or_not(words,scores,letters,index+1);
        }
        int not_taken =  take_or_not(words,scores,letters,index+1);
        for(int i=0;i<26;i++){
            letters[i]-=words[index][i];
        }
        int take = scores[index]+take_or_not(words,scores,letters,index+1);
        return max(not_taken,take);
    }
};