// Plan: Two pointers. walk both ptrs foward when match is found.  If match not found, walk only t ptr. If
//       get to end of s, then return true, if get to end of t and not end of s, return false.
// Time: size(t)
// Space: 1

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (!size(s) && !size(t)) return true;
        if (!size(s) && size(t)) return true;
        if (size(s) && !size(t)) return false;
        auto s_ptr = 0;
        auto t_ptr = 0;
        while (s_ptr < size(s) && t_ptr < size(t)) {
            auto s_char = s[s_ptr];
            auto t_char = t[t_ptr];
            if (s_char == t_char) {
                ++s_ptr;
            }
            ++t_ptr;
        }
        return s_ptr == size(s);
    }
};
