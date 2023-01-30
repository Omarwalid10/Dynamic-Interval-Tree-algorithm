#include <iostream>
using namespace std;
//this class have the low ,high ,max of the interval node and the left and right children of it
class IntervalNode{
public: int r,l,max;
public: IntervalNode* left;
public: IntervalNode* right;
    //this is the default constructor
    IntervalNode(){
        this->r=0;
        this->l=0;
        max=0;
        left=right= nullptr;
    }
    //this is the parametrized constructor
    IntervalNode(int l,int r){
        this->l=l;
        this->r=r;
        max=r;
        left=right= nullptr;
    }
    //to check the ll , rr of any node make overlap of the current node or not
    bool intersection(int ll, int rr){
        if((this->l < ll && this->r > ll)|| (this->l < rr && this->r > rr)){
            return true;
        }
        return false;
    }
};
//this class to hold the root node and all nodes of the interval tree
class IntervalTree{
    //this is the root of the tree
public: IntervalNode* root;
    //to initialize the root on the first construct of the tree
    IntervalTree(){
        root= nullptr;
    }
    //this fun make the insert of new node and update the max value of the all nodes in the tree
    void insert(int ll,int rr){
        //check the tree is empty or not
        if(root== nullptr){
            root=new IntervalNode(ll,rr);
        }
        //when the tree is not empty
        else{
            //make node parent to know the parent of the current node and insert the new node in his right pointer or left pointer
            IntervalNode *parent;
            IntervalNode *current=root;
            //to know the new node but it in the right side or the left side
            bool right= true;
            //to iterate on the path from the root to the place where we put the new node on it
            while(current!= nullptr){
                //to save the parent of the current when the while loop end
                parent=current;
                //we iterate here in the same method of the binary search tree go to right when bigger and left when smaller
                //but with the low value of the all nodes not the bigger value
                if(current->l > ll){
                    right= false;
                    if(rr > current->max){
                        current->max=rr;
                    }
                    current=current->left;
                }
                else{
                    right= true;
                    if(rr > current->max){
                        current->max=rr;
                    }
                    current=current->right;
                }
            }
            //insert the new node in the correct place right or left
            if(right){
                parent->right=new IntervalNode(ll,rr);
            }
            else{
                parent->left=new IntervalNode(ll,rr);
            }
        }
    }
    //to check the overlap
     void searchAllOverlap(int ll,int rr) {
        IntervalNode * current =root;
        bool found=false;
        int arr[200],i=0;
        while(current!= nullptr){
           // cout<<"1"<<endl;
            if(current->intersection(ll,rr)) {
                //first intersection
                if(!found){
                    cout<<"the ( "<<ll<<" , "<<rr<<" ) Interval is overlap with ---> "<<endl;
                }
                cout<<" ( "<<current->l<<" , "<<current->r<<" ) "<<endl;
                arr[i]=current->l;
                i++;
                arr[i]=current->r;
                i++;
                this->deleteNode(current->l,current->r);
                found= true;
                current= this->root;
                continue;
                //if we need one intersection add break in here
            }
            //to check if the max value of the left or the left not found go to right
            if(current->left== nullptr||current->left->max<ll) {
                current = current->right;
              //  cout<<"right"<<endl;
            }
            else{
              //  cout<<"left"<<endl;
                current=current->left;
            }
        }
        //when we not found any intersection

        if(!found){
            cout<<"the interval( "<<ll<<" "<<rr<<" ) not found any intersection!!!!!!!!!"<<endl;
        }
        else{
            for (int j = 0; j < i; j+=2) {
               // cout<<arr[j]<<" "<<arr[j+1]<<endl;
                this->insert(arr[j],arr[j+1]);
            }

        }
    }
    //this function to delete the node and update the max value of the all nodes in the tree
    void deleteNode(int ll, int rr){
        //make node parent to know the parent of the current node and delete node in his right pointer or left pointer
        IntervalNode * current =root;
        IntervalNode * parent= current;
        //to check we found it and to check this node is in the right or left of the parent node
        bool found=false,right=true;
        while(current!= nullptr&&!found){
            //when we find the node we want to delete it
            if(current->l==ll&&current->r==rr) {
                found=true;
                //when the node is leaf node
                if(current->left== nullptr&&current->right== nullptr){
                    if(right)parent->right= nullptr;
                    else parent->left= nullptr;
                    delete current;
                }
                //when it is interval node but have one child
                else if(current->left== nullptr&&current->right!= nullptr){
                    //when the root is deleted
                    if(current==root){
                        root = root->right;
                    }
                    else {
                        if (right) parent->right = current->right;
                        else parent->left = current->right;
                    }
                    delete current;
                }
                else if(current->left!= nullptr&&current->right== nullptr){
                    //when the root is deleted
                    if(current==root){
                        root=root->left;
                    }
                    else {
                        if (right)parent->right = current->left;
                        else parent->left = current->left;
                    }
                    delete current;
                }
                //when it is interval node but have two child we use the predecessor method to delete it
                //predecessor
                else{
                    IntervalNode *pred =  current-> right;
                    IntervalNode *predParent=current;
                    bool left= false;
                    while (pred -> left != nullptr) {
                        left=true;
                        predParent=pred;
                        pred = pred->left;
                    }

                    if(left) {
                        current->l=pred->l;
                        current->r=pred->r;
                        predParent->left = nullptr;
                        delete pred;
                    }
                    else {
                        //when the root is deleted
                        if(current==root){
                            pred->left=current->left;
                            root=pred;
                        }
                        else {
                            if (right) {
                                pred->left = current->left;
                                parent->right = pred;
                            } else {
                                pred->left = current->left;
                                parent->left = pred;

                            }
                        }
                        delete current;

                    }
                }
            }
            //when we not found go to the right or left like binary search tree
            else if(current->l > ll) {
                parent=current;
                right=false;
                current=current->left;
                //cout<<"left"<<endl;
            }
            else{
                parent=current;
                right=true;
                current = current->right;
                //cout<<"right"<<endl;
            }
        }
        if(!found)cout<<"the Tree doesn't have this node to delete!!!!"<<endl;
        else cout<<"the node deleted "<<ll<<" "<<rr<<endl;
        updatePreorder(root);
    }
    //use the following 3 functions to update the max value in the tree when we delete any node
    void updateNode(IntervalNode *node){
        int max=node->r;
        int max2=update(node,max);
        node->max=max2;
    }
    int update(IntervalNode *current,int currentMax){
        if (current == nullptr)
            return currentMax;
        if( current->r>= currentMax )   currentMax=current->r;
        update(current->left, currentMax);
        update(current->right, currentMax);
    }
    void updatePreorder(IntervalNode* node)
    {
        if (node == nullptr)
            return;
        /* first print data of node */
        updateNode(node);

        /* then recur on left subtree */
        updatePreorder(node->left);

        /* now recur on right subtree */
        updatePreorder(node->right);
    }
    //to print the tree nodes
    void printPreorder(IntervalNode* node)
    {
        if (node == nullptr)
            return;

        /* first print data of node */
        cout << node->l<<" "<<node->r <<" max = "<<node->max <<endl;

        /* then recur on left subtree */
        printPreorder(node->left);

        /* now recur on right subtree */
        printPreorder(node->right);
    }
};
int main()
{
 // the test cases  :
 // the first tree :
IntervalTree tree;
//test of insert:
cout<<"#######      the first tree      ########"<<endl<<endl;
tree.insert(17,19);
tree.insert(21,24);
tree.insert(5,8);
tree.insert(4,8);
tree.insert(15,18);
tree.insert(16,22);
tree.insert(7,10);
cout<<"print Tree in preorder method before delete and search: "<<endl;
cout<<endl;
tree.printPreorder(tree.root);
cout<<endl;
//the 10 test cases of the first tree:
tree.searchAllOverlap(16,20);
//    tree.printPreorder(tree.root);
tree.searchAllOverlap(17,25);
//    tree.printPreorder(tree.root);
tree.searchAllOverlap(3,7);
tree.searchAllOverlap(9,20);
tree.searchAllOverlap(10,16);
tree.searchAllOverlap(23,25);
tree.searchAllOverlap(20,20);
tree.searchAllOverlap(12,14);
tree.searchAllOverlap(11,13);
tree.searchAllOverlap(2,3);
cout<<endl;
cout<<"print Tree in preorder method after search: "<<endl;
cout<<endl;
tree.printPreorder(tree.root);
cout<<endl;
//test of delete:
tree.deleteNode(16,22);
tree.deleteNode(5,8);
tree.deleteNode(3,3);
cout<<"print Tree in preorder method after delete: "<<endl;
tree.printPreorder(tree.root);



// the test cases  :
// the second tree :
IntervalTree tree1;
//test of insert:
cout<<"#######      the second tree      ########"<<endl<<endl;
tree1.insert(15,40);
tree1.insert(10,28);
tree1.insert(16,23);
tree1.insert(5,24);
tree1.insert(11,16);
tree1.insert(18,60);
cout<<"print tree1 in preorder method before delete or search: "<<endl;
cout<<endl;
tree1.printPreorder(tree1.root);
cout<<endl;
//the 10 test cases of the second tree:
tree1.searchAllOverlap(11,12);
tree1.searchAllOverlap(8,9);
tree1.searchAllOverlap(4,7);
tree1.searchAllOverlap(6,20);
tree1.searchAllOverlap(7,16);
tree1.searchAllOverlap(22,25);
tree1.searchAllOverlap(20,20);
tree1.searchAllOverlap(61,66);
tree1.searchAllOverlap(1,2);
tree1.searchAllOverlap(2,3);
cout<<endl;
cout<<"print tree1 in preorder method after search: "<<endl;
cout<<endl;
tree1.printPreorder(tree1.root);
//test of delete:
tree1.deleteNode(18,60);
tree1.deleteNode(5,8);
tree1.deleteNode(3,3);
cout<<"print tree1 in preorder method after delete: "<<endl;
tree1.printPreorder(tree1.root);

// the test cases  :
// the third tree :
IntervalTree tree2;
cout<<"#######      the third tree      ########"<<endl<<endl;
//test of insert:
tree2.insert(20,36);
tree2.insert(3,41);
tree2.insert(29,99);
tree2.insert(0,1);
tree2.insert(10,15);
cout<<"print tree2 in preorder method before delete or search: "<<endl;
cout<<endl;
tree2.printPreorder(tree2.root);
cout<<endl;
//the 10 test cases of the third tree:
tree2.searchAllOverlap(14,17);
tree2.searchAllOverlap(8,9);
tree2.searchAllOverlap(4,7);
tree2.searchAllOverlap(10,20);
tree2.searchAllOverlap(10,16);
tree2.searchAllOverlap(22,25);
tree2.searchAllOverlap(98,155);
tree2.searchAllOverlap(20,20);
tree2.searchAllOverlap(100,166);
tree2.searchAllOverlap(2,2);
cout<<endl;
cout<<"print tree2 in preorder method after search: "<<endl;
cout<<endl;
tree2.printPreorder(tree2.root);
//test of delete:
tree2.deleteNode(0,1);
tree2.deleteNode(3,41);
tree2.deleteNode(3,4);
cout<<"print tree2 in preorder method after delete: "<<endl;
tree2.printPreorder(tree2.root);


}
