/**
 * Time complexity => O(n) for insertion, searching, and deletion operations
 * @file trieImplementation.cpp
 * @brief This file contains the implementation of a Trie data structure.
 *
 * A Trie, also known as a prefix tree, is a tree-based data structure that is used to efficiently store and retrieve strings.
 * This implementation includes the TrieNode class and the Trie class, which provides methods for inserting, searching, and deleting words in the Trie.
 * The main function demonstrates the usage of the Trie by inserting words, searching for words, and deleting words from the Trie.
 */
#include <bits/stdc++.h>
using namespace std;

// TrieNode class
class TrieNode
{
public:
    char data;              // Data of the node
    TrieNode *children[26]; // Array of pointers for each character of the alphabet
    bool isTerminal;        // Boolean to mark the end of a word

    // Constructor to initialize a new TrieNode
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// Trie class
class Trie
{
public:
    TrieNode *root; // Root of the Trie

    // Constructor to initialize a new Trie
    Trie()
    {
        root = new TrieNode('\0');
    }

    // Utility function to insert a word into the Trie
    void insertUtil(TrieNode *root, string word)
    {
        // Base case: if the word length is 0, mark the node as terminal
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Assuming the words to be in uppercase
        int index = word[0] - 'A';
        TrieNode *child;

        // If the child node exists, use it
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // If the child node does not exist, create a new one
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursively insert the rest of the word
        insertUtil(child, word.substr(1));
    }

    // Function to insert a word into the Trie
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // Utility function to search for a word in the Trie
    bool searchUtil(TrieNode *root, string word)
    {
        // Base case: if the word length is 0, return the terminal status of the node
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        // Assuming the words to be in uppercase
        int index = word[0] - 'A';
        TrieNode *child;

        // If the child node exists, use it
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // If the child node does not exist, the word is not in the Trie
            return false;
        }

        // Recursively search for the rest of the word
        return searchUtil(child, word.substr(1));
    }

    // Function to search for a word in the Trie
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // Utility function to delete a word from the Trie
    void deleteUtil(TrieNode *root, string word)
    {
        // Base case: if the word length is 0, unmark the node as terminal
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // If the child node exists, use it
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // If the child node does not exist, the word is not in the Trie
            cout << "Word is not available" << endl;
        }

        // Recursively delete the rest of the word
        deleteUtil(child, word.substr(1));
    }

    // Function to delete a word from the Trie
    void deleteWord(string word)
    {
        deleteUtil(root, word);
    }
};

// Main function
int main()
{
    // Create a new Trie
    Trie *t = new Trie();

    // Insert words into the Trie
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("DOING");

    // Search for words in the Trie and print the results
    cout << "\nPresent or Not ? : " << t->searchWord("TIME") << endl;
    cout << "\nPresent or Not ? : " << t->searchWord("DOI") << endl;
    cout << "\nPresent or Not ? : " << t->searchWord("DOING") << endl;

    // Delete words from the Trie
    t->deleteWord("DO");
    t->deleteWord("DOING");

    // Search for the deleted words in the Trie and print the results
    cout << "\nPresent or Not ? : " << t->searchWord("DO") << endl;
    cout << "\nPresent or Not ? : " << t->searchWord("DOING") << endl;

    cout << endl;
    return 0;
}
