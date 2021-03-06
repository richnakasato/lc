/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (33.90%)
 * Total Accepted:    272.9K
 * Total Submissions: 805.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> results;
        std::vector<int> curr = intervals[0];
        for (int i=1; i<intervals.size(); ++i) {
            if (curr[1] >= intervals[i][0]) {
                curr[1] = std::max(curr[1],intervals[i][1]);
            } else {
                results.push_back(curr);
                curr = intervals[i];
            }
        }
        results.push_back(curr);
        return results;
    }
};
