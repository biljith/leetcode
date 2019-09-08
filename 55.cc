#include <algorithm>
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int last_good = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= last_good) {
                last_good = i;
            }
        }
        return last_good == 0;
    }
};
