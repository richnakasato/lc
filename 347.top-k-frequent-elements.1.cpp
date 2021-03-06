/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (51.97%)
 * Total Accepted:    154.2K
 * Total Submissions: 296.7K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 *
 *
 */
class Solution {
public:
    struct compare {
        bool operator()(const std::tuple<int,int>& lhs,
                        const std::tuple<int,int>& rhs) {
            return std::get<1>(lhs) < std::get<1>(rhs);
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> results;
        if (nums.empty()) return results;
        if (!k) return results;
        std::unordered_map<int,int> counts;
        for (auto num : nums) {
            ++counts[num];
        }
        std::priority_queue<std::tuple<int,int>,
                            std::vector<std::tuple<int,int>>,
                            compare> pq;
        for (auto entry : counts) {
            auto val = entry.first;
            auto count = entry.second;
            std::tuple<int,int> temp(val,count);
            pq.push(temp);
        }
        for (auto i=0; i<k; ++i) {
            auto temp = pq.top();
            pq.pop();
            results.push_back(std::get<0>(temp));
        }
        return results;
    }
};
