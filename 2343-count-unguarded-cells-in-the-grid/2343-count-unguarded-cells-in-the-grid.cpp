class Solution {
public:
    void mark(vector<vector<int>>& grid, pair<int, int> cordinates){
        int x = cordinates.first;
        int y = cordinates.second;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = y-1; i >= 0 && grid[x][i] != 2 && grid[x][i] != 3; i--){
            grid[x][i] = 1;
        }
        for(int i = y+1; i < n && grid[x][i] != 2 && grid[x][i] != 3; i++){
            grid[x][i] = 1;
        }
        for(int i = x+1; i < m && grid[i][y] != 2 && grid[i][y] != 3; i++){
            grid[i][y] = 1;
        }
        for(int i = x-1; i >= 0 && grid[i][y] != 2 && grid[i][y] != 3; i--){
            grid[i][y] = 1;
        }
        return;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(auto it:guards){
            v[it[0]][it[1]] = 2;
        }
        for(auto it:walls){
            v[it[0]][it[1]] = 3;
        }
        for(auto it:guards){
            mark(v, {it[0], it[1]});
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == 0)
                ans++;
            }
        }
        return ans;
    }
};