class Solution {
public:
    bool shouldMerge(const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[1] >= rhs[0];
    }
    vector<int> doMerge(const vector<int>& lhs, const vector<int>& rhs) {
        auto result = vector<int>{};
        result.push_back(lhs[0]);
        result.push_back(max(lhs[1], rhs[1]));
        return result;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto result = vector<vector<int>>{};
        if (!size(intervals)) return result;
        sort(begin(intervals),
             end(intervals),
             [](const vector<int>& lhs, const vector<int>& rhs){
                 if (lhs[0] == rhs[0]) {
                     return lhs[1] < rhs[1];
                 }
                 return lhs[0] < rhs[0];
             });
        auto curr = intervals[0];
        for (auto i=1; i<size(intervals); ++i) {
            if (shouldMerge(curr, intervals[i])) {
                curr = doMerge(curr, intervals[i]);
            } else {
                result.push_back(curr);
                curr = intervals[i];
            }
        }
        result.push_back(curr);
        return result;
    }
};
