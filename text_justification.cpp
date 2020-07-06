#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector; 
using std::string;

class Solution {
public:
    vector<string> fit_sentences_to_width (vector<string>& words, int max_width, char separator = ' ');
    void fit_to_width(string& str, int max_width, char separator = ' ');
    void last_line_padding(string& str, int max_width, char separator = ' ');
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> sentences = fit_sentences_to_width(words, maxWidth);

        return sentences;
    }
};

vector<string> Solution::fit_sentences_to_width(vector<string>& words, int max_width, char separator){
    vector<string> result;

    string str = "";
    int str_len = 0;

    for (auto& word : words){

        if (word.size() > max_width){
            result.push_back(str);
            str = "";
            string sub = "";
            int data_saved = 0;

            while (data_saved < word.size()){
                sub = word.substr(data_saved, max_width-1);
                if ((max_width + data_saved < word.size()-1) && (sub.back() != '-')){
                    sub += '-';
                }
                data_saved += max_width-1;
                result.push_back(sub);
                sub = "";
            }
            continue;
        }
        
        if (str_len == 0){
            str = word;
        } else if (str_len+word.size()+1 <= max_width){
            str += (separator + word);
        } else if (str_len+word.size()+1 > max_width){
            fit_to_width(str, max_width);
            result.push_back(str);
            str = word;
        }
        str_len = str.size();
    }

    last_line_padding(str, max_width, separator);
    result.push_back(str);
    return result;
}


void Solution::fit_to_width(string& str, int max_width, char separator){

    while (str[str.size()-1] == separator){
        str.pop_back();
    }

    int pos = str.find(separator);
    int last_pos = 0;
    int spaces_remain = max_width - str.size();

    while (pos < str.size() && spaces_remain){
        if (str[pos] == separator)
            str.insert(pos, 1, separator);
        while(str[pos] == separator){
            pos++;
        }
        last_pos = ++pos;
        pos = str.find(separator, last_pos);
        spaces_remain = max_width - str.size();

        if (spaces_remain && pos == -1) pos = 0;
    }
}

void Solution::last_line_padding(string& str, int max_width, char separator){
    while (str.size() < max_width){
        str += separator;
    }
}

int main(){
    const int max_width = 10;
    vector<string> words = {"This", "is", "an", "example", "of", "a", "text", "justification.", "With", "one", "long", "word", "in", "it.", "Livingonthecoastofafrica."};

    Solution ob;
    auto sentences = ob.fullJustify(words, max_width);

    string top_bottom(max_width, '-');
    std::cout << "+-" << top_bottom << "-+" << std::endl;
    for (auto& sentence : sentences){
        if (sentence.size() < max_width) ob.last_line_padding(sentence, max_width);        
        std::cout << "| " << sentence << " |" << std::endl;
    }
    std::cout << "+-" << top_bottom << "-+" << std::endl;

    return 0;
}