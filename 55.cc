#include <algorithm>
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;
        for (int i = nums.size() - 2; i >=0; --i) {
            int furthest = std::min(i + nums[i], (int)nums.size() - 1);
            for (int j = i + 1; j <= furthest ; ++j) {
                if (dp[j] == true) {
                    dp[i] = true;
                    break;
                }    
            }
        }
        if (dp[0] == true) return true;
        else return false;
    }
};
