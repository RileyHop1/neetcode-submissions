/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <list>
#include <unordered_map>
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        list<Node*> graph;
        unordered_map<Node*, Node*> key;

        graph.push_back(node);

        while(!graph.empty()) {
            auto front = graph.front();
            graph.pop_front();

            key[front] = new Node(front->val);

            for (auto& n: front->neighbors) {
                if (key.contains(n)) continue;
                graph.push_back(n);

            }   
        }

        for (auto& n: key) {
            for (auto& i: n.first->neighbors) {
                n.second->neighbors.push_back(key[i]);
            }


        }


        return key[node];
        
    }
};
