class Solution {
    bool solve(vector<int>& powers, vector<bool>& isTaken, int n, int idx){
        if(n == 0) return true;
        if(n < 0) return false;
        for(int i = idx; i < 16; i++){
            isTaken[i] = true;
            if(solve(powers, isTaken, n-powers[i], i+1)) return true;
            isTaken[i] = false;
        }
        return false;
    }

public:
    bool checkPowersOfThree(int n) {
        vector<int> powers(16, 1);
        vector<bool> isTaken(16, false);
        for(int i = 1; i < 16; i++)
        powers[i] = powers[i-1]*3;
        return solve(powers, isTaken, n, 0);
    }
};