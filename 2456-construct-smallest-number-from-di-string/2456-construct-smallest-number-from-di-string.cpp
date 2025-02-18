class Solution {
    string solve(string &pat, string ans, int prev, vector<bool> &used, int index){
        if(ans.length() == pat.length() + 1) return ans;
        for(int i = 1; i <= 9; i++){
            if(used[i]) continue;
            if(index != 0 && pat[index-1] == 'I' && i <= prev) continue;
            if(index != 0 && pat[index-1] == 'D' && i >= prev) continue;
            used[i] = true;
            string temp = solve(pat, ans+to_string(i), i, used, index+1);
            if(temp != "-1")return temp;
            used[i] = false;
        }
        return "-1";
    }

public:
    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        return solve(pattern, "", -1, used, 0);
    }
};