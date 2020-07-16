/*
plan: walk backwards over string, when find non space char, store position, walk backwards until next space found, copy from previous position to stored position into results string, append with space, repeat until primary string is exhausted, remember to store last word when out of for loop
time: linear
space: linear

" "
 i
  l
""
*/

class Solution {
public:
    string reverseWords(string s) {
        if (!size(s)) return s;
        auto result = string{};
        int last_char = -1;
        for (int i=size(s); i-->0;) {
            if (last_char == -1 && s[i] != ' ') {
                last_char = i;
            } else if (last_char != -1 && s[i] == ' ') {
                for (auto j=i+1; j<=last_char; ++j) {
                    result.push_back(s[j]);
                }
                result.push_back(' ');
                last_char = -1;
            }
        }
        if (last_char != -1) {
            auto start = 0;
            while(s[start] == ' ') ++start;
            for (auto j=start; j<=last_char; ++j) {
                result.push_back(s[j]);
            }
        }
        if (size(result)) {
            while (result[size(result)-1] == ' ') result.pop_back();
        }
        return result;
    }
};
