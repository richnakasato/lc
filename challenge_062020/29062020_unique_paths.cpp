class Solution {
public:
    int uniquePaths(int m, int n) {
        auto counts = vector<vector<int>>(m, vector<int>(n));
        for (auto r=0; r<size(counts); ++r) {
            counts[r][0] = 1;
        }
        for (auto c=0; c<size(counts[0]); ++c) {
            counts[0][c] = 1;
        }
        for (auto r=1; r<size(counts); ++r) {
            for (auto c=1; c<size(counts[0]); ++c) {
                counts[r][c] = counts[r-1][c] + counts[r][c-1];
            }
        }
        return counts[m-1][n-1];
    }
};
