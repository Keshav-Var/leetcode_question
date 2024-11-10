class Solution {
public:
    void updateBits(vector<int>& bits, int num, int diff){
        for(int i = 0; i < 32; i++){
            if(num & (1<<i))
            bits[i] += diff;
        }
        cout<<endl;
    }

    int findOr(vector<int>& bits){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i])
            ans = ans | (1<<i);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0, ans = INT_MAX;
        vector<int> bits(32, 0);
        for(int j = 0; j < nums.size(); j++){
            updateBits(bits, nums[j], 1);
            while(i <= j && findOr(bits) >= k){
                ans = min(ans, j - i + 1);
                updateBits(bits, nums[i], -1);
                i++;
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};