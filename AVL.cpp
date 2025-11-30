#include <iostream>
#include <vector>
using namespace std;

struct AVL
{
    int val;
    AVL* left;
    AVL* right;
    int height;

    AVL(int v,AVL* l=nullptr,AVL* r=nullptr)
    {
        this->val=v;
        this->left=l;
        this->right=r;
        this->height=1;
    }

    ~AVL()
    {

    }

    int leftheight()
    {
        if(this->left)return this->left->height;
        return 0;
    }

    int rightheight()
    {
        if(this->right)return this->right->height;
        return 0;
    }

    int getbalance()
    {
        return this->leftheight()-this->rightheight();
    }

    AVL* balance()
    {
        int b=this->getbalance();
        if(b>1)
        {
            if(this->left->getbalance()>=0) return this->rr();
            else return this->lr();
        }
        else if(b<-1)
        {
            if(this->right->getbalance()>=0) return this->rl();
            else return this->ll();
        }
        else return this;
    }

    AVL* rr()
    {
        AVL* t=this->left;
        this->left=t->right;
        t->right=this;
        this->height=max(this->leftheight(),this->rightheight())+1;
        t->height=max(t->leftheight(),t->rightheight())+1;
        return t;
    }

    AVL* ll()
    {
        AVL* t=this->right;
        this->right=t->left;
        t->left=this;
        this->height=max(this->leftheight(),this->rightheight())+1;
        t->height=max(t->leftheight(),t->rightheight())+1;
        return t;
    }

    AVL* lr()
    {
        this->left=this->left->ll();
        return this->rr();
    }

    AVL* rl()
    {
        this->right=this->right->rr();
        return this->ll();
    }

    AVL* insert(int val)
    {
        if(val==this->val)
        {
            cout<<"Duplicate"<<endl;
            return this;
        }
        if(val<this->val)
        {
            if(this->left) this->left=this->left->insert(val);
            else this->left=new AVL(val);
            this->height=max(this->leftheight(),this->rightheight())+1;
            return this->balance();
        }
        else if(val>this->val)
        {
            if(this->right) this->right=this->right->insert(val);
            else this->right=new AVL(val);
            this->height=max(this->leftheight(),this->rightheight())+1;
            return this->balance();
        }
    }

    void inorder()
    {
        if(this->left)this->left->inorder();
        cout<<this->val<<" ";
        if(this->right)this->right->inorder();
    }

    void printTree(int space = 0, int indent = 5)
    {
        if (!this) return;

        // Increase distance between levels
        space += indent;

        // Print right child first
        this->right->printTree(space, indent);

        // Print current node after spaces
        cout << endl;
        for (int i = indent; i < space; i++)
            cout << " ";
        cout << this->val << "\n";

        // Print left child
        this->left->printTree(space, indent);
    }

};



int main()
{
    // Create the root of the tree
    AVL* root = new AVL(1);

    // Sequence that triggers all four rotations
    vector<int> values;
    for(int i=2;i<8;i++)values.push_back(i);
    for(int i=15;i>=8;i--)values.push_back(i);
    // This set will hit LL, RR, LR, and RL cases.

    cout << "Inserting values...\n";

    for (int v : values)
    {
        cout << "Insert " << v << endl;
        root = root->insert(v);
        root->printTree();
    }

    // Test duplicates
    cout << "Trying duplicate insert (should warn):\n";
    root = root->insert(20);

    cout << "\nFinal inorder traversal:\n";
    root->inorder();
    cout << "\n";

    root->printTree();

    return 0;
}
