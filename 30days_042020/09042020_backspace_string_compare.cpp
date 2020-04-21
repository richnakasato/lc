class Solution {
public:
    std::string getActual(std::string typed) {
        std::string actual;
        int ti = 0;
        int ai = 0;
        while (ti < typed.size()) {
            if (typed[ti] != '#') {
                actual.push_back(typed[ti]);
                ++ai;
            } else {
                if (ai > 0) {
                    actual.pop_back();
                    --ai;
                }
            }
            ++ti;
        }
        return actual;
    }
    std::string replace(std::string typed) {
        int lhs = 0;
        int rhs = 0;
        while (rhs < typed.size()) {
            if (typed[rhs] != '#') {
                typed[lhs] = typed[rhs];
                ++lhs;
            } else {
                lhs > 0 ? --lhs : 0;
            }
            ++rhs;
        }
        return typed.substr(0, lhs);
    }

    bool backspaceCompare(string S, string T) {
        if (S == T) return true;
        return replace(S) == replace(T);
    }
};
