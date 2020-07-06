#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Solution
{
public:
    string contains_substr(const string &word, const string &sub_char)
    {
        auto str_cpy = word;

        for (auto &s : sub_char)
        {
            int pos = str_cpy.find(s);
            if (pos >= 0)
                str_cpy.replace(pos, 1, "*");
            else
            {
                return "";
            }
        }

        int b = str_cpy.find('*');
        int e = str_cpy.rfind('*');

        str_cpy = ""; // reuse variable;

        for (int i = b; i <= e; i++)
        {
            str_cpy += word[i];
        }

        return str_cpy;
    }
    string minWindow(string s, string t)
    {

        if (t.size() > s.size())
            return "";

        vector<string> words;
        int s_pos = 0;

        for (auto it = s.begin(); it != s.end(); it++, s_pos++)
        {
            words.push_back(contains_substr(s.substr(s_pos), t));
        }

        std::sort(words.begin(), words.end(), [](auto &a, auto &b) {
            return a.size() < b.size();
        });

        std::remove_if(words.begin(), words.end(), [=](auto &word) {
            return word.size() < t.size() || !word.size();
        });

        return words[0];
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
