/*
plan: iterate through list, tracking counts in map, iterate through map pushing elements into min heap
      of size k.  be sure to check that size of map is > k, otherwise just return map entries
time: n to iterate list, n lg k to work through map + min heap
space: linear, n ish
*/

class Solution {
public:
    struct customComp {
        bool operator()(const tuple<int,int>& lhs, const tuple<int,int>& rhs) {
            return get<1>(lhs) > get<1>(rhs);
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto results = vector<int>{};
        if (!size(nums)) return results;

        auto counts = unordered_map<int,int>{};
        for (auto num : nums) {
            ++counts[num];
        }

        if (size(counts) <= k) {
            for (auto entry : counts) {
                results.push_back(entry.first);
            }
            return results;
        }

        auto heap = vector<tuple<int,int>>{};
        for (auto entry : counts) {
            auto temp = tuple<int,int>{entry.first, entry.second};
            heap.push_back(temp);
            push_heap(begin(heap), end(heap), customComp());
            if (size(heap) > k) {
                pop_heap(begin(heap), end(heap), customComp());
                heap.pop_back();
            }
        }
        for (auto entry : heap) {
            results.push_back(get<0>(entry));
        }

        return results;
    }
};
