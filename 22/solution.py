#
# [22] Generate Parentheses
#
# https://leetcode.com/problems/generate-parentheses/description/
#
# algorithms
# Medium (51.33%)
# Total Accepted:    268.1K
# Total Submissions: 522.1K
# Testcase Example:  '3'
#
#
# Given n pairs of parentheses, write a function to generate all combinations
# of well-formed parentheses.
#
#
#
# For example, given n = 3, a solution set is:
#
class Solution:
    def helper(self, lp_count, rp_count, cur_list, res_list):
        if lp_count == 0 and rp_count == 1:
            new_list = cur_list + [")"]
            res_str = ''.join(new_list)
            res_list.append(res_str)
        else:
            if lp_count > 0:
                new_list = cur_list + ["("]
                self.helper(lp_count-1, rp_count, new_list, res_list)
            if rp_count > lp_count:
                new_list = cur_list + [")"]
                self.helper(lp_count, rp_count-1, new_list, res_list)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        lp_count = n
        rp_count = n
        cur_list = list()
        res_list = list()
        self.helper(lp_count, rp_count, cur_list, res_list)
        return res_list


def main():
    s = Solution()
    n = 3
    s.generateParenthesis(n)

if __name__ == "__main__":
    main()

