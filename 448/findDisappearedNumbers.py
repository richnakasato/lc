def findDisappearedNumbers(self, nums):
    """
    :type nums: List[int]
    :rtype: List[int]
    """
    perfect = [0 for x in range(len(nums))]
    for num in nums:
        perfect[num-1] = num
    return [i+1 for i,v in enumerate(perfect) if v == 0]

def main():
    pass

if __name__ == "__main__":
    main()
