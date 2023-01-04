#include <unitest.hpp>
#include <map>
#include <cassert>

void test_map_constructor()
{
    // test constructors std map with ft map

    std::map<char, int> std_map;
    ft::map<char, int> ft_map;

    cout << "\033[32m [TEST CONSTRUCTOR] \033[0m" << endl;

    std_map['a'] = 10;
    std_map['b'] = 30;
    std_map['c'] = 50;
    std_map['d'] = 70;

    ft_map['a'] = 10;
    ft_map['b'] = 30;
    ft_map['c'] = 50;
    ft_map['d'] = 70;

    std::map<char, int> std_map2(std_map);
    ft::map<char, int> ft_map2(ft_map);

    // test map constructor with with assert

    assert(std_map2['a'] == ft_map2['a']);
    assert(std_map2['b'] == ft_map2['b']);
    assert(std_map2['c'] == ft_map2['c']);
    assert(std_map2['d'] == ft_map2['d']);

	cout << "\033[34m CONSTRUCTOR MAP \033[0m => \033[32m [OK] \033[0m" << endl;


    // test map constructor with range

    std::map<char, int> std_map3(std_map.begin(), std_map.end());
    ft::map<char, int> ft_map3(ft_map.begin(), ft_map.end());

    // test map constructor with range with assert

    assert(std_map3['a'] == ft_map3['a']);
    assert(std_map3['b'] == ft_map3['b']);
    assert(std_map3['c'] == ft_map3['c']);
    assert(std_map3['d'] == ft_map3['d']);

    cout << "\033[34m CONSTRUCTOR MAP WITH RANGE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map constructor with copy

    std::map<char, int> std_map4(std_map3);
    ft::map<char, int> ft_map4(ft_map3);

    // test map constructor with copy with assert

    assert(std_map4['a'] == ft_map4['a']);
    assert(std_map4['b'] == ft_map4['b']);
    assert(std_map4['c'] == ft_map4['c']);
    assert(std_map4['d'] == ft_map4['d']);

    cout << "\033[34m CONSTRUCTOR MAP WITH COPY \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map constructor with allocator

    std::map<char, int, std::less<char>, std::allocator<std::pair<const char, int> > > std_map7;
    ft::map<char, int, std::less<char>, std::allocator<std::pair<const char, int> > > ft_map7;

    // test map constructor with allocator with assert

    assert(std_map7.empty() == ft_map7.empty());

    cout << "\033[34m CONSTRUCTOR MAP WITH ALLOCATOR \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map constructor with allocator and range

    std::map<char, int, std::less<char>, std::allocator<std::pair<const char, int> > > std_map8(std_map.begin(), std_map.end());
    ft::map<char, int, std::less<char>, std::allocator<std::pair<const char, int> > > ft_map8(ft_map.begin(), ft_map.end());

    // test map constructor with allocator and range with assert

    assert(std_map8['a'] == ft_map8['a']);
    assert(std_map8['b'] == ft_map8['b']);
    assert(std_map8['c'] == ft_map8['c']);
    assert(std_map8['d'] == ft_map8['d']);

    cout << "\033[34m CONSTRUCTOR MAP WITH ALLOCATOR AND RANGE \033[0m => \033[32m [OK] \033[0m" << endl;

}

void test_map_iterators()
{
    // test iterators std map with ft map

    std::map<char, int> std_map;
    ft::map<char, int> ft_map;

    cout << "\033[32m [TEST ITERATORS] \033[0m" << endl;

    std_map['a'] = 10;
    std_map['b'] = 30;
    std_map['c'] = 50;
    std_map['d'] = 70;

    ft_map['a'] = 10;
    ft_map['b'] = 30;
    ft_map['c'] = 50;
    ft_map['d'] = 70;

    // test map iterators with assert c++98

    std::map<char, int>::iterator it = std_map.begin();
    ft::map<char, int>::iterator it2 = ft_map.begin();

    assert(it->first == it2->first);
    assert(it->second == it2->second);

    it++;
    it2++;

    assert(it->first == it2->first);
    assert(it->second == it2->second);

    it++;
    it2++;

    assert(it->first == it2->first);
    assert(it->second == it2->second);

    it++;
    it2++;

    assert(it->first == it2->first);
    assert(it->second == it2->second);

    cout << "\033[34m ITERATOR MAP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map const iterators with assert c++98

    std::map<char, int>::const_iterator it3 = std_map.begin();
    ft::map<char, int>::const_iterator it4 = ft_map.begin();

    assert(it3->first == it4->first);
    assert(it3->second == it4->second);

    it3++;
    it4++;

    assert(it3->first == it4->first);
    assert(it3->second == it4->second);

    it3++;
    it4++;

    assert(it3->first == it4->first);
    assert(it3->second == it4->second);

    it3++;
    it4++;

    assert(it3->first == it4->first);
    assert(it3->second == it4->second);

    cout << "\033[34m CONST ITERATOR MAP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map reverse iterators with assert c++98

    std::map<char, int>::reverse_iterator it5 = std_map.rbegin();
    ft::map<char, int>::reverse_iterator it6 = ft_map.rbegin();

    assert(it5->first == it6->first);
    assert(it5->second == it6->second);

    it5++;
    it6++;

    assert(it5->first == it6->first);
    assert(it5->second == it6->second);


    it5++;
    it6++;

    assert(it5->first == it6->first);
    assert(it5->second == it6->second);

    it5++;
    it6++;

    assert(it5->first == it6->first);
    assert(it5->second == it6->second);

    cout << "\033[34m REVERSE ITERATOR MAP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map const reverse iterators with assert c++98

    std::map<char, int>::const_reverse_iterator it7 = std_map.rbegin();
    ft::map<char, int>::const_reverse_iterator it8 = ft_map.rbegin();

    assert(it7->first == it8->first);
    assert(it7->second == it8->second);

    it7++;
    it8++;

    assert(it7->first == it8->first);
    assert(it7->second == it8->second);

    it7++;
    it8++;

    assert(it7->first == it8->first);
    assert(it7->second == it8->second);

    it7++;
    it8++;
    
    assert(it7->first == it8->first);
    assert(it7->second == it8->second);

    cout << "\033[34m CONST REVERSE ITERATOR MAP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map iterator operator ++, --, ==, !=, *, -> with assert using for loop c++98

    std::map<char, int>::iterator it9 = std_map.begin();
    ft::map<char, int>::iterator it10 = ft_map.begin();

    for (int i = 0; i < 3; i++)
    {
        assert(it9->first == it10->first);
        assert(it9->second == it10->second);
        it9++;
        it10++;
    }

    cout << "\033[34m ITERATOR MAP OPERATOR ++ \033[0m => \033[32m [OK] \033[0m" << endl;

    for (int i = 0; i < 4; i++)
    {
        assert(it9->first == it10->first);
        assert(it9->second == it10->second);
        it9--;
        it10--;
    }

    cout << "\033[34m ITERATOR MAP OPERATOR -- \033[0m => \033[32m [OK] \033[0m" << endl;

    it9 = std_map.begin();
    it10 = ft_map.begin();

    for (int i = 0; i < 4; i++)
    {
        assert(it9->first == it10->first);
        assert(it9->second == it10->second);
        it9++;
        it10++;
    }

    cout << "\033[34m ITERATOR MAP OPERATOR == \033[0m => \033[32m [OK] \033[0m" << endl;

    it9 = std_map.begin();
    it10 = ft_map.begin();

    for (int i = 0; i < 4; i++)
    {
        assert(it9->first == it10->first);
        assert(it9->second == it10->second);
        it9++;
        it10++;
    }

    cout << "\033[34m ITERATOR MAP OPERATOR != \033[0m => \033[32m [OK] \033[0m" << endl;

    it9 = std_map.begin();

    assert(it9->first == 'a');
    assert(it9->second == 10);

    cout << "\033[34m ITERATOR MAP OPERATOR * \033[0m => \033[32m [OK] \033[0m" << endl;

    it9 = std_map.begin();

    assert(it9->first == 'a');
    assert(it9->second == 10);

    cout << "\033[34m ITERATOR MAP OPERATOR -> \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map reverse iterator operator ++, --, ==, !=, *, -> with assert using for loop c++98

    std::map<char, int>::reverse_iterator it11 = std_map.rbegin();
    ft::map<char, int>::reverse_iterator it12 = ft_map.rbegin();


    for (int i = 0; i < 3; i++)
    {
        assert(it11->first == it12->first);
        assert(it11->second == it12->second);
        it11++;
        it12++;
    }

    cout << "\033[34m REVERSE ITERATOR MAP OPERATOR ++ \033[0m => \033[32m [OK] \033[0m" << endl;

    for (int i = 0; i < 4; i++)
    {
        assert(it11->first == it12->first);
        assert(it11->second == it12->second);
        it11--;
        it12--;
    }

    cout << "\033[34m REVERSE ITERATOR MAP OPERATOR -- \033[0m => \033[32m [OK] \033[0m" << endl;

    it11 = std_map.rbegin();
    it12 = ft_map.rbegin();

    for (int i = 0; i < 4; i++)
    {
        assert(it11->first == it12->first);
        assert(it11->second == it12->second);
        it11++;
        it12++;
    }

    cout << "\033[34m REVERSE ITERATOR MAP OPERATOR == \033[0m => \033[32m [OK] \033[0m" << endl;

    it11 = std_map.rbegin();
    it12 = ft_map.rbegin();

    for (int i = 0; i < 4; i++)
    {
        assert(it11->first == it12->first);
        assert(it11->second == it12->second);
        it11++;
        it12++;
    }

    cout << "\033[34m REVERSE ITERATOR MAP OPERATOR != \033[0m => \033[32m [OK] \033[0m" << endl;

    it11 = std_map.rbegin();
    it12 = ft_map.rbegin();

    assert(it11->first == it12->first);
    assert(it11->second == it12->second);

    cout << "\033[34m REVERSE ITERATOR MAP OPERATOR * \033[0m => \033[32m [OK] \033[0m" << endl;

    it11 = std_map.rbegin();
    it12 = ft_map.rbegin();

    assert(it11->first == it12->first);
    assert(it11->second == it12->second);

    cout << "\033[34m REVERSE ITERATOR MAP OPERATOR -> \033[0m => \033[32m [OK] \033[0m" << endl;

}



void test_map_capacity()
{
    // test map empty with assert

    std::map<char, int> std_map;
    ft::map<char, int> ft_map;

    assert(std_map.empty() == ft_map.empty());

    cout << "\033[34m MAP EMPTY \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map size with assert

    std_map['a'] = 10;
    std_map['b'] = 20;
    std_map['c'] = 30;
    std_map['d'] = 40;

    ft_map['a'] = 10;
    ft_map['b'] = 20;
    ft_map['c'] = 30;
    ft_map['d'] = 40;

    assert(std_map.size() == ft_map.size());

    cout << "\033[34m MAP SIZE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map max_size with assert

    assert(std_map.max_size() == ft_map.max_size());

    cout << "\033[34m MAP MAX SIZE \033[0m => \033[32m [OK] \033[0m" << endl;

}


void test_map_element_access()
{
    // test map operator [] with assert

    std::map<char, int> std_map;
    ft::map<char, int> ft_map;

    std_map['a'] = 10;
    std_map['b'] = 20;
    std_map['c'] = 30;
    std_map['d'] = 40;

    ft_map['a'] = 10;
    ft_map['b'] = 20;
    ft_map['c'] = 30;
    ft_map['d'] = 40;

    assert(std_map['a'] == ft_map['a']);
    assert(std_map['b'] == ft_map['b']);
    assert(std_map['c'] == ft_map['c']);
    assert(std_map['d'] == ft_map['d']);

    cout << "\033[34m MAP OPERATOR [] \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map at with assert

    assert(std_map.at('a') == ft_map.at('a'));
    assert(std_map.at('b') == ft_map.at('b'));
    assert(std_map.at('c') == ft_map.at('c'));
    assert(std_map.at('d') == ft_map.at('d'));

    cout << "\033[34m MAP AT \033[0m => \033[32m [OK] \033[0m" << endl;

}


void test_map_modifiers()
{
    // test map insert with assert

    std::map<char, int> std_map;
    ft::map<char, int> ft_map;

    std_map.insert(std::pair<char, int>('a', 10));
    std_map.insert(std::pair<char, int>('b', 20));
    std_map.insert(std::pair<char, int>('c', 30));
    std_map.insert(std::pair<char, int>('d', 40));

    ft_map.insert(ft::pair<char, int>('a', 10));
    ft_map.insert(ft::pair<char, int>('b', 20));
    ft_map.insert(ft::pair<char, int>('c', 30));
    ft_map.insert(ft::pair<char, int>('d', 40));

    assert(std_map['a'] == ft_map['a']);
    assert(std_map['b'] == ft_map['b']);
    assert(std_map['c'] == ft_map['c']);
    assert(std_map['d'] == ft_map['d']);

    cout << "\033[34m MAP INSERT \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map erase with assert

    std_map.erase(std_map.begin());
    ft_map.erase(ft_map.begin());

    assert(std_map['b'] == ft_map['b']);
    assert(std_map['c'] == ft_map['c']);
    assert(std_map['d'] == ft_map['d']);

    cout << "\033[34m MAP ERASE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map swap with assert

    std::map<char, int> std_map2;
    ft::map<char, int> ft_map2;

    std_map2['a'] = 10;
    std_map2['b'] = 20;
    std_map2['c'] = 30;
    std_map2['d'] = 40;

    ft_map2['a'] = 10;
    ft_map2['b'] = 20;
    ft_map2['c'] = 30;
    ft_map2['d'] = 40;

    std_map.swap(std_map2);
    ft_map.swap(ft_map2);

    assert(std_map['a'] == ft_map['a']);
    assert(std_map['b'] == ft_map['b']);
    assert(std_map['c'] == ft_map['c']);
    assert(std_map['d'] == ft_map['d']);

    cout << "\033[34m MAP SWAP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map clear with assert

    std_map.clear();
    ft_map.clear();

    assert(std_map.size() == ft_map.size());

    cout << "\033[34m MAP CLEAR \033[0m => \033[32m [OK] \033[0m" << endl;

}


void test_map_observers()
{
    // test map find with assert

    std::map<char, int> std_map;
    ft::map<char, int> ft_map;

    std_map['a'] = 10;
    std_map['b'] = 20;
    std_map['c'] = 30;
    std_map['d'] = 40;

    ft_map['a'] = 10;
    ft_map['b'] = 20;
    ft_map['c'] = 30;
    ft_map['d'] = 40;

    assert(std_map.find('a')->second == ft_map.find('a')->second);
    assert(std_map.find('b')->second == ft_map.find('b')->second);
    assert(std_map.find('c')->second == ft_map.find('c')->second);
    assert(std_map.find('d')->second == ft_map.find('d')->second);

    cout << "\033[34m MAP FIND \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map count with assert

    assert(std_map.count('a') == ft_map.count('a'));
    assert(std_map.count('b') == ft_map.count('b'));
    assert(std_map.count('c') == ft_map.count('c'));
    assert(std_map.count('d') == ft_map.count('d'));

    cout << "\033[34m MAP COUNT \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map lower_bound with assert

    assert(std_map.lower_bound('a')->second == ft_map.lower_bound('a')->second);
    assert(std_map.lower_bound('b')->second == ft_map.lower_bound('b')->second);
    assert(std_map.lower_bound('c')->second == ft_map.lower_bound('c')->second);
    assert(std_map.lower_bound('d')->second == ft_map.lower_bound('d')->second);

    cout << "\033[34m MAP LOWER_BOUND \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map upper_bound with assert

    assert(std_map.upper_bound('a')->second == ft_map.upper_bound('a')->second);
    assert(std_map.upper_bound('b')->second == ft_map.upper_bound('b')->second);
    assert(std_map.upper_bound('c')->second == ft_map.upper_bound('c')->second);

    cout << "\033[34m MAP UPPER_BOUND \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map equal_range with assert

    assert(std_map.equal_range('a').first->second == ft_map.equal_range('a').first->second);
    assert(std_map.equal_range('b').first->second == ft_map.equal_range('b').first->second);
    assert(std_map.equal_range('c').first->second == ft_map.equal_range('c').first->second);
    assert(std_map.equal_range('d').first->second == ft_map.equal_range('d').first->second);


    cout << "\033[34m MAP EQUAL_RANGE \033[0m => \033[32m [OK] \033[0m" << endl;

}


void test_map_operations()
{
    // test map insert with assert

    std::map<char, int> std_map;
    ft::map<char, int> ft_map;

    std_map.insert(std::pair<char, int>('a', 10));
    std_map.insert(std::pair<char, int>('b', 20));
    std_map.insert(std::pair<char, int>('c', 30));
    std_map.insert(std::pair<char, int>('d', 40));

    ft_map.insert(ft::pair<char, int>('a', 10));
    ft_map.insert(ft::pair<char, int>('b', 20));
    ft_map.insert(ft::pair<char, int>('c', 30));
    ft_map.insert(ft::pair<char, int>('d', 40));

    assert(std_map['a'] == ft_map['a']);
    assert(std_map['b'] == ft_map['b']);
    assert(std_map['c'] == ft_map['c']);
    assert(std_map['d'] == ft_map['d']);

    cout << "\033[34m MAP INSERT \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map erase with assert

    std_map.erase(std_map.begin());
    ft_map.erase(ft_map.begin());

    assert(std_map['b'] == ft_map['b']);
    assert(std_map['c'] == ft_map['c']);
    assert(std_map['d'] == ft_map['d']);

    cout << "\033[34m MAP ERASE \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map swap with assert

    std::map<char, int> std_map2;
    ft::map<char, int> ft_map2;

    std_map2['a'] = 10;
    std_map2['b'] = 20;
    std_map2['c'] = 30;
    std_map2['d'] = 40;

    ft_map2['a'] = 10;
    ft_map2['b'] = 20;
    ft_map2['c'] = 30;
    ft_map2['d'] = 40;

    std_map.swap(std_map2);
    ft_map.swap(ft_map2);

    assert(std_map['a'] == ft_map['a']);
    assert(std_map['b'] == ft_map['b']);

    assert(std_map2['c'] == ft_map2['c']);
    assert(std_map2['d'] == ft_map2['d']);

    cout << "\033[34m MAP SWAP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map clear with assert

    std_map.clear();
    ft_map.clear();

    assert(std_map.empty() == ft_map.empty());

    cout << "\033[34m MAP CLEAR \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map key_comp with assert

    std::map<char, int>::key_compare std_key_comp = std_map.key_comp();
    ft::map<char, int>::key_compare ft_key_comp = ft_map.key_comp();

    assert(std_key_comp('a', 'b') == ft_key_comp('a', 'b'));
    assert(std_key_comp('b', 'a') == ft_key_comp('b', 'a'));

    cout << "\033[34m MAP KEY_COMP \033[0m => \033[32m [OK] \033[0m" << endl;

    // test map value_comp with assert

    std::map<char, int>::value_compare std_value_comp = std_map.value_comp();
    ft::map<char, int>::value_compare ft_value_comp = ft_map.value_comp();

    assert(std_value_comp(std::pair<char, int>('a', 10), std::pair<char, int>('b', 20)) == ft_value_comp(ft::pair<char, int>('a', 10), ft::pair<char, int>('b', 20)));

    cout << "\033[34m MAP VALUE_COMP \033[0m => \033[32m [OK] \033[0m" << endl;

}



void test_map()
{
    std::cout << "\033[34m***************************[MAP]***************************\033[0m" << std::endl;
    std::cout << "\033[34m*                                                          *\033[0m" << std::endl;
    std::cout << "\033[34m*                                                          *\033[0m" << std::endl;
    std::cout << "\033[34m*  SELECT TEST:                                            *\033[0m" << std::endl;
    std::cout << "\033[34m*                                                          *\033[0m" << std::endl;
    std::cout << "\033[34m*  1. CONSTRUCTOR                                          *\033[0m" << std::endl;
    std::cout << "\033[34m*  2. ITERATOR                                             *\033[0m" << std::endl;
    std::cout << "\033[34m*  3. CAPACITY                                             *\033[0m" << std::endl;
    std::cout << "\033[34m*  4. ELEMENT ACCESS                                       *\033[0m" << std::endl;
    std::cout << "\033[34m*  5. MODIFIERS                                            *\033[0m" << std::endl;
    std::cout << "\033[34m*  6. OBSERVERS                                            *\033[0m" << std::endl;
    std::cout << "\033[34m*  7. OPERATIONS                                           *\033[0m" << std::endl;
    std::cout << "\033[34m*  8. ALL                                                  *\033[0m" << std::endl;
    std::cout << "\033[34m*                                                          *\033[0m" << std::endl;
    std::cout << "\033[34m*                                                          *\033[0m" << std::endl;
    std::cout << "\033[34m************************************************************\033[0m" << std::endl;
    std::cout << "\n";
    std::cout << "\033[32mSELECT TEST => \033[0m";

    int test;
    std::cin >> test;
    std::cout << "\n";

    while (1)
    {
        if (test == 1)
            test_map_constructor();
        if (test == 2)
            test_map_iterators();
        if (test == 3)
            test_map_capacity();
        if (test == 4)
            test_map_element_access();
        if (test == 5)
            test_map_modifiers();
        if (test == 6)
            test_map_observers();
        if (test == 7)
            test_map_operations();
        if (test == 8)
        {
            test_map_constructor();
            test_map_iterators();
            test_map_capacity();
            test_map_element_access();
            test_map_modifiers();
            test_map_observers();
            test_map_operations();
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
        cout << "\033[34m6. OBSERVERS\033[0m" << endl;
        cout << "\033[34m7. OPERATIONS\033[0m" << endl;
        cout << "\033[34m8. ALL\033[0m" << endl;
		cout << "\033[34m9. EXIT\033[0m" << endl;
		cout << "\n\n";
		std::cout << "\033[32mSELECT TEST => \033[0m";
		std::cin >> test;
		std::cout << "\n";


    }
}
