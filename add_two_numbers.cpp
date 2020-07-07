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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sum = nullptr;

        auto f = l1;
        auto s = l2;

        int rem = 0;
        int n = 0;

        while (f || s)
        {
            int fval = f ? f->val : 0;
            int sval = s ? s->val : 0;

            n = (fval + sval) + rem;

            if (n >= 10)
            {
                n -= 10;
                rem = 1;
            }
            else
            {
                rem = 0;
            }

            if (!sum)
            {
                sum = new ListNode(n, nullptr);
            }
            else
            {
                auto sum_ptr = sum;
                while (sum_ptr && sum_ptr->next)
                {
                    sum_ptr = sum_ptr->next;
                }
                sum_ptr->next = new ListNode(n, nullptr);
            }

            f = f && f->next ? f->next : nullptr;
            s = s && s->next ? s->next : nullptr;
        }

        if (rem)
        {
            auto sum_ptr = sum;
            while (sum_ptr && sum_ptr->next)
            {
                sum_ptr = sum_ptr->next;
            }
            sum_ptr->next = new ListNode(rem, nullptr);
        }

        return sum;
    }
};

// Helper Function
ListNode *populateList(vector<int> nums)
{
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
    vector<int> v1 = {5, 3, 3};
    vector<int> v2 = {5, 2, 3};

    // create sample list
    ListNode *list1 = populateList(v1);
    ListNode *list2 = populateList(v2);

    auto list = sol.addTwoNumbers(list1, list2);

    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "Merging: " << v1[i] << " + " << v2[i] << "\n";
    }

    while (list)
    {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << "\n";
    return 0;
}
