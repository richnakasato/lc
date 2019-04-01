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
#include <vector>

struct Node {
    size_t idx;
    int temp;
};

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& T)
    {
        std::vector<Node> unresolved;
        std::vector<int> res(T.size(),0);
        for (size_t i=0; i<T.size(); ++i) {
            if (unresolved.empty() || unresolved.back().temp >= T[i])
                unresolved.push_back({i,T[i]});
            else if (!unresolved.empty()) {
                while (!unresolved.empty() && unresolved.back().temp < T[i]) {
                    res[unresolved.back().idx] = i - unresolved.back().idx;
                    unresolved.pop_back();
                }
                unresolved.push_back({i,T[i]});
            }
        }
        return res;
    }
};
