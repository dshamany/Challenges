#include <iostream>
#include <string>

using std::string;

// Here we are trying to reverse the initial string
// No extra memory should be required
void reverseString(string &str, int edge_pos = 0)
{
    if (edge_pos == str.size() / 2)
        return;

    // lets perform a swap on the edges
    auto c = *(str.end() - 1 - edge_pos);
    *(str.end() - 1 - edge_pos) = *(str.begin() + edge_pos);
    *(str.begin() + edge_pos) = c;

    // call function recursively
    reverseString(str, edge_pos + 1);
}

int main(int argc, const char *argv[])
{
    // Take input from user through inline arguments
    string s = (argc > 1) ? argv[1] : "tnemugrA dilavnI";

    (argc > 1) && std::cout << s << std::endl;

    reverseString(s);

    std::cout << s << std::endl;

    return 0;
}
