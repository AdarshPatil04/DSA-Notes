/**
 * @brief This code implements the second approach to find the longest common prefix among a vector of words using a Trie data structure.
 *
 * The code defines a TrieNode class and a Trie class. The TrieNode class represents a node in the Trie and contains the data, an array of pointers for each alphabet letter, the count of children nodes, and a flag to mark the end of a word.
 * The Trie class represents the Trie data structure and contains the root of the Trie. It provides utility functions to insert a word into the Trie and find the longest common prefix.
 * The main function creates a Trie, inserts the words from a vector into the Trie, and finds the longest common prefix among the words.
 *
 * Time Complexity: O(N*M), where N is the number of words and M is the average length of the words.
 * Space Complexity: O(N*M), where N is the number of words and M is the average length of the words.
 */

// Approach - 2 : Using Trie
// Time Complexity = O(N*M)
// Space Complexity = O(N*M)

#include <bits/stdc++.h>
using namespace std;

// TrieNode class
class TrieNode
{
public:
    char data;              // data of the node
    TrieNode *children[26]; // array of pointers for each alphabet letter
    int childCount;         // count of children nodes
    bool isTerminal;        // flag to mark the end of a word

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

// Trie class
class Trie
{
public:
    TrieNode *root; // root of the Trie

    // constructor
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    // utility function to insert a word into the Trie
    void insertUtil(TrieNode *root, string word)
    {
        // base case: if the word length is 0, mark the node as terminal
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // if the child node already exists, use it
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // else create a new child node
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        // recursive call for the rest of the word
        return insertUtil(child, word.substr(1));
    }

    // function to insert a word into the Trie
    void insert(string word)
    {
        insertUtil(root, word);
    }

    // function to find the longest common prefix (lcp)
    void lcp(string word, string &ans)
    {
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            // if the node has only one child, add the character to the answer
            if (root->childCount == 1)
            {
                ans.push_back(ch);

                // move to the next node
                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;

            // if the node is terminal, break the loop
            if (root->isTerminal)
                break;
        }
    }
};

// function to find the longest common prefix among a vector of words
string longestCommonPrefix(vector<string> &word, int n)
{
    Trie *t = new Trie('\0');

    // insert all words into the Trie
    for (int i = 0; i < n; i++)
    {
        t->insert(word[i]);
    }

    string first = word[0];
    string ans = "";

    // find the longest common prefix
    t->lcp(first, ans);
    return ans;
}

// main function
int main()
{
    vector<string> arr = {"flower", "flow", "flight"};
    int n = arr.size();
    cout << longestCommonPrefix(arr, n) << endl;
    return 0;
}
