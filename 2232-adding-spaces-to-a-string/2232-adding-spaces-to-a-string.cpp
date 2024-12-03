class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        int i = s.length() - 1;
        s = s + string(n--, ' ');
        int j = s.length() - 1;
        while(i >= 0 && n >= 0){
            while(i >= 0 && i != spaces[n]-1){
                swap(s[i], s[j]);
                i--; j--;
            }
            j--; n--;
        }
        return s;
    }
};