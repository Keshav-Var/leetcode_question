class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorFreq;
        unordered_map<int, int> ballColor;
        vector<int> ans;
        for(auto query:queries){
            int ball = query[0], color = query[1];
            colorFreq[color]++;
            if(ballColor.contains(ball)){
                colorFreq[ballColor[ball]]--;
                if(colorFreq[ballColor[ball]] == 0)
                colorFreq.erase(ballColor[ball]);
            }
            ballColor[ball] = color;
            ans.push_back(colorFreq.size());
        }
        return ans;
    }
};