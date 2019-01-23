#
# [412] Fizz Buzz
#
# https://leetcode.com/problems/fizz-buzz/description/
#
# algorithms
# Easy (58.25%)
# Total Accepted:    162.4K
# Total Submissions: 278.8K
# Testcase Example:  '1'
#
# Write a program that outputs the string representation of numbers from 1 to
# n.
#
# But for multiples of three it should output “Fizz” instead of the number and
# for the multiples of five output “Buzz”. For numbers which are multiples of
# both three and five output “FizzBuzz”.
#
# Example:
#
# n = 15,
#
# Return:
# [
# ⁠   "1",
# ⁠   "2",
# ⁠   "Fizz",
# ⁠   "4",
# ⁠   "Buzz",
# ⁠   "Fizz",
# ⁠   "7",
# ⁠   "8",
# ⁠   "Fizz",
# ⁠   "Buzz",
# ⁠   "11",
# ⁠   "Fizz",
# ⁠   "13",
# ⁠   "14",
# ⁠   "FizzBuzz"
# ]
#
#
#
class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = list()
        for i in range(1,n+1):
            if not i%3 and not i%5:
                result.append("FizzBuzz")
            elif not i%3:
                result.append("Fizz")
            elif not i%5:
                result.append("Buzz")
            else:
                result.append(str(i))
        return result


def main():
    s = Solution()
    print(s.fizzBuzz(3))


if __name__ == "__main__":
    main()
