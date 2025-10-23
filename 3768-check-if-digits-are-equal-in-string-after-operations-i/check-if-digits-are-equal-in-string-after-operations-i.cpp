class Solution {
public:
    bool hasSameDigits(std::string s) {
        int len = s.size();
        while (len > 2) {
            for (int i = 0; i < len - 1; ++i) {
                s[i] = ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            }
            --len;
        }
        return s[0] == s[1];
    }
};