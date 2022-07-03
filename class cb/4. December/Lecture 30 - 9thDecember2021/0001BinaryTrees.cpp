#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildTree()
{
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    else
    {
        node*root=new node(data);           //creating the root node
        root->left=buildTree();         //for the left subtree
        root->right=buildTree();            //for the right subtree
        return root;            //returning the root
    }
}


void preorder(node*root)
{
    //base case
    if(root==NULL)
    {
        return;         //if root is null then return this
    }


    //recursive case
    cout<<root->data<<" ";           //print the data of the root
    preorder(root->left);           //to call on the left part
    preorder(root->right);          //calls on the right part
}


void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

}


void postorder(node*root)
{
    //base case
    if(root==NULL)
    {
        return;         //if root is null then return this
    }


    //recursive case
    preorder(root->left);           //to call on the left part
    preorder(root->right);          //calls on the right part
    cout<<root->data<<" ";           //print the data of the root
}


int countNodes(node*root)
{
    //base case
    if(root==NULL)
    {
        return 0;
    }

    //recursive case
    return 1+countNodes(root->left)+countNodes(root->right);
}

int height(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(height(root->left),height(root->right))+1;//to get the max of left subtree and right subtree and we add 1 for the root node
}

int sum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    return sum(root->left)+sum(root->right)+root->data;     //to get sum of left and right subtree and add the value of the root
}


void mirror(node*root)
{
    //base case
    if(root==NULL)
    {
        return;
    }

    //recursive case
    swap(root->left,root->right);           //to swap the left and the right sutree
    mirror(root->left);     //for the left part
    mirror(root->right);            //for the right part
}


int diameter(node*root)     //max distance between two nodes
{
    if(root==NULL)
    {
        return 0;
    }

    //if the diameter passes through the left subtree
    int op1=diameter(root->left);

    //if diameter passes through the right subtree
    int op2=diameter(root->right);


    //if the diameter passes through the root node

    int op3=height(root->left)+height(root->right);     //height is equal to the diameter of the subtree

    return max(op1,max(op2,op3));       //returns the max of the three options
}


class Pair{
    public:
    int height;
    int diameter;
    Pair()
    {
        height=0;
        diameter=0;
    }
};


Pair fastdiameter(node*root)
{
    Pair p;         //creating the pair
    if(root==NULL)
    {
        p.height=0;
        p.diameter=0;
        return p;
    }

    //recursive case
    Pair left=fastdiameter(root->left);         //calling it on the left part
    Pair right=fastdiameter(root->right);           //calling it on the right part
    p.height=max(left.height,right.height)+1;      //when it passes through the root node


    int op1=left.height+right.height;           //if max passes through the root node
    int op2=left.diameter;
    int op3=right.diameter;
    p.diameter=max(op1,max(op2,op3));          //to get the maximum diameter of the three options

    return p;
}

void printLevelWiseReversed(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    stack<node*> s;
    while(!q.empty())
    {
        node*x = q.front();
        q.pop();
        s.push(x);
        if(x->right)                //first we have to do the right part for reverse level order traversal
        {
            q.push(x->right);
        }
        if(x->left)
        {
            q.push(x->left);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

void printLevelWise(node*root)
{
    queue<node*> q;         //to hold the elements of the tree
    q.push(root);       //to put in the first root node
    q.push(NULL);               //to put in NULL after the root node
    while (!q.empty())
    {
        node*x=q.front();       //to get the front element of the queue and hold its value
        q.pop();        //to remove that element from the queue --> otherwise the queue will not get empty
        if(x==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {   //null in the queue defines line change
                q.push(NULL);//if the queue is not empty then we push null to the queue as there are other elements that needs to be printed
            }
        }
        else
        {
            cout<<x->data<<" ";     //after printing the data of x then we put it's children in the queue
            if(x->left!=NULL)
            {
                q.push(x->left);        //if the left child exists i.e !=null then we put that in the queue
            }
            if(x->right!=NULL)
            {
                q.push(x->right);       //if the right child exists i.e !=null then we put that in the queue
            }
        }
    }
}



node*buildTreeLevelWise()
{
    node*root=NULL;     //creating the root of the tree

    int data;       //the data that needs to be pushed in the root
    cin>>data;
    if(data==-1)
    {
        return NULL;        //if data is -1 node does not exist
    }
    root=new node(data);        //putting the value in the root node

    queue<node*> q;         //taken this queue so that we can store all the children present on the same level of the node
    q.push(root);       //so that we can get all the children of the nodes


    while (!q.empty())      //till the time queue is not empty
    {
        node*x=q.front();       //to get the front element of the queue
        q.pop();            //to remove the front element

        cout<<"The the data for the left and right children of"<<x->data<<endl;
        int leftData,rightData;
        cin>>leftData>>rightData;       //to get the value of the children

        if(leftData!=-1)
        {
            x->left->data=leftData;//to put the value of the left child left to the node under consideration that is stored in the x pointer
            q.push(x->left);        //it is added to the queue so that we can find it's children
        }
        if(rightData!=-1)
        {
            x->right->data=rightData; //to put the value of the right node in place
            q.push(x->right);  //it is added to the queue so that we can find it's children
        }
        }
        return root;
}



int pre[]={8,3,1,6,4,7,16,14,13};       //preorder array to create tree
int in[]={1,3,4,6,7,8,16,13,14};            //inorder array to create tree
int i=0;


node*createTree(int s, int e)
{
    //base case
    if(s>e)                     //when there is no element left in the array
    {
        return NULL;
    }


    //recursive case
    int d=pre[i++];//so that we get the information about the root node. i++ increases i after use so that we can get the next root from the preorder array
    node*root=new node(d); //creating a root node from the data received
    int k=-1;       //to hold index value of the matching element ----> set to -1 as it is not a valid index
    for(int j=s;j<=e;j++)
    {
        if(in[j]==d)
        {
            k=j;
            break;
        }
    }
    root->left=createTree(s,k-1);       //attaching left subtree to the root node
    root->right=createTree(k+1,e);      //attaching the right subtree to the right of the root node

    return root;            //returns once it gets attached to its right subtree and the left subtree
}


node*insertBST(node*root,int data)
{
    if(root==NULL)
    {
        root=new node(data);        //if the binary tree is still not formed then we form the root node using DMA.
    }


    else if(data<=root->data)
    {//when we get in this then root->left is still not formed so when it calls inserBST it takes root->left as null and so it forms a new node
        root->left=insertBST(root->left,data);//if the data is less than the root then it needs to get attached to the left part of the tree
    }

    else if(data>root->data)
    {
        root->right=insertBST(root->right,data);//if the data is greater than the root node then attach it to the right of the binary tree
    }


    return root;        //returns the root once formed
}



node*buildBinarySearchTree()
{
    node*root=NULL;         //inititally the root created points to NULL
    int data;
    cin>>data;
    while (data!=-1)
    {
       root=insertBST(root,data);
       cin>>data;           //keeps on taking data till it gets -1
    }
    return root;        //finally returns the root when the entire tree is formed
}



bool searchinBST(node*root,int key)
{
    //base case
    if(root==NULL)
    {
        return false;
    }


    //recursive case
    if(key==root->data)
    {
        return true;            //data found
    }
    else if(key<root->data)
    {
        return searchinBST(root->left,key);
    }
    else if(key>root->data)
    {
        return searchinBST(root->right,key);
    }


    return false;//just to handle the warning at the time of execution due to the fact that every return statement is in the if conditions and so it is showing warning
}



void printRange(node*root,int k1,int k2)
{
    //base case
    if(root==NULL)
    {
        return;
    }

    //recursive case
    printRange(root->left,k1,k2);           //to call recursion on the left subtree
    if(root->data>=k1&&root->data<=k2)              //I am printing the value of the node if it is in the range
    {
        cout<<root->data<<" ";
    }
    printRange(root->right,k1,k2);          //to call recursion on the right subtree
}



bool isBST(node*root,int min=INT_MIN,int max=INT_MAX)
{
    //base case
    if(root==NULL)
    {
        return true;            //null root is BST so it returns true
    }


    //recursive case
    if(root->data>=min&&root->data<=max&&isBST(root->left,min,root->data)&&isBST(root->right,root->data,max)) //it checks whether the root data is in a valid range and the left and right subtree should be BST
    {
        return true;
    }
    else
    {
        return false;
    }

}



class pairForBalancedTree{         //for checking if a tree is balanced or not
    public:
    int height;
    bool balanced;
    pairForBalancedTree()
    {
        height=0;
        balanced=true;
    }
};



pairForBalancedTree isBalanced(node*root)
{
    pairForBalancedTree p;
    //base case
    if(root==NULL)
    {
        return p;
    }

    //recursive case
    pairForBalancedTree left=isBalanced(root->left);       //for the left subtree
    pairForBalancedTree right=isBalanced(root->right);             //for the right subtree
    p.height=max(left.height,right.height)+1;           //for the entire pair

    if(left.balanced==true&&right.balanced==true&&abs(left.height-right.height)<=1)//we are checking the if the left and right subtree is balanced and the difference in the height of the left and the right subtree is less than or equal to 1
    {
        p.balanced=true;
    }
    else
    {
        p.balanced=false;
    }

    return p;       //returning the final p formed

}



class linkedList{
    public:
    node*head;
    node*tail;
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
};

linkedList BSTtoLinkedList(node*root)       //node passed is of BST
{
    linkedList l;           //creating a new linked list
    //base case
    if(root==NULL)
    {
        return l;
    }


    //recursive case
    //case 1 --> when right and left of the root node is NULL
    if(root->right==NULL&&root->left==NULL)
    {
        l.head=root;
        l.tail=root;
        return l;
    }
    //case 2 --> when left subtree is not NULL and right subtree is NULL
    else if(root->left!=NULL&&root->right==NULL)
    {
        linkedList left=BSTtoLinkedList(root->left);    //creating a new linked list to hold the left linked list formed
        left.tail->right=root;  //left is a linked list therefore left.tail but ->right comes as the value it holds at tail is a node of the tree
        //we have taken right pointer of the node but we can take any pointer right or left of the elements in linked list
        l.head=left.head;
        l.tail=root;

        return l;
    }
    //case 3 --> when right subtree is not equal to NULL but left subtree is equal to NULL
    else if(root->left==NULL&&root->right!=NULL)
    {
        linkedList Right=BSTtoLinkedList(root->right);
        root->right=Right.head;
        l.head=root;
        l.tail=Right.tail;

        return l;
    }
    else
    {
        linkedList left=BSTtoLinkedList(root->left);
        linkedList Right=BSTtoLinkedList(root->right);  //as we are using the right pointer so to stop confusion we take name of linked list as  Right with capital R
        left.tail->right=root;  //as the element at tail is node so we use its right pointer
        root->right=Right.head;
        l.head=left.head;           //putting it in the final linked list after forming links
        l.tail=Right.tail;


        return l;       //returning the formed linked list
    }
}



void printll(node*head)
{
    while (head!=NULL)
    {
        cout<<head->data<<"-->";        //head->data is defined as head points to a node and data is defined for node
        head=head->right;       //we use right because it points to the head
    }
    cout<<"NULL"<<endl;
}

node* createBSTUsingSortedArray(int*arr,int s,int e)
{
    //base case
    if(s>e)
    {
        return NULL;
    }

    //recursive case
    int mid=(s+e)/2;
    node*root=new node(arr[mid]);       //creating root using mid data
    root->left=createBSTUsingSortedArray(arr,s,mid-1);      //for the left subtree
    root->right=createBSTUsingSortedArray(arr,mid+1,e);     //for the right subtree

    return root;        //returns the tree formed
}


node* deleteElementsInBST(node*root,int key)
{
    //case 1 --> if root->data > key --> search in the left subtree
    if(root->data>key)
    {
        root->left=deleteElementsInBST(root->left,key);     //calls on the left subtree and attaches it to the left of the root after deletion
        return root;
    }
    else if(root->data<key)
    {
        root->right=deleteElementsInBST(root->right,key);
        return root;
    }
    else
    {
        //no child
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
        }


        //one child
        //case 1 when left child is present and right child is not present
        if(root->left!=NULL&&root->right==NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;    //we return temp as it will automatically attach itself to the root node
        }


        //case 2 when left child is not present and the right child is present
        if(root->left==NULL&&root->right!=NULL)
        {
            node*temp=root->right;   //holds the left child
            delete root;        //deletes the root element
            return temp;    //when temp is returned it forms link with the root before it automatically
        }

        //two children
        else
        {
            node*replace=root->right;   //to hold the right of the root to be deleted
            while (replace->left!=NULL)
            {
                replace=replace->left;  //to reach the min. element of the right subtree that is the --> leftmost element of the tree
            }
            swap(root->data,replace->data);
            root->right=deleteElementsInBST(root->right,replace->data); //deletes the value held by replace that is the previous root node value

            return root;
        }
    }
}


void rightView(node*root,int level,int &maxlevel)   //we pass maxlevel using reference so that change persists when it is returned
{       //reference allows us to hold the value even on return and it remains intact.
    //base case
    if(root==NULL)
    {
        return;
    }


    //recursive case
    if(level>maxlevel)          //if level is greater than maxlevel printed then that node will be visible as it will not be able to hide behind any other node so we print that
    {
        cout<<root->data<<" ";
        maxlevel=level; //we replace the maxlevel with level every time we print the node
    }

    rightView(root->right,level+1,maxlevel);        //we first call on the right subtree as it is right view
    rightView(root->left,level+1,maxlevel);     //we then call on the left subtree so that any element on a level greater then maxlevel gets printed
}


int main()
{
    // node*root=buildTree();      //it is holding the address of the root so when it is passed in the mirror then it alters the entire structure
    // preorder(root);

    // cout<<endl;
    // mirror(root);
    // preorder(root);



    // cout<<endl;
    // cout<<"The diameter of the tree is : "<<diameter(root)<<endl;


    // cout<<endl;
    // Pair x=fastdiameter(root);
    // cout<<"The diameter of the tree using O(N) approach : "<<x.diameter<<endl;


    // cout<<endl;
    // cout<<"Printing the tree in level order :- "<<endl;
    // printLevelWise(root);


    cout<<endl;
    cout<<"Binary search tree :"<<endl;
    node*rootOfBSTTree=buildBinarySearchTree();
    printLevelWise(rootOfBSTTree);


    // cout<<endl;
    // cout<<"Creating tree using preorder and inorder arrays :"<<endl;
    // int start=0;
    // int end=sizeof(in)/sizeof(int);
    // node*rootOfTreeCreatedByPreorderAndInorder=createTree(start,end-1);
    // printLevelWise(rootOfTreeCreatedByPreorderAndInorder);


    // cout<<endl;
    // cout<<"Searching in the BST, enter the element to be searched"<<endl;
    // int n;
    // cin>>n;
    // bool ans=searchinBST(rootOfBSTTree,n);      //searching in the BST
    // if(ans)
    // {
    //     cout<<"Element found"<<endl;
    // }
    // else
    // {
    //     cout<<"Element not found";
    // }



    // cout<<endl;
    // cout<<"Checking if the tree is BST or not :- "<<endl;
    // bool ans=isBST(rootOfBSTTree);
    // if(ans)
    // {
    //     cout<<"Yes it is BST"<<endl;
    // }
    // else
    // {
    //     cout<<"No it is not BST"<<endl;
    // }




    // cout<<endl;
    // cout<<"Converting BST to sorted linked list :-"<<endl;
    // linkedList hold=BSTtoLinkedList(rootOfBSTTree);     //created hold linked list to hold the returned linked list
    // printll(hold.head);     //passing head of the returned linked list



    // cout<<endl;
    // cout<<"The BST formed from the array is :-"<<endl;
    // int arr[]={1,3,4,6,7,8,10,13,14};       //sorted array to form the linked list
    // int e=(sizeof(arr)/sizeof(int))-1;
    // node*rootHold=createBSTUsingSortedArray(arr,0,e);
    // printLevelWise(rootHold);
    // cout<<"Checking if the tree formed is BST :-"<<endl;
    // if(isBST(rootHold))
    // {
    //     cout<<"Yes the tree formed is BST";
    // }
    // else
    // {
    //     cout<<"No the tree formed is not BST";
    // }



    // cout<<endl;
    // cout<<"Enter the key to be deleted"<<endl;
    // int key;
    // cin>>key;
    // cout<<"BST after deletion of the key : "<<key<<" is :-"<<endl;
    // node*rootAfterDeletion=deleteElementsInBST(rootOfBSTTree,key);
    // printLevelWise(rootAfterDeletion);




    return 0;

}
