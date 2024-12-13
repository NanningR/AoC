#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

namespace
{
    int n = 57, answer = 0;
    const int original = n;
    vector<vector<int>> numbers(original);

    bool trailheadUnique(set<pi> const &foundTrailheads, const pi trailhead)
    {
        return ranges::none_of(foundTrailheads, [&](const auto &el)
                               { return el == trailhead; });
    }

    bool moveAllowed(vector<pi> const &visitedLocations, const pi posOld, const pi posNew)
    {
        bool posAllowed = posNew.first >= 0 && posNew.first < original && posNew.second >= 0 && posNew.second < original;
        bool valueAllowed = false;
        bool visitAllowed = false;

        if (posAllowed)
            valueAllowed = numbers[posNew.first][posNew.second] - numbers[posOld.first][posOld.second] == 1;

        if (ranges::none_of(visitedLocations, [&](const auto &el)
                            { return el == posNew; }))
            visitAllowed = true;

        return posAllowed && valueAllowed && visitAllowed;
    }

    void findRoutes(set<pi> &foundTrailheads, vector<pi> &visitedLocations, const pi previous)
    {
        if (numbers[previous.first][previous.second] == 9)
        {
            if (trailheadUnique(foundTrailheads, previous))
            {
                answer++;
                foundTrailheads.insert(previous);
            }
            return;
        }

        vector<pi> moves = {
            {previous.first, previous.second + 1},
            {previous.first, previous.second - 1},
            {previous.first + 1, previous.second},
            {previous.first - 1, previous.second}};

        for (const auto &el : moves)
        {
            if (moveAllowed(visitedLocations, previous, el))
            {
                visitedLocations.push_back(el);
                findRoutes(foundTrailheads, visitedLocations, el);
                visitedLocations.pop_back();
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int index = 0;
    set<pi> trailheads;

    while (n--)
    {
        string temp;
        cin >> temp;
        for (auto &ch : temp)
            numbers[index].push_back(ch - '0');

        index++;
    }

    for (int i = 0; i < numbers.size(); i++)
        for (int j = 0; j < numbers.size(); j++)
            if (numbers[i][j] == 0)
                trailheads.insert({i, j});

    for (const auto &el : trailheads)
    {
        vector<pi> visitedLocations;
        set<pi> foundTrailheads;
        // traverse all paths with recursive backtracking
        findRoutes(foundTrailheads, visitedLocations, el);
    }

    cout << answer << "\n";

    return 0;
}