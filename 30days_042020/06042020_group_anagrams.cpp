class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<std::string>& strs) {
        auto memo = std::unordered_map<std::string, std::vector<std::string>>();
        for (const auto &str : strs) {
            auto sorted = str;
            std::sort(sorted.begin(), sorted.end());
            memo[sorted].push_back(str);
        }
        std::vector<std::vector<std::string>> result;
        for (const auto &pair : memo) {
            result.push_back(pair.second);
        }
        return result;
    }
};
