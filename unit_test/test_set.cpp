#include <unitest.hpp>
#include <set>
#include <cassert>


void test_set_constructor()
{
    // test constructors std set with ft set with assert

    std::set<int> std_set;
    ft::set<int> ft_set;

    cout << "\033[32m [TEST CONSTRUCTOR] \033[0m" << endl;

    // test default constructor

    assert(std_set.size() == ft_set.size());

	cout << "\033[34m DEFAULT CONSTRUCTOR \033[0m => \033[32m [OK] \033[0m" << endl;

    // test range constructor

    std::set<int> std_set2(std_set.begin(), std_set.end());
    ft::set<int> ft_set2(ft_set.begin(), ft_set.end());

    assert(std_set2.size() == ft_set2.size());

    cout << "\033[34m RANGE CONSTRUCTOR \033[0m => \033[32m [OK] \033[0m" << endl;

    // test copy constructor

    std::set<int> std_set3(std_set2);
    ft::set<int> ft_set3(ft_set2);

    assert(std_set3.size() == ft_set3.size());

    cout << "\033[34m COPY CONSTRUCTOR \033[0m => \033[32m [OK] \033[0m" << endl;

    // test operator=

    std::set<int> std_set4;
    ft::set<int> ft_set4;

    std_set4 = std_set3;
    ft_set4 = ft_set3;

    assert(std_set4.size() == ft_set4.size());

    cout << "\033[34m OPERATOR= \033[0m => \033[32m [OK] \033[0m" << endl;

    // test constructor with compare

    std::set<int, std::greater<int> > std_set5;
    ft::set<int, std::greater<int> > ft_set5;

    assert(std_set5.size() == ft_set5.size());

    cout << "\033[34m CONSTRUCTOR WITH COMPARE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test constructor with compare and range

    std::set<int, std::greater<int> > std_set6(std_set5.begin(), std_set5.end());
    ft::set<int, std::greater<int> > ft_set6(ft_set5.begin(), ft_set5.end());

    assert(std_set6.size() == ft_set6.size());

    cout << "\033[34m CONSTRUCTOR WITH COMPARE AND RANGE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test constructor with compare and copy

    std::set<int, std::greater<int> > std_set7(std_set6);
    ft::set<int, std::greater<int> > ft_set7(ft_set6);

    assert(std_set7.size() == ft_set7.size());

    cout << "\033[34m CONSTRUCTOR WITH COMPARE AND COPY \033[0m => \033[32m [OK] \033[0m" << endl;

    // test constructor with compare and operator=

    std::set<int, std::greater<int> > std_set8;
    ft::set<int, std::greater<int> > ft_set8;

    std_set8 = std_set7;
    ft_set8 = ft_set7;

    assert(std_set8.size() == ft_set8.size());

    cout << "\033[34m CONSTRUCTOR WITH COMPARE AND OPERATOR= \033[0m => \033[32m [OK] \033[0m" << endl;

}


void test_set_iterators() 
{
    // test iterators std set with ft set with assert

    std::set<int> std_set;
    ft::set<int> ft_set;

    std_set.insert(1);
    std_set.insert(2);
    std_set.insert(3);
    std_set.insert(4);
    std_set.insert(5);

    ft_set.insert(1);
    ft_set.insert(2);
    ft_set.insert(3);
    ft_set.insert(4);
    ft_set.insert(5);

    cout << "\033[32m [TEST ITERATORS] \033[0m" << endl;

    // test begin

    assert(*std_set.begin() == *ft_set.begin());

    cout << "\033[34m BEGIN \033[0m => \033[32m [OK] \033[0m" << endl;

    // test end

    cout << *std_set.end() << endl;
    cout << *ft_set.end() << endl;

    assert(*std_set.end() == *ft_set.end());

    cout << "\033[34m END \033[0m => \033[32m [OK] \033[0m" << endl;

    // test rbegin

    assert(*std_set.rbegin() == *ft_set.rbegin());

    cout << "\033[34m RBEGIN \033[0m => \033[32m [OK] \033[0m" << endl;

    // test rend

    assert(*std_set.rend() == *ft_set.rend());

    cout << "\033[34m REND \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set iterator operator ++, --, ==, !=, * with assert using for loop c++98

    std::set<int>::iterator std_it = std_set.begin();
    ft::set<int>::iterator ft_it = ft_set.begin();

    for (std_it = std_set.begin(); std_it != std_set.end(); std_it++)
    {
        assert(*std_it == *ft_it);
        ft_it++;
    }

    cout << "\033[34m ITERATOR OPERATOR ++ \033[0m => \033[32m [OK] \033[0m" << endl;

    for (std_it = std_set.end(); std_it != std_set.begin(); std_it--)
    {
        assert(*std_it == *ft_it);
        ft_it--;
    }

    cout << "\033[34m ITERATOR OPERATOR -- \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set const iterator operator ++, --, ==, !=, * with assert using for loop c++98

    std::set<int>::const_iterator std_cit = std_set.begin();
    ft::set<int>::const_iterator ft_cit = ft_set.begin();

    for (std_cit = std_set.begin(); std_cit != std_set.end(); std_cit++)
    {
        assert(*std_cit == *ft_cit);
        ft_cit++;
    }

    cout << "\033[34m CONST ITERATOR OPERATOR ++ \033[0m => \033[32m [OK] \033[0m" << endl;

    for (std_cit = std_set.end(); std_cit != std_set.begin(); std_cit--)
    {
        assert(*std_cit == *ft_cit);
        ft_cit--;
    }

    cout << "\033[34m CONST ITERATOR OPERATOR -- \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set reverse iterator operator ++, --, ==, !=, * with assert using for loop c++98   

    std::set<int>::reverse_iterator std_rit = std_set.rbegin();
    ft::set<int>::reverse_iterator ft_rit = ft_set.rbegin();

    for (std_rit = std_set.rbegin(); std_rit != std_set.rend(); std_rit++)
    {
        assert(*std_rit == *ft_rit);
        ft_rit++;
    }

    cout << "\033[34m REVERSE ITERATOR OPERATOR ++ \033[0m => \033[32m [OK] \033[0m" << endl;

    for (std_rit = std_set.rend(); std_rit != std_set.rbegin(); std_rit--)
    {
        assert(*std_rit == *ft_rit);
        ft_rit--;
    }

    cout << "\033[34m REVERSE ITERATOR OPERATOR -- \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set const reverse iterator operator ++, --, ==, !=, * with assert using for loop c++98

    std::set<int>::const_reverse_iterator std_crit = std_set.rbegin();
    ft::set<int>::const_reverse_iterator ft_crit = ft_set.rbegin();

    for (std_crit = std_set.rbegin(); std_crit != std_set.rend(); std_crit++)
    {
        assert(*std_crit == *ft_crit);
        ft_crit++;
    }

    cout << "\033[34m CONST REVERSE ITERATOR OPERATOR ++ \033[0m => \033[32m [OK] \033[0m" << endl;

    for (std_crit = std_set.rend(); std_crit != std_set.rbegin(); std_crit--)
    {
        assert(*std_crit == *ft_crit);
        ft_crit--;
    }

    cout << "\033[34m CONST REVERSE ITERATOR OPERATOR -- \033[0m => \033[32m [OK] \033[0m" << endl;

}


void test_set_capacity()
{
    // test set empty with assert

    std::set<int> std_set;
    ft::set<int> ft_set;

    assert(std_set.empty() == ft_set.empty());

    cout << "\033[34m EMPTY \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set size with assert

    std_set.insert(1);
    ft_set.insert(1);

    assert(std_set.size() == ft_set.size());

    cout << "\033[34m SIZE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set max_size with assert
    
    assert(std_set.max_size() == ft_set.max_size());

    cout << "\033[34m MAX_SIZE \033[0m => \033[32m [OK] \033[0m" << endl;


}

void test_set_modifiers()
{
    // test set insert with assert

    std::set<int> std_set;
    ft::set<int> ft_set;

    std_set.insert(1);
    ft_set.insert(1);

    assert(*std_set.begin() == *ft_set.begin());

    cout << "\033[34m INSERT \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set insert range with assert

    std::set<int> std_set2;
    ft::set<int> ft_set2;

    std_set2.insert(std_set.begin(), std_set.end());
    ft_set2.insert(ft_set.begin(), ft_set.end());

    assert(*std_set2.begin() == *ft_set2.begin());

    cout << "\033[34m INSERT RANGE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set insert hint with assert

    std_set.insert(std_set.begin(), 2);
    ft_set.insert(ft_set.begin(), 2);

    assert(*std_set.begin() == *ft_set.begin());

    cout << "\033[34m INSERT HINT \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set erase with assert

    std_set.erase(1);
    ft_set.erase(1);

    assert(std_set.empty() == ft_set.empty());

    cout << "\033[34m ERASE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set erase range with assert

    std_set.insert(1);
    ft_set.insert(1);

    std_set.erase(std_set.begin(), std_set.end());
    ft_set.erase(ft_set.begin(), ft_set.end());

    assert(std_set.empty() == ft_set.empty());

    cout << "\033[34m ERASE RANGE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set swap with assert

    std_set.insert(1);
    ft_set.insert(1);

    std_set.swap(std_set2);
    ft_set.swap(ft_set2);

    assert(*std_set.begin() == *ft_set.begin());

    cout << "\033[34m SWAP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set clear with assert

    std_set.clear();
    ft_set.clear();

    assert(std_set.empty() == ft_set.empty());

    cout << "\033[34m CLEAR \033[0m => \033[32m [OK] \033[0m" << endl;


}


void test_set_observers()
{
    // test set key_comp with assert

    std::set<int> std_set;
    ft::set<int> ft_set;

    std_set.insert(1);
    ft_set.insert(1);

    assert(std_set.key_comp()(*std_set.begin(), *std_set.begin()) == ft_set.key_comp()(*ft_set.begin(), *ft_set.begin()));

    cout << "\033[34m KEY_COMP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set value_comp with assert

    assert(std_set.value_comp()(*std_set.begin(), *std_set.begin()) == ft_set.value_comp()(*ft_set.begin(), *ft_set.begin()));

    cout << "\033[34m VALUE_COMP \033[0m => \033[32m [OK] \033[0m" << endl;

}

void test_set_operations()
{
    // test set find with assert

    std::set<int> std_set;
    ft::set<int> ft_set;

    std_set.insert(1);
    std_set.insert(2);
    std_set.insert(3);

    ft_set.insert(1);
    ft_set.insert(2);
    ft_set.insert(3);

    assert(*std_set.find(2) == *ft_set.find(2));

    cout << "\033[34m FIND \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set count with assert

    assert(std_set.count(2) == ft_set.count(2));

    cout << "\033[34m COUNT \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set lower_bound with assert

    assert(*std_set.lower_bound(2) == *ft_set.lower_bound(2));

    cout << "\033[34m LOWER_BOUND \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set upper_bound with assert

    assert(*std_set.upper_bound(2) == *ft_set.upper_bound(2));

    cout << "\033[34m UPPER_BOUND \033[0m => \033[32m [OK] \033[0m" << endl;

    // test set equal_range with assert

    assert(*std_set.equal_range(2).first == *ft_set.equal_range(2).first);

    cout << "\033[34m EQUAL_RANGE \033[0m => \033[32m [OK] \033[0m" << endl;
}


void test_set()
{
    cout << "\033[34m***************************[SET]****************************\033[0m" << endl;
    cout << "\033[34m*                                                          *\033[0m" << endl;
    cout << "\033[34m*                                                          *\033[0m" << endl;
    cout << "\033[34m*  SELECT TEST:                                            *\033[0m" << endl;
    cout << "\033[34m*                                                          *\033[0m" << endl;
    cout << "\033[34m*  1. CONSTRUCTOR                                          *\033[0m" << endl;
    cout << "\033[34m*  2. ITERATOR                                             *\033[0m" << endl;
    cout << "\033[34m*  3. CAPACITY                                             *\033[0m" << endl;
    cout << "\033[34m*  4. MODIFIERS                                            *\033[0m" << endl;
    cout << "\033[34m*  5. OBSERVERS                                            *\033[0m" << endl;
    cout << "\033[34m*  6. OPERATIONS                                           *\033[0m" << endl;
    cout << "\033[34m*  7. ALL                                                  *\033[0m" << endl;
    cout << "\033[34m*  8. EXIT                                                 *\033[0m" << endl;
    cout << "\033[34m*                                                          *\033[0m" << endl;
    cout << "\033[34m*                                                          *\033[0m" << endl;
    cout << "\033[34m************************************************************\033[0m" << endl;

    cout << "\n";
    cout << "\033[32mSELECT TEST => \033[0m";

    int test;
    std::cin >> test;
    cout << "\n";

    while (1)
    {
        if (test == 1)
            test_set_constructor();
        if (test == 2)
            test_set_iterators();
        if (test == 3)
            test_set_capacity();
        if (test == 4)
            test_set_modifiers();
        if (test == 5)
            test_set_observers();
        if (test == 6)
            test_set_operations();
        if (test == 7){
            test_set_constructor();
            test_set_iterators();
            test_set_capacity();
            test_set_modifiers();
            test_set_observers();
            test_set_operations();
        }
        if (test == 8){
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
        cout << "\033[34m6. OBSERVERS\033[0m" << endl;
        cout << "\033[34m7. OPERATIONS\033[0m" << endl;
        cout << "\033[34m8. ALL\033[0m" << endl;
		cout << "\033[34m9. EXIT\033[0m" << endl;
		cout << "\n\n";
		cout << "\033[32mSELECT TEST => \033[0m";
		std::cin >> test;
		cout << "\n";


    }

}