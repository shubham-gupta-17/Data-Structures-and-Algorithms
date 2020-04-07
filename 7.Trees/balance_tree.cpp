int k=-1;
  vector<int> a;
void inorder(TreeNode*root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    a.push_back(root->val);
    inorder(root->right);
    return ;
}
BSTIterator::BSTIterator(TreeNode *root) {

   
    inorder(root);
   
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(k==a.size()-1)
    return false;
    
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    k++;
    return a[k];
}