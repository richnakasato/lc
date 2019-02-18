/*
 * [191] Number of 1 Bits
 *
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (40.96%)
 * Total Accepted:    228.5K
 * Total Submissions: 557.9K
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Write a function that takes an unsigned integer and returns the number of
 * '1' bits it has (also known as the Hamming weight).
 *
 * Example 1:
 *
 *
 * Input: 11
 * Output: 3
 * Explanation: Integer 11 has binary representation
 * 00000000000000000000000000001011
 *
 *
 * Example 2:
 *
 *
 * Input: 128
 * Output: 1
 * Explanation: Integer 128 has binary representation
 * 00000000000000000000000010000000
 *
 *
 */
#include <unordered_map>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        const std::unordered_map<uint32_t,uint32_t> lookup {{0,0},
                                                            {1,1},
                                                            {2,1},
                                                            {3,2},
                                                            {4,1},
                                                            {5,2},
                                                            {6,2},
                                                            {7,3},
                                                            {8,1},
                                                            {9,2},
                                                            {10,2},
                                                            {11,3},
                                                            {12,2},
                                                            {13,3},
                                                            {14,3},
                                                            {15,4}};
        if (!n) return 0;
        uint32_t shift = 4;
        uint32_t sum = 0;
        uint32_t four_bytes = 32;
        for (uint32_t i=0; i<four_bytes; i+=shift) {
            uint32_t half_byte = n & 0xF;
            sum += lookup.at(half_byte);
            n >>= shift;
        }
        return sum;
    }
};
