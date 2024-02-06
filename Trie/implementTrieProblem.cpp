/**
 * @brief This code implements a Trie data structure and demonstrates its usage.
 *
 * The Trie class provides functionality to insert words into the Trie, search for words in the Trie,
 * and check if any word in the Trie starts with a given prefix.
 *
 * The TrieNode class represents a node in the Trie and contains the character data, an array of pointers
 * for each character of the alphabet, and a boolean flag to mark the end of a word.
 *
 * The main function creates a new Trie, inserts a word into the Trie, searches for a word in the Trie,
 * and checks if any word in the Trie starts with a given prefix.
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
    TrieNode *root; // Root of the Trie

public:
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

        // Assuming the words to be in lowercase
        int index = word[0] - 'a';
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
    void insert(string word)
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

        // Assuming the words to be in lowercase
        int index = word[0] - 'a';
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
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    // Utility function to check if any word in the Trie starts with the given prefix
    bool prefixUtil(TrieNode *root, string prefix)
    {
        // Base case: if the prefix length is 0, return true
        if (prefix.length() == 0)
        {
            return true;
        }

        // Assuming the words to be in lowercase
        int index = prefix[0] - 'a';
        TrieNode *child;

        // If the child node exists, use it
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // If the child node does not exist, no word in the Trie starts with the prefix
            return false;
        }

        // Recursively check for the rest of the prefix
        return prefixUtil(child, prefix.substr(1));
    }

    // Function to check if any word in the Trie starts with the given prefix
    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};

// Main function
int main()
{
    // Create a new Trie
    Trie *obj = new Trie();

    // Insert a word into the Trie
    obj->insert("apple");

    // Search for a word in the Trie and print the result
    bool check2 = obj->search("apple");
    cout << "Is 'apple' present in the Trie? : " << (check2 ? "Yes" : "No") << endl;

    // Check if any word in the Trie starts with a given prefix and print the result
    bool check3 = obj->startsWith("app");
    cout << "Does any word in the Trie start with 'app'? : " << (check3 ? "Yes" : "No") << endl;

    return 0;
}
