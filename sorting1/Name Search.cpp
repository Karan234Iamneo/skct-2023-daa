#include <iostream>
#include <string>
#include <vector>

// Function to perform a linear search for a name in a list of names
int linearSearch(const std::vector<std::string>& names, const std::string& target) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == target) {
            return i;  // Name found, return its index
        }
    }
    return -1;  // Name not found
}

int main() {
    std::vector<std::string> nameList;
    std::string targetName;

    int numNames;
    // std::cout << "Enter the number of names: ";
    std::cin >> numNames;

    // Input names from the user
    for (int i = 0; i < numNames; i++) {
        std::string name;
        // std::cout << "Enter name " << i + 1 << ": ";
        std::cin >> name;
        nameList.push_back(name);
    }

    // std::cout << "Enter a name to search: ";
    std::cin >> targetName;

    int result = linearSearch(nameList, targetName);

    if (result != -1) {
        std::cout << "Name found at index " << result << std::endl;
    } else {
        std::cout << "Name not found in the list." << std::endl;
    }

    return 0;
}
