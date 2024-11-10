class Solution {
public:
    int updateBits(vector<int>& bits, int num, int diff){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(num & (1<<i))
            bits[i] += diff;
            if(bits[i])
            ans = ans | (1<<i);
        }
        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0, ans = INT_MAX;
        int orVal;
        vector<int> bits(32, 0);
        for(int j = 0; j < nums.size(); j++){
            orVal = updateBits(bits, nums[j], 1);
            while(i <= j && orVal >= k){
                ans = min(ans, j - i + 1);
                orVal = updateBits(bits, nums[i], -1);
                i++;
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};