/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (35.27%)
 * Total Accepted:    145.5K
 * Total Submissions: 412.5K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        auto memo = std::vector<std::vector<int>>(word1.size()+1,
                                                  std::vector<int>(word2.size()+1,
                                                                   0));
        for (int r=1; r<memo.size(); ++r) {
            memo[r][0] = r;
        }
        for (int c=1; c<memo[0].size(); ++c) {
            memo[0][c] = c;
        }
        for (int r=1; r<memo.size(); ++r) {
            for (int c=1; c<memo[0].size(); ++c) {
                if (word1[r-1] == word2[c-1]) {
                    memo[r][c] = memo[r-1][c-1];
                } else {
                    auto diag = memo[r-1][c-1];
                    auto up = memo[r-1][c];
                    auto left = memo[r][c-1];
                    memo[r][c] = std::min(diag, up);
                    memo[r][c] = std::min(memo[r][c], left);
                    ++memo[r][c];
                }
            }
        }
        return memo[word1.size()][word2.size()];
    }
};
