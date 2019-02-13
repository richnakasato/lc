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
#include <algorithms>
#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // n*m log m time, n*m space
        std::unordered_map<std::string,std::vector<std::string> > memo;
        for (const auto& s : strs) { // n
            std::string temp = s;
            std::sort(temp.begin(), temp.end()); // m long m
            memo[temp].push_back(s);
        }
        std::vector<std::vector<std::string> > results;
        for (const auto& entry : memo) {
            results.push_back(entry.second);
        }
        return results;
    }
};
