#include <iostream>
#include "red_black_tree.hpp"
int main()
{
{
   Tree<int>* m = new Tree<int>(5);
   Node<int>* a = new Node<int>(7);
   Node<int>* z = new Node<int>(2);
   Node<int>* x = new Node<int>(81);
   Node<int>* c = new Node<int>(8);
   Node<int>* v = new Node<int>(0);
   Node<int>* b = new Node<int>(18);
   Node<int>* f = new Node<int>(5);
   Node<int>* e = new Node<int>(8);
   m->insert(a);
   delete a;
   m->insert(z);
   delete z;
   m->insert(x);
   delete x;
   m->insert(c);
   delete c;
   m->insert(v);
   delete v;
   m->insert(b);
   delete b;
   m->insert(f);
   delete f;
   m->insert(e);
   delete e;
   // Tree<int>* s = new Tree<int>(*m);
   std::cout << &m->root->right <<"m>>>>" <<m->root->value<< std::endl;
   std::cout << &m->root->right <<"m>>>>" <<m->root->right->value<< std::endl;
   std::cout << &m->root->right <<"m>>>>" <<m->root->left->value<< std::endl;
   std::cout << &m->root->right <<"m>>>>" <<m->root->right->right->value<< std::endl;
   std::cout << &m->root->right <<"m>>>>" <<m->root->left->value<< std::endl;
   // std::cout << &s->root->right <<">>>>" <<s->root->right->value<< std::endl;
   // std::cout << &s->root->right <<">>>>" <<s->root->left->value<< std::endl;
   // std::cout << &s->root->right <<">>>>" <<s->root->right->right->value<< std::endl;
   // std::cout << &s->root->right <<"x>>>>" <<s->root->right->value<< std::endl;
   // s->delete_node(s->root->right);
   // std::cout << &s->root->right <<"x>>>>" <<s->root->right->value<< std::endl;
   // std::cout << &s->root->right <<">>>>" <<s->root->value<< std::endl;
   delete m;
   // delete s;
}
   system("leaks a.out");
}