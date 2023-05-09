#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder((*root).left);
    cout << (*root).key << " ";
    traverseInOrder((*root).right);
}
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  // If tree is empty then create and return a new node
  if (node == NULL) {
      node = new struct node;
      (*node).key = key;
      (*node).left =NULL;
      (*node).right = NULL;
  }
  // else the key recursively insert to to a new node by comparing
  else if (key < (*node).key){
      (*node).left = insertNode((*node).left, key);}
  else if (key > (*node).key){
      (*node).right = insertNode((*node).right, key);}
  return node;
}




// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL)//if root is empty then return root
      return root;
  //by comparing key with the root key this recrsively deletes the node
  if (key > (*root).key)
      (*root).right = deleteNode((*root).right, key);
  else if (key < (*root).key)
      (*root).left = deleteNode((*root).left, key);
   //if key equals to root key
  else {//if root has child,this make that root child as the new root
      if ((*root).right == NULL) {
          struct node *temp = (*root).left;
          delete root;
          return temp;
      }
      else if ((*root).left == NULL) {
          struct node *temp = (*root).right;
          delete root;
          return temp;
      }
      struct node *temp = (*root).right;
      while (temp && (*temp).left != NULL)
          temp = (*temp).left;
      (*root).key = (*temp).key;
      (*root).right = deleteNode((*root).right, (*temp).key);

  }
  return root;
}



 


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
