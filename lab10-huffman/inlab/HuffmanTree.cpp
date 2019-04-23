/*
Name: Tho Nguyen
Email ID: tnn7yc
File name: HuffmanTree.cpp
Date: 11/27/18
*/
#include "HuffmanTree.h"

using namespace std;

HuffmanTree::HuffmanTree(){
  root = NULL;
}

HuffmanTree::~HuffmanTree(){
  delete root;
}

void HuffmanTree::createNode(const string& c, const string& p){
  createNode(root, c, p, p);
  //printTree(root, NULL, false);
}

void HuffmanTree::createNode(HuffmanNode* &n, const string& c, const string& curP, const string& p){
  if (n == NULL)
    n = new HuffmanNode();
  if (curP.length() == 1){
    if (curP == "0"){
      n->left = new HuffmanNode(c, p);
    }
    else if (curP == "1"){
      n->right = new HuffmanNode(c, p);
    }
  }
  else if ( curP.length() > 1 && curP.substr(0, 1) == "0" ){
    createNode(n->left, c, curP.substr(1), p);
  }
  else if ( curP.length() > 1 && curP.substr(0, 1) == "1" ){
    createNode(n->right, c, curP.substr(1), p);
  }
}

void HuffmanTree::decode(const string& bits){
  decode(root, bits);
}

void HuffmanTree::decode(HuffmanNode* n, const string& bits){
  if (bits.length() == 0){
    if (n->c == "space")
      cout << " " << endl;
    else
      cout << n->c << endl;
  }
  else if (bits.length() > 0){
    if (n->left == NULL && n->right == NULL){
      if (n->c == "space")
	cout << " ";
      else
	cout << n->c;
      decode(root, bits);
    }
    else if (bits.substr(0, 1) == "0"){
      decode(n->left, bits.substr(1));
    }
    else if (bits.substr(0, 1) == "1"){
      decode(n->right, bits.substr(1));
    }
  }
}

// Helper function to print branches of the binary tree
void HuffmanTree::showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}

void HuffmanTree::printTree(HuffmanNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->c << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}
