class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mul;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                mul[nums[i] * nums[j]]++;
            }
        }
        for(auto it:mul){
            count += it.second * (it.second-1) * 4;
        }
        return count;
    }
};