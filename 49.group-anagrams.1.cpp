/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (42.93%)
 * Total Accepted:    266.5K
 * Total Submissions: 620.7K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note:
 *
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 *
 *
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        if (strs.empty()) return result;
        std::unordered_map<std::string,int> lookup;
        for (auto s : strs) {
            auto temp = s;
            std::sort(temp.begin(), temp.end());
            int idx = result.size();
            if (lookup.find(temp) == lookup.end()) {
                std::vector<std::string> new_vec;
                new_vec.push_back(s);
                result.push_back(new_vec);
                lookup[temp] = idx;
            } else {
                result[lookup[temp]].push_back(s);
            }
        }
        return result;
    }
};
