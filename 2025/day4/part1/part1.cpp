#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using pi = pair<int, int>;
using vc = vector<vector<char>>;

vector<pi> get_positions(pi const &pos)
{
    vector<pi> positions = {
        {pos.first - 1, pos.second},
        {pos.first + 1, pos.second},
        {pos.first, pos.second - 1},
        {pos.first, pos.second + 1},
        {pos.first - 1, pos.second - 1},
        {pos.first + 1, pos.second + 1},
        {pos.first - 1, pos.second + 1},
        {pos.first + 1, pos.second - 1}};

    return positions;
}

bool get_role_can_be_accessed(vc const &grid, pi const &pos, int const &limit)
{
    int count = 0;
    const auto &positions = get_positions(pos);

    for (const auto &pos_to_check : positions)
    {
        if (pos_to_check.first >= 0 && pos_to_check.first < limit && pos_to_check.second >= 0 && pos_to_check.second < limit)
        {
            if (grid[pos_to_check.first][pos_to_check.second] == '@')
                count++;
        }
    }

    return count < 4;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 137;
    int answer = 0;
    vc grid(n);

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            char input;
            cin >> input;
            grid[i].push_back(input);
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] != '@')
                continue;
            const auto valid = get_role_can_be_accessed(grid, {i, j}, n);
            if (valid)
                answer++;
        }
    }

    cout << answer << endl;

    return 0;
}