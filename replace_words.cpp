// Time Complexity :
//  for insert : o(L) .... where L is length of the word
//  for search : 0(L)
// Space Complexity : O(L * n) .... where is L is average length of words and n is number of words 


/*
Leetcode : https://leetcode.com/problems/replace-words/

In English, we have a concept called root, which can be followed by some other word to form 
another longer word - let's call this word derivative. For example, when the root "help" 
is followed by the word "ful", we can form a derivative "helpful".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces,
 replace all the derivatives in the sentence with the root forming it. 
 If a derivative can be replaced by more than one root, replace it with the root that has 
 the shortest length.
Return the sentence after the replacement.
*/

/*
Explaination :  watch for understanding - https://www.youtube.com/watch?v=LJFvndvoZFs
*/

class Solution {
    class Trie {
        class Trienode {
            public :
                bool isValid;
                Trienode** array;

            Trienode(){
                isValid = false;
                array = new Trienode*[26];
                for(int i=0; i<26; i++){
                    array[i] = nullptr;
                }
            }
        };

        private:
        Trienode* root;

        public:
        Trie(){
            root = new Trienode();
        }

        void insert(string word){
            Trienode* cur = root;
            for(int i=0; i<word.size(); i++){
                char ch = word[i];
                if(cur->array[ch - 'a'] == nullptr){
                    cur->array[ch - 'a'] = new Trienode();
                }
                cur = cur->array[ch - 'a'];
            }
            cur->isValid = true;
        }

        string getShort(string word){
            Trienode* cur = root;
            string shortName = "";
            for(int i=0; i<word.size(); i++){
                char ch = word[i];
                if(cur->isValid) return shortName;
                if(cur->array[ch - 'a'] == nullptr) break;
                cur = cur->array[ch - 'a'];
                shortName += ch;
            }
            return word;
        }
    };

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(int i=0; i<dictionary.size(); i++){
            t.insert(dictionary[i]);
        }

        std::istringstream ss(sentence);
        string word;
        vector<string>words;

        while(ss >> word){
            words.push_back(word);
        }
        
        string result = "";

        for(int i=0; i<words.size(); i++){
            result += " " + t.getShort(words[i]);
        }

        return result.substr(1, result.size()-1);
    }
};