#include <iostream>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int lineCount = 6;

    ll answer = 0;
    smatch match;
    string totalInput;
    vector<string> input;
    regex re(R"(mul\((\d{1,3}),(\d{1,3})\))");

    while (lineCount--)
    {
        string s;
        getline(cin, s);
        input.push_back(s);
    }

    for (const auto &el : input)
        totalInput += el;

    auto it = totalInput.cbegin();
    while (regex_search(it, totalInput.cend(), match, re))
    {
        int first = stoi(match[1].str());
        int second = stoi(match[2].str());
        answer += first * second;
        it = match.suffix().first;
    }

    cout << answer << "\n";

    return 0;
}
