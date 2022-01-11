//
// Created by ck on 2021/11/5.
//

#include <iostream>

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(int id)
    : id(id), leftSubTree(nullptr), rightSubTree(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other): id(other.id)
{
    // TODO: Clone the two subtrees accordingly.
    if(other.leftSubTree != nullptr){
        leftSubTree = new BinarySearchTree(*other.leftSubTree);
    }else leftSubTree = nullptr;

    if(other.rightSubTree != nullptr){
        rightSubTree = new BinarySearchTree(*other.rightSubTree);
    }else rightSubTree = nullptr;

}

BinarySearchTree::~BinarySearchTree()
{
    // TODO: release the resources occupied by the two subtrees if any.
    if(leftSubTree != nullptr)
        delete leftSubTree;
    if(rightSubTree != nullptr)
        delete rightSubTree;
}

void BinarySearchTree::add(int newId)
{
    // TODO: Insert the newId to the current tree.
    // You need to create a new node for the newId and attach it to the correct place.
    // Do nothing if the id is already in the tree.
    if(newId == id){
        return;
    }
    if(newId <id){
        if(leftSubTree == nullptr)
            leftSubTree  =  new BinarySearchTree(newId);
        else leftSubTree->add(newId);
           
    }else if (newId > id){
        if(rightSubTree == nullptr)
            rightSubTree = new BinarySearchTree(newId);
        else rightSubTree->add(newId);
    }
    
}

bool BinarySearchTree::hasId(int idToFind) const
{
    // TODO: Check whether the given id is in the tree.
    // You need to determinate whether to seach the left subtree or right subtree.
    if(id == idToFind)
        return true;
    else if(idToFind < id){
        if(leftSubTree!= nullptr)
            return leftSubTree->hasId(idToFind);
        }
    else if(idToFind > id){
        if(rightSubTree != nullptr)
            return rightSubTree->hasId(idToFind);
    }else
        return false;
}

int BinarySearchTree::height() const
{
    // TODO: Calculate the height of the tree.
    // Tree like this has height 0:
    //    O
    //
    // Trees like these have height 1:
    //    O        O       O
    //  /  \        \     /
    // O    O        O   O
    
    

    if(this->leftSubTree==nullptr && this->rightSubTree==nullptr){
        return 0;
    }
    else{
        int lHeight, rHeight=0;
        if(leftSubTree){
            lHeight=1+leftSubTree->height();
        }
        if(rightSubTree){
            lHeight=1+rightSubTree->height();
        }
        return (lHeight>rHeight)?lHeight:rHeight;
    }
   
}

void BinarySearchTree::printDFSPrefix() const
{
    std::cout << id << " ";
    if (leftSubTree != nullptr)
        leftSubTree->printDFSPrefix();

    if (rightSubTree != nullptr)
        rightSubTree->printDFSPrefix();
}

void BinarySearchTree::printDFSInfix() const
{
    if (leftSubTree != nullptr)
        leftSubTree->printDFSInfix();
    std::cout << id << " ";
    if (rightSubTree != nullptr)
        rightSubTree->printDFSInfix();
}

