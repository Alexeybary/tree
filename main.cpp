#include <iostream>
#include <string>

using namespace std;
struct tree {
    int data;
    int key;
    tree *left, *right;

} *root = NULL;

void InsertList(int data, int key, tree *tek = root, tree *prev = root) {

    if (tek == NULL) {
        tree *q = new tree;
        q->data = data;
        q->key = key;
        q->left = NULL;
        q->right = NULL;
        if (prev != NULL) {
            if (key > prev->key)
                prev->right = q;
            else
                prev->left = q;
        } else
            root = q;
        return;
    }
    if (key < tek->key)
        InsertList(data, key, tek->left, tek);
    else if (key > tek->key)
        InsertList(data, key, tek->right, tek);
    else tek->data = data;
}

int found(int number_key, tree *tek = root) {
    int numb=number_key;
    if (tek->key == numb)
        return tek->data;

    if ((tek->right != NULL) && (tek->key < numb))
        return found(numb, tek->right);
    else if ((tek->left != NULL) && (tek->key > numb))
        return found(numb, tek->left);
    else
        return 0;
}

void show(tree *tek = root) {
    while (tek != NULL) {
        cout << tek->data;
        tek = tek->left;
    }
}

void allElement(tree *tek = root) {
    int k = 0;
    if ((tek->left == NULL) && (tek->right == NULL)) {
        cout << tek->data;

    } else {
        if (tek->left != NULL) {
            allElement(tek->left);
        }
        cout << tek->data;
        if (tek->right != NULL) {
            allElement(tek->right);
        }

    }
}

int numberOfLists(tree *tek = root) {
    if(root== nullptr)
    return 0;

    if ((tek->left == NULL) && (tek->right == NULL)) {
        return 1;
    } else {
        int k=0;
        if (tek->left != NULL) {

            k+=numberOfLists(tek->left);
        }
        if (tek->right != NULL) {
            k+=numberOfLists(tek->right);
        }
        return k;
    }

}



int height_tree(tree *tek = root) {

    if(tek== nullptr)
        return 0;
     else{
         int height_left=1;
         int height_right=1;
         height_left+=height_tree(tek->left);
         height_right+=height_tree(tek->right);
        return max(height_right,height_left);
     }

    }




int main() {
    int data;
    int key;
    int number = 1;
    while (number != 0) {
        cout << "enter a number\n";
        cin >> number;
        if (number == 1) {
            cout << "enter a data and key\n";
            cin >> data >> key;
            InsertList(data, key);
        }
        if (number == 2) {
            cout << "enter a key to found";
            cin >> key;
            cout << found(key);
        }
        if (number == 3)
            cout << ' ' << numberOfLists() << '\n';
        if (number == 4)
            cout << ' ' << height_tree() << '\n';
    }
    allElement();
}
