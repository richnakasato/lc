// Plan: Greedy.  Create vector of deltas (city a vs b cost), sort by decreasing order (greatest diff first).
//       Add to min cost of a or b to sum until a or b have N sums, then sum remaining costs from other city.
// Time: O(n lg n) -> cost of the sort
// Space: O(n) -> array of deltas
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto diffs = vector<tuple<int,int>>{};
        for (auto i=0; i<size(costs); ++i) {
            auto diff = tuple<int,int>{costs[i][1] - costs[i][0], i};
            diffs.push_back(diff);
        }
        sort(begin(diffs), end(diffs), [](const tuple<int,int>& lhs,
                                          const tuple<int,int>& rhs) { 
                return abs(get<0>(lhs)) > abs(get<0>(rhs));  });
        auto count_a = 0;
        auto count_b = 0;
        auto limit = size(costs) / 2;
        auto sum = 0;
        for (auto diff : diffs) {
            auto cost = get<0>(diff);
            auto idx = get<1>(diff);
            if (count_a == limit) {
                ++count_b;
                sum += costs[idx][1];
            } else if (count_b == limit) {
                ++count_a;
                sum += costs[idx][0];
            } else {
                if (cost >= 0) {
                    ++count_a;
                    sum += costs[idx][0];
                } else {
                    ++count_b;
                    sum += costs[idx][1];
                }
            }
        }
        return sum;
    }
};
