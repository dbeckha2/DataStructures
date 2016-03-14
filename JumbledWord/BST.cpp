#include"BST.h"
#include<iostream>

using namespace std;

void BSTNode::insert(string key) {
    if (key < this->key) {
        if (left == NULL) {
            left = new BSTNode(key);
        } else {
            left->insert(key);
        }
    } else {
        if (right == NULL) {
            right = new BSTNode(key);
        } else {
            right->insert(key);
        }
    }
}

int BSTNode::getValue(string key) {
    if (key == this->key) {
        //return this->key;
   return 1;
	 }
    if (key < this->key) {
        if (left == NULL) {
            //throw "no such key " + key + "!";
        	return 0;
	} else {
            return left->getValue(key);
        }
    } else {
        if (right == NULL) {
            //throw "no such key " + key + "!";
        	return 0;
	} else {
            return right->getValue(key);
        }
    }
}

BSTNode::BSTNode(string key) {
    left = right = NULL;
    this->key = key;
}


void BST::insert(string key) {
    if (root == NULL) {
        root = new BSTNode(key);
    } else {
        root->insert(key);
    }
//cout <<"this is the middle root word : "<<  key << endl;
}


int BST::getValue(string key) {
    if (root != NULL) {
        return root->getValue(key);
    }
   // throw "no such key " + key + "!";
	return 0;
}

BST::BST() {
    root = NULL;
}

