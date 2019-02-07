/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (47.27%)
 * Total Accepted:    85.2K
 * Total Submissions: 180.3K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 *
 *
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 *
 *
 * Example:
 *
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 *
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */
#include <queue>
#include <vector>

struct MinQueueCompare {
    bool operator()(const int& left, const int& right) const {
        return left > right;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int, std::vector<int>, MinQueueCompare> pq;
        for (const auto& row : matrix) {
            for (const auto& elem : row) {
                pq.push(elem);
            }
        }
        for (int i=1; i<k; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};
