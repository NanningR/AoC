#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <unordered_map>

using namespace std;
using ll = long long;

namespace
{
    bool nodeValid(vector<vector<char>> const &matrix, pair<int, int> const &node)
    {
        return (node.first >= 0 && node.first < matrix.size()) && (node.second >= 0 && node.second < matrix.size());
    }

    vector<pair<int, int>> transformNodes(pair<int, int> seed1, pair<int, int> seed2, pair<int, int> difYX)
    {
        vector<pair<int, int>> nodes;
        int node1X = seed1.second > seed2.second ? seed1.second + difYX.second : seed1.second - difYX.second;
        int node2X = seed1.second > seed2.second ? seed2.second - difYX.second : seed2.second + difYX.second;
        nodes.emplace_back(seed1.first - difYX.first, node1X);
        nodes.emplace_back(seed2.first + difYX.first, node2X);
        return nodes;
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
    unordered_map<char, int> antennaCount;

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
            {
                antennas.insert(ch);
                antennaCount[ch]++;
            }

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

                pair<int, int> loc1 = *it1;
                pair<int, int> loc2 = *it2;

                pair difYX = {abs(loc1.first - loc2.first), abs(loc1.second - loc2.second)};

                while (true)
                {
                    const auto &pairs = transformNodes(loc1, loc2, difYX);
                    bool temp1Valid = nodeValid(matrix, pairs[0]);
                    bool temp2Valid = nodeValid(matrix, pairs[1]);

                    if (temp1Valid)
                        anti_nodes.insert(pairs[0]);
                    if (temp2Valid)
                        anti_nodes.insert(pairs[1]);
                    if (!temp1Valid && !temp2Valid)
                        break;

                    loc1 = pairs[0];
                    loc2 = pairs[1];
                }
            }
        }

        for (const auto &el : locations)
            if (antennaCount[antenna] > 1)
                anti_nodes.insert(el);
    }

    cout << anti_nodes.size() << "\n";

    return 0;
}
