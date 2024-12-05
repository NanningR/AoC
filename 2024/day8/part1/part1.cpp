#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

namespace
{
    bool nodeValid(vector<vector<char>> const &matrix, pair<int, int> const &node, char const &activeAntenna)
    {
        bool positionTaken = true;
        bool positionValid = (node.first >= 0 && node.first < matrix.size()) && (node.second >= 0 && node.second < matrix.size());

        if (positionValid)
            positionTaken = matrix[node.first][node.second] == activeAntenna;
        return positionValid && !positionTaken;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 50, index = 0;

    vector<vector<char>> matrix(n);
    set<pair<int, int>> anti_nodes;
    set<char> antennas;

    while (n--)
    {
        string input;
        cin >> input;
        for (const auto &ch : input)
            matrix[index].push_back(ch);

        index++;
    }

    for (const auto &vec : matrix)
        for (const auto &ch : vec)
            if (ch != '.')
                antennas.insert(ch);

    for (const auto &antenna : antennas)
    {
        set<pair<int, int>> locations;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                pair location = {i, j};
                if (matrix[i][j] == antenna)
                    locations.insert(location);
            }
        }

        for (int i = 0; i < locations.size() - 1; i++)
        {
            for (int j = i + 1; j < locations.size(); j++)
            {
                set<pair<int, int>>::iterator it1 = locations.begin();
                set<pair<int, int>>::iterator it2 = locations.begin();
                advance(it1, i);
                advance(it2, j);

                const auto &loc1 = *it1;
                const auto &loc2 = *it2;

                pair difYX = {abs(loc1.first - loc2.first), abs(loc1.second - loc2.second)};
                int node1X = loc1.second > loc2.second ? loc1.second + difYX.second : loc1.second - difYX.second;
                int node2X = loc1.second > loc2.second ? loc2.second - difYX.second : loc2.second + difYX.second;
                pair node1 = {loc1.first - difYX.first, node1X};
                pair node2 = {loc2.first + difYX.first, node2X};

                if (nodeValid(matrix, node1, antenna))
                    anti_nodes.insert(node1);
                if (nodeValid(matrix, node2, antenna))
                    anti_nodes.insert(node2);
            }
        }
    }

    cout << anti_nodes.size() << "\n";

    return 0;
}
