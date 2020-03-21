class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;
        std::vector<std::vector<int>> memo(
            text1.size()+1,
            std::vector<int>(text2.size()+1, 0));
        for (int r=1; r<text1.size()+1; ++r) {
            for (int c=1; c<text2.size()+1; ++c) {
                if (text1[r-1] == text2[c-1]) {
                    memo[r][c] = memo[r-1][c-1] + 1;
                } else {
                    memo[r][c] = std::max(memo[r-1][c], memo[r][c-1]);
                }
            }
        }
        return memo[text1.size()][text2.size()];
    }
};
