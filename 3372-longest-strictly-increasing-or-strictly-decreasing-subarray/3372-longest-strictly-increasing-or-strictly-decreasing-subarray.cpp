class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l = 1;
        int temp = 1;
        for(int i = 1; i < nums.size();){
            while(i < nums.size() && nums[i] > nums[i - 1]){
                temp++;
                i++;
            }
            l = max(l, temp);
            temp = 1;
            while(i < nums.size() && nums[i] < nums[i - 1]){
                temp++;
                i++;
            }
            l = max(l, temp);
            temp = 1;
            if(i<nums.size() && nums[i] == nums[i-1])
            i++;
        }
        return l;
    }
};