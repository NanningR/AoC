/* GIVES WRONG ANSWER
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

void build_ranges(vector<pl> const &original_ranges, vector<pl> &merged_ranges)
{
    for (const auto original : original_ranges)
    {
        if (merged_ranges.size() < 1)
        {
            merged_ranges.push_back(original);
            continue;
        }

        bool new_insert = true;

        for (auto &merged : merged_ranges)
        {
            bool modified = false;
            bool extend_left = original.first < merged.first && original.second > merged.first;
            bool extend_right = original.second > merged.second && original.first < merged.second;

            if (extend_left)
            {
                merged.first = original.first;
                modified = true;
                new_insert = false;
            }

            if (extend_right)
            {
                merged.second = original.second;
                modified = true;
                new_insert = false;
            }

            if (original.first <= merged.first && original.second >= merged.second)
            {
                merged.first = original.first;
                merged.second = original.second;
                modified = true;
                new_insert = false;
            }

            if (original.first >= merged.first && original.second <= merged.second)
            {
                new_insert = false;
                break;
            }

            if (modified)
                break;
        }
        if (new_insert)
            merged_ranges.push_back(original);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 185;
    // 344378119285362 = not right?
    // int n = 4;

    ll answer = 0;
    vector<string> inputs;
    vector<pl> original_ranges, merged_ranges;

    while (n--)
    {
        string temp;
        cin >> temp;
        inputs.push_back(temp);
    }

    for (const auto &input : inputs)
    {
        char del = '-';
        const auto pos = input.find('-');
        if (pos == string::npos)
            break;
        original_ranges.push_back({stoll(input.substr(0, pos)), stoll(input.substr(pos + 1))});
    }

    sort(original_ranges.begin(), original_ranges.end());
    build_ranges(original_ranges, merged_ranges);
    sort(merged_ranges.begin(), merged_ranges.end());

    for (const auto &el : merged_ranges)
        answer += (el.second - el.first) + 1;

    cout << answer << endl;

    return 0;
}
*/