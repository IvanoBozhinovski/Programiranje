#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct BTNode
{
    int val;
    BTNode* left;
    BTNode* right;

    BTNode(int v=0)
    {
        this->val = v;
        this->left=this->right=nullptr;
    }

    void insert(int value)
    {
        queue<BTNode*> q;
        q.push(this);

        while (!q.empty())
        {
            BTNode* curr = q.front();
            q.pop();

            if (!curr->left)
            {
                curr->left =new BTNode(value);
                return;
            }
            else
            {
                q.push(curr->left);
            }

            if (!curr->right)
            {
                curr->right =new BTNode(value);
                return;
            }
            else
            {
                q.push(curr->right);
            }
        }
    }

    BTNode* find(int value)
    {
        if(val==value) return this;
        if (left)
        {
            return left->find(value);
        }
        if (right)
        {
            return right->find(value);
        }
        return nullptr;
    }

    void preorder()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        cout<<val<<' ';
        if(left) left->preorder();
        if(right) right->preorder();
    }

    void inorder()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        if(left) left->inorder();
        cout<<val<<' ';
        if(right) right->inorder();
    }

    void postorder()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        if(left) left->postorder();
        if(right) right->postorder();
        cout<<val<<' ';
    }

    void preorder_stack()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        stack<BTNode*> st;
        st.push(this);

        while(!st.empty())
        {
            BTNode* cur = st.top();
            st.pop();
            cout << cur->val <<' ';
            if (cur->right) st.push(cur->right);
            if (cur->left)  st.push(cur->left);
        }
    }

    void inorder_stack()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        stack<BTNode*> st;
        BTNode* cur = this;

        while(cur||!st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cout << cur->val <<' ';
            cur = cur->right;
        }
    }

    void postorder_stack()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        stack<BTNode*> st1, st2;
        st1.push(this);

        while(!st1.empty())
        {
            BTNode* cur = st1.top();
            st1.pop();
            st2.push(cur);

            if (cur->left)  st1.push(cur->left);
            if (cur->right) st1.push(cur->right);
        }

        while(!st2.empty())
        {
            cout << st2.top()->val <<' ';
            st2.pop();
        }
    }

    void BFS()
    {
        queue<BTNode*> q;
        q.push(this);

        while(!q.empty())
        {
            BTNode* cur = q.front();
            q.pop();
            cout<<cur->val<<' ';
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }

    int sum()
    {
        int sum=0;
        queue<BTNode*> q;
        q.push(this);

        while(!q.empty())
        {
            BTNode* cur=q.front();
            q.pop();
            sum+=cur->val;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return sum;
    }
};

struct BSTNode
{
    int val;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int v=0)
    {
        this->val = v;
        this->left=this->right=nullptr;
    }

    void insert(int value)
    {
        if(val==0)
        {
            val=value;
            return;
        }
        if (value<val)
        {
            if(left) left->insert(value);
            else left=new BSTNode(value);
        }
        else
        {
            if(right) right->insert(value);
            else right=new BSTNode(value);
        }
    }

    BSTNode* find(int value)
    {
        if(val==value) return this;
        if(value<val&&left) return left->find(value);
        if(value>val&&right) return right->find(value);
        return nullptr;
    }

    void preorder()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        cout<<val<<' ';
        if(left) left->preorder();
        if(right) right->preorder();
    }

    void inorder()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        if(left) left->inorder();
        cout<<val<<' ';
        if(right) right->inorder();
    }

    void postorder()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        if(left) left->postorder();
        if(right) right->postorder();
        cout<<val<<' ';
    }

    void preorder_stack()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        stack<BSTNode*> st;
        st.push(this);

        while(!st.empty())
        {
            BSTNode* cur = st.top();
            st.pop();
            cout << cur->val <<' ';
            if (cur->right) st.push(cur->right);
            if (cur->left)  st.push(cur->left);
        }
    }

    void inorder_stack()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        stack<BSTNode*> st;
        BSTNode* cur = this;

        while(cur||!st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cout << cur->val <<' ';
            cur = cur->right;
        }
    }

    void postorder_stack()
    {
        if(val==0)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        stack<BSTNode*> st1, st2;
        st1.push(this);

        while(!st1.empty())
        {
            BSTNode* cur = st1.top();
            st1.pop();
            st2.push(cur);

            if (cur->left)  st1.push(cur->left);
            if (cur->right) st1.push(cur->right);
        }

        while(!st2.empty())
        {
            cout << st2.top()->val <<' ';
            st2.pop();
        }
    }

    void BFS()
    {
        queue<BSTNode*> q;
        q.push(this);

        while(!q.empty())
        {
            BSTNode* cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
};

int main()
{
    ///Ova ne go pisuvav jas :)

    //BT
    cout << "=== Binary Tree Tests ===\n";

    BTNode* bt = new BTNode(10);
    int btValues[9] = {5, 20, 3, 7, 15, 30, 1, 6, 8};

    for (int v : btValues) {
        bt->insert(v);
    }

    cout << "BT Preorder:   ";
    bt->preorder();
    cout << "\n";

    cout << "BT Inorder:    ";
    bt->inorder();
    cout << "\n";

    cout << "BT Postorder:  ";
    bt->postorder();
    cout << "\n";

    cout << "BT BFS:        ";
    bt->BFS();
    cout << "\n";

    int targetBT = 15;
    cout << "Find " << targetBT << " in BT: ";
    cout << (bt->find(targetBT) ? "Found" : "Not Found") << "\n";

    cout << "BT Sum:        " << bt->sum() << "\n\n";


    //BST
    cout << "=== Binary Search Tree Tests ===\n";

    BSTNode* bst = new BSTNode(10);
    int bstValues[9] = {1, 5, 20, 3, 7, 15, 30, 6, 8};

    for (int v : bstValues) {
        bst->insert(v);
    }

    cout << "BST Preorder:  ";
    bst->preorder();
    cout << "\n";

    cout << "BST Inorder:   ";
    bst->inorder();
    cout << "\n";

    cout << "BST Postorder: ";
    bst->postorder();
    cout << "\n";

    cout << "BST BFS:       ";
    bst->BFS();
    cout << "\n";

    int targetBST = 7;
    cout << "Find " << targetBST << " in BST: ";
    cout << (bst->find(targetBST) ? "Found" : "Not Found") << "\n";

    cout << "\nDone.\n";

    return 0;
}