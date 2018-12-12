/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.54%)
 * Total Accepted:    408.7K
 * Total Submissions: 1.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int str_len = s.length();
      int max_len = 0;
      int cur_len = 0;
      int start_idx = 0;
      int end_idx = 0;
      set<char> seen_chars = {};

      if(s=="") { return 0; }

      char start_char = s[start_idx];
      char end_char = s[end_idx];
      while(end_idx < str_len) {
        auto search = seen_chars.find(end_char);
        while(search != seen_chars.end()) {
          seen_chars.erase(start_char);
          cur_len--;
          start_idx++;
          start_char = s[start_idx];
          search = seen_chars.find(end_char);
        }
        seen_chars.insert(end_char);
        cur_len++;
        end_idx++;
        end_char = s[end_idx];
        if(cur_len > max_len) { max_len = cur_len; }
      }
      return max_len;
    }
};
