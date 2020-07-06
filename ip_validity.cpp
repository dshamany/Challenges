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
    string validIPAddress(const string &IP)
    {
        return "";
    }
};

int main(int argc, char const *argv[])
{
    string IP = "sFS::fdsf::fsdfs::0000::fsdfs::0000::sfdsfds";
    string IPv4 = "123.123.123.123";
    string rplce = "0000";

    std::cout << IP << " ->  ";

    while (IP.find(rplce) != string::npos)
    {
        IP.replace(IP.find(rplce), rplce.size(), "0");
    }

    std::cout << IP << std::endl;

    puts("Split Here");

    Solution sol;
    auto v = sol.splitString(IP, "::");

    // std::cout << v.size() << "\n";

    for (auto &e : v)
    {
        std::cout << e << ' ';
    }
    puts("");

    return 0;
}
