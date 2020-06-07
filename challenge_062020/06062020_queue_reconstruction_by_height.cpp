ass Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(begin(people), end(people), [](const vector<int>& lhs,
                                            const vector<int>& rhs) {
            if (lhs[0] > rhs[0]) return true;
            if (lhs[0] == rhs[0]) return lhs[1] <= rhs[1];
            return false;
        }); // n log n
        auto queue = list<vector<int>>{};
        for (auto p : people) {
            auto height = p[0];
            auto infront = p[1];
            auto iter = begin(queue);
            while (iter != end(queue)) {
                if ((*iter)[0] >= height) {
                    if (!infront) break;
                    --infront;
                }
                iter = next(iter);
            }
            queue.insert(iter, p);
        } // n^2
        auto result = vector<vector<int>>{};
        for (auto n : queue) {
            result.push_back(n);
        } // n
        return result;
    }
};
