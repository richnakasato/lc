class Solution:
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        g_max = 0
        super_memo = [None] * len(nums)
        for i in range(len(nums)):
            memo = set()            
            done = False
            idx = i
            cur_len = 0
            while not done:
                if super_memo[i]:
                    cur_len = super_memo[i]
                    done = True
                val = nums[idx]
                if val in memo:
                    cur_len = len(memo)
                    for item in memo:
                        super_memo[item] = cur_len
                    done = True
                else:
                    memo.add(val)
                    idx = val
            g_max = max(g_max, cur_len)
        return g_max


def main():
    pass

if __name__ == "__main__":
    main()

