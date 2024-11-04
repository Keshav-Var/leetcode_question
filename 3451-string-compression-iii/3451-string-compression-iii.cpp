class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        for(int i = 0; i < word.length();){
            char ch = word[i];
            int freq = 0;
            while(i < word.length() && word[i] == ch && freq < 9){
                i++;
                freq++;
            }
            comp += to_string(freq) + ch;
        }
        return comp;
    }
};