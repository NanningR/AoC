#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 850;
    ll answer = 0;
    vector<string> inputs;

    while (n--)
    {
        string s;
        getline(cin, s);
        inputs.push_back(s);
    }

    for (auto const &input : inputs)
    {
        bool valid = false;

        ll testValue;
        vector<int> numbers;
        string temp, temp2;

        for (auto const &el : input)
        {
            if (isdigit(el))
                temp += el;
            else
                break;
        }

        testValue = stoll(temp);
        temp = input.substr(temp.size() + 2);

        stringstream ss(temp);
        while (getline(ss, temp2, ' '))
            numbers.push_back(stoi(temp2));

        vector<vector<char>> operators;
        size_t operatorCount = numbers.size() - 1;
        ll possibleCombinations = pow(2, operatorCount);

        // fill the vectors with all possible combinations using bit shifts
        for (ll i = 0; i < possibleCombinations; i++)
        {
            vector<char> current(operatorCount);
            for (int j = 0; j < operatorCount; j++)
            {
                if (i & (1LL << j))
                    current[j] = '*';
                else
                    current[j] = '+';
            }
            operators.push_back(current);
        }

        while (true)
        {
            for (const auto &op : operators)
            {
                ll tempCalc = numbers[0];

                for (int i = 1; i < numbers.size(); i++)
                {
                    int num = numbers[i];
                    if (op[i - 1] == '*')
                        tempCalc *= num;
                    else
                        tempCalc += num;
                }

                if (tempCalc == testValue)
                {
                    valid = true;
                    break;
                }
            }
            break;
        }

        if (valid)
            answer += testValue;
    }

    cout << answer << "\n";

    return 0;
}