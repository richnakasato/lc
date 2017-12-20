/*
[1] Two Sum

https://leetcode.com/problems/two-sum

* algorithms
* Easy (36.38%)
* Total Accepted:    722.6K
* Total Submissions: 2M
* Testcase Example:  '[3,2,4]\n6'

Given an array of integers, return indices of the two numbers such that they add u
p to a specific target.

You may assume that each input would have exactly one solution, and you may not us
e the same element twice.


Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

//#define BRUTE

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> idxs = {};

#ifdef BRUTE
      // brute force is double for loop, O(N^2)
      for(int iii=0; iii<nums.size(); ++iii) {
        for(int jjj=iii+1; jjj<nums.size(); ++jjj) {
          if(nums[iii] + nums[jjj] == target) {
            idxs.push_back(iii);
            idxs.push_back(jjj);
            return idxs;
          }
        }
      }
#endif

#ifndef BRUTE
      // map version, key is compliment and val is idx, O(N)
      map<int, int> comps = {};
      for(int iii=0; iii<nums.size(); ++iii) {
        int comp = target - nums[iii];
        auto search = comps.find(comp);
        if(search != comps.end()) {
          idxs.push_back(comps[comp]);
          idxs.push_back(iii);
          return idxs;
        }
        else {
          comp = nums[iii];
          comps[comp] = iii;
        }
      }
#endif
      return {};
    }
};
