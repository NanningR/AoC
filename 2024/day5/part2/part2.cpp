#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

namespace
{
    pair<int, int> getFirstAndSecond(const string &order)
    {
        int firstInt = stoi(order.substr(0, 2));
        int secondInt = stoi(order.substr(3, 2));
        return {firstInt, secondInt};
    }

    void formatNumbers(vector<int> &numbers, vector<string> const &orders, bool &wasValid)
    {
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            bool changeOccurred = false;
            for (auto const &order : orders)
            {
                pair<int, int> _pair = getFirstAndSecond(order);
                if (numbers[i] == _pair.second && numbers[i + 1] == _pair.first)
                {
                    wasValid = false;
                    changeOccurred = true;
                    swap(numbers[i], numbers[i + 1]);
                }
            }
            if (changeOccurred)
                i = 0;
        }
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
            string temp;
            vector<int> numbers;
            stringstream ss(el);
            while (getline(ss, temp, ','))
                numbers.push_back(stoi(temp));

            bool wasValid = true;

            // we can just swap invalid numbers[i] with numbers [i + 1] until no change anymore
            formatNumbers(numbers, orders, wasValid);
            // second iteration for good measure (and required, don't know why)
            formatNumbers(numbers, orders, wasValid);

            if (!wasValid)
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
    cout << answer << "\n";

    return 0;
}
