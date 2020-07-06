#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    vector<string> splitString(const string &str, const string &delimiter = " ")
    {
        vector<string> result = {};
        string tmp = "";
        int begin = 0;
        int end = 0;
        int found = 0;

        while (found != string::npos)
        {
            found = str.find(delimiter, begin);      // this is required for some strange reason
            end = (found >= 0) ? found : str.size(); // handle -1 and set it to str.size()
            tmp = str.substr(begin, end - begin);
            result.push_back(tmp);
            begin += (tmp.size() + delimiter.size());
        }
        return result;
    }
    bool isIPv4(const string &address)
    {
        auto v = splitString(address, ".");

        if (v.size() != 4)
            return false;

        for (auto &e : v)
        {
            if (e[0] == '0' && e.size() > 1)
                return false;

            string tmp = "";

            for (auto &c : e)
            {
                if (isdigit(c))
                {
                    tmp += c;
                }
                else
                {
                    return false;
                }
            }

            int n = 0;

            if (tmp == "")
            {
                return false;
            }
            else
            {
                n = stoi(tmp); // convert tmp to digit
            }

            tmp = "";

            if (n > 255 || n < 0)
                return false;
        }

        return true;
    }
    bool isIPv6(const string &address)
    {

        const char hex[22] = "123456789ABCDEFabcdef";

        auto v = splitString(address, ":");

        if (v.size() != 8)
        {
            return false;
        }

        for (auto &e : v)
        {
            if (e.size() > 4 || e.size() < 1)
                return false;

            for (auto &c : e)
            {
                if (!isxdigit(c))
                    return false;
            }
        }

        return true;
    }
    string validIPAddress(const string &IP)
    {
        if (IP.find(".") != string::npos)
        {
            if (isIPv4(IP))
                return "IPv4";
        }

        if (IP.find(":") != string::npos)
        {
            if (isIPv6(IP))
                return "IPv6";
        }
        return "Neither";
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    std::cout << sol.validIPAddress(argv[1]) << std::endl;

    return 0;
}
