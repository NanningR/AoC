#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

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
        vector<int> numbers;
        stringstream ss(s);

        char delimiter = ' ';
        while (getline(ss, temp, delimiter))
            numbers.push_back(stoi(temp));

        bool allInc = true, allDec = true, adjacentAllowed = true;

        for (int i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] <= numbers[i + 1])
                allDec = false;
            if (numbers[i] >= numbers[i + 1])
                allInc = false;
            int low = min(numbers[i], numbers[i + 1]);
            int high = max(numbers[i], numbers[i + 1]);
            if (high - low <= 0 || high - low >= 4)
                adjacentAllowed = false;
        }

        const bool safe = (allDec || allInc) && adjacentAllowed;
        if (safe)
            answer++;
    }

    cout << answer << "\n";

    return 0;
}