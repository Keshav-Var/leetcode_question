class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int small = 0, equal = 0;
        for(auto i:nums){
            if(i < pivot) small++;
            else if(i == pivot) equal++;
        }
        int i = 0, j = small, k = small+equal;
        for(auto it:nums){
            if(it < pivot) ans[i++] = it;
            else if(it == pivot) ans[j++] = it;
            else ans[k++] = it;
        }
        return ans;
    }
};