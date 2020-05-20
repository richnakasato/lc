class Solution {
public:
    int currValue(vector<vector<int>>& area, int r, int c) {
        if (r == 2 || c == 0) return area[r][c];
        auto smallest = min(area[r-1][c-1], min(area[r-1][c], area[r][c-1]));
        if (!smallest) return area[r][c];
        return pow(sqrt(smallest)+1, 2);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        auto area = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        for (auto r=0; r<matrix.size(); ++r) {
            for (auto c=0; c<matrix[0].size(); ++c) {
                area[r][c] = matrix[r][c] == '0' ? 0 : 1;
            }
        }
        auto largest = 0;
        for (auto r=0; r<area.size(); ++r) {
            for (auto c=0; c<area[0].size(); ++c) {
                if (area[r][c]) {
                    area[r][c] = currValue(area, r, c);
                    largest = max(largest, area[r][c]);
                }
            }
        }
        return largest;
    }
};
