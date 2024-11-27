class Solution {
public:
    int findSortest(vector<vector<int>>& v, vector<int>& dp, int source){
        if(dp[source] == -1){
            if(v[source].size() == 0)
            dp[source] = 0;
            else{
                int minimum = INT_MAX;
                for(int i = 0; i < v[source].size(); i++){
                    minimum = min(minimum, findSortest(v, dp, v[source][i]));
                }
                dp[source] = minimum + 1;
            }
        }
        return dp[source];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        vector<vector<int>> gp(n);
        for(int i = 0; i < n-1; i++){
            gp[i].push_back(i+1);
        }
        for(int i = 0; i < m; i++){
            gp[queries[i][0]].push_back(queries[i][1]);
            vector<int> dp(n, -1);
            ans[i] = findSortest(gp, dp, 0);
        }
        return ans;
    }
};