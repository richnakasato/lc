// Plan: Need to keep map<val,idx> for o(1) lookup, removal, vector<val> for randomization (randomization on          idx). To remove from vector, swap tail with idx to remove, then pop_back (should cost O(1))
// Lesson: Remove is tricky... need to remember to update indexes after swap in vector, also need to do ONE erase at the end and one pop_back at the end, so that way if src and dst values same (i.e. 1 element left) you still take care of it ok.

class RandomizedSet {
public:
    unordered_map<int,int> seen;
    vector<int> indexes;

    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (seen.find(val) != end(seen)) return false;
        indexes.push_back(val);
        seen[val] = size(indexes) - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (seen.find(val) == end(seen)) return false;
        auto idx = seen[val];
        auto dst_idx = size(indexes) - 1;
        auto dst_val = indexes[dst_idx];
        swap(indexes[idx], indexes[dst_idx]);
        seen[dst_val] = idx;
        seen.erase(val);
        indexes.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, size(indexes) - 1);
        return indexes[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
