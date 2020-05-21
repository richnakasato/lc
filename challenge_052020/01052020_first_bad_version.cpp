// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int helper(int lo, int hi, int last) {
        if (lo > hi) return last;
        int mid = lo + ((hi - lo) / 2);
        bool bad = isBadVersion(mid);
        if (!bad) return helper(mid+1, hi, last);
        else return helper(lo, mid-1, mid);
    }
    int firstBadVersion(int n) {
        if (!n) return -1;
        return helper(1, n, -1);
    }
};
