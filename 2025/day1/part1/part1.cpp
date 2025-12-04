#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 4462;
    // int n = 10;
    int count = 50;
    int answer = 0;

    while (n--)
    {
        string temp;
        cin >> temp;

        int rotation = stoi(temp.substr(1)) % 100;
        temp[0] == 'L' ? count -= rotation : count += rotation;

        int dif = (count - 100) % 100;
        if (dif < 0)
            dif *= -1;

        if (count < 0)
            count = 100 - dif;
        else if (count > 99)
            count = 0 + dif;

        if (count == 0)
            answer++;
    }

    cout << answer << endl;

    return 0;
}