class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.length();
        int maxCount = 0;
        unordered_set<string> ht;
        backtracking(s, 0, ht, &maxCount);
        return maxCount;
    }
    
    void backtracking(string s, int index, unordered_set<string> ht, int *mC){
        if (ht.size() + (s.size() - index) <= *mC) return;

        if(index == s.length()){
            int n = ht.size();
            *mC = max(*mC, n);
            return;
        }
        string temp = "";
        for(int i = index; i < s.length(); i++){
            temp = temp + s[i];
            if(ht.find(temp) == ht.end()){
                ht.insert(temp);
                backtracking(s, i + 1, ht, mC);
                ht.erase(temp);
            }
        }
        return;
    }

};