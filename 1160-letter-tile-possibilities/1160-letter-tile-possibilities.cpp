class Solution {
    unordered_set<string> sequences;
    void solve(string &s, int i, string seq){
        if(i == s.length()) {
            if(seq != "")
            sequences.insert(seq);
            return;
        }
        for(int j = i; j < s.length(); j++){
            swap(s[i], s[j]);
            solve(s, i+1, seq);
            solve(s, i+1, seq+s[i]);
            swap(s[i], s[j]);
        }
    }
public:
    int numTilePossibilities(string tiles) {
        solve(tiles, 0, "");
        // for(auto s:sequences) cout<<s<<" ";
        return sequences.size();
    }
};