#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 200;
    int answer = 0;

    while (n--)
    {
        string input;
        cin >> input;
        int split_index = 0, highest = 0, second_highest = 0;

        for (int i = 0; i < input.size(); i++)
        {
            int temp = input[i] - '0';
            if (temp > highest && i != input.size() - 1)
            {
                highest = temp;
                split_index = i + 1;
            }
        }
        for (int i = split_index; i < input.size(); i++)
        {
            int temp = input[i] - '0';
            if (temp > second_highest)
                second_highest = temp;
        }

        answer += stoi(to_string(highest) + to_string(second_highest));
    }

    cout << answer << endl;

    return 0;
}