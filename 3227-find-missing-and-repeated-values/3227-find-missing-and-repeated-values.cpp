class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xorValue = 0;
        int temp = 1;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                xorValue ^= grid[i][j];
                xorValue ^= temp;
                temp++;
            }
        }
        int lastSetBit = xorValue & (~(xorValue-1));
        int x = 0;
        int y = 0;
        temp = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] & lastSetBit)
                x ^= grid[i][j];
                else
                y ^= grid[i][j];

                if(temp & lastSetBit)
                x ^= temp;
                else 
                y ^= temp;
                temp++;
            }
        }
        int freqx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == x) freqx++;
            }
        }

        if(freqx == 2) return {x, y};
        else return {y, x};
    }
};