#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1185, index = 0, answer = 0;

    vector<string> inputs;
    vector<pl> ranges;
    vector<ll> numbers_to_check;

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
        ranges.push_back({stoll(input.substr(0, pos)), stoll(input.substr(pos + 1))});
        index++;
    }

    for (int i = index; i < inputs.size(); i++)
    {
        numbers_to_check.push_back(stoll(inputs[i]));
    }

    for (const auto &num : numbers_to_check)
    {
        for (const auto &range : ranges)
        {
            if (num >= range.first && num <= range.second)
            {
                answer++;
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}