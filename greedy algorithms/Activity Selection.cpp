#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Match {
    std::string name;
    int stime;
    int ftime;
};

// Comparator function to sort activities by finish time
bool compareByFinishTime(const Match &a, const Match &b) {
    return a.ftime < b.ftime;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Match> matches(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> matches[i].name >> matches[i].stime >> matches[i].ftime;
    }

    // Sort activities by finish time
    std::sort(matches.begin(), matches.end(), compareByFinishTime);

    std::cout << "Selected Activities are:\n";
    std::cout << matches[0].name << " ";
    int lastSelectedIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (matches[i].stime >= matches[lastSelectedIndex].ftime) {
            std::cout << matches[i].name << " ";
            lastSelectedIndex = i;
        }
    }

    return 0;
}
