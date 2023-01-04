#include <unitest.hpp>
#include <vector>
#include <cassert>  

void test_vector_constructor(){
	// test constructors

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	cout << "\033[32m [TEST CONSTRUCTOR] \033[0m" << endl;

	// test constructor vector with assert

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.empty() == ft_vector.empty());

	cout << "\033[34m CONSTRUCTOR VECTOR \033[0m => \033[32m [OK] \033[0m" << endl;

	// test constructor with size

	std::vector<int> std_vector2(5);
	ft::vector<int> ft_vector2(5);

	assert(std_vector2.size() == ft_vector2.size());
	assert(std_vector2.empty() == ft_vector2.empty());

	cout << "\033[34m CONSTRUCTOR WITH SIZE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test constructor with size and value

	std::vector<int> std_vector3(5, 42);
	ft::vector<int> ft_vector3(5, 42);

	assert(std_vector3.size() == ft_vector3.size());
	assert(std_vector3.empty() == ft_vector3.empty());

	cout << "\033[34m CONSTRUCTOR WITH SIZE AND VALUE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test constructor with range

	std::vector<int> std_vector4(std_vector3.begin(), std_vector3.end());
	ft::vector<int> ft_vector4(ft_vector3.begin(), ft_vector3.end());

	assert(std_vector4.size() == ft_vector4.size());
	assert(std_vector4.empty() == ft_vector4.empty());

	cout << "\033[34m CONSTRUCTOR WITH RANGE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test constructor with copy

	std::vector<int> std_vector5(std_vector4);
	ft::vector<int> ft_vector5(ft_vector4);

	assert(std_vector5.size() == ft_vector5.size());
	assert(std_vector5.empty() == ft_vector5.empty());

	cout << "\033[34m CONSTRUCTOR WITH COPY \033[0m => \033[32m [OK] \033[0m" << endl;

	// test constructor with assignation

	std::vector<int> std_vector6 = std_vector5;	
	ft::vector<int> ft_vector6 = ft_vector5;

	assert(std_vector6.size() == ft_vector6.size());
	assert(std_vector6.empty() == ft_vector6.empty());

	cout << "\033[34m CONSTRUCTOR WITH ASSIGNATION \033[0m => \033[32m [OK] \033[0m" << endl;
}

void test_vector_iterator()
{
	// test iterators

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	cout << "\033[32m [TEST ITERATOR] \033[0m" << endl;

	// test begin and end

	std::vector<int>::iterator std_it = std_vector.begin();
	std::vector<int>::iterator std_ite = std_vector.end();
	ft::vector<int>::iterator ft_it = ft_vector.begin();
	ft::vector<int>::iterator ft_ite = ft_vector.end();

	assert(std_it == std_ite);
	assert(ft_it == ft_ite);

	cout << "\033[34m BEGIN AND END \033[0m => \033[32m [OK] \033[0m" << endl;

	// test rbegin and rend

	std::vector<int>::reverse_iterator std_rit = std_vector.rbegin();
	std::vector<int>::reverse_iterator std_rite = std_vector.rend();
	ft::vector<int>::reverse_iterator ft_rit = ft_vector.rbegin();
	ft::vector<int>::reverse_iterator ft_rite = ft_vector.rend();

	assert(std_rit == std_rite);
	assert(ft_rit == ft_rite);

	cout << "\033[34m RBEGIN AND REND \033[0m => \033[32m [OK] \033[0m" << endl;

	// test const begin and end

	std::vector<int>::const_iterator std_cit = std_vector.begin();
	std::vector<int>::const_iterator std_cite = std_vector.end();
	ft::vector<int>::const_iterator ft_cit = ft_vector.begin();
	ft::vector<int>::const_iterator ft_cite = ft_vector.end();

	assert(std_cit == std_cite);
	assert(ft_cit == ft_cite);

	cout << "\033[34m CONST BEGIN AND END \033[0m => \033[32m [OK] \033[0m" << endl;

	// test const rbegin and rend

	std::vector<int>::const_reverse_iterator std_crit = std_vector.rbegin();
	std::vector<int>::const_reverse_iterator std_crite = std_vector.rend();
	ft::vector<int>::const_reverse_iterator ft_crit = ft_vector.rbegin();
	ft::vector<int>::const_reverse_iterator ft_crite = ft_vector.rend();

	assert(std_crit == std_crite);
	assert(ft_crit == ft_crite);

	cout << "\033[34m CONST RBEGIN AND REND \033[0m => \033[32m [OK] \033[0m" << endl;
}

void test_vector_capacity()
{
	// test capacity

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	cout << "\033[32m [TEST CAPACITY] \033[0m" << endl;

	// test size

	assert(std_vector.size() == ft_vector.size());

	cout << "\033[34m SIZE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test max_size

	assert(std_vector.max_size() == ft_vector.max_size());

	cout << "\033[34m MAX SIZE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test resize

	std_vector.resize(5);
	ft_vector.resize(5);

	assert(std_vector.size() == ft_vector.size());

	cout << "\033[34m RESIZE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test capacity

	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m CAPACITY \033[0m => \033[32m [OK] \033[0m" << endl;

	// test empty

	assert(std_vector.empty() == ft_vector.empty());

	cout << "\033[34m EMPTY \033[0m => \033[32m [OK] \033[0m" << endl;

	// test reserve

	std_vector.reserve(10);
	ft_vector.reserve(10);

	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m RESERVE \033[0m => \033[32m [OK] \033[0m" << endl;
}


void test_vector_element_access()
{
	// test element access

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	cout << "\033[32m [TEST ELEMENT ACCESS] \033[0m" << endl;

	// test operator[]

	std_vector.push_back(1);
	ft_vector.push_back(1);

	assert(std_vector[0] == ft_vector[0]);

	cout << "\033[34m OPERATOR[] \033[0m => \033[32m [OK] \033[0m" << endl;

	// test at

	assert(std_vector.at(0) == ft_vector.at(0));

	cout << "\033[34m AT \033[0m => \033[32m [OK] \033[0m" << endl;

	// test front

	assert(std_vector.front() == ft_vector.front());

	cout << "\033[34m FRONT \033[0m => \033[32m [OK] \033[0m" << endl;

	// test back

	assert(std_vector.back() == ft_vector.back());

	cout << "\033[34m BACK \033[0m => \033[32m [OK] \033[0m" << endl;
}

void test_vector_modifiers()
{
	// test modifiers

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	cout << "\033[32m [TEST MODIFIERS] \033[0m" << endl;

	// test assign

	std_vector.assign(5, 10);
	ft_vector.assign(5, 10);

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m ASSIGN \033[0m => \033[32m [OK] \033[0m" << endl;

	// test push_back

	std_vector.push_back(1);
	ft_vector.push_back(1);

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m PUSH BACK \033[0m => \033[32m [OK] \033[0m" << endl;

	// test pop_back

	std_vector.pop_back();
	ft_vector.pop_back();

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m POP BACK \033[0m => \033[32m [OK] \033[0m" << endl;

	// test insert

	std_vector.insert(std_vector.begin(), 1);
	ft_vector.insert(ft_vector.begin(), 1);

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m INSERT \033[0m => \033[32m [OK] \033[0m" << endl;

	// test erase

	std_vector.erase(std_vector.begin());
	ft_vector.erase(ft_vector.begin());

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m ERASE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test swap

	std::vector<int> std_vector2;
	ft::vector<int> ft_vector2;

	std_vector2.push_back(1);
	ft_vector2.push_back(1);

	std_vector.swap(std_vector2);
	ft_vector.swap(ft_vector2);

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m SWAP \033[0m => \033[32m [OK \033[0m" << endl;
}

void test_vector_operations()
{
	// test operations

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	cout << "\033[32m [TEST OPERATIONS] \033[0m" << endl;

	// test clear

	std_vector.push_back(1);
	ft_vector.push_back(1);

	std_vector.clear();
	ft_vector.clear();

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m CLEAR \033[0m => \033[32m [OK] \033[0m" << endl;

	// test resize

	std_vector.resize(5);
	ft_vector.resize(5);

	assert(std_vector.size() == ft_vector.size());


	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m RESIZE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test resize with value

	std_vector.resize(5, 1);
	ft_vector.resize(5, 1);

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m RESIZE WITH VALUE \033[0m => \033[32m [OK] \033[0m" << endl;

	// test swap

	std::vector<int> std_vector2;
	ft::vector<int> ft_vector2;

	std_vector2.push_back(1);
	ft_vector2.push_back(1);

	std_vector.swap(std_vector2);
	ft_vector.swap(ft_vector2);

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m SWAP \033[0m => \033[32m [OK] \033[0m" << endl;
}

void test_vector_non_member_function_overloads()
{
	// test non member function overloads

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	std::vector<int> std_vector2;
	ft::vector<int> ft_vector2;

	cout << "\033[32m [TEST NON MEMBER FUNCTION OVERLOADS] \033[0m" << endl;

	// test relational operators

	std_vector.push_back(1);
	ft_vector.push_back(1);

	std_vector2.push_back(1);
	ft_vector2.push_back(1);

	assert((std_vector == std_vector2) == (ft_vector == ft_vector2));
	assert((std_vector != std_vector2) == (ft_vector != ft_vector2));
	assert((std_vector < std_vector2) == (ft_vector < ft_vector2));
	assert((std_vector <= std_vector2) == (ft_vector <= ft_vector2));
	assert((std_vector > std_vector2) == (ft_vector > ft_vector2));
	assert((std_vector >= std_vector2) == (ft_vector >= ft_vector2));

	cout << "\033[34m RELATIONAL OPERATORS \033[0m => \033[32m [OK] \033[0m" << endl;

	// test swap

	std::vector<int> std_vector3;
	ft::vector<int> ft_vector3;

	std_vector3.push_back(1);
	ft_vector3.push_back(1);

	std::swap(std_vector, std_vector3);
	std::swap(ft_vector, ft_vector3);

	assert(std_vector.size() == ft_vector.size());
	assert(std_vector.capacity() == ft_vector.capacity());

	cout << "\033[34m SWAP \033[0m => \033[32m [OK] \033[0m" << endl;
}

void test_vector_iterators()
{
	// test iterators

	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	cout << "\033[32m [TEST ITERATORS] \033[0m" << endl;

	// test begin

	std_vector.push_back(1);
	ft_vector.push_back(1);

	assert(*std_vector.begin() == *ft_vector.begin());

	cout << "\033[34m BEGIN \033[0m => \033[32m [OK] \033[0m" << endl;

	// test end

	std_vector.push_back(2);
	ft_vector.push_back(2);

	assert(*std_vector.end() == *ft_vector.end());

	cout << "\033[34m END \033[0m => \033[32m [OK] \033[0m" << endl;

	// test rbegin

	std_vector.push_back(3);
	ft_vector.push_back(3);

	assert(*std_vector.rbegin() == *ft_vector.rbegin());

	cout << "\033[34m RBEGIN \033[0m => \033[32m [OK] \033[0m" << endl;

	// test rend

	std_vector.push_back(4);
	ft_vector.push_back(4);

	assert(*std_vector.rend() == *ft_vector.rend());

	cout << "\033[34m REND \033[0m => \033[32m [OK] \033[0m" << endl;
}

void test_vector()
{
	// test ft::vector with std::vector c++98
	std::cout << "\033[34m***************************[VECTOR]***************************\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                          BY ZKASMI                          *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*  SELECT TEST:                                               *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*  1. CONSTRUCTOR                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*  2. ITERATOR                                                *\033[0m" << std::endl;
	std::cout << "\033[34m*  3. CAPACITY                                                *\033[0m" << std::endl;
	std::cout << "\033[34m*  4. ELEMENT ACCESS                                          *\033[0m" << std::endl;
	std::cout << "\033[34m*  5. MODIFIERS                                               *\033[0m" << std::endl;
	std::cout << "\033[34m*  6. OPERATIONS                                              *\033[0m" << std::endl;
	std::cout << "\033[34m*  7. NON-MEMBER FUNCTION OVERLOADS                           *\033[0m" << std::endl;
	std::cout << "\033[34m*  8. TEST ALL                                                *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m*                                                             *\033[0m" << std::endl;
	std::cout << "\033[34m***************************************************************\033[0m" << std::endl;
	std::cout << "\n";

	std::cout << "\033[32mSELECT TEST => \033[0m";
	int test;
	std::cin >> test;
	std::cout << "\n";

	while(1){

		if (test == 1 || test == 8){
			test_vector_constructor();
		}
		if (test == 2 || test == 8){
			test_vector_iterator();
		}
		if (test == 3 || test == 8){
			test_vector_capacity();
		}
		if (test == 4 || test == 8){
			test_vector_element_access();
		}
		if (test == 5 || test == 8){
			test_vector_modifiers();
		}
		if (test == 6 || test == 8){
			test_vector_operations();
		}
		if (test == 7 || test == 8){
			test_vector_non_member_function_overloads();
		}
		if (test == 8 || test == 8){
			test_vector_constructor();
			test_vector_iterator();
			test_vector_capacity();
			test_vector_element_access();
			test_vector_modifiers();
			test_vector_operations();
			test_vector_non_member_function_overloads();
		}

		if (test == 9){
			cout << "\033[34mEXIT\033[0m" << endl;
			break;
		}

		cout << "\n";
		cout << "\033[36m======================================\033[0m" << endl;
		cout << "\n";
		cout << "\033[34mSELECT TEST:\033[0m" << endl;
		cout << "\033[34m1. CONSTRUCTOR\033[0m" << endl;
		cout << "\033[34m2. ITERATOR\033[0m" << endl;
		cout << "\033[34m3. CAPACITY\033[0m" << endl;
		cout << "\033[34m4. ELEMENT ACCESS\033[0m" << endl;
		cout << "\033[34m5. MODIFIERS\033[0m" << endl;
		cout << "\033[34m6. OPERATIONS\033[0m" << endl;
		cout << "\033[34m7. NON-MEMBER FUNCTION OVERLOADS\033[0m" << endl;
		cout << "\033[34m8. TEST ALL\033[0m" << endl;
		cout << "\033[34m9. EXIT\033[0m" << endl;
		cout << "\n\n";
		std::cout << "\033[32mSELECT TEST => \033[0m";
		std::cin >> test;
		std::cout << "\n";

	}
}
