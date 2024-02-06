/**
 * Time Complexity: O(N*M^2)
 * Space Complexity: O(N*M)
 * This code implements a phone directory using a Trie data structure.
 * It allows inserting a list of contacts into the directory and provides suggestions for a given query string.
 * The Trie data structure is used to efficiently store and retrieve the contacts.
 * The code defines two classes: TrieNode and Trie.
 * TrieNode represents a node in the Trie and contains the character data, an array of pointers for each character, and a flag to mark the end of a word.
 * Trie represents the Trie data structure and provides functions to insert a string into the Trie and get suggestions for a given query string.
 * The main function demonstrates the usage of the Trie class by inserting a list of contacts and getting suggestions for a query string.
 */
// https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666

#include <bits/stdc++.h>
using namespace std;

// TrieNode class
class TrieNode
{
public:
    char data;              // data of the node
    TrieNode *children[26]; // array of pointers for each character
    bool isTerminate;       // flag to mark the end of a word

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; // initialize all children pointers to NULL
        }
        isTerminate = false; // initialize isTerminate to false
    }
};

// Trie class
class Trie
{
public:
    TrieNode *root; // root of the Trie

    // constructor
    Trie()
    {
        root = new TrieNode('\0'); // initialize root with null character
    }

    // function to insert a string into the Trie
    void insertUtil(TrieNode *root, string str)
    {
        // base case
        if (str.length() == 0)
        {
            root->isTerminate = true; // mark the end of a word
            return;
        }

        int index = str[0] - 'a'; // calculate index for the array
        TrieNode *child;

        // if the child node exists
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // if the child node does not exist, create a new one
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }

        // recursive call for the rest of the string
        return insertUtil(child, str.substr(1));
    }

    // function to start the insertion process
    void insertStr(string str)
    {
        insertUtil(root, str);
    }

    // function to print all suggestions starting with a given prefix
    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        // if the current node marks the end of a word, add it to the suggestions
        if (curr->isTerminate)
        {
            temp.push_back(prefix);
        }

        // iterate over all possible characters
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            // if the next node exists
            if (next != NULL)
            {
                prefix.push_back(ch);                 // add the character to the prefix
                printSuggestions(next, temp, prefix); // recursive call for the next node
                prefix.pop_back();                    // remove the last character from the prefix
            }
        }
    }

    // function to get all suggestions for a given string
    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        string prefix = "";
        vector<vector<string>> output;

        // iterate over the string
        for (int i = 0; i < str.length(); i++)
        {
            char lastCh = str[i];

            prefix.push_back(lastCh); // add the character to the prefix

            // check for the last character in the Trie
            TrieNode *curr = prev->children[lastCh - 'a'];

            // if the character is not found, break the loop
            if (curr == NULL)
            {
                break;
            }

            // if the character is found
            vector<string> temp;

            // get all suggestions starting with the current prefix
            printSuggestions(curr, temp, prefix);
            output.push_back(temp); // add the suggestions to the output

            temp.clear(); // clear the temporary vector
            prev = curr;  // move to the next node
        }
        return output; // return the output
    }
};

// function to get all suggestions for a given query string from a list of contacts
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // create a new Trie
    Trie *t = new Trie();

    // insert all contacts into the Trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertStr(str);
    }

    // return all suggestions for the query string
    return t->getSuggestions(queryStr);
}

// main function
int main()
{
    // list of contacts
    vector<string> contactList = {"gfg", "geeks", "for", "geeksfor", "geeksforgeeks"};
    // query string
    string queryStr = "geek";
    // get all suggestions for the query string
    vector<vector<string>> ans = phoneDirectory(contactList, queryStr);
    // print all suggestions
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
