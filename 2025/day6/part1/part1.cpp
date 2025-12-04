#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 5, input_size = n - 1;
    ll answer = 0, index = 0;

    stringstream ss;
    vector<char> operations;
    vector<vector<int>> inputs(input_size);

    while (n--)
    {
        string input;
        getline(cin, input);
        if (!isdigit(input[0]) && input[0] != ' ')
        {
            input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
            for (const auto &ch : input)
            {
                operations.push_back(ch);
            }
        }
        else
        {
            stringstream ss(input);
            string temp;
            while (getline(ss, temp, ' '))
            {
                if (temp.size() > 0)
                {
                    inputs[index].push_back(stoi(temp));
                }
            }
            index++;
        }
    }

    for (int i = 0; i < inputs[0].size(); i++)
    {
        ll temp = 0;
        char op = operations[i];
        for (int j = 0; j < inputs.size(); j++)
        {
            ll temp2 = inputs[j][i];
            if (temp == 0)
                temp = temp2;
            else if (op == '*')
                temp *= temp2;
            else if (op == '+')
                temp += temp2;
        }

        answer += temp;
    }

    cout << answer << endl;

    return 0;
}