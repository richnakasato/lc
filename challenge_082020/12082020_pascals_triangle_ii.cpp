/*
plan: non-optimal space - create whole triangle structure, then perform general pascal triangle lookup sum
      linear space - create prev_row and curr_row of size rowIndex+1, perform same as above, but copy
      curr_row back to prev_row and rinse repeat
time: quadratic wrt rowIndex
space: quadratic wrt rowIndex
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        auto triangle = vector<vector<int>>{};
        for (auto r=0; r<rowIndex+1; ++r) {
            for (auto c=0; c<rowIndex+1; ++c) {
                triangle.push_back(vector<int>(c+1, 1));
            }
        }
        for (auto r=2; r<size(triangle); ++r) {
            for (auto c=1; c<size(triangle[r])-1; ++c) {
                triangle[r][c] = triangle[r-1][c-1] + triangle[r-1][c];
            }
        }
        return triangle[rowIndex];
    }
};
