class Solution:
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) < 2:
            return 0
        last_min = count = zeros = ones = 0
        prev = curr = None
        for bit in s:
            curr = bit
            if curr != prev:
                if curr == "0":
                    zeros = 0
                else:
                    ones = 0
                last_min = 0
            if curr == "0":
                zeros += 1
            else:
                ones += 1
            if min(zeros, ones) > last_min:
                count += 1
                last_min += 1
            prev = curr
        return count
