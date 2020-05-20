#include <iostream>
#include <string>

#define MAX_INT 2147483647

using namespace std;

//Collaborated with Patrick Doran and referenced pseudocode in textbook

struct Node
{
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
};

Node* Create(int data)
{
    Node* temp = new Node();
    temp->data = data;

    return temp;
}

Node* Minimum(Node* temp)
{
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* Search(Node* tree, int target)
{
    if(tree == NULL || target == tree->data)
    {
        return tree;
    }
    if(target < tree->data)
    {
        return Search(tree->left, target);
    }
    else
    {
        return Search(tree->right, target);
    }
}

Node* Insert(Node* tree, Node* insert)
{
    Node* parent = new Node();
    parent = NULL;
    Node* temp = tree;

    while(temp != NULL)
    {
        parent = temp;
        if(insert->data < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    insert->parent = parent;
    if(parent == NULL)
    {
        tree = insert;
    }
    else if(insert->data < parent->data)
    {
        parent->left = insert;
    }
    else
    {
        parent->right = insert;
    }
    return tree;
}

Node* Transplant(Node* tree, Node* u, Node* v)
{
    if(u->parent == NULL)
    {
        tree = v;
    }
    else if(u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    
    if(v != NULL)
    {
        v->parent = u->parent;
    }
    return tree;
}

Node* Delete(Node* tree, Node* remove)
{
    if(remove->left == NULL)
    {
        tree = Transplant(tree, remove, remove->right);
    }
    else if(remove->right == NULL)
    {
        tree = Transplant(tree, remove, remove->left);
    }
    else
    {
        Node* y = Minimum(remove->right);
        if(y->parent != remove)
        {
            tree = Transplant(tree, y, y->right);
            y->right = remove->right;
            y->right->parent = y;
        }
        tree = Transplant(tree, remove, y);
        y->left = remove->left;
        y->left->parent = y;
    }
    return tree;
}

void Preorder(Node* tree) //root before children
{
    if(tree != NULL)
    {
        cout << tree->data << endl;
        Preorder(tree->left);
        Preorder(tree->right);
    }
}

void Inorder(Node* tree) //left child, root, right child
{
    if(tree != NULL)
    {
        Inorder(tree->left);
        cout << tree->data << endl;
        Inorder(tree->right);
    }
}

void Postorder(Node* tree) //left child, right child, root
{
    if(tree != NULL)
    {
        Postorder(tree->left);
        Postorder(tree->right);
        cout << tree->data << endl;
    }
}

int main(int argc,char **argv)
{
    Node* tree = new Node();
    tree = NULL;
    string userinput;

    cin >> userinput;

    while(userinput != "e")
    {
        if(userinput.at(0) == 'i')
        {
            string tempinput = userinput.erase(0,1);
            int numinput = stoi(tempinput);
            Node* temp = Create(numinput);
            tree = Insert(tree, temp);

            cin >> userinput;
        }
        else if(userinput.at(0) == 'd')
        {
            string tempinput = userinput.erase(0,1);
            int numinput = stoi(tempinput);
            Node* temp = Search(tree, numinput);
            tree = Delete(tree, temp);

            cin >> userinput;
        }
        else if(userinput == "opre")
        {
            Preorder(tree);

            cin >> userinput;
        }
        else if(userinput == "opost")
        {
            Postorder(tree);

            cin >> userinput;
        }
        else if(userinput == "oin")
        {
            Inorder(tree);

            cin >> userinput;
        }
        else
        {
            cin >> userinput;
        }
    }

    

    return 0;
}