#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to search for a specific word in the input file and return its frequency
int findFrequency(string word) {
    // Open the input file for reading
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    // Initialize the frequency count to 0
    int count = 0;

    // Read each word in the input file
    string currentWord;
    while (inputFile >> currentWord) {
        // If the current word matches the search word, increment the frequency count
        if (currentWord == word) {
            count++;
        }
    }

    // Close the input file and return the frequency count
    inputFile.close();
    return count;
}

// Function to print the list of items and their frequencies
void printList() {
    // Open the input file for reading
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    // Read each line in the input file and print the item and frequency
    string item;
    int frequency;
    while (inputFile >> item >> frequency) {
        cout << item << " " << frequency << endl;
    }

    // Close the input file
    inputFile.close();
}

// Function to print a histogram of the item frequencies
void printHistogram() {
    // Open the input file for reading
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    // Read each line in the input file and store the item and frequency in a vector of pairs
    vector<pair<string, int>> itemFrequencyPairs;
    string item;
    int frequency;
    while (inputFile >> item >> frequency) {
        itemFrequencyPairs.push_back(make_pair(item, frequency));
    }

    // Sort the vector of pairs by frequency in descending order
    sort(itemFrequencyPairs.begin(), itemFrequencyPairs.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    // Print a histogram of the item frequencies
    for (const auto& pair : itemFrequencyPairs) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }

    // Close the input file
    inputFile.close();
}

int main() {
    int choice = 0;
    string searchWord;
    while (choice != 4) {
        // Print the main menu and prompt the user for their choice
        cout << "Corner Grocery" << endl;
        cout << "1. Find the frequency of a specific item" << endl;
        cout << "2. Print the list of items and their frequencies" << endl;
        cout << "3. Print a histogram of the item frequencies" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Perform the appropriate action based on the user's choice
        switch (choice) {
            case 1:
                // Prompt the user for the item they wish to search for and print the frequency
                cout << "Enter the item you wish to search for: ";
                cin >> searchWord;
                cout << "The frequency of " << searchWord << " is " << findFrequency(searchWord) << endl;
                break;
            case 2:
                // Print the list of items and their frequencies
                printList();
                break;
            case 3:
                // Print a histogram of
                printHistogram();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}