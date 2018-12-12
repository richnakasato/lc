#
# [804] Rotated Digits
#
# https://leetcode.com/problems/rotated-digits/description/
#
# algorithms
# Easy (51.47%)
# Total Accepted:    18.2K
# Total Submissions: 35.3K
# Testcase Example:  '10'
#
# X is a good number if after rotating each digit individually by 180 degrees,
# we get a valid number that is different from X.  Each digit must be rotated -
# we cannot choose to leave it alone.
#
# A number is valid if each digit remains a digit after rotation. 0, 1, and 8
# rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
# other, and the rest of the numbers do not rotate to any other number and
# become invalid.
#
# Now given a positive number N, how many numbers X from 1 to N are good?
#
#
# Example:
# Input: 10
# Output: 4
# Explanation:
# There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
# Note that 1 and 10 are not good numbers, since they remain unchanged after
# rotating.
#
#
# Note:
#
#
# N  will be in range [1, 10000].
#
#
#
class Solution:
    def helper(self, n, good, bad):
        seen_good = False
        while n:
            digit = n%10
            if digit in bad:
                return False
            elif digit in good:
                seen_good = True
            n//=10
        return seen_good

    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        bad = [3, 4, 7]
        good = [2, 5, 6, 9]
        count = 0
        for i in range(1, N+1):
            if self.helper(i, good, bad):
                count+=1
        return count

def main():
    pass

if __name__ == "__main__":
    main()
