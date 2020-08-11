/*
plan: thinking some calculation with modulo here... will need to shift everything to 1-26, maybe treat
      each character as a 26 base digit and just multi shift
*/

class Solution {
public:
    int titleToNumber(string s) {
        auto result = 0;
        auto power = 0;
        for (auto i=size(s); i-->0;) { // iterate backwards
            auto c = s[i];
            int val = s[i] - 'A' + 1;
            result += val * pow(26,power++);
        }
        return result;
    }
};
