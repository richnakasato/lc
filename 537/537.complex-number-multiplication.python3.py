#
# [537] Complex Number Multiplication
#
# https://leetcode.com/problems/complex-number-multiplication/description/
#
# algorithms
# Medium (64.31%)
# Total Accepted:    30.5K
# Total Submissions: 47.5K
# Testcase Example:  '"1+1i"\n"1+1i"'
#
#
# Given two strings representing two complex numbers.
#
#
# You need to return a string representing their multiplication. Note i2 = -1
# according to the definition.
#
#
# Example 1:
#
# Input: "1+1i", "1+1i"
# Output: "0+2i"
# Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it
# to the form of 0+2i.
#
#
#
# Example 2:
#
# Input: "1+-1i", "1+-1i"
# Output: "0+-2i"
# Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
# it to the form of 0+-2i.
#
#
#
# Note:
#
# The input strings will not have extra blank.
# The input strings will be given in the form of a+bi, where the integer a and
# b will both belong to the range of [-100, 100]. And the output should be also
# in this form.
#
#
#
class Solution:
    def get_real_img_cplx(cplx_num_str):
        cplx_num_list = cplx_num_str.split("+")
        return int(cplx_num_list[0]), int(''.join(cplx_num_list[1][:-1]))

    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a_real, a_img = Solution.get_real_img_cplx(a)
        b_real, b_img = Solution.get_real_img_cplx(b)
        real = str(a_real*b_real + (-1)*a_img*b_img)
        img = str(a_real*b_img + a_img*b_real) + "i"
        return "+".join([real, img])

