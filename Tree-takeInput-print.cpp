#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>

class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data)
    {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelwise()
{
    int rootData;
    cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    
    return root;
    
}


void printLevelWise(TreeNode<int>* root) {
    
    if(root==NULL)
    {
        return;
    }
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
   
    while(pendingNode.size()!=0)
    {
        TreeNode<int> * front = pendingNode.front();
        pendingNode.pop();
       
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            
            if(i==(front->children.size()-1))
            {
                cout<<front->children[i]->data;
                pendingNode.push(front->children[i]);
            }else{
                cout<<front->children[i]->data<<",";
            pendingNode.push(front->children[i]);
            }
            
        }
        
        cout<<endl;
    }
}


int main()
{
    TreeNode<int> * root = takeInputLevelwise();
    printLevelWise(root);
}
