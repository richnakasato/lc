/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        auto temps = vector<Node*>{};
        auto curr = head;
        while (curr) {
            if (curr->child) {
                temps.push_back(curr->next); // could push back a null here!
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            if (!curr->next) {
                if (size(temps)) {
                    auto temp = temps.back();
                    temps.pop_back();
                    curr->next = temp;
                    if (temp)
                        temp->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
