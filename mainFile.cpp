#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>
#include <map>
#include <algorithm>
#include "./binarySearchTree.h"

/* Find duplicates in a word for the permutation formula */
int findDuplicates(std::string word) {
    int numberOfDubplicates = 0;
    int strLen = word.length();
    std::map<char, int> map;    /* Store word's letter in a map */

    for(int i=0; i<strLen; i++) {
        map[word[i]] += 1;  /* If there are duplicates some words will result higher than 1 */
    }

    for(auto element : map) {
        if(element.second > 1) {
            numberOfDubplicates += element.second;  /* Increment the sum of duplicates */
        }
    }

    return numberOfDubplicates;
}

/* Factorial number function */
int findFactorial(int number, int result) {     /* Calculate factorial number for the permutation formula with recursion*/
    return (number == 0) ? result : findFactorial(number-1, result*number);
}

/* Create anagrams and search them in the BST */
std::vector<std::string> makeAnagrams(std::string word) {
    std::vector<std::string> anagramsArray;
    std::string tempWord = word;
    int wordLen = word.length();    /*Get word length */
    int nDuplicates = findDuplicates(word);     /* Get number of duplicates */

    /* Print number of possible anagrams with duplicates permutation formula */
    std::cout << "\nNumber of possible anagrams: " << (findFactorial(wordLen,1)/findFactorial(nDuplicates, 1)) << "\n";

    std::cout << "Making anagrams...\n";
    std::sort(tempWord.begin(), tempWord.end());    /* Sort the word */
    anagramsArray.emplace_back(tempWord);

    while(std::next_permutation(tempWord.begin(), tempWord.end())) {    /* Create permutation with algorithm.h funcion */
        anagramsArray.emplace_back(tempWord);
    }

    return anagramsArray;
}

void search(std::vector<std::string> anagramsArray, std::shared_ptr<BST> bst)
{
    std::cout << "Searching...\n";
    for (auto wordOfArray : anagramsArray) {
        bst->search(wordOfArray, bst->root);    //Search data in the BST
    }
}

int main() {

    std::fstream file;
    std::string output;
    std::string word;
    std::vector<std::string> arrayOfAnagrams;

    file.open("../wordList.txt", std::ios::in | std::ios::out);   /* Try to open the file */
    if(file.fail()) {   /* Check for errors */
        std::cout << "Errore nell'apertura del file, file non trovato o corrotto...";
        return 1;
    }else {
        std::cout << "File aperto correttamente\n";
    }

        std::cout << "--------------------\n";
        std::cout << "Inserisci una parola: ";
        std::cin >> word;
        if (word=="exit") {    /* Check for break */
            return 0;
        }

        arrayOfAnagrams = makeAnagrams(word);

        /* Lettura del file e inserimento dei dati nel binary search tree*/
        while(file) {
            {   /* Start shared pointer */
            std::shared_ptr<BST> bst(new BST);  /* BST is the binary search tree class */

            constexpr size_t bufferSizeLimit = 1024 * 128;
            size_t bufferSize = 0;

            while (file >> output && bufferSize < bufferSizeLimit) {
                bst->insertData(output, bst->root);
                bufferSize += sizeof(output);
            }

            search(arrayOfAnagrams, bst);

        }   /*End shared pointer*/
    }

	return 0;
}
