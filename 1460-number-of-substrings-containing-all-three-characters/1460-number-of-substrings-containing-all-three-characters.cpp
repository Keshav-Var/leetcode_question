class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int st = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            while(st < i && mp.contains('a') && mp.contains('b') && mp.contains('c')){
                count += s.length() - i;
                mp[s[st]]--;
                if(mp[s[st]] == 0)
                mp.erase(s[st]);
                st++;
            }
        }
        return count;
    }
};