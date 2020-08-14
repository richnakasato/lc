class CombinationIterator {
public:
    string chars;
    int len;
    int ptr;
    vector<string> combs;
    void helper(string& curr, int idx) {
        curr.push_back(chars[idx]);
        if (size(curr) == len) {
            combs.push_back(curr);
            curr.pop_back();
            return;
        }
        for (auto i=idx+1; i<size(chars); ++i) {
            helper(curr, i);
        }
        curr.pop_back();
        return;
    }
    CombinationIterator(string characters, int combinationLength) {
        chars = characters;
        len = combinationLength;
        ptr = 0;
        auto curr = string{};
        for (auto i=0; i<size(chars); ++i) {
            helper(curr, i);
        }
    }

    string next() {
        return combs[ptr++];
    }

    bool hasNext() {
        return (ptr < size(combs));
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
