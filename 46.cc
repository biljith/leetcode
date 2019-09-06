class Solution {
private:
    vector<vector<int>> permutations;
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        get_permutations(nums, 0, nums.size() - 1);
        return permutations;
    }
    void get_permutations(vector<int>& nums, int l, int r) {
        if (l >= r) {
            permutations.push_back(nums);
            return;
        }
        for (int i = l; i <= r; ++i) {
            swap(nums[l], nums[i]);
            get_permutations(nums, l + 1, r);
            swap(nums[l], nums[i]);
        }
    }
};
