#include <iostream>
using namespace std;
#include "bst.h"
#include "tree_functions.cpp"
#include "operator_overloading.cpp"

int main(){
    int testCase = 1;
    cout << "Please enter the test case number: ";
    cin >> testCase;
    cout << endl;

    cout << "============================================" << endl;
    cout << "Showing the output for test case " << testCase << ":" << endl;

    if (testCase==1){
        // Testing insert() function
        int virus_sequence[] = {14, 8, 12, 14, 19, 11, 7, 7, 2, 11};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        cout<<"Testing insert() function"<<endl;
        virus_tree.print();
    }
    else if (testCase==2){
        // Testing getMaxHeight function
        int virus_sequence[] = {14, 8, 12, 14, 19, 11, 7, 7, 2, 11};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Testing getMaxHeight() function"<<endl;
        cout<<"Maximum height of the tree: "<<virus_tree.getMaxHeight()<<endl;
    }
    else if (testCase==3){
        // Testing getMaxCounter function
        int virus_sequence[] = {11, 1, 2, 2, 18, 20, 14, 17, 5, 4, 2, 6, 10, 15, 17, 10, 19, 1, 8, 12};
        BST<int> virus_tree;
        for (int i = 0; i<20; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Testing getMaxcounter() function"<<endl;
        cout<<"Maximum counter present in the tree: "<<virus_tree.getMaxcounter()<<endl;
    }
    else if (testCase==4){
        // Testing totalNodes function
        int virus_sequence[] = {17, 11, 10, 8, 17, 20, 14, 12, 10, 13, 2, 6, 12, 3, 11};
        BST<int> virus_tree;
        for (int i = 0; i<15; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Testing totalNodes() function"<<endl;
        cout<<"Total number of nodes in the tree: "<<virus_tree.totalNodes()<<endl;
    }
    else if (testCase==5){
        // Testing breakbond function
        int virus_sequence[] = {17, 16, 18, 12, 17, 20, 14, 12, 10, 13, 2, 6, 12, 3, 11};
        BST<int> virus_tree;
        for (int i = 0; i<15; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Testing breakbond() function"<<endl;
        cout<<"Breaking bond with strength 2"<<endl;

        // Vaccine of strength 2 in action
        virus_tree.breakbond(2);
        virus_tree.print();
    }
    else if (testCase==6){
        // Testing operator= function
        int virus_sequence[] = {17, 16, 18, 12, 17, 20, 14, 12, 10, 13, 2, 6, 12, 3, 11};
        BST<int> virus_tree;
        for (int i = 0; i<15; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        BST<int> clone;
        clone = virus_tree;

        int new_sequence[] = {3, 4, 5};
        for (int i = 0; i<3; i++){
            virus_tree.insert(new_sequence[i]);
        }

        cout<<"Testing operator=() function"<<endl;
        cout<<"Original virus after when adding more sequence after cloning"<<endl;
        virus_tree.print();
        cout<<"Cloned virus"<<endl;
        clone.print();
        cout<<"If deepcopy was successful, the virus and the clone should NOT be the same"<<endl;
    }
    else if (testCase==7){
        // Testing deepcopy constructor
        int virus_sequence[] = {6, 10, 6, 8, 15, 11, 14, 12, 8, 7};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        BST<int> clone(virus_tree);

        int new_sequence[] = {3, 4, 5};
        for (int i = 0; i<3; i++){
            virus_tree.insert(new_sequence[i]);
        }

        cout<<"Testing deepcopy constructor"<<endl;
        cout<<"Original virus after when adding more sequence after cloning"<<endl;
        virus_tree.print();
        cout<<"Deepcopied virus"<<endl;
        clone.print();
        cout<<"If deepcopy was successful, the virus and the Deepcopied virus should NOT be the same"<<endl;
    }
    else if (testCase==8){
        // Testing operator++ function
        int virus_sequence[] = {14, 9, 18, 2, 7, 11, 1, 2, 9, 13, 10, 9, 11, 16, 12, 4, 15, 3, 20, 11};
        BST<int> virus_tree;
        for (int i = 0; i<20; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        
        cout<<"Testing operator++ function"<<endl;
        cout<<"Before operator++"<<endl;
        virus_tree.print();
        cout<<"After operator++"<<endl;
        virus_tree++;
        virus_tree.print();
    }
    else if (testCase==9){
        // Testing operator[] function
        int virus_sequence[] = {8, 18, 16, 13, 12, 13, 5, 13, 2, 1, 14, 1, 17, 16, 14, 6, 1, 15, 19, 6};
        BST<int> virus_tree;
        for (int i = 0; i<20; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        
        cout<<"Testing operator[] function"<<endl;
        virus_tree.print();
        for (int i=-25; i < 35; i+=5){
            cout<<"Index at: "<<i<<" is "<<virus_tree[i]<<endl;
        }
    }
    else if (testCase==10){
        // Testing operator+ function
        int virus_sequence[] = {6, 17, 15, 13, 1, 2, 1, 10, 3, 7, 3, 1, 10, 19, 10, 13, 9, 17, 16, 1};
        BST<int> virus_tree;
        for (int i = 0; i<20; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        
        int cell_sequence[] = {13, 10, 8, 17, 13, 2, 16, 10, 14, 15};
        BST<int> cell_tree;
        for (int i = 0; i<10; i++){
            cell_tree.insert(cell_sequence[i]);
        }

        cout<<"Testing operator+ function"<<endl;
        BST<int> new_virus;
        new_virus = virus_tree + cell_tree;

        cout<<"Consumption should be successful"<<endl;
        cout<<"After consumption:"<<endl;
        cout<<"Original virus tree:"<<endl;
        virus_tree.print();
        cout<<"Temp object returned:"<<endl;
        new_virus.print();
        cout<<"Cell tree should have been killed"<<endl;
        cell_tree.print();
        cout<<"Printing finished"<<endl;
    }
    else if (testCase==11){
        // Testing operator+ function version2
        int virus_sequence[] = {1, 1, 3, 13, 16, 11, 18, 1, 11, 17};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        
        int cell_sequence[] = {13, 10, 8, 17, 13, 2, 16, 10, 14, 15};
        BST<int> cell_tree;
        for (int i = 0; i<10; i++){
            cell_tree.insert(cell_sequence[i]);
        }

        cout<<"Testing operator+ function"<<endl;
        BST<int> new_virus;
        new_virus = virus_tree + cell_tree;

        cout<<"Consumption should not be successful"<<endl;
        cout<<"After consumption:"<<endl;
        cout<<"Original virus tree:"<<endl;
        virus_tree.print();
        cout<<"Temp object returned:"<<endl;
        new_virus.print();
        cout<<"Cell tree should NOT have been killed"<<endl;
        cell_tree.print();
        cout<<"Printing finished"<<endl;
    }
    else if (testCase==12){
        // Testing mutate function
        cout<<"Testing mutate() function. This test assumes your breakbond() implementation is done and correct"<<endl;
        int virus_sequence[] = {7, 2, 4, 3, 9, 6, 1, 5, 8, 0};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        
        if (virus_tree.breakbond(2))
            cout<<"Non-mutated virus bond broken by vaccine"<<endl;
        else
            cout<<"Non-mutated virus bond not affected by vaccine"<<endl;

        BST<int> new_virus;
        for (int i = 0; i<10; i++){
            new_virus.insert(virus_sequence[i]);
        }
        new_virus.mutate();
        if (new_virus.breakbond(2))
            cout<<"Mutated virus bond broken by vaccine"<<endl;
        else
            cout<<"Mutated virus bond not affected by vaccine"<<endl;
    }
    cout << "============================================" << endl << endl;
    return 0;
}
