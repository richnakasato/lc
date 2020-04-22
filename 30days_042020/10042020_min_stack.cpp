class MinStack {
public:
    /** initialize your data structure here. */
    std::vector<int> n_stack;
    std::vector<int> m_stack;

    MinStack() {
    }

    void push(int x) {
        if (push_m_stack(x)) m_stack.push_back(x);
        n_stack.push_back(x);
    }

    void pop() {
        int x = n_stack.back();
        if (pop_m_stack(x)) m_stack.pop_back();
        n_stack.pop_back();
    }

    int top() {
        return n_stack.back();
    }

    int getMin() {
        return m_stack.back();
    }

    bool push_m_stack(int x) {
        if (m_stack.empty()) return true;
        return m_stack.back() >= x;
    }

    bool pop_m_stack(int x) {
        if (m_stack.empty()) return false;
        return m_stack.back() == x;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
