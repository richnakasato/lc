class Solution {
public:
    int popHeap(vector<int>& v) {
        std::pop_heap(v.begin(), v.end());
        int result = v.back();
        v.pop_back();
        return result;
    }
    void pushHeap(vector<int>& v, int val) {
        v.push_back(val);
        std::push_heap(v.begin(), v.end());
    }
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        if (stones.size() == 1) return stones[0];
        std::make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            int first = popHeap(stones);
            int second = popHeap(stones);
            int diff = std::max(first, second) - std::min(first, second);
            if (diff) pushHeap(stones, diff);
        }
        return stones.empty() ? 0 : stones[0];
    }
};
