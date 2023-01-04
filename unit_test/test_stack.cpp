#include <unitest.hpp>
#include <stack>
#include <cassert>

void test_stack()
{
	// test ft::stack with std::stack c++98
	std::cout << "\033[34m***************************[STACK]***************************\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                          BY ZKASMI                          *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*  SELECT TEST:                                               *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*  1. CONSTRUCTOR                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*  2. EMPTY                                                   *\033[0m" << std::endl;
	std::cout << "\033[34m*  3. SIZE                                                    *\033[0m" << std::endl;
	std::cout << "\033[34m*  4. TOP                                                     *\033[0m" << std::endl;
	std::cout << "\033[34m*  5. PUSH                                                    *\033[0m" << std::endl;
	std::cout << "\033[34m*  6. POP                                                     *\033[0m" << std::endl;
	std::cout << "\033[34m*  7. RELATIONAL OPERATORS                                    *\033[0m" << std::endl;
	std::cout << "\033[34m*  8. TEST ALL                                                *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m***************************************************************\033[0m" << std::endl;
	std::cout << "\n";

	std::cout << "\033[32mSELECT TEST => \033[0m";
	int test;
	std::cin >> test;
	std::cout << "\n";

	while (1)
	{

		if (test == 1 || test == 8)
		{
			// test constructors
			std::stack<int> std_stack;
			ft::stack<int> ft_stack;

			cout << "\033[32m [TEST CONSTRUCTOR] \033[0m" << endl;

			// test constructor stack with assert
			assert(std_stack.size() == ft_stack.size());
			assert(std_stack.empty() == ft_stack.empty());

			cout << "\033[34m CONSTRUCTOR STACK \033[0m => \033[32m [OK] \033[0m" << endl;
			// test copy constructor

			std::stack<int> std_stack2(std_stack);
			ft::stack<int> ft_stack2(ft_stack);

			assert(std_stack2.size() == ft_stack2.size());
			assert(std_stack2.empty() == ft_stack2.empty());

			cout << "\033[34m COPY CONSTRUCTOR \033[0m => \033[32m [OK] \033[0m" << endl;
			// test operator=

			std::stack<int> std_stack3;
			ft::stack<int> ft_stack3;

			std_stack3 = std_stack;
			ft_stack3 = ft_stack;

			assert(std_stack3.size() == ft_stack3.size());
			assert(std_stack3.empty() == ft_stack3.empty());

			cout << "\033[34m OPERATOR= \033[0m => \033[32m [OK] \033[0m" << endl;
			// test constructor with container

			std::deque<int> std_vector;
			ft::vector<int> ft_vector;

			for (int i = 0; i < 5; i++)
			{
				std_vector.push_back(i);
				ft_vector.push_back(i);
			}

			std::stack<int> std_stack4(std_vector);
			ft::stack<int> ft_stack4(ft_vector);

			assert(std_stack4.size() == ft_stack4.size());
			assert(std_stack4.empty() == ft_stack4.empty());

			cout << "\033[34m CONSTRUCTOR WITH CONTAINER \033[0m => \033[32m [OK] \033[0m" << endl;
		}

		if (test == 2 || test == 8)
		{
			// test empty
			std::stack<int> std_stack;
			ft::stack<int> ft_stack;

			cout << "\033[32m [TEST EMPTY] \033[0m" << endl;

			assert(std_stack.empty() == ft_stack.empty());

			std_stack.push(1);
			ft_stack.push(1);

			assert(std_stack.empty() == ft_stack.empty());

			cout << "\033[34m EMPTY \033[0m => \033[32m [OK] \033[0m" << endl;
		}
		if (test == 3 || test == 8)
		{
			// test size
			std::stack<int> std_stack;
			ft::stack<int> ft_stack;

			cout << "\033[32m [TEST SIZE] \033[0m" << endl;

			assert(std_stack.size() == ft_stack.size());

			std_stack.push(1);
			ft_stack.push(1);

			assert(std_stack.size() == ft_stack.size());

			cout << "\033[34m SIZE \033[0m => \033[32m [OK] \033[0m" << endl;
		}

		if (test == 4 || test == 8)
		{
			// test top
			std::stack<int> std_stack;
			ft::stack<int> ft_stack;

			cout << "\033[32m [TEST TOP] \033[0m" << endl;

			std_stack.push(1);
			ft_stack.push(1);

			assert(std_stack.top() == ft_stack.top());

			cout << "\033[34m TOP \033[0m => \033[32m [OK] \033[0m" << endl;
		}

		if (test == 5 || test == 8)
		{
			// test push
			std::stack<int> std_stack;
			ft::stack<int> ft_stack;

			cout << "\033[32m [TEST PUSH] \033[0m" << endl;

			std_stack.push(1);
			ft_stack.push(1);

			assert(std_stack.top() == ft_stack.top());

			cout << "\033[34m PUSH \033[0m => \033[32m [OK] \033[0m" << endl;
		}

		if (test == 6 || test == 8)
		{
			// test pop
			std::stack<int> std_stack;
			ft::stack<int> ft_stack;

			cout << "\033[32m [TEST POP] \033[0m" << endl;

			std_stack.push(1);
			ft_stack.push(1);

			std_stack.pop();
			ft_stack.pop();

			assert(std_stack.empty() == ft_stack.empty());

			cout << "\033[34m POP \033[0m => \033[32m [OK] \033[0m" << endl;
		}

		if (test == 7 || test == 8)
		{
			// test relational operators
			std::stack<int> std_stack;
			ft::stack<int> ft_stack;

			std::stack<int> std_stack2;
			ft::stack<int> ft_stack2;

			cout << "\033[32m [TEST RELATIONAL OPERATORS] \033[0m" << endl;

			std_stack.push(1);
			ft_stack.push(1);

			std_stack2.push(1);
			ft_stack2.push(1);

			assert((std_stack == std_stack2) == (ft_stack == ft_stack2));
			assert((std_stack != std_stack2) == (ft_stack != ft_stack2));
			assert((std_stack < std_stack2) == (ft_stack < ft_stack2));
			assert((std_stack <= std_stack2) == (ft_stack <= ft_stack2));
			assert((std_stack > std_stack2) == (ft_stack > ft_stack2));
			assert((std_stack >= std_stack2) == (ft_stack >= ft_stack2));

			cout << "\033[34m RELATIONAL OPERATORS \033[0m => \033[32m [OK] \033[0m" << endl;
		}

		else if (test == 9){
			cout << "\033[34mEXIT\033[0m" << endl;
			break;
		}

		cout << "\n";
		cout << "\033[36m======================================\033[0m" << endl;
		cout << "\n";
		cout << "\033[34mSELECT TEST:\033[0m" << endl;
		cout << "\033[34m1. CONSTRUCTOR\033[0m" << endl;
		cout << "\033[34m2. EMPTY\033[0m" << endl;
		cout << "\033[34m3. SIZE\033[0m" << endl;
		cout << "\033[34m4. TOP\033[0m" << endl;
		cout << "\033[34m5. PUSH\033[0m" << endl;
		cout << "\033[34m6. POP\033[0m" << endl;
		cout << "\033[34m7. RELATIONAL OPERATORS\033[0m" << endl;
		cout << "\033[34m8. ALL TEST\033[0m" << endl;
		cout << "\033[34m9. EXIT\033[0m" << endl;
		cout << "\n\n";
		std::cout << "\033[32mSELECT TEST => \033[0m";
		std::cin >> test;
		std::cout << "\n";
	}
}