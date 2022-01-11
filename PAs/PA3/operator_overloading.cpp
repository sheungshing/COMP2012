#include "bst.h"

template <typename T>
const T& BST<T>::operator[](int i) const
{
    // This function overloads operator[] whereby when value i is indexed, the (i+1)th smallest value is returned
    
    // Hint: remember to handle out of bound indexing
    
    i = (i+totalNodes()*1000)%totalNodes();
    
     

            if(root->left.totalNodes() == i ){
                return root->value;
            }
            if(root->left.totalNodes() > i ){
                return (root->left)[i];
            }else {
                //int temp = (root->left.root) ? i-(root->left.totalNodes())-1 : i-1 ;
                return (root->right)[i-(root->left.totalNodes())-1];
            }
            //return (root->left.totalNodes() >i )?((root->left)[i]):(root->right)[i-(root->left.totalNodes())-1];
    
    

}

template <typename T>
BST<T> BST<T>::operator+(BST<T>& bst)
{
    // This function overloads operator+, this serves to illustrate when two BSTs merge into one BST
    // or in Virus-Cell-Vaccine scenario, it is when the Virus consumes the Cell
    // When the virus tries to consume the cell, it first needs to check if it has a node with counter value of at least 4.
    // If yes, then the virus will consume the cell, and else the virus does NOT consume and temp object of the virus created is returned from the function.

    // Suppose virus BST is A and cell BST is B. when we do A + B, return a new BST such that it's node values
    // are the same as when you insert all B's nodes from smallest to largest
    // NOTE: You only need to add each value of B once, in another words, you can ignore the counter value associated with the nodes of B

    // Hint: you could consider taking advantage of operator[] if you have implemented it before this!
    BST<T> tempTree(*this);
    if(tempTree.getMaxcounter() < 4){
        return tempTree;
    }else{
        for(int i =0 ; i< bst.totalNodes() ;i++){
            tempTree.insert(bst[i]);
        }
        bst.beKilled();
        return tempTree;
    }


}

template <typename T>
void BST<T>::operator++(int)
{
    //This function should increment counter value present in ALL nodes of the BST
    if(!is_empty()){
        (root->left)++;
        root->counter++;
        (root->right)++;
    }
       
}

template <typename T>
BST<T>& BST<T>::operator=(const BST& bst)
{
    // This function should overload the operator= such that it carries out deepcopy
    if(this != &bst){
        beKilled();
        root = new BSTnode (*bst.root);
        return *this;
    }
    return *this;
}