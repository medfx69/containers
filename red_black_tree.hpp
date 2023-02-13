#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
template <class T>
struct s_node
{
    enum{red, black};
    T value;
    struct s_node lift;
    struct s_node root;
    struct s_node right;
    s_node(T value){
        this->value = value;
    }
} typedef node;


template <class T>
class RedBlackTree
{
private:
    node<T> red;
public:
    RedBlackTree(){
        red.lift = 0;
        red.right = 0;
        red.root = 0;
    }
    RedBlackTree(T value){
        if (red.root == 0){
            red = node(value);
        }
        for (; )
    }
    ~RedBlackTree();

};


#endif