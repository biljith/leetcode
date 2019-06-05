class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.empty()) {
            if (b.size() % 2 == 0) return (b[b.size() / 2 - 1] + b [b.size() / 2]) / 2.0;
            else return b[b.size() / 2];
        }
        
        if (b.empty()) {
            if (a.size() % 2 == 0) return (a[a.size() / 2 - 1] + a [a.size() / 2]) / 2.0;
            else return a[a.size() / 2];
        }
        
        int median = (a.size() + b.size() + 1) / 2;
        int aMin = max(0, median - (int)b.size());
        int aMax = min(median, (int)a.size());
        
        while (aMin <= aMax) {
            int aNums = aMin + (aMax - aMin) / 2;
            int bNums = median - aNums;
            
            if (aNums < a.size() && bNums > 0 && b[bNums - 1] > a[aNums])
                aMin = aNums + 1;
            else if (bNums < b.size() && aNums > 0 && a[aNums - 1] > b[bNums])
                aMax = aNums - 1;
            else{
                if ((a.size() + b.size()) % 2 == 1) {
                    int maxi = -1;
                    if (aNums > 0) maxi = max(maxi, a[aNums - 1]);
                    if (bNums > 0) maxi = max(maxi, b[bNums - 1]);
                    return maxi;
                } else {
                    int mini = INT_MAX;
                    if (aNums < a.size())
                        mini = min(mini, a[aNums]);
                    if (bNums < b.size())
                        mini = min(mini, b[bNums]);
                    int maxi = -1;
                    if (aNums > 0) {
                        maxi = max(maxi, a[aNums - 1]);
                    }
                    if (bNums > 0) {
                        maxi = max(maxi, b[bNums - 1]);
                    }
                    return (maxi + mini) / 2.0;
                }
            }
        }
        return 0;
    }
};
