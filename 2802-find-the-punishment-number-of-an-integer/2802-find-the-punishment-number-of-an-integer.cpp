class Solution {
    bool checkNum(string sq, int i, int n, int sum){
        if(sum > n) return false;
        if(i == sq.length() && sum == n) return true;
        if(i == sq.length()) return false;
        for(int j = i+1; j <= sq.length(); j++){
            if(checkNum(sq, j, n, sum + stoi(sq.substr(i, j - i))))
            return true;
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(checkNum(to_string(i*i), 0, i, 0)) ans += i*i;
        }
        return ans;
    }
};