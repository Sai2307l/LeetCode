class Solution {
public:

    bool isLetter(char ch) {
        return 'a' <= ch && ch <= 'z';
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";

        for(string &part : chunks) {
            s += part;
        }

        unordered_map<string, int> freq;

        int n = s.size();

        int i = 0;

        while(i < n) {

            // separator
            if(!isLetter(s[i])) {
                i++;
                continue;
            }

            string word = "";

            while(i < n) {

                // normal letter
                if(isLetter(s[i])) {
                    word += s[i];
                    i++;
                }

                // valid hyphen
                else if(s[i] == '-') {

                    bool left =
                        !word.empty();

                    bool right =
                        (i + 1 < n &&
                         isLetter(s[i + 1]));

                    if(left && right) {
                        word += '-';
                        i++;
                    }
                    else {
                        break;
                    }
                }

                // separator
                else {
                    break;
                }
            }

            freq[word]++;
        }

        vector<int> ans;

        for(string &q : queries) {
            ans.push_back(freq[q]);
        }

        return ans;
    }
};