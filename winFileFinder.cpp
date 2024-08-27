#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>
#include <system_error>

namespace fs = std::filesystem;

// Function to convert a string to lowercase
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to search for files based on the search criteria
void searchFiles(const fs::path& root, const std::string& searchTerm, std::vector<fs::path>& foundFiles, int searchOption) {
    std::string lowerSearchTerm = toLowerCase(searchTerm);
    try {
        for (const auto& entry : fs::recursive_directory_iterator(root, fs::directory_options::skip_permission_denied)) {
            try {
                if (fs::is_regular_file(entry.status())) {
                    std::string lowerFilename = toLowerCase(entry.path().filename().string());
                    switch (searchOption) {
                        case 1: // Search by exact filename (case-insensitive)
                            if (lowerFilename == lowerSearchTerm) {
                                foundFiles.push_back(entry.path());
                            }
                            break;
                        case 2: // Search by file extension only
                            if (entry.path().extension() == searchTerm) {
                                foundFiles.push_back(entry.path());
                            }
                            break;
                        case 3: // Search by partial filename (case-insensitive)
                            if (lowerFilename.find(lowerSearchTerm) != std::string::npos) {
                                foundFiles.push_back(entry.path());
                            }
                            break;
                        default:
                            std::cerr << "Invalid search option.\n";
                            return;
                    }
                }
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Error accessing file " << entry.path() << ": " << e.what() << std::endl;
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing " << root << ": " << e.what() << std::endl;
    }
}

// Function to display found files
void displayFoundFiles(const std::vector<fs::path>& foundFiles) {
    std::cout << "\nFound " << foundFiles.size() << " file(s):\n";
    for (const auto& path : foundFiles) {
        std::cout << path << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    while (true) {
        std::cout << "\n========== File Search Menu ==========\n";
        std::cout << "1. Search by exact filename (case-insensitive)\n";
        std::cout << "2. Search by file extension (e.g., .txt)\n";
        std::cout << "3. Search by partial filename (case-insensitive)\n";
        std::cout << "4. Exit\n";
        std::cout << "=======================================\n";
        std::cout << "Enter your choice: ";
        
        int choice;
        std::cin >> choice;

        if (choice < 1 || choice > 4) {
            std::cerr << "Invalid option. Please try again.\n";
            continue;
        }

        if (choice == 4) {
            std::cout << "Exiting the program.\n";
            break;
        }

        std::string searchTerm;
        std::cout << "Enter the search term: ";
        std::cin.ignore(); // To clear the newline character left in the buffer
        std::getline(std::cin, searchTerm); // Use getline to allow spaces in search term

        std::vector<fs::path> foundFiles;
        fs::path rootPath = "C:\\";

        std::cout << "\nSearching for \"" << searchTerm 
                  << "\" under " << rootPath << "...\n";

        searchFiles(rootPath, searchTerm, foundFiles, choice);

        if (foundFiles.empty()) {
            std::cout << "\nNo files found matching the search criteria.\n";
        } else {
            displayFoundFiles(foundFiles);
        }
    }

    return 0;
}




