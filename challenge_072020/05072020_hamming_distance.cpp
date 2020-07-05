/*
plan: xor will give us bits that differ... then we can use kernighan bit counting trick...
time: xor == 1, bit counting trick, n where n is number of bits set to true
space: 1
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        auto z = x ^ y;
        auto count = 0;
        while (z) {
            ++count;
            z &= (z-1);
        }
        return count;
    }
};
