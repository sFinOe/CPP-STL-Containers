#include <unitest.hpp>


int main ()
{
	// user input to select test to run

	

	cout << "\033[34m***************************[UNITEST]***************************\033[0m" << endl;
	cout << "\033[34m*                                                             *\033[0m" << endl;
	cout << "\033[34m*                                                             *\033[0m" << endl;
	cout << "\033[34m*                          BY ZKASMI                          *\033[0m" << endl;
	cout << "\033[34m*                                                             *\033[0m" << endl;
	cout << "\033[34m*                                                             *\033[0m" << endl;
	cout << "\033[34m*  SELECT CONTAINER TYPE TEST:                                *\033[0m" << endl;
	cout << "\033[34m*                                                             *\033[0m" << endl;
	cout << "\033[34m*  1. VECTOR                                                  *\033[0m" << endl;
	cout << "\033[34m*  2. STACK                                                   *\033[0m" << endl;
	cout << "\033[34m*  3. MAP                                                     *\033[0m" << endl;
	cout << "\033[34m*  4. SET                                                     *\033[0m" << endl;
	cout << "\033[34m*                                                             *\033[0m" << endl;
	cout << "\033[34m*                                                             *\033[0m" << endl;
	cout << "\033[34m***************************************************************\033[0m" << endl;
	cout << "\n";
	cout << "\033[32mSELECT CONTAINER TYPE TEST => \033[0m";



	int container;
	std::cin >> container;
	cout << "\n";
	if (container == 1){
		test_vector();
	}
	if (container == 2){
		test_stack();
	}
	if (container == 3){
		test_map();
	}
	if (container == 4){
		test_set();
	}

}