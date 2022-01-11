#include <iostream>
#include "bst.h"
using namespace std;

template <typename T>          
bool BST<T>::breakbond(const T& x)
{
    // This function should find the first bond that exceeds the value of x, break it and return
    // If no such bond exists, then simply return
    // When implementing, take note of the following:
    // 1. Search from the leftmost branch and iteratively move to the rightmost branch (similar to how we search from smallest value in normal BST search)
    // 2. But take note! that this is trying to find the 'bond' which is the absolute value of the difference in value instead of the value itself!
    // 3. Upon finding the first bond that is greater than the function parameter value x, break the bond and return. Careful: Only break the first bond that meets this criteria
    // 4. breakbond function should return true when a bond has been broken otherwise return false
    
    // Hint: You could consider taking advantage of the boolean returned for recursive call
    if(is_empty())
        return false;
    else{
        bool current_1 = false;
        bool current_2 = 0 ;
        if(root->left.root != nullptr){
            if(x < abs(this->root->value - root->left.root->value)){
                root->left.beKilled();
                return 1;
            }
            else
            { 
                  current_1= root->left.breakbond(x);
            }
        }
        
        if(root->right.root != nullptr && current_1 ==false ){
            if(x < abs(this->root->value - root->right.root->value)){
                root->right.beKilled();
                return 1;
            }
            else
            {
                current_2 = root->right.breakbond(x);
            
            }
        }
        return current_1 || current_2 || 0;
    
    
    }
    
}

template <typename T>
BST<T>::BST(const BST<T>& bst)
{
    // This function should perform deep-copy of one BST to another
    if(bst.is_empty()){
        return;
    }
    //delete this->root;//***not sure
    this->root = new BSTnode(*bst.root);
    
}

template <typename T>
int BST<T>::getMaxcounter() const
{
    // This function should find the maximum counter value of all the nodes present in BST
    // Base case
    if(is_empty()){
         return 0;
    }
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree 3) Max in right subtree
    int currentCounter = root->counter;
    int leftCounter = root->left.getMaxcounter();
    int rightCounter = root->right.getMaxcounter();
    return currentCounter = max(rightCounter,max(leftCounter,currentCounter));


}

template <typename T>
int BST<T>::getMaxHeight() const{
    // This function should return the maximum height of the BST
   
    if(this->is_empty()){
        return 0;
    }else{
        int leftHeight = root->left.getMaxHeight();
        int rightHeight = root->right.getMaxHeight();
        return max(leftHeight,rightHeight)+1;
    }
    
}

template <typename T>          
void BST<T>::insert(const T& x)
{
    // This function inserts the given value into the BST
    // If the value to be inserted already exists in the BST, remember to handle the counter!
    if(is_empty()){
        root = new BSTnode(x);
        root->counter = 1;
    }
    else if(x == root->value)
        (root->counter)++;
    else if (x < root->value)
        root->left.insert(x);  // Recursion on the left sub-tree

    else if (x > root->value)
        root->right.insert(x); // Recursion on the right sub-tree

    else // This line is optional; just for illustration
        ;                      // x == root->value; do nothing
}

template <typename T>
void BST<T>::mutate()
{
    // This function aims to mutate the virus such that it minimizes bond length while maintaining all the nodes
    // Write a function that reorders the nodes of the BST such that the bond length is minimized
    // This reordering can only occur if the height of the tree is at least 3. If less than 3, then do nothing.

    // NOTE: In the process of mutating, the virus BST loses information of its nodes' counter values.
    //       In another words, you do not need to worry about preserving the counter value when reordering the nodes!

    // Hint: 
    // 1. You could consider using operator[] if you have implemented it prior to this
    // 2. Suppose we have two nodes A and B. The bond length (difference between value of A and B) is minimal when
    //    there are no other nodes with value in between A and B. Hope this helps~
    if(getMaxHeight() < 3){
        return;
    }
    BST<T> tempTree;
    for(int i=0; i< totalNodes(); i++){
        tempTree.insert((*this)[(totalNodes()-i-1)]);
    }
    *this = tempTree;
   
}

template <typename T>
int BST<T>::totalNodes() const{

    // This function should return the total number of nodes present in the BST
    int total = 0;
    if (is_empty())
       return 0;
    else
        total++;

    return total+=(root->left.totalNodes()+root->right.totalNodes());
}
