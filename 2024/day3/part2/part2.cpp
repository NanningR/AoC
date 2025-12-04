#include <iostream>
#include <regex>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long long;

size_t find_last_occurrence(const string &str, const string &sub, size_t before_pos)
{
    size_t last_pos = string::npos;
    size_t temp_pos = str.find(sub);
    while (temp_pos != string::npos && temp_pos < before_pos)
    {
        last_pos = temp_pos;
        temp_pos = str.find(sub, last_pos + 1);
    }
    return (last_pos == string::npos) ? 0 : last_pos;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int lineCount = 6;
    ll answer = 0;
    smatch match;
    string totalInput;
    vector<string> input;
    regex re(R"(mul\((\d{1,3}),(\d{1,3})\))");

    unordered_map<int, pair<int, int>> iteration_mul_values;
    unordered_map<int, pair<int, int>> iteration_do_dont;

    for (int i = 0; i < lineCount; ++i)
    {
        string line;
        getline(cin, line);
        totalInput += line;
    }

    auto cIt = totalInput.cbegin();
    int iteration = 0;

    while (regex_search(cIt, totalInput.cend(), match, re))
    {
        int first = stoi(match[1].str());
        int second = stoi(match[2].str());

        size_t current_pos = cIt - totalInput.begin();
        size_t last_do_pos = find_last_occurrence(totalInput, "do()", current_pos);
        size_t last_dont_pos = find_last_occurrence(totalInput, "don't()", current_pos);

        iteration_mul_values[iteration] = {first, second};
        if (iteration > 0)
        {
            iteration_do_dont[iteration - 1] = {last_do_pos, last_dont_pos};
        }

        cIt = match.suffix().first;
        ++iteration;
    }

    size_t last_do_pos = find_last_occurrence(totalInput, "do()", totalInput.size());
    size_t last_dont_pos = find_last_occurrence(totalInput, "don't()", totalInput.size());
    iteration_do_dont[iteration - 1] = {last_do_pos, last_dont_pos};

    for (int i = 0; i < iteration; ++i)
    {
        const auto &[first, second] = iteration_mul_values[i];
        const auto &[do_pos, dont_pos] = iteration_do_dont[i];

        if (do_pos > dont_pos || (do_pos == 0 && dont_pos == 0))
        {
            answer += first * second;
        }
    }

    cout << answer << "\n";
    return 0;
}
