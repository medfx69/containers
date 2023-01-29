#include "vector.hpp"
#include "unistd.h"

#define TESTED_TYPE int

int             main(void)
{{
        vector<TESTED_TYPE> vct(7);
        vector<TESTED_TYPE> vct_two(4);
        vector<TESTED_TYPE> vct_three;
        vector<TESTED_TYPE> vct_four;

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 3;
        for (unsigned long int i = 0; i < vct_two.size(); ++i)
                vct_two[i] = (vct_two.size() - i) * 5;
        std::cout << vct.size() << std::endl;
        std::cout << vct_two.size() << std::endl;

        vct_three.assign(vct.begin(), vct.end());
        vct.assign(vct_two.begin(), vct_two.end());
        vct_two.assign(2, 42);
        vct_four.assign(4, 21);

        std::cout << "\t### After assign(): ###" << std::endl;

        std::cout << vct.size() << std::endl;
        std::cout << vct_two.size() << std::endl;
        std::cout << vct_three.size() << std::endl;
        std::cout << vct_four.size() << std::endl;

        vct_four.assign(6, 84);
        std::cout << vct_four.size() << std::endl;

        std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

        vct.assign(5, 53);
        vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

        std::cout << vct.size() << std::endl;
        std::cout << vct_two.size() << std::endl;
}
        // system("leaks a.out");
        return (0);
}