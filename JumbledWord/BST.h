/*
 * This program unscrambles jumbled words in order to solve a riddle.
 *Programmer: Dalina Beckham
*/

#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

class BSTNode {
    public:
        void insert(string key);
        int getValue(string key);
        BSTNode(string key);

    private:
        string key;
        BSTNode *left, *right;
};

class BST {

    public:
        void insert(string key);
        int getValue(string key);
        BST();

    private:
        BSTNode *root;
};
#endif
