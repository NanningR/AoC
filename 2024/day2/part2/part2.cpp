#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

namespace
{
    bool isSafe(vector<int> &numbers)
    {
        bool allIncreasing = true, allDecreasing = true, adjacentAllowed = true;
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] <= numbers[i + 1])
                allDecreasing = false;
            if (numbers[i] >= numbers[i + 1])
                allIncreasing = false;
            int dif = abs(numbers[i] - numbers[i + 1]);
            if (dif <= 0 || dif >= 4)
                adjacentAllowed = false;
        }
        return (allDecreasing || allIncreasing) && adjacentAllowed;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1000;
    int answer = 0;

    while (n--)
    {
        string s;
        getline(cin, s);

        string temp;
        stringstream ss(s);
        vector<int> numbers;
        char delimiter = ' ';

        while (getline(ss, temp, delimiter))
            numbers.push_back(stoi(temp));
        bool safe = isSafe(numbers);
        if (safe)
            answer++;

        else
        {
            for (int i = 0; i < numbers.size(); i++)
            {
                vector<int> numCopy = numbers;
                numCopy.erase(numCopy.begin() + i);
                if (isSafe(numCopy))
                {
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;
}