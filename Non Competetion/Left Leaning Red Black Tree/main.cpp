#include <iostream>

using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* leftNode = 0;
    Node<T>* rightNode = 0;
    bool isRed = false;

    Node<T>(T key,bool color)
    {
        data = key;
        isRed = color;
    }
};

template<class T>
class LLRBTree
{
    Node<T> *root = 0;
public:
    Node<T>* getRoot()
    {
        return root;
    }

    bool keyFind(T key)
    {
        return keyFind(root,key);
    }

    bool keyFind(Node<T> *r, T key)
    {
        if(r==0)
            return false;
        if(r->data==key)
            return true;
        if(key < r->data)
            return keyFind(r->leftNode, key);
        else return keyFind(r->rightNode, key);
    }

    Node<T>* leftRotate(Node<T>* r)
    {
        r->isRed = true;
        Node<T>* rChild = r->rightNode;
        rChild->isRed = false;
        r->rightNode = rChild->leftNode;
        rChild->leftNode = r;

        return rChild;
    }

    Node<T>* rightRotate(Node<T>* r)
    {
        r->isRed = true;
        Node<T>* lChild = r->leftNode;
        lChild->isRed = false;

        r->leftNode = lChild->rightNode;
        lChild->rightNode = r;

        return lChild;
    }

    void flipColors(Node<T>* r)
    {
        r->isRed = true;
        r->leftNode->isRed = false;
        r->rightNode->isRed = false;
    }

    void insertKey(T key)
    {
        root = insertKey(root,key);
    }

    bool redORblack(Node<T>* r)         //Most important bcoz if node is null it is considered black, which if u do without
    {                                   //function, it would give nullPointerException (Accessing null pointer)
        if (r==0)
            return false;
        return (r->isRed);
    }

    Node<T>* insertKey(Node<T>* r, T key)
    {
        if(r==0)
            return new Node<T>(key,true);
        int cmp = (key < r->data);
        if(cmp)
            r->leftNode = insertKey(r->leftNode, key);
        else    r->rightNode = insertKey(r->rightNode, key);


        if(redORblack(r->rightNode) && !redORblack(r->leftNode))
            r = leftRotate(r);
        if(redORblack(r->leftNode) && redORblack(r->leftNode->leftNode))
            r = rightRotate(r);
        if(redORblack(r->leftNode) && redORblack(r->rightNode))
            flipColors(r);
        return r;
    }
};

int main()
{
    LLRBTree<int> redBlackBST;
    redBlackBST.insertKey(5); redBlackBST.insertKey(4); redBlackBST.insertKey(redBlackBST.getRoot(),8);
    redBlackBST.insertKey(11); redBlackBST.insertKey(6); redBlackBST.insertKey(1);
    cout<<redBlackBST.keyFind(7)<<" "<<redBlackBST.keyFind(1);
    return 0;
}
