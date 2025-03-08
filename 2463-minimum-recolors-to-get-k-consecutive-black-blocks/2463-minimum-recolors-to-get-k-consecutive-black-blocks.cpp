class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = k;
        int count = 0;
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'B') count++;
        }
        ans = min(ans, k - count);
        for(int i = k; i < blocks.size(); i++){
            if(blocks[i - k] == 'B') count--;
            if(blocks[i] == 'B') count++;
            ans = min(ans, k - count);
        }
        return ans;
    }
};