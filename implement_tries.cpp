// Time Complexity :
//  for insert : o(L) .... where L is length of the word
//  for search : 0(L)
// Space Complexity : O(L * n) .... where is L is average length of words and n is number of words 


/*
Leetcode : https://leetcode.com/problems/implement-trie-prefix-tree/

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

/*
Explaination :  watch for understanding - https://www.youtube.com/watch?v=LJFvndvoZFs
*/



class Trie {
    class TrieNode {
        public:
        bool isValid;
        TrieNode** array;

        TrieNode() {
            array = new TrieNode*[26];
            for(int i=0 ; i<26; i++){
                array[i] = nullptr;
            }
            isValid = false;
        }
    };
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(cur->array[ch - 'a'] == nullptr){
                cur->array[ch - 'a'] = new TrieNode();
            }
            cur = cur->array[ch - 'a'];
        }
        cur->isValid = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(cur->array[ch - 'a'] == nullptr) return false; 
            cur = cur->array[ch - 'a'];
        }
        return cur->isValid;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(cur->array[ch - 'a'] == nullptr) return false;
            cur = cur->array[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */