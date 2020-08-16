/*
plan: sort, then iterate through searching for 2nd node of curr element greater than first node of next
      element... need special comparison function to sort
time: log linear wrt size(intervals)
space: constant if in place, otherwise linear wrt size(intervals)
learn: trick here seems to be to sort by the 2nd node instead of 1st (like merge interval)
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (size(intervals) < 2) return 0;
        auto result = 0;
        sort(begin(intervals), end(intervals), [](const vector<int>& lhs, const vector<int>& rhs){
            if (lhs[1] == rhs[1]) return lhs[0] < rhs[0];
            return lhs[1] < rhs[1];
        });
        auto lhs = 0;
        auto rhs = 1;
        while (rhs < size(intervals)) {
            if (intervals[lhs][1] > intervals[rhs][0]) {
                ++rhs;
                ++result;
            } else {
                lhs = rhs;
                ++rhs;
            }
        }
        return result;
    }
};
