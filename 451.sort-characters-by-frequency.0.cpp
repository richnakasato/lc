/*
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (53.81%)
 * Total Accepted:    74.7K
 * Total Submissions: 138.9K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 *
 *
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 *
 */
class Solution {
    struct Compare {
        bool operator()(const tuple<char,int>& lhs, const tuple<char,int>& rhs)
        {
            return get<1>(lhs) > get<1>(rhs);
        }
    };
public:
    string frequencySort(const string s)
    {
        unordered_map<char,int> counts;
        for (const auto& c : s)
            ++counts[c];
        vector<tuple<char,int>> temp;
        for (const auto& e : counts)
            temp.push_back(make_tuple(e.first,e.second));
        sort(temp.begin(),temp.end(),Compare());
        string result;
        for (const auto& e : temp)
            result += string(get<1>(e),get<0>(e));
        return result;
    }
};
