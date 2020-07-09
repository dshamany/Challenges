
template <typename T>
struct Node
{
    T value;
    Node *left;
    Node *right;
    Node() : value(0), left(nullptr), right(nullptr) {}
    Node(T val, Node *l = nullptr, Node *r = nullptr) : value(val), left(l), right(r) {}
    Node *operator=(T val)
    {
        value = val;
        return this;
    }
};