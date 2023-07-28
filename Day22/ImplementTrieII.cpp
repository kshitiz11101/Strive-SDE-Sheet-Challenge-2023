#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int last;
    int between;
    Node(){
        last = 0;
        between = 0;
    }
};
class Trie{

     public:
    Node* root;
    Trie(){
        // Write your code here.
        // Define a root
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        // Starting from root and then traversing for inserting
        Node* temp = root;
        for(auto ch : word){
            if(temp->links[ch-'a'] == nullptr){
                temp->links[ch-'a'] = new Node();
                temp->links[ch-'a']->between += 1;    
            }
            else temp->links[ch-'a']->between += 1;
            temp = temp->links[ch-'a'];
        }
        temp->last += 1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        // Starting from root and then going to the end and checking for the last value
        Node *temp = root;
        for(auto ch : word){
            if(temp->links[ch-'a'] == nullptr) return 0;
            temp = temp->links[ch-'a'];
        }
        return temp->last;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        // Starting and moving to inbetween node
        Node *temp = root;
        for(auto ch : word){
            if(temp->links[ch-'a'] == nullptr) return 0;
            temp = temp->links[ch-'a'];
        }
        return temp->between;
    }

    void erase(string &word){
        // Write your code here.
        Node *temp = root;
        for(auto ch : word){
            temp->links[ch-'a']->between -= 1;
            temp = temp->links[ch-'a'];
        }
        temp->last -= 1;
    }
};
