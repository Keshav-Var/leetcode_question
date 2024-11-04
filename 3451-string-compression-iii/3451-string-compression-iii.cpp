class Solution {
public:
    string compressedString(string word) {
        for(int i = word.length()-1; i >= 0;){
            char ch = word[i];
            int freq = 0;
            int si = i;
            while(i >= 0 && word[i] == ch){
                i--;
                freq++;
            }
            string temp = "";
            while(freq > 0){
                if(freq > 9){
                    temp = temp + "9" + ch;
                    freq -= 9;
                }else{
                    temp = temp + to_string(freq) + ch;
                    freq = 0;
                }
            }
            word.replace(i+1, si-i, temp);
        }
        return word;
    }
};