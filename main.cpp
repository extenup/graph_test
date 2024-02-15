// Unsafe code because index out of range is not checked

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool CalcPath(const vector<vector<int>>& graph, vector<int>& path)
{
    path.push_back(graph[0][0]);

    for (int row = 0, col = 0; row < graph.size() - 1; row++)
    {
        int t = graph[row][col];
        int l = graph[row + 1][col];
        int r = graph[row + 1][col + 1];

        if ((t % 2 == 0 && l % 2 != 0 && r % 2 != 0) ||
            (t % 2 != 0 && l % 2 == 0 && r % 2 == 0))
        {
            if (r > l)
            {
                col++;
                path.push_back(r);
            }
            else
            {
                path.push_back(l);
            }
        }
        else
        if ((t % 2 == 0 && l % 2 != 0) ||
            (t % 2 != 0 && l % 2 == 0))
        {
            path.push_back(l);
        }
        else
        if ((t % 2 == 0 && r % 2 != 0) ||
            (t % 2 != 0 && r % 2 == 0))
        {
            col++;
            path.push_back(r);
        }
        else
        {
            cout << "ERROR. Incorrect input data" << endl;
            return false;
        }
    }

    return true;
}

void PrintResult(const vector<int>& path)
{
    int maxSum = 0;
    string spath = "";
    for (int i = 0; i < path.size(); i++)
    {
        maxSum += path[i];
        spath += to_string(path[i]) + ((i + 1 < path.size()) ? ", " : "");
    }
    cout << "Max sum: " << maxSum << endl;
    cout << "Path: " << spath << endl;
}

int main()
{
    const vector<vector<int>> graph = {{ 215 },
                                       { 192, 124 },
                                       { 117, 269, 442 },
                                       { 218, 836, 347, 235 },
                                       { 320, 805, 522, 417, 345 },
                                       { 229, 601, 728, 835, 133, 124 },
                                       { 248, 202, 277, 433, 207, 263, 257 },
                                       { 359, 464, 504, 528, 516, 716, 871, 182 },
                                       { 461, 441, 426, 656, 863, 560, 380, 171, 923 },
                                       { 381, 348, 573, 533, 448, 632, 387, 176, 975, 449 },
                                       { 223, 711, 445, 645, 245, 543, 931, 532, 937, 541, 444 },
                                       { 330, 131, 333, 928, 376, 733, 017, 778, 839, 168, 197, 197 },
                                       { 131, 171, 522, 137, 217, 224, 291, 413, 528, 520, 227, 229, 928 },
                                       { 223, 626, 034, 683, 839, 052, 627, 310, 713, 999, 629, 817, 410, 121 },
                                       { 924, 622, 911, 233, 325, 139, 721, 218, 253, 223, 107, 233, 230, 124, 233 }};

    vector<int> path;
    bool ok = CalcPath(graph, path);

    if (ok)
    {
        PrintResult(path);
    }
    else
    {
        cout << "ERROR is occured";
    }

    return 0;
}
