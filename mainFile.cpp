#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>
#include <map>
#include <algorithm>
#include "functions.h"

int main() {

    std::fstream file;
    std::string fileOutput;
    std::string word;
    std::vector<std::string> arrayOfAnagrams;
    int fileLength;

    file.open("../wordList.txt", std::ios::in | std::ios::out);   // Try to open the file
    if(file.fail()) {   // Check for errors
        std::cout << "Error occurred, file not found or corrupted...";
        return 1;
    }else {
        std::cout << "File opened correctly\n";
    }

    file.seekg(0, file.end);
    fileLength = file.tellg();
    file.seekg(0, file.beg);

    std::cout << "--------------------\n";
    std::cout << "Insert the word: ";
    std::cin >> word;
    if (word=="exit") {    // Check for exit
        return 0;
    }

    // Make anagrams of the word inserted
    arrayOfAnagrams = makeAnagrams(word);

    // Read the file 131 KB at once (around 11 hundred words at once)
    while(file) {
        int fileIteratorPosition = file.tellg();    // Get iterator position for percentage
        std::cout << "\n" << (fileIteratorPosition*100)/fileLength << "%";  // Calculate and print percentage
        {   // Start shared pointer
        // Create a vector pointer
        std::shared_ptr<std::vector<std::string>> dataArray(new std::vector<std::string>);

        constexpr size_t bufferSizeLimit = 1024 * 128;
        size_t bufferSize = 0;

        // Load block of data in the vector
        while (file >> fileOutput && bufferSize < bufferSizeLimit) {
            dataArray->emplace_back(fileOutput);
            bufferSize += sizeof(fileOutput);
        }

        // Search word in the vector
        search(arrayOfAnagrams, dataArray);

        }   //End shared pointer
    }

	return 0;
}
