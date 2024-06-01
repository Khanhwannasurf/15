#include <iostream>
using namespace std;

struct Node {
    int value; 
    Node* left; 
    Node* right; 

    Node(int v, Node* l = NULL, Node* r = NULL)
        : value(v), left(l), right(r) {}
};

class BSTree {
private:
    Node* root;

public:
    BSTree() : root(NULL) {}

    ~BSTree() {
        makeEmpty();
    }

    bool isEmpty() const {
        return root == NULL;
    }

    void makeEmpty() {
        makeEmpty(root);
    }

    void insert(int val1) {
        insert(val1, root);
    }

    Node* search(int val2) {
        return search(val2, root);
    }

    void printTree(ostream& out = cout) const {
        if (isEmpty())
            out << "Empty tree" << endl;
        else
            printTree(root, out);
    }

private:
    void makeEmpty(Node*& t) {
        if (t == NULL)
            return;
        makeEmpty(t->left); 
        makeEmpty(t->right); 
        delete t; 
        t = NULL; 
    }

    void insert(int val1, Node*& t) {
        if (t == NULL) 
            t = new Node(val1);
        else if (val1 < t->value)
            insert(val1, t->left);
        else if (val1 > t->value)
            insert(val1, t->right);
    }

    Node* search(int val2, Node* t) const {
        if (t == NULL)
            return NULL;
        if (val2 < t->value)
            return search(val2, t->left);
        else if (val2 > t->value)
            return search(val2, t->right);
        else
            return t;
    }

    void printTree(Node* t, ostream& out) const {
        if (t != NULL) {
            printTree(t->left, out);
            out << t->value << " ";
            printTree(t->right, out);
        }
    }
};

void PREORDER_travl(Node* t) {
    if (t != NULL) {
        cout << t->value << " ";
        PREORDER_travl(t->left);
        PREORDER_travl(t->right);
    }
}

int main() {
    BSTree bst;
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);

    Node* root = bst.search(5);

    cout << "Duyet cay thu tu truoc" << endl;
    PREORDER_travl(root);
    cout << endl;

    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    if (n1 != NULL)
        cout << "Node co gia tri = 4 la " << n1->value << endl;
    if (n2 == NULL)
        cout << "Khong tim thay node co gia tri = 9" << endl;
        
    bst.makeEmpty();

    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}

