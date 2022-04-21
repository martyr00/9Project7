#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

string split (const string &s)
{
    regex trim_regexp ("^ {1,}| {1,}$");
    regex double_space_regexp (" {2,}");

    string trimmed_str = regex_replace(s, trim_regexp, "");
    string prepared_str = regex_replace(trimmed_str, double_space_regexp, " ");

    return prepared_str;
}

vector<string> to_vector(const string& line)
{

    string temp = split(line);
    regex space_between{" "};
    vector<string> strPairs{
            sregex_token_iterator(temp.begin(), temp.end(), space_between, -1),
            sregex_token_iterator()
    };

    return strPairs;
}

int sum(vector<string> strPairs, int number_of_line, int result)
{
    for(int i = 0; i < strPairs.size(); i++)
    {
        if (strPairs.size() - number_of_line == i) {
            break;
        }

        // cout << strPairs[i] << " ";

        result += std::stoi( strPairs[i] );
    }

    // cout << endl;

    return result;
}

int main()
{
    ifstream fin("z32.txt");

    int number_of_line = 0;
    int result = 0;

    for (string line; getline(fin, line); )
    {
        vector<string> strPairs = to_vector(line);

        result = sum(strPairs, number_of_line, result);

        number_of_line++;
    }

    cout << "The sum of numbers: " << result;
    fin.close();
}
