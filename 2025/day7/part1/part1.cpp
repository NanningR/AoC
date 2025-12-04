#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using vc = vector<char>;
using pi = pair<int, int>;

void walk_beams(vector<vc> &grid, set<pi> &beam_positions)
{
    set<pi> new_positions;
    char visited = '|';

    for (auto &el : beam_positions)
    {
        for (int i = el.second; i < grid[0].size(); i++)
        {
            for (int j = el.first + 1; j < grid.size(); j++)
            {
                auto &ch = grid[j][i];
                if (ch == '^')
                {
                    pi new_one = {j, i + 1};
                    pi new_two = {j, i - 1};

                    grid[new_one.first][new_one.second] = visited;
                    grid[new_two.first][new_two.second] = visited;

                    if (new_one.first < grid.size())
                    {
                        if (new_one.second < grid[0].size())
                            new_positions.insert(new_one);

                        if (new_two.second >= 0)
                            new_positions.insert(new_two);
                    }
                    break;
                }
                ch = visited;
            }
            break;
        }
    }
    beam_positions = new_positions;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 142;
    int answer = 0, index = 0;

    vector<vc> grid(n);
    set<pi> beam_positions;

    while (n--)
    {
        string temp;
        cin >> temp;

        for (const auto &el : temp)
        {
            if (el == 'S')
                beam_positions.insert({index, static_cast<int>(grid[index].size())});

            grid[index].push_back(el);
        }

        index++;
    }

    bool loop = true;
    while (loop)
    {
        bool all_done = true;
        walk_beams(grid, beam_positions);

        for (const auto &el : beam_positions)
        {
            if (el.first != grid.size() - 1)
            {
                all_done = false;
                break;
            }
        }

        loop = !all_done;
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '^' && grid[i - 1][j] == '|')
                answer++;
        }
    }

    cout << answer << endl;

    return 0;
}