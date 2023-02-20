#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#include <iostream>
#include <memory>


template <class T>
class Tree
{
    private:
        struct sNode{
            T value;
            enum clore {red = 0, black = 0};
            sNode *lift;
            sNode *right;
            sNode(T val): value(val), lift(nullptr), right(nullptr){}
            sNode(): value(0), lift(nullptr), right(nullptr){}
        };
        typedef std::allocator<sNode> Alloc;
        Alloc alloc;
    public:
        sNode *root;
        Tree(){
        }
        Tree(T val){
            root = alloc.allocate(1);
            *root = sNode(val);
        }
        sNode  *copy_tree(sNode *tree){
            sNode *node;

            if (tree == 0)
                return 0;
            node = alloc.allocate(1);
            alloc.construct(node, sNode(tree->value));
            node->lift = copy_tree(tree->lift);
            node->right = copy_tree(tree->right);
            return node;
        }
        Tree(const Tree &tree)
        {
            this->root = copy_tree(tree.root);
        }
        void deleteTree(sNode *node)
        {
            if (node == 0) return;
            deleteTree(node->lift);
            deleteTree(node->right);
            alloc.deallocate(node, 1);
        }
        ~Tree(){
            deleteTree(this->root);
            // deleteTree(this->right);
        }
        void insert(T val)
        {
            sNode *n;

            n = this->root;
            while (n){
                if (val < n->value){
                    if (n->lift == 0){
                        n->lift = alloc.allocate(1);
                        alloc.construct(n->lift, sNode());
                        n = n->lift;
                        break;
                    }
                    n = n->lift;
                }
                else{
                    if (n->right == 0){
                        n->right = alloc.allocate(1);
                        alloc.construct(n->right, sNode());
                        n = n->right;
                        break;
                    }
                    n = n->right;
                }
            }
            n->value = val;
            n->lift = 0;
            n->right = 0;
        }
        sNode * search(sNode *node, T key){
            if (node == NULL || node->value == key)
                return node;
            if (node->value < key)
                return search(node->right, key);
            return search(node->lift, key);
        }

};


#endif