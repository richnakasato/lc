class Solution {
public:
    int accumulate(vector<vector<int>> shift, int dir) {
        int sum = 0;
        for (vector<int> pair: shift) {
            if (pair[0] == dir) sum += pair[1];
        }
        return sum;
    }
    int index(int src, int r_shift, int sz) {
        return (src + r_shift) % sz;
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        if (!s.length() || !shift.size()) return s;
        int left_shift = accumulate(shift, 0) % s.length();
        int right_shift = accumulate(shift, 1) % s.length();
        if (left_shift == right_shift) return s;
        int left_shift_right = s.length() - left_shift;
        int total = (left_shift_right + right_shift) % s.length();
        string copy = s;
        for (int i=0; i<s.length(); ++i) {
            int j = index(i, total, s.length());
            copy[j] = s[i];
        }
        return copy;
    }
};
