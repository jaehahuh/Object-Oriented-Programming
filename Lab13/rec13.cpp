//Author: Jaeha Huh
//Name of File: rec13.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;



//inheritance test

//class Base {
//public:
//    virtual ~Base(){cout << "~Base" << endl;}
//};
//class Derived : public Base {
//public:
//    ~Derived(){cout << "~Derived" << endl;}
//};
//int main(){
//    Derived d;
//    Base base(d);
//
//}



//struct MyException: public exception {
//    const char* what() noexcept {return "this is MyException";}
//};
//
//
//void bar(int n){
//
//    assert(n <= 200);//assertion makes it easier to debug; it assumes the info that passed in or gonna to be returned is correct;
//
////    throw 3.145;//anything type can be thrown; you'll not be in that block of code/loop/function anymore
////    throw exception();
////    cout << "dfdfd"; //won't be executed because of throw
//
//    vector<int> v;
////    cout << v[0] << endl; // segmentation error at run-time
//
//    v.push_back(17);
////    cout << v[1] << endl;//may print a random garbage value
//    cout << v.at(1) << endl;//carsh but will be different than before
//}
//
//void foo(int n){
////    cout<<"D1"<<endl;
//    bar(n);
////    cout<<"D2"<<endl; //once throw this and next line won't be executed
////    bar(n);
//}
//
//
//
//int main(){
//
//    try{
//        foo(300);
//    }
////    catch (MyException myex){
////        cout << "Caught: " << myex.what() << endl;
////    }
//    catch (out_of_range oor) {//this one is more specific, therefore, should be put before the next one: catch (exception& ex){}
//        cout << "Caught out of range: " << oor.what() << endl; //what() tells you which type of object produces the error
//    }
//    catch (exception ex) {//by value: slicing problem
////    catch (exception& ex) {//by reference: reference of the object causes virtual mechanism; this line will now catch any exceptions
//        cout << "Caught exception: " << ex.what() << endl;
//    }
//
//    catch (...){//... because it doesn't know what typy of thing it is thrown at
//        cerr << "error message" << endl;
//    }
//    cerr << "Running..." << endl; //program is still running after catch
//}







//task 9 //
void printList(const list<int>& l) {
	for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
		cout << *i << ' ';
	}
}



//task 12 //
list<int>::const_iterator searchItem(const list<int>& l, int num) {
	for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
		if (*i == num) {
			return i;
		}
	}
	return l.end();
}


//task 13 //
auto searchItem2(const list<int>& l, int num) {
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (*i == num) {
			return i;
		}
	}
	return l.end();
}



//task 15 //
bool isEven(int n) {
	return n % 2 == 0;
}



//task 16 //
class Whatever {
public:
	Whatever(int num) :number(num) {}
	bool operator()(int n) {
		return n % number == 0;
	}
	//    bool operator()(int n){
	//        return n % 3 == 0;
	//    }
private:
	int number;
};


//task 19 //
list<int>::const_iterator ourFind(const list<int>::const_iterator& begin, const list<int>::const_iterator& end, int n) {
	cout << "ourFind" << endl;
	for (list<int>::const_iterator i = begin; i != end; ++i) {
		if (*i == n) {
			return i;
		}
	}
	return end;
}


//task 20 //
template <class T, class N>
T ourFind(const T& begin, const T& end, const N& n) {
	cout << "ourFind_TEMPLATE" << endl;
	for (T i = begin; i != end; ++i) {
		if (*i == n) {
			return i;
		}
	}
	return end;
}


//void foo(int& n){
//    cout<<"";
//}

//class s{
//public:
//    s(int n):n(n){}
//private:
//    int n;
//};
//
//class ss{
//public:
//    ss(int n):a(){}
//private:
//    s a;
//};



void foo(int*& ptr, int& d) { //passing pointer by reference allows you to change the address it points to
	cout << "in foo:" << endl;
	//        *ptr = 99999;
	ptr = &d;
	cout << *ptr << endl;
	cout << "end foo" << endl;
}

class a {
public:
	virtual void display() { cout << "a"; }
};

class b {
public:
	virtual void display() { cout << "b"; }
};

class c : public a, public b {
public:
};


//for (vector<int>::iterator i = v.begin(); i != v.end()l ++i) {
	//...
//}




int main() {
	//    c c;
	//    c.display();

	//    int p = 3;
	//    foo(p);

	//    delete nullptr;//wrong
	//    int pp=9;
	//    int* p = &pp;
	//    delete p;
	//    delete p;




		// 1. Create a vector with some values and display using ranged for
	cout << "Task 1:\n";
	vector<int> v = { 1,2,4,3,6,34 };
	cout << "vector: ";
	for (int val : v) {
		cout << val << " ";
	}
	cout << "\n=======\n";





	// 2. Initalize a list as a copy of values from the vector
	cout << "Task 2:\n";
	list<int> l(v.begin(), v.end());
	//    copy(v.begin(), v.end(), l.begin());
	//    copy(l.begin(), l.end(), v.begin());
	cout << "list: ";
	for (int val : l) {
		cout << val << " ";
	}
	cout << "\n=======\n";





	// 3. Sort the original vector.  Display both the vector and the list
	cout << "Task 3:\n";
	sort(v.begin(), v.end());
	cout << "vector: ";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl << "list: ";
	for (int val : l) {
		cout << val << " ";
	}
	cout << "\n=======\n";





	// 4. print every other element of the vector.
	cout << "Task 4:\n";
	cout << "vector: ";
	for (size_t i = 0; i < v.size(); ++++i) {
		cout << v[i] << " ";
	}
	cout << "\n=======\n";




	// 5. Attempt to print every other element of the list using the
	//    same technique.
	cout << "Task 5:\n";
	cout << "failed attempt";
	//    for(size_t i = 0; i < l.size(); ++++i){
	//        cout << l[i] << " ";
	//    }
	cout << "\n=======\n";

	//
	// Iterators
	//




	// 6. Repeat task 4 using iterators.  Do not use auto;
	cout << "Task 6:\n";
	cout << "vector: ";
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++++i) { //or use i = i + 2
		cout << *i << ' ';
	}
	cout << "\n=======\n";




	// 7. Repeat the previous task using the list.  Again, do not use auto.
	//    Note that you cannot use the same simple mechanism to bump
	//    the iterator as in task 6.
	cout << "Task 7:\n";
	cout << "list: ";
	for (list<int>::iterator i = l.begin(); i != l.end(); ++++i) {// can't use i = i + 2
		cout << *i << ' ';
	}
	//    int counter = 0;
	//    for(list<int>::iterator i = l.begin(); i != l.end(); ++i){
	//        if(counter % 2 == 0){
	//            cout << *i << ' ';
	//        }
	//        ++counter;
	//    }
	cout << "\n=======\n";





	// 8. Sorting a list
	cout << "Task 8:\n";
	cout << "list: ";
	l.sort();
	for (int val : l) {
		cout << val << " ";
	}
	cout << "\n=======\n";






	// 9. Calling the function to print the list
	cout << "Task 9:\n";
	cout << "list: ";
	printList(l);
	cout << "\n=======\n";






	// 10. Calling the function that prints the list, using ranged-for
	cout << "Task 10:\n";
	cout << "list: ";
	for (int val : l) {
		cout << val << " ";
	}
	cout << "\n=======\n";




	//
	// Auto
	//

	// 11. Calling the function that, using auto, prints alterate
	// items in the list
	cout << "Task 11:\n";
	cout << "list: ";
	for (auto i = l.begin(); i != l.end(); ++i) {
		cout << *i << " ";
	}
	cout << "\n=======\n";






	// 12.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 12:\n";
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
	for (auto i = l.begin(); i != l.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;


	int a = 4; //in the list
	int b = 100; // not in the list
	list<int>::const_iterator find1 = searchItem(l, a);
	list<int>::const_iterator find2 = searchItem(l, b);
	if (find1 != l.end()) cout << *find1 << endl; else { cout << "not found" << endl; }
	if (find2 != l.end()) cout << *find2 << endl; else { cout << "not found" << endl; }
	cout << "\n=======\n";






	// 13.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 13:\n";
	find1 = searchItem2(l, a); //in the list
	find2 = searchItem2(l, b); //not in the list
	if (find1 != l.end()) cout << *find1 << endl; else { cout << "not found" << endl; }
	if (find2 != l.end()) cout << *find2 << endl; else { cout << "not found" << endl; }
	cout << "\n=======\n";





	//
	// Generic Algorithms
	//

	// 14. Generic algorithms: find
	cout << "Task 14:\n";
	find1 = find(l.begin(), l.end(), a);
	find2 = find(l.begin(), l.end(), b);
	if (find1 != l.end()) cout << *find1 << endl; else { cout << "not found" << endl; }
	if (find2 != l.end()) cout << *find2 << endl; else { cout << "not found" << endl; }
	cout << "\n=======\n";





	// 15. Generic algorithms: find_if
	cout << "Task 15:\n";
	cout << "vector: ";
	vector<int>::const_iterator find7 = find_if(v.begin(), v.end(), isEven);
	if (find7 != v.end()) { cout << *find7; }
	else { cout << "not found"; }
	cout << endl;
	cout << "list: ";
	if (find_if(l.begin(), l.end(), isEven) != l.end()) { cout << *find_if(l.begin(), l.end(), isEven); }
	else { cout << "not found"; }
	cout << "\n=======\n";





	// 16. Functor
	cout << "Task 16:\n";
	cout << "vector: ";
	find7 = find_if(v.begin(), v.end(), Whatever(17));
	if (find7 != v.end()) { cout << *find7; }
	else { cout << "not found"; }
	cout << endl;
	cout << "list: ";
	if (find_if(l.begin(), l.end(), Whatever(2)) != l.end()) { cout << *find_if(l.begin(), l.end(), Whatever(2)); }
	else { cout << "not found"; }
	cout << "\n=======\n";





	// 17. Lambda
	cout << "Task 17:\n";

	[] { cout << "Hello Lambda!"; }();

	[](int a, int b) { cout << a + b << endl; } (4, 5);

	int result = [](int a, int b) { return a + b; } (4, 5);
	cout << "the result is: " << result << endl;

	int result2 = [](int a, int b) -> int { return a + b; } (4, 5);
	cout << "the result is: " << result2 << endl;



	list<int>::const_iterator find3 = find_if(l.begin(), l.end(), [](int n)->bool {return n % 2 == 0; });
	if (find3 != l.end()) cout << *find3 << endl; else { cout << "not found" << endl; }

	cout << "\n=======\n";





	// 18. Generic algorithms: copy to an array
	cout << "Task 18:\n";
	int arr[6]; // if there are eight items in the vector
	copy(l.begin(), l.end(), arr);
	sort(arr, arr + 6);
	for (int val : arr) {
		cout << val << " ";
	}
	//    for(int* i = arr; i != arr+6; ++i){
	//        cout << *i<<" ";
	//    }
	cout << endl;

	cout << *find(arr, arr, 1) << " was found!" << endl;

	int* find5 = find_if(arr, arr + 6, Whatever(2));
	if (find5 != arr + 6) cout << *find5; else { cout << "not found"; }
	cout << "\n=======\n";





	//
	// Templated Functions
	//

	// 19. Implement find as a function for lists
	cout << "Task 19:\n";
	find1 = ourFind(l.begin(), l.end(), a);
	if (find1 != l.end()) cout << *find1; else { cout << "not found"; }
	cout << "\n=======\n";





	// 20. Implement find as a templated function
	cout << "Task 20:\n";
	vector<int>::const_iterator find4 = ourFind(v.begin(), v.end(), a);
	if (find4 != v.end()) cout << *find4; else { cout << "not found"; }
	cout << "\n=======\n";





	//
	// Associative collections
	//

	// 21. Using a vector of strings, print a line showing the number
	//     of distinct words and the words themselves.
	cout << "Task 21:\n";
	ifstream ifs;
	ifs.open("pooh-nopunc.txt");
	if (!ifs) {
		cout << "Error: Can't open the file\n";
		exit(1);
	}
	string word;
	vector<string> wordVector;
	while (ifs >> word) {
		bool found = false;
		for (size_t i = 0; i < wordVector.size(); ++i) {
			if (word == wordVector[i]) {
				found = true;
				break;
			}
		}
		if (!found) {
			wordVector.push_back(word);
		}
	}
	cout << wordVector.size() << endl;
	//    for(string aWord: wordVector){
	//        cout << aWord << " ";
	//    }
	ifs.close();
	cout << "\n=======\n";







	// 22. Repeating previous step, but using the set
	cout << "Task 22:\n";
	ifs.open("pooh-nopunc.txt");
	if (!ifs) {
		cout << "Error: Can't open the file\n";
		exit(1);
	}
	set<string> wordSet;
	while (ifs >> word) {
		if (wordSet.find(word) == wordSet.end()) {
			wordSet.insert(word);
		}
	}

	//    cout << wordSet.size() << endl;
	//    for(string aWord: wordSet){
	//        cout << aWord << " ";
	//    }


	for (set<string>::const_iterator i = wordSet.begin(); i != wordSet.end(); ++++i) {
		cout << *i << " ";
	}

	ifs.close();
	cout << "\n=======\n";







	// 23. Word co-occurence using map
	cout << "Task 23:\n\n\n\n";
	ifs.open("pooh-nopunc.txt");
	if (!ifs) {
		cout << "Error: Can't open the file\n";
		exit(1);
	}
	map<string, vector<int>> wordMap;
	int counter1 = 1;
	while (ifs >> word) {
		if (wordMap[word].size() == 0) {
			wordMap[word].push_back(counter1);
			++counter1;
		}
	}
	cout << wordMap.size() << endl;

	//    cout<<wordMap["a"][0];
	//    auto i = wordMap.find("a"); //i will be a pointer to a pair in map is found
	//    if(i!=wordMap.end()) cout<<i->second[0]; else{cout<<"not found";}


	//    for(const auto& aPair: wordMap){
	//        cout << aPair.first << " ";
	//        for(int pos: aPair.second){
	//            cout << pos << endl;
	//        }
	//    }

	//    cout<<"\n\n\n\n\n\n iterator\n";
	//    for(map<string, vector<int>>::const_iterator i = wordMap.begin(); i != wordMap.end(); ++i){ //doesnt support i=i+2 !
	//        cout<<i->first<<" ";
	//        for (int pos: i->second){
	//            cout<<pos<<endl;
	//        }
	//    }
	//    cout <<wordMap[0];//wrong
	ifs.close();
	cout << "\n=======\n";

	int c = 6;
	int d = 100;
	int* ptr = &c;
	foo(ptr, d);
	cout << c << endl;
	cout << *ptr << endl;



}


