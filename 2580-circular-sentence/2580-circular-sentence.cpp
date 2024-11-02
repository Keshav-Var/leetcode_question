class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[(i+1)%sentence.size()])
                return false;
            }
        }
        if(sentence[sentence.length() - 1] != sentence[0])
        return false;
        return true;
    }
};