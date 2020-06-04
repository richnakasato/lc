// Plan: 2 Pointer.  Increment from start and decrement from end, swapping chars until the two pointers meet 
//       in the middle.
// Time: O(n) -> iterate through half of vector
// Space: O(1) -> performed in place, plus cost of swap
// Lesson: Check if we need to swap in the first place!

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() < 2) return;
        auto fwd = 0;
        auto rev = s.size() - 1;
        while (fwd < rev) {
            swap(s[fwd], s[rev]);
            ++fwd;
            --rev;
        }
        return;
    }
};
