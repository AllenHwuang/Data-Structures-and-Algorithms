//
// Created by 29546 on 2020/3/28.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class BinaryTree{
    struct BTreeNode{
        char val;
        BTreeNode *lchild = nullptr, *rchild = nullptr;
        explicit BTreeNode(char x) : val(x), lchild(nullptr), rchild(nullptr) {}
    };
public:
    BTreeNode * PreInCreate(string A, string B, int l1, int h1, int l2, int h2){
        auto* root = (BTreeNode *) malloc(sizeof(BTreeNode));
        root->val = A[l1];
        int i;
        for (i = l2; B[i] != root->val; ++i);
        int llen = i - l2;
        int rlen = h2 - i;
        if (llen)
            root->lchild = PreInCreate(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
        else
            root->lchild = nullptr;
        if (rlen)
            root->rchild = PreInCreate(A, B, l1 + llen + 1, h1, h2 - rlen + 1, h2);
        else
            root->rchild = nullptr;
        return root;
    }

public:
    void PreOrderBTree(BTreeNode *btree){
        stack<BTreeNode*> stack;
        while(btree || !stack.empty()){
            if(btree){
                cout << btree->val;
                if(btree->rchild)
                    stack.push(btree->rchild);
                btree = btree->lchild;
            } else{
                btree = stack.top();
                stack.pop();
            }
        }
        cout << endl;
    }

public:
    void InOrderBTree(BTreeNode *btree){
        stack<BTreeNode*> stack;
        while(btree || !stack.empty()){
            if(btree){
                stack.push(btree);
                btree = btree->lchild;
            } else{
                btree = stack.top();
                stack.pop();
                cout << btree->val;
                btree = btree->rchild;
            }
        }
    }

public:
    void PostOrder(BTreeNode *btree){

    }

public:
    void run(){
        string preOrder="#ABDHNIOEJPUVQCFKRWLSXGMTYZ", inOrder="#HNDOIBEUPVJQAKWRFLXSCMYTZG";
        int orderLen = preOrder.length() - 1;
        BTreeNode *btree = nullptr;
        btree = PreInCreate(preOrder, inOrder, 1, orderLen, 1, orderLen);
        PreOrderBTree(btree);
        InOrderBTree(btree);
    }
};
