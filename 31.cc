class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Handle small size arrays.
        if (nums.size() <= 1) return;
        
        int i = nums.size() - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) break;
        }
        if (i == -1) reverse(nums.begin(), nums.end());
        else {
            int larger = INT_MAX;
            int larger_index = 0;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i] && nums[j] < larger) {
                    larger = nums[j];
                    larger_index = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[larger_index];
            nums[larger_index] = temp;
            sort(nums.begin() + i + 1, nums.end());
        }
    }
};
