#include <iostream>
#include <vector>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::vector;

struct Node
{
    Node() : value(-1), left(nullptr), right(nullptr) {}
    Node(const int &_value, Node *_left = nullptr, Node *_right = nullptr)
        : value(_value), left(_left), right(_right) {}
    int value;
    Node *left;
    Node *right;
};

class Heap
{
private:
    Node *root;
    vector<Node *> endNodes;
    size_t size;

public:
    Heap() : root(nullptr) {}
    Heap(Node *node)
    {
        push(node);
    }
    Node *begin() { return root; }
    void push(Node *node)
    {
        if (!root)
        {
            endNodes.push_back(node);
            root = endNodes[0];
            return;
        }
        else
        {
            for (auto &e : endNodes)
            {
                if (!e->left)
                {
                    e->left = node;
                    endNodes.push_back(node);
                    return;
                }
                else if (!e->right)
                {
                    e->right = node;
                    endNodes.push_back(node);
                    return;
                }
            }
        }
    }
    void push(const int &_value)
    {
        push(new Node(_value));
    }
};

class Solution
{
public:
    vector<vector<int>> bfs(Node *root)
    {
        vector<vector<int>> ans = {};
        queue<Node *> q;
        Node *cur = nullptr;

        if (root)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            int size = q.size();
            ans.push_back(vector<int>());

            for (int i = 0; i < size; i++)
            {
                cur = q.front();
                ans.back().push_back(cur->value);
                q.pop();
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;

    Heap *h = new Heap();
    h->push(3);
    h->push(9);
    h->push(77);
    h->push(88);
    h->push(20);
    h->push(15);
    h->push(7);

    auto v = s.bfs(h->begin());

    for (auto &vec : v)
    {
        for (auto &val : vec)
        {
            std::cout << "[" << val << "]";
        }
        puts("");
    }
    puts("");

    return 0;
}
