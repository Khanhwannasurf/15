#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
public:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T v, Node* l = NULL, Node* r = NULL) : value(v), left(l), right(r) {}
    };
    Node* root;
    int size;

    void makeEmpty(Node*& t) {
        if (t != NULL) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            size--;
            t = NULL;
        }
    }

    Node* findNode(Node* t, const T& x) const {
        if (t == NULL)
            return NULL;
        if (t->value == x)
            return t;
        Node* foundNode = findNode(t->left, x);
        if (foundNode == NULL)
            foundNode = findNode(t->right, x);
        return foundNode;
    }

public:
    BinaryTree() : root(NULL), size(0) {}

    ~BinaryTree() {
        makeEmpty(root);
    }

    void InitBTree() {
        makeEmpty(root);
    }

    void InsertParent(const T& x, Node* P) {
        if (P == NULL) {
            root = new Node(x);
            size++;
        } else {
            Node* newParent = new Node(x, P->left, P->right);
            P->left = NULL;
            P->right = NULL;
            if (P == root) {
                root = newParent;
            } else {
                Node* parent = findNode(root, P->value);
                if (parent->left == P)
                    parent->left = newParent;
                else
                    parent->right = newParent;
            }
            size++;
        }
    }

    void InsertLeftChild(const T& x, Node* P) {
        if (P != NULL && P->left == NULL) {
            P->left = new Node(x);
            size++;
        }
    }

    void InsertRightChild(const T& x, Node* P) {
        if (P != NULL && P->right == NULL) {
            P->right = new Node(x);
            size++;
        }
    }

    Node* FindNode(const T& x) {
        return findNode(root, x);
    }

    void DeleteCurrentNode(Node* P) {
        if (P != NULL) {
            makeEmpty(P);
        }
    }

    void DeleteLeftChild(Node* P) {
        if (P != NULL && P->left != NULL) {
            makeEmpty(P->left);
        }
    }

    void DeleteRightChild(Node* P) {
        if (P != NULL && P->right != NULL) {
            makeEmpty(P->right);
        }
    }

    int GetSize() const {
        return size;
    }
};


int main() {
    BinaryTree<int> bt;
    bt.InitBTree();
    bt.InsertParent(10, NULL);
    BinaryTree<int>::Node* root = bt.FindNode(10);
    bt.InsertLeftChild(5, root);
    bt.InsertRightChild(15, root);

    
    BinaryTree<int>::Node* node = bt.FindNode(5); 
    if (node != NULL)
        cout << "tim kiem gia tri node: " << node->value << endl;

    cout << "kich thuoc cay: " << bt.GetSize() << endl;

    bt.DeleteLeftChild(root);
    cout << "kich thuoc sau khi xoa nhanh trai: " << bt.GetSize() << endl;

    bt.DeleteCurrentNode(root);
    cout << "kich thuoc cay sau khi xoa goc: " << bt.GetSize() << endl;

    return 0;
}


