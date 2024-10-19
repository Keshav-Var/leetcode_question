class Solution {
public:
    char findKthBit(int n, int k) {
        return recurrsive(n, k, "0", 1);
    }

    char recurrsive(int n, int k, string s, int index){
        if(index == n)
        return s[k - 1];
        int mid = s.length()/2;
        string stemp = s;
        stemp[mid] = stemp[mid] == '0'? '1':'0';
        return recurrsive(n, k, s + '1' + stemp, index+1);
    }
};