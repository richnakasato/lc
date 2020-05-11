    int helper(vector<int>& nums, int start, int end, int target) {
        if (start > end) return -1;

        int mid = start + ((end - start) / 2);
        if (nums[start] == target) return start;
        if (nums[mid] == target) return mid;
        if (nums[end] == target) return end;

        if (nums[start] <= nums[mid] && nums[mid] <= nums[end]) {
            if (target < nums[mid]) return helper(nums, start, mid-1, target);
            return helper(nums, mid+1, end, target);
        }
        else if (nums[start] >= nums[mid] && nums[mid] <= nums[end]) {
            if (target > nums[mid] && target < nums[end]) return helper(nums, mid+1, end, target);
            return helper(nums, start, mid-1, target);
        }
        else {
            if (target > nums[start] && target < nums[mid]) return helper(nums, start, mid-1, target);
            return helper(nums, mid+1, end, target);
        }
    }
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return helper(nums, 0, nums.size() - 1, target);
    }
