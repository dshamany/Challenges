#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        auto begin = l1;
        auto f = l1;
        auto s = l2;

        while (s)
        {
            auto node = new ListNode(s->val, begin);
            begin = node;
            f = begin;

            while (f->next)
            {
                if (f->val > f->next->val)
                {
                    auto v = f->val;
                    f->val = f->next->val;
                    f->next->val = v;
                }
                f = f->next;
            }
            s = s->next;
        }

        return begin;
    }
};

// Helper Function
ListNode *populateList(vector<int> nums)
{
    // sort nums in reverse to have ordered list
    std::sort(nums.rbegin(), nums.rend());

    ListNode *root = nullptr;

    for (auto &n : nums)
    {
        auto node = new ListNode(n, root);
        root = node;
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Solution sol;

    // SAMPLE DATA
    vector<int> v1 = {4, 3, 6, 2, 7, 1, 1};
    vector<int> v2 = {5, 2, 7, 9, 6, 0, 3};

    // create sample list
    ListNode *list1 = populateList(v1);
    ListNode *list2 = populateList(v2);

    auto list = sol.mergeTwoLists(list1, list2);

    while (list)
    {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << "\n";

    return 0;
}
