class Solution {
public:
    string toHex(int num) {
        unsigned int ourNum = num;
        string str;
        char letter[17] = "0123456789abcdef";

        do{
            str += letter[ourNum %16];
            ourNum /= 16;
        }while(ourNum);

        return {str.rbegin(),str.rend()};
    }
};