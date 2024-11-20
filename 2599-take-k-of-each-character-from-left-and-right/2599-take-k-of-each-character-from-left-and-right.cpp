class Solution {
public:
    int takeCharacters(string s, int k) {
        int count[3];
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']++;
        }
        if(count[0] < k || count[1] < k || count[2] < k)
        return -1;
        int mini = s.length(), start = 0;
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']--;
            while(start <= i && (count[0]<k || count[1]<k || count[2]<k)){
                count[s[start] - 'a']++;
                start++;
            }
            mini = min(mini, int(s.length()-(i-start+1)));
        }
        return mini;
    }
};