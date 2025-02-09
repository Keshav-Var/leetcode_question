class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n = nums.size();
        unordered_map<int, int> ht;
        long long goodPair = 0;
        for(int i = 0; i < n; i++){
            long long temp = nums[i] - i;
            ht[temp]++;
            goodPair += ht[temp] - 1;
        }
        long long int tt = n%2 == 0? (n/2)*(n-1) : n * ((n-1)/2);
        return tt - goodPair;
    }
};