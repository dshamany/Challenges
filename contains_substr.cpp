
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using std::string;
using std::vector;

class Solution
{
public:
    string substr_contains(const string &word, const string &sub_char)
    {
        auto str_cpy = word;

        for (auto &s : sub_char)
        {
            int pos = str_cpy.find(s);
            if (pos != string::npos)
                str_cpy.replace(pos, 1, "*");
            else
                return "";
        }

        int b = str_cpy.find('*');
        int e = str_cpy.rfind('*');

        str_cpy = word.substr(b, e + 1);

        return str_cpy;
    }
    string minWindow(const string &s, const string &t)
    {

        if (t.size() > s.size())
            return "";

        vector<string> words;
        string content = "";

        for (auto it = s.begin(); it != s.end(); it++)
        {
            content = substr_contains(s.substr(it - s.begin()), t);
            if (content != "" && content.size() >= t.size())
                words.push_back(content);
        }

        std::sort(words.begin(), words.end(), [](auto &a, auto &b) {
            return a.size() < b.size();
        });

        for (auto &w : words)
        {
            std::cout << w << "\n";
            if (w.size() >= t.size())
                return w;
        }

        return "";
    }
};

int main(int argc, char const *argv[])
{
    string str, substr;

    std::cout << "Enter a string (no spaces): ";
    std::cin >> str;
    std::cout << "Enter a substring (no spaces): ";
    std::cin >> substr;

    Solution sol;

    std::cout << str << " -> " << sol.minWindow(str, substr) << std::endl;
    return 0;
}
