/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        std::unordered_map<int,Node*> seen;
        std::queue<Node*> to_visit;
        Node* orig = node;
        Node* curr = NULL;
        seen[orig->val] = new Node(orig->val);
        to_visit.push(orig);
        while (!to_visit.empty()) {
            orig = to_visit.front();
            to_visit.pop();
            curr = seen[orig->val];
            for (Node* n : orig->neighbors) {
                if (seen.find(n->val) == seen.end()) {
                    seen[n->val] = new Node(n->val);
                    to_visit.push(n);
                }
                curr->neighbors.push_back(seen[n->val]);
            }
        }
        return seen[node->val];
    }
};
