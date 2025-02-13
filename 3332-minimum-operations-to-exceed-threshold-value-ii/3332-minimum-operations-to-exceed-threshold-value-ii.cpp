class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long>> heap;
        for(auto it:nums){
            heap.push(it);
        }
        int count = 0;
        while(nums.size() > 1 && heap.top() < k){
            long long int x = heap.top(); heap.pop();
            long long int y = heap.top(); heap.pop();
            heap.push(2*x+y);
            count++;
        }
        return count;
    }
};