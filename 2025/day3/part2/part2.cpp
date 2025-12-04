#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 200;

    ll answer = 0;
    vector<ll> results;

    while (n--)
    {
        string input;
        cin >> input;

        set<int> order;
        vector<int> number_construct;

        int string_size = input.size();
        int to_go = 12, split_index = 0, split_temp = 0;

        while (true)
        {
            int highest = 0;
            for (int i = split_index; i <= input.size() - to_go; i++)
            {
                int temp = input[i] - '0';
                if (temp > highest)
                {
                    highest = temp;
                    split_temp = i + 1;
                }
            }

            to_go--;
            split_index = split_temp;
            number_construct.push_back(highest);

            if (number_construct.size() == 12)
                break;
        }

        string temp = "";
        for (const auto &el : number_construct)
        {
            temp += to_string(el);
        }

        results.push_back(stoll(temp));
    }

    for (const auto &el : results)
    {
        answer += el;
    }

    cout << answer << endl;

    return 0;
}