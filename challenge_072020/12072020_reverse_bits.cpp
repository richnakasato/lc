class Solution {
public:
    unordered_map<uint32_t,uint32_t> cache;
    uint32_t reverseWord(uint32_t n, int word) {
        auto shift = word * 8;
        n >>= shift;
        n &= 0xFF;
        uint32_t res = 0;
        res |= (0x01 & n) << 7;
        res |= (0x02 & n) << 5;
        res |= (0x04 & n) << 3;
        res |= (0x08 & n) << 1;
        res |= (0x10 & n) >> 1;
        res |= (0x20 & n) >> 3;
        res |= (0x40 & n) >> 5;
        res |= (0x80 & n) >> 7;
        res <<= shift;
        return res;
    }
    uint32_t reverseBits(uint32_t n) {
        auto word_0 = reverseWord(n, 0);
        auto word_1 = reverseWord(n, 1);
        auto word_2 = reverseWord(n, 2);
        auto word_3 = reverseWord(n, 3);
        auto result = (word_0 << 24) | (word_1 << 8) | (word_2 >> 8) | (word_3 >> 24);
        return result;
    }
};
