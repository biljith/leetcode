class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > a(nums.size());
        vector<int> res(2);
        for (int i = 0; i < nums.size(); ++i) {
            a[i] = make_pair(nums[i], i);
        }
        sort(a.begin(), a.end());
        
        for (int i = 0, j = nums.size() - 1; i < j;) {
            if (a[i].first + a[j].first == target) {
                res[0] = a[i].second;
                res[1] = a[j].second;
                return res;
            } else if (a[i].first + a[j].first > target)
                j--;
            else
                i++;
        }
        return res;
    }
};
