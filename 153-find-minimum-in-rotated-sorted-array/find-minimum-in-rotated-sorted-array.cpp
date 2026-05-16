class Solution {
public:
    int findMin(vector<int>& nums) {
      int ans = INT_MAX;
      for (int val : nums)
      {
          ans = min(ans, val);
      }
      return ans;
    }
};