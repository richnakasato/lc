class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        if (arr.size() < 2) return count;
        std::vector<int> elements(1001, 0);
        for (auto i : arr) {
            ++elements[i];
        }
        for (int i=1; i<elements.size(); ++i) {
            if (elements[i-1] && elements[i]) {
                count += elements[i-1];
            }
        }
        return count;
    }
};
