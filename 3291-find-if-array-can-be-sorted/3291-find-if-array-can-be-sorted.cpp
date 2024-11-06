class Solution {
public:
    int countSetBits(int n){
        int count = 0;
        while(n>0){
            n = n & (n-1);
            count++;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> hm;
        for(auto it:nums){
            hm[it] = countSetBits(it);
        }

        for(int i = 0; i < nums.size()-1; i++){
            for(int j = 1; j < nums.size()-i; j++){
                if(nums[j] >= nums[j-1])
                continue;
                else if(nums[j] < nums[j-1] && hm[nums[j]] == hm[nums[j-1]])
                swap(nums[j], nums[j-1]);
                else
                return false;
            }
        }

        return true;
    }
};