#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

namespace
{
    bool sum(string &temp)
    {
        if (temp.find("MAS") != string::npos)
            return true;
        return false;
    }

    void count(vector<vector<char>> const &matrix, int &answer, int x, int y)
    {
        string one, two;
        bool oneIsMas = false, twoIsMas = false;

        one += matrix[x - 1][y - 1];
        one += matrix[x][y];
        one += matrix[x + 1][y + 1];
        if (sum(one))
            oneIsMas = true;
        ranges::reverse(one);
        if (sum(one))
            oneIsMas = true;

        two += matrix[x - 1][y + 1];
        two += matrix[x][y];
        two += matrix[x + 1][y - 1];
        if (sum(two))
            twoIsMas = true;
        ranges::reverse(two);
        if (sum(two))
            twoIsMas = true;

        if (oneIsMas && twoIsMas)
            answer++;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int xy = 140, a = xy, index = 0, answer = 0;
    vector<vector<char>> matrix(xy);

    while (a--)
    {
        string temp;
        cin >> temp;
        for (const auto &el : temp)
            matrix[index].push_back(el);
        index++;
    }

    // The nested for loop generates the starting positions for the crosses:
    // XY >= 1, XY <= xy - 1
    for (int x = 1; x < xy - 1; x++)
        for (int y = 1; y < xy - 1; y++)
            count(matrix, answer, x, y);

    cout << answer << "\n";

    return 0;
}
