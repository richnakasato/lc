/*
idea: bfs
time: linear wrt # nodes
space: linear wrt # nodes
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* curr) {

    }
    Node* connect(Node* root) {
        if (!root) return root;
        auto bfs = queue<tuple<Node*,int>>{};
        auto last = tuple<Node*,int>{nullptr,-1};
        auto temp = tuple<Node*,int>{root,0};
        bfs.push(temp);
        while (size(bfs)) {
            temp = bfs.front(); bfs.pop();
            auto curr = get<0>(temp);
            auto lvl = get<1>(temp);
            if (get<0>(last) && get<1>(last) == lvl) get<0>(last)->next = curr;
            if (curr->left) bfs.push(tuple<Node*,int>{curr->left,lvl+1});
            if (curr->right) bfs.push(tuple<Node*,int>{curr->right,lvl+1});
            last = tuple<Node*,int>{curr,lvl};
        }
        return root;
    }
};
