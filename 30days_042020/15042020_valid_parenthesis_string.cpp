class Solution {
public:
    bool checkValidString(string s) {
        if (!s.size()) return true;
        std::vector<int> stack;
        std::vector<int> wild;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') stack.push_back(i);
            else if (s[i] == '*') wild.push_back(i);
            else {
                if (!stack.empty()) stack.pop_back();
                else if (!wild.empty()) wild.pop_back();
                else return false;
            }
        }
        while (!stack.empty() && !wild.empty() && stack.back() < wild.back()) {
            stack.pop_back();
            wild.pop_back();
        }
        if (stack.empty()) return true;
        return false;
    }
};
