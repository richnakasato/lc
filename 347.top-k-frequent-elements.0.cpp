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
#include <queue>
#include <tuple>
#include <unordered_map>

struct CompareTuple {
    bool operator()(std::tuple<int,int> left, std::tuple<int,int> right) {
        return std::get<1>(left) < std::get<1>(right);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> counts;
        for (const auto& num : nums) {
            ++counts[num];
        }
        std::priority_queue<std::tuple<int,int>,
                            std::vector<std::tuple<int,int>>,
                            CompareTuple> pq;
        for (const auto& entry : counts) {
            std::tuple<int,int> temp {entry.first, entry.second};
            pq.push(temp);
        }
        std::vector<int> result;
        for (int i=0; i<k; ++i) {
            std::tuple<int,int> temp = pq.top();
            result.push_back(std::get<0>(temp));
            pq.pop();
        }
        return result;
    }
};
