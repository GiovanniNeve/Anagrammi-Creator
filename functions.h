#ifndef ANAGRAMMI_CREATOR_FUNCTIONS_H
#define ANAGRAMMI_CREATOR_FUNCTIONS_H

#endif //ANAGRAMMI_CREATOR_FUNCTIONS_H

// Find duplicates of a word
int findDuplicates(std::string word) {
    int numberOfDubplicates = 0;
    int stringLength = word.length();     // Get the word length
    std::map<char, int> anagramMap;    // Store word's letter in a map

    for(int i=0; i<stringLength; i++) {
        anagramMap[word[i]] += 1;  // If there are duplicates some letters will result higher than 1
    }

    for(auto anagram : anagramMap) {
        if(anagram.second > 1) {
            numberOfDubplicates += anagram.second;  // Increment the sum of duplicates
        }
    }

    return numberOfDubplicates;
}

// Factorial number function
int calculateFactorial(int number, int result) {     // Calculate factorial number with recursion
    return (number == 0) ? result : calculateFactorial(number - 1, result * number);
}


// Create anagrams of a word
std::vector<std::string> makeAnagrams(std::string word) {
    std::vector<std::string> anagramsArray;     // Create an empty string array to store anagrams
    std::string tempWord = word;    // Create a copy of the word to work with
    int wordLen = word.length();    // Get word length
    int numberOfDuplicateCharacter = findDuplicates(word);     // Store the number of duplicates

    // Print number of possible anagrams
    // Use the permutation formula for duplicates
    std::cout << "\nNumber of possible anagrams: " << (calculateFactorial(wordLen,1) / calculateFactorial(numberOfDuplicateCharacter, 1)) << "\n";

    std::cout << "Making anagrams...\n";
    std::sort(tempWord.begin(), tempWord.end());    // Sort the letter of the word
    anagramsArray.emplace_back(tempWord);   // Insert the first word as an anagram

    while(std::next_permutation(tempWord.begin(), tempWord.end())) {    // Create permutation with next_permutation formula
        anagramsArray.emplace_back(tempWord);   // Insert the other anagrams
    }

    return anagramsArray;
}

// Search the word inserted in the dictionary
void search(std::vector<std::string> anagramsArray, std::shared_ptr<std::vector<std::string>> dataArray) {
    for(auto word : *dataArray) {
        for (auto wordOfArray : anagramsArray) {
            // If the first letter of the inserted word is ahead it will skip all of them
            if (wordOfArray[0] < word[0]) {
                continue;
            } else if(word.compare(wordOfArray) == 0) {     // If the words are the same it prints it out
                std::cout << "\nWord found " << word<< "\n";
            }
        }
    }
}
