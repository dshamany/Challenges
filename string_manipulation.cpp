#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
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

string serialized = "[]";

void stringify(Node *root)
{
    if (!root)
        serialized.insert(serialized.rfind("]"), "null");

    if (serialized == "[]")
    {
        serialized.insert(serialized.rfind("]"), std::to_string(root->value));
    }
    else
    {
        serialized.insert(serialized.rfind("]"), ("," + std::to_string(root->value)));
    }

    stringify(root->left);
    stringify(root->right);
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    auto h = new Heap();

    for (auto &n : vec)
    {
        h->push(n);
    }

    stringify(h->begin());

    std::cout << serialized << "\n";
    return 0;
}
