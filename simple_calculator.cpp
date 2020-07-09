#include <iostream>
#include <vector>
#include <string>
#include "helper/binary_node.h"

using std::string;
using std::vector;

Node<string> *parseString(const string &str);

bool isOperator(const string &c)
{
    if (c == "*" || c == "/" || c == "+" || c == "-")
        return true;
    return false;
}

bool opcmp(const string &op1, const string &op2)
{
    map<string, int> ops = {{"*", 4}, {"/", 3}, {"+", 2}, {"-", 1}};

    return ops[op1] > ops[op2];
}

template <typename T>
void printTree(Node<T> *node, const string &order = "in")
{
    if (order == "pre")
        std::cout << node->value << " ";

    if (node->left)
        printTree(node->left);

    if (order == "in")
        std::cout << node->value << " ";

    if (node->right)
        printTree(node->right);

    if (order == "post")
        std::cout << node->value << " ";
}

int calc(Node<string> *node)
{
    auto value = node->value;

    switch (value[0])
    {
    case '*':
        return calc(node->left) * calc(node->right);
    case '/':
        return calc(node->left) / calc(node->right);
    case '+':
        return calc(node->left) + calc(node->right);
    case '-':
        return calc(node->left) - calc(node->right);
    default:
        return std::stoi(value);
    }

    return -1;
}

Node<string> *convertToBTree(vector<string> &from)
{
    Node<string> *root = nullptr;

    for (auto it = from.begin(); it != from.end(); it++)
    {
        if (!root)
        {
            root = new Node<string>(*it);
        }
        else if (isOperator(*it))
        {
            root = new Node<string>(*it, root);
        }
        else if (*it == "(")
        {
            string str = "";
            while (*it != ")")
            {
                if (*it == "(")
                    it++;

                str += *it;
                it++;
            }
            auto res = parseString(str);
            root->right = res;
        }
        else
        {
            if (!root->left)
            {
                root->left = new Node<string>(*it);
            }
            else if (!root->right)
            {
                root->right = new Node<string>(*it);
            }
        }
    }

    return root;
}

Node<string> *parseString(const string &str)
{
    vector<string> parsed = {};
    string tmp;

    for (auto &c : str)
    {
        if (c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')')
        {
            parsed.push_back(tmp);
            tmp = c;
            parsed.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp += c;
        }
    }

    if (tmp.size())
        parsed.push_back(tmp);

    return convertToBTree(parsed);
}

int main(int argc, char *argv[])
{
    string str = argv[1];

    std::cout << str;

    str.erase(str.find("("), 1);
    str.erase(str.find(")"), 1);

    auto p = parseString(str);

    std::cout << " = " << calc(p) << std::endl;

    return 0;
}
