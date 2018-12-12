def majorityElement(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    counts = dict()
    for num in nums:
        if num not in counts:
            counts[num] = 1
        else:
            counts[num] += 1
    threshold = len(nums)//2
    for num,count in counts.items():
        if count > threshold:
            return num

def majorityElement2(self, nums):
    nums.sort()
    return nums[len(nums)/2]


def main():
    pass

if __name__ == "__main__":
    main()

