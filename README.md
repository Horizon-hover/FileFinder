# FileFinder

# File Search Program

This C++ program allows users to search for files on their Windows system based on different search criteria, such as exact filename, file extension, or partial filename. The program is built using the C++17 filesystem library and provides a simple menu-driven interface for users.

## Features

- **Search by Exact Filename**: Case-insensitive search for files with an exact name match.
- **Search by File Extension**: Find files based on their extension (e.g., `.txt`, `.cpp`).
- **Search by Partial Filename**: Case-insensitive search for files containing a specific substring in their name.
- **User-Friendly Interface**: A simple menu system allows users to choose the search option and view the results in an organized manner.

## Requirements

- **C++17 or higher**: The program utilizes the C++17 filesystem library.
- **Windows OS**: The program is designed to search files across a Windows filesystem.

## Installation

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/yourusername/filesearcher.git
    cd filesearcher
    ```

2. **Compile the Program**:
    ```sh
    g++ -std=c++17 -o filesearcher main.cpp
    ```

3. **Run the Program**:
    ```sh
    ./filesearcher
    ```

## Usage

1. **Start the Program**:
   Run the compiled executable. A menu will be presented with the following options:

2. **Choose a Search Option**:
- Enter `1` to search by exact filename.
- Enter `2` to search by file extension.
- Enter `3` to search by partial filename.
- Enter `4` to exit the program.

3. **Enter Search Term**:
After selecting an option, the program will prompt you to enter the search term (filename, extension, or partial filename).

4. **View Results**:
The program will search the `C:\` directory and display the results in the terminal. If no files are found, a message will indicate this.

5. **Repeat or Exit**:
The program will continue to present the menu until you choose the exit option.

## Limitations

- **Windows Specific**: The root directory is set to `C:\`, which is specific to Windows systems.
- **Permission Issues**: The program might skip certain directories due to insufficient permissions, resulting in incomplete search results.
- **Performance**: The program performs a recursive search starting from the root directory, which might take a considerable amount of time on systems with large filesystems.
- **No Support for Regular Expressions**: The search is based purely on exact or partial string matching; it doesn't support regular expressions.

## Error Handling

The program handles the following errors:

- **Filesystem Errors**: If the program encounters an issue accessing a file or directory, it will skip the problematic entry and continue searching.
- **Invalid Input**: If the user enters an invalid option, the program will prompt the user to try again.

## Contributing

If you have suggestions for improvements or find bugs, feel free to open an issue or create a pull request.
