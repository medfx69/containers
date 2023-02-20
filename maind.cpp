#include <iostream>
#include "red_black_tree.hpp"
int main()
{
{
   Tree<int>* m = new Tree<int>(5);

   m->insert(7);
   m->insert(2);
   m->insert(8);
   Tree<int>* s = new Tree<int>(*m);
   std::cout << &m->root->right <<">>>>" <<m->root->right->value<< std::endl;
   std::cout << &m->root->right <<">>>>" <<m->root->lift->value<< std::endl;
   std::cout << &m->root->right <<">>>>" <<m->root->right->right->value<< std::endl;
   std::cout << &m->root->right <<">>>>" <<m->root->value<< std::endl;
   std::cout << &s->root->right <<">>>>" <<s->root->right->value<< std::endl;
   std::cout << &s->root->right <<">>>>" <<s->root->lift->value<< std::endl;
   std::cout << &s->root->right <<">>>>" <<s->root->right->right->value<< std::endl;
   std::cout << &s->root->right <<">>>>" <<s->root->value<< std::endl;
   delete m;
   delete s;
}
   system("leaks a.out");
}