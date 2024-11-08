// Time Complexity : O(n*l) + O(n*l) ~ o(n*l)
//  O(n*l) for creation of the Trie : O(n) ...... n is total number of words and l is avg. length of words 
//  o(n*l) for iterating over all words to verify the condition 
// Space Complexity : O(L * n) .... where is L is average length of words and n is number of words 

/*
Leetcode : https://leetcode.com/problems/longest-word-in-dictionary/

Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
Note that the word should be built from left to right with each additional character being added to the end of a previous word. 
*/

/*
Explaination : 

First Trie is created with given set of words.
Then each word is checked if it satisfies the given condition and then result is updated
depending on the length of the word.
*/


class Solution {

    class Trie{
        class TrieNode {
            public:
            bool isValid;
            TrieNode** array;

            TrieNode() {
                isValid = false;
                array = new TrieNode*[26];
                for(int i=0; i<26; i++){
                    array[i] = nullptr;
                }
            }
        };

        public:
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }

        void insertWord(string word){
            TrieNode* current = root;
            for(int i=0; i<word.size(); i++){
                char ch = word[i];
                if(current->array[ch - 'a'] == nullptr){
                    current->array[ch - 'a'] = new TrieNode();
                }
                current = current->array[ch - 'a'];
            }
            current->isValid = true;
        }

        bool isTrue (string word){
            TrieNode* current = root;
            for(int i=0; i<word.size(); i++){
                char ch = word[i];
                if(!current->array[ch - 'a']->isValid) return false;
                current = current->array[ch - 'a'];
            }
            return true;
        }
    };
    
public:
    string longestWord(vector<string>& words) {
        string result = "";
        Trie t;
        for(int i=0; i<words.size(); i++){
            t.insertWord(words[i]);
        }

        for(int i=0; i<words.size(); i++){
            if(t.isTrue(words[i])){
                if(result.size() < words[i].size()) result = words[i];
                else if (result.size() == words[i].size()){
                    result = std::min(result, words[i]);
                }
            }
        }
        
        return result;
    }
};