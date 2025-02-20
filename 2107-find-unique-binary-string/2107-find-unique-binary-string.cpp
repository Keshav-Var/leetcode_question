class Solution {
    string solve(vector<string>& nums, unordered_set<string>& ht, int n, string s){
        if(s.length() == n) {
            if(ht.find(s) == ht.end()) return s;
            return "";
        }
        string temp = solve(nums, ht, n, s+'0');
        if(temp != "") return temp;
        return solve(nums, ht, n, s+'1');
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> ht(nums.begin(), nums.end());
        return solve(nums, ht, nums.size(), "");
    }
};