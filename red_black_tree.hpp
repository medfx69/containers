#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#include <iostream>
#include <memory>


enum Color {red = 1, black = 0};
template <class T>
struct Node{
    Color color;
    T value;
    Node *left;
    Node *right;
    Node *parent;
    Node(T val): value(val), parent(nullptr), left(nullptr), right(nullptr){}
    Node(): value(0), left(nullptr), parent(nullptr), right(nullptr){}
};
template <class T>
class Tree
{
    private:
        typedef std::allocator<Node<T> > Alloc;
        Alloc alloc;
    public:
        typedef Node<T> Node;
        Node *root;
        Node *nil;
        Tree(){
            nil = alloc.allocate(1);
            nil->left = alloc.allocate(1);
            nil->right = alloc.allocate(1);
            *nil = Node();
            *nil->right = Node();
            *nil->left = Node();
            root = nil;
            this->root->parent = alloc.allocate(1);
            this->root->parent = nil;
            this->nil->color = black;
        }
        Tree(T val){
            nil = alloc.allocate(1);
            *nil = Node();
            nil->right = alloc.allocate(1);
            *nil->right = Node();
            nil->left = alloc.allocate(1);
            *nil->left = Node();
            root = alloc.allocate(1);
            *root = Node(val);
            root->left = nil;
            root->right = nil;
            this->root->parent = nil;
            this->nil->color = black;
        }
        Node  *copy_tree(Node *tree, Node *tNil){
            Node *node;

            if (tree == tNil)
                return nil;
            node = alloc.allocate(1);
            alloc.construct(node, Node(tree->value));
            node->parent = tree->parent;
            node->color = tree->color;
            node->left = copy_tree(tree->left, tNil);
            node->right = copy_tree(tree->right, tNil);
            return node;
        }
        Tree(const Tree &tree)
        {
            nil = alloc.allocate(1);
            *nil = Node();
            nil->right = alloc.allocate(1);
            *nil->right = Node();
            nil->left = alloc.allocate(1);
            *nil->left = Node();
            this->root = copy_tree(tree.root, tree.nil);
            this->root->parent = nil;
            this->nil->color = black;
        }
        void deleteTree(Node *node)
        {
            if (node == nil)
                return ;
            deleteTree(node->left);
            deleteTree(node->right);
            std::cout << node->right << std::endl;
            if (node != nil)
                alloc.deallocate(node, 1);
        }
        ~Tree(){
            deleteTree(this->root);
            alloc.deallocate(nil->left, 1);
            alloc.deallocate(nil->right, 1);
            alloc.deallocate(nil, 1);

        }
        void leftRotate(Node *x){
            Node *y = x->right;
            x->right = y->left;
            std::cout << "::::>"<< x->left->parent<< std::endl <<"::::>"<< x << std::endl;
            if(y->left != nil)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == nil)
                this->root = y;
            else if(x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }
        void rightRotate(Node *x){
            Node *y = x->left;
            x->left = y->right;
            if(y->right != nil)
                y->right->parent = x;
            y->parent = x->parent;
            if (x->parent == nil)
                this->root = y;
            else if(x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
            y->right = x;
            x->parent = y;
        }
        void insertFixUp(Node *z){
            while (z->parent->color == red){
                if (z->parent == z->parent->parent->left){
                    Node *y = z->parent->parent->right;
                    if (y->color == red){
                        z->parent->color = black;
                        y->color = black;
                        z->parent->parent->color = red;
                        z = z->parent->parent;
                    }
                    else if(z == z->parent->right){
                        z = z->parent;
                        leftRotate(z);
                    }
                    else{
                        z->parent->color = black;
                        z->parent->parent->color = red;
                        rightRotate(z->parent->parent);
                    }
                    
                }
                else{
                    Node *y = z->parent->parent->left;
                    if (y->color == red){
                        z->parent->color = black;
                        y->color = black;
                        z->parent->parent->color = red;
                        z = z->parent->parent;
                    }
                    else if(z == z->parent->left){
                        z = z->parent;
                        leftRotate(z);
                    }
                    else {
                        z->parent->color = black;
                        z->parent->parent->color = red;
                        rightRotate(z->parent->parent);
                    }
                }
            }
            root->color = black;
        }
        void insert(Node *z)
        {
            Node *n = this->root;
            Node *y = nil;

            while (n != nil){
                y = n;
                if (z->value < n->value)
                    n = n->left;
                else
                    n = n->right;
            }
            z->parent = y;
            if (y == nil)
                this->root = z;
            else if (z->value < y->value){
                y->left = alloc.allocate(1);
                alloc.construct(y->left, *z);
                y->left->left = nil;
                y->left->right = nil;
                y->left->color = red;
                insertFixUp(y->left);
            }
            else{
                y->right = alloc.allocate(1);
                alloc.construct(y->right, *z);
                y->right->left = nil;
                y->right->right = nil;
                y->right->color = red;
                insertFixUp(y->right);
            }
            insertFixUp(z);
        }
        // void delete_node(Node *z){
        //     Node *y = z;

        //     if (node->left == nil && node != nil){
        //         if (node->right != nil)
        //         {
        //             tmp = node->right;
        //             node->value = node->right->value;
        //             node->left = node->right->left;
        //             node->right = node->right->right;
        //             alloc.deallocate(tmp, 1);
        //         }
        //         else
        //             node = nil;
        //     }
        //     else if (node->right == nil && node != nil){
        //         if (node->left != nil){
        //             tmp = node->right;
        //             tmp = node->left;
        //             node->value = node->right->value;
        //             node->right = node->left->right;
        //             node->left = node->left->left;
        //             alloc.deallocate(tmp, 1);
        //         }
        //         else
        //             node = nil;
        //     }
        //     else if (node != nil){
                
        //     }
        // }
        Node * search(Node *node, T key){
            if (node == NULL || node->value == key)
                return node;
            if (node->value < key)
                return search(node->right, key);
            return search(node->left, key);
        }

};


#endif