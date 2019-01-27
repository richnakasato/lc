/*
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (56.96%)
 * Total Accepted:    39.9K
 * Total Submissions: 70.1K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 *
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 *
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 *
 */
#include <stack>
#include <vector>

struct HelperNode {
    int idx = 0;
    int val = 0;
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> results(T.size(), 0);
        std::stack<HelperNode> unsolved;
        for (std::vector<int>::size_type i=0; i<T.size(); ++i) {
            while (!unsolved.empty() && T[i] > unsolved.top().val) {
                HelperNode temp = unsolved.top();
                unsolved.pop();
                results[temp.idx] = i - temp.idx;
            }
            HelperNode to_solve;
            to_solve.idx = i;
            to_solve.val = T[i];
            unsolved.push(to_solve);
        }
        return results;
    }
};
