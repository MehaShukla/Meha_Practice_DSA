/*
    link: https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

    sol: https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
*/

// ----------------------------------------------------------------------------------------------------------------------- //
class Solution
{
public:
    Node *prev = NULL;
    void inorder(Node *root)
    {
        //code here
        if (root==NULL){
            return;
        }
        inorder(root->right);
        if (root!=NULL){
            root->next = prev;
            prev = root;
        }
        inorder(root->left);
    }
};
/*
    using reverse inorder traversal
*/
/* Set next of p and all descendants of p by traversing them in reverse Inorder */
void inorder(node* p)
{
    // The first visited node will be the
    // rightmost node next of the rightmost
    // node will be NULL
    static node* next = NULL;

    if (p)
    {
        // First set the next pointer
        // in right subtree
        inorder(p->right);

        // Set the next as previously visited
        // node in reverse Inorder
        p->next = next;

        // Change the prev for subsequent node
        next = p;

        // Finally, set the next pointer in
        // left subtree
        inorder(p->left);
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by passing ref. variable
*/
// A wrapper over inorderRecur
void inorder(node* root)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    node* next = NULL;

    inorderRecur(root, &next);
}

/* Set next of all descendents of p by
traversing them in reverse Inorder */
void inorderRecur(node* p, node** next_ref)
{
    if (p)
    {
        // First set the next pointer in right subtree
        inorderRecur(p->right, next_ref);

        // Set the next as previously visited
        // node in reverse Inorder
        p->next = *next_ref;

        // Change the prev for subsequent node
        *next_ref = p;

        // Finally, set the next pointer in right subtree
        inorderRecur(p->left, next_ref);
    }
}