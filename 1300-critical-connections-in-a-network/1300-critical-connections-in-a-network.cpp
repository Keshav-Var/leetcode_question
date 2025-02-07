class Solution {
    private: 
    int time = 0;
    void solve(vector<vector<int>> &gp, vector<vector<int>> &ans, vector<int> &parent, vector<bool> &visited, vector<int> &low, vector<int> &dtime, int src){
        visited[src] = true;
        dtime[src] = time;
        low[src] = time;
        time++;
        for(auto it:gp[src]){
            if(!visited[it]){
                parent[it] = src;
                solve(gp, ans, parent, visited, low, dtime, it);
                low[src] = min(low[src], low[it]);
                if(low[it] > dtime[src]){
                    ans.push_back({src, it});
                }
            }
            else if(it != parent[src]){
                low[src] = min(low[src], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        vector<int> low(n, -1);
        vector<int> dtime(n, -1);
        vector<vector<int>> ans;
        vector<vector<int>> gp(n);

        for(auto connection:connections){
            gp[connection[0]].push_back(connection[1]);
            gp[connection[1]].push_back(connection[0]);
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == false)
            solve(gp, ans, parent, visited, low, dtime, i);
        }
        return ans;
    }
};