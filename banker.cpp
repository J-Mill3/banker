// Bankers Algorithm to check for safety
// Jack Miller
// 11/22/2024
// g++ banker.cpp -o banker

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ////////////////////////////////////////////////////////////////////////
    // GETTING INPUT FROM FILE
    ////////////////////////////////////////////////////////////////////////

    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    vector<vector<int>> allocated;
    vector<vector<int>> max;
    vector<int> available;

    string line;
    int section = 0; // 0: Allocation, 1: Max, 2: Available

    while (getline(inputFile, line)) {
        if (line == "Allocation") {
            section = 0;
            continue;
        } else if (line == "Max") {
            section = 1;
            continue;
        } else if (line == "Available") {
            section = 2;
            continue;
        }

        vector<int> row;
        int value;
        istringstream ss(line);

        while (ss >> value) {
            row.push_back(value);
        }

        if (section == 0) {
            allocated.push_back(row);
        } else if (section == 1) {
            max.push_back(row);
        } else if (section == 2) {
            available = row; // Available is a single row vector
        }
    }

    inputFile.close();

    ////////////////////////////////////////////////////////////////////////
    // FINISHED GETTING INPUT
    ////////////////////////////////////////////////////////////////////////

    int n = allocated.size(); // Number of processes
    int m = available.size(); // Number of resources
    int i, j, k;

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; ++k) {
        f[k] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j)
        need[i][j] = max[i][j] - allocated[i][j];
    }

    int y = 0;
    for (k = 0; k < 5; ++k) {
        for (i = 0; i < n; ++i) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; ++j) {
                    if (need[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                ans[ind++] = i;
                for (y = 0; y < m; ++y) available[y] += allocated[i][y];
                f[i] = 1;
                }
            }
        }
    }
    
    int flag = 1;
    
    for(int i = 0; i < n; ++i) {
            if(f[i] == 0) {
            flag = 0;
            cout << "The system is not in a safe state." << endl;
            break;
        }
    }

    if(flag==1) {
        cout << "The safe sequence is: " << endl;
        for (i = 0; i < n - 1; ++i) cout << " P" << ans[i] << ",";
        cout << " P" << ans[n - 1] <<endl;
    }

    return 0;
}
