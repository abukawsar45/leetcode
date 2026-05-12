class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        // connect with git

        for (auto var : nums) {
            string temp = to_string(var);
            for(auto ch: temp){
                ans.push_back(ch-'0');
            }

        }

        return ans;

        
    }
};