#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>
#include <map>
#include "./bst.h"

std::fstream openFile() {

    /* Apertura o creazione di un file */
    std::fstream file;

        file.open("Prova.txt", std::ios::in | std::ios::out);
    if(file.fail()) {
        std::cout << "File non trovato\nCreazione di un nuovo file...\n";
        file.open("Prova.txt", std::ios::in | std::ios::out | std::ios::app);
        if(file.fail()) {
            std::cout << "Errore nella creazione del file\n";
        } else {
            std::cout << "File creato correttamente\n";
        }
    } else {
        std::cout << "File aperto correttamente\n";
    }

    return file;
}

int findDuplicates(std::string word) {
    int numberOfDubplicates = 0;
    int strLen = word.length();
    std::map<char, int> map;

    for(int i=0; i<strLen; i++) {
        map[word[i]] += 1;
    }

    for(auto element : map) {
        if(element.second > 1) {
            numberOfDubplicates += element.second;
        }
    }

    return numberOfDubplicates;
}

int findFactorial(int number, int result) {
    return (number == 0) ? result : findFactorial(number-1, result*number);
}

void customSearch(std::string word, std::shared_ptr<BST> bst) {
    std::vector<std::string> anagramsArray;
    int nDuplicates;
    int wordLen = word.length();
    std::string tempWord;
    nDuplicates = findDuplicates(word);

    std::cout << "Number of possible anagrams: " << (findFactorial(wordLen,1)/findFactorial(nDuplicates, 1)) << "\n";

    std::cout << "Making anagrams...\n";
    for(char c1 : word) {
        for(char c2 : word) {
            //Make anagrams
        }
    }


    std::cout << "Searching";
    //bst->search(word, bst->root);
}

int main() {

	std::fstream file = openFile();
    std::string output;
    std::string word;

    {   /* Start unique pointer */
        std::shared_ptr<BST> bst(new BST);

        /* Lettura e output del file */
        while(file >> output) {
            bst->insertData(output, bst->root);
        }

        while(true) {
            std::cout << "Insert the word: ";
            std::cin >> word;
            if(word == "exit") {
                break;
            } else {
                customSearch(word, bst);
            }
        }
        //bst->getData(bst->root);

    }   /*End unique pointer*/

	return 0;
}
