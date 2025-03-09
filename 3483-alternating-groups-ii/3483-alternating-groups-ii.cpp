class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int len = 1;
        int st = 0;
        for(int i = 1; i < k; i++){
            if(colors[i] != colors[i - 1])
            len++;
            else {
                len = 1;
                st = i;
            }
        }
        if(len == k) count++;
        for(int i = k; i < n+k-1; i++){
            if(st <= i - k) len--;
            if(colors[i%n] != colors[(i-1)%n]) len++;
            else {len = 1; st = i%n;}
            if(len == k) count++;
        }
        return count;
    }
};