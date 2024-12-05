#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

namespace
{
    pair<int, int> getFirstAndSecond(const string &order)
    {
        int firstInt = stoi(order.substr(0, 2));
        int secondInt = stoi(order.substr(3, 2));
        return {firstInt, secondInt};
    }

    void countValidRows(vector<string> const &input, int &answer)
    {
        int startIndex = 0;
        for (int i = 0; i < input.size(); i++)
            if (!isdigit(input[i][0]))
                startIndex = i + 1;

        vector orders(input.begin(), input.begin() + (startIndex - 1));
        vector cases(input.begin() + startIndex, input.end());

        for (auto const &el : cases)
        {
            bool isValid = true;

            string temp;
            vector<int> numbers;
            stringstream ss(el);
            while (getline(ss, temp, ','))
                numbers.push_back(stoi(temp));

            for (int i = 0; i < numbers.size() - 1; i++)
            {
                for (auto const &order : orders)
                {
                    auto orderPair = getFirstAndSecond(order);
                    if (numbers[i] == orderPair.second && numbers[i + 1] == orderPair.first)
                        isValid = false;
                }
            }

            if (isValid)
                answer += numbers[floor(numbers.size() / 2)];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1377, answer = 0;
    vector<string> input, updateRows;
    vector<int> printOrder;

    while (n--)
    {
        string s;
        getline(cin, s);
        input.push_back(s);
    }

    countValidRows(input, answer);
    cout << answer << endl;

    return 0;
}
