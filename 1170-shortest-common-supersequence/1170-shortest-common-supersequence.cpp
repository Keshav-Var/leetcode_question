class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = (str1[i-1] == str2[j-1])? dp[i-1][j-1] + 1: max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--; j--;
            }
            else if(dp[i][j-1] > dp[i-1][j]){
                ans += str2[j-1]; j--;
            }
            else{
                ans += str1[i-1]; i--;
            }
        }

        while(i > 0){
            ans += str1[i-1];
            i--;
        }   

        while(j > 0){
            ans += str2[j-1];
            j--; 
        }    
        reverse(ans.begin(), ans.end());
        return ans;
    }
};