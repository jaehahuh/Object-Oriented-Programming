//Author: Jaeha Huh
//Name of File: rec09.cpp


/*
 #include <iostream>
 using namespace std;

 class PrintedMaterial {
 public:
 protected:
 private:
 unsigned numOfPages;
 };

 class Magazine : public PrintedMaterial {
 public:
 protected:
 private:
 unsigned numOfPages;
 };

 class Book : public PrintedMaterial {
 public:
 protected:
 private:
 unsigned numOfPages;
 };

 class TextBook : public Book {
 public:
 protected:
 private:
 unsigned numOfPages;
 };

 class Novel : public Book {
 public:
 protected:
 private:
 unsigned numOfPages;
 };

 // tester/modeler code
 int main()
 {
 TextBook t;
 Novel n;
 Magazine m;
 }
 */

 /*
 #include <iostream>
 using namespace std;

 class PrintedMaterial {
 public:
 protected:
 private:
	unsigned numOfPages;
 };

 class Magazine : public PrintedMaterial {
 public:
 protected:
 private:
	unsigned numOfPages;
 };

 class Book : public PrintedMaterial {
 public:
 protected:
 private:
	unsigned numOfPages;
 };

 class TextBook : public Book {
 public:
 protected:
 private:
	unsigned numOfPages;
 };

 class Novel : public Book {
 public:
 protected:
 private:
	unsigned numOfPages;
 };

 // tester/modeler code
 int main()
 {
	TextBook t;
	Novel n;
	Magazine m;
 }
 */


 // Task 6 

 //#include <iostream>
 //using namespace std;
 //
 ////child class can inherit funcs and members from parent, can call funcs in parent
 //
 //class PrintedMaterial {
 //public:
 ////    PrintedMaterial(unsigned numberOfPages): numberOfPages(numberOfPages){}
 ////    virtual void displayNumPages() const = 0;
 //    void displayNumPages() const { cout << numberOfPages << "  base" << endl; }
 //protected:
 //private:
 //    unsigned numberOfPages;
 //};
 //
 ////void PrintedMaterial:: displayNumPages() const { cout << numberOfPages << endl; }
 //
 //
 //
 //class Magazine : public PrintedMaterial {
 //public:
 ////    Magazine(unsigned numberOfPages): PrintedMaterial(numberOfPages) {}
 ////    void displayNumPages() const {PrintedMaterial::displayNumPages();}
 //protected:
 //private:
 //};
 //
 //
 //
 //class Book : public PrintedMaterial {
 //public:
 ////    Book(unsigned numberOfPages): PrintedMaterial(numberOfPages) {}
 ////    void displayNumPages() const {PrintedMaterial::displayNumPages();}
 //protected:
 //private:
 //};
 //
 //
 //
 //class TextBook : public Book {
 //public:
 ////    TextBook(unsigned numberOfPages): Book(numberOfPages) {}
 ////    void displayNumPages() const {Book::displayNumPages();}
 //protected:
 //private:
 //};
 //
 //
 //
 //class Novel : public Book {
 //public:
 ////    Novel(unsigned numberOfPages): Book(numberOfPages) {}
 ////    void displayNumPages() const {Book::displayNumPages();}
 //protected:
 //private:
 //};
 //
 //
 //
 //// tester/modeler code
 //int main(){
 //
 //    TextBook t;
 //    Novel n;
 //    Magazine m;
 //
 ////    TextBook t(3);
 ////    Novel n(4);
 ////    Magazine m(5);
 //
 //    t.displayNumPages();
 //    n.displayNumPages();
 //    m.displayNumPages();
 //
 //}





 // Task 7

 //what is virtual; how does it work????

 //#include <iostream>
 //using namespace std;
 //
 //class PrintedMaterial {
 //public:
 //    PrintedMaterial( unsigned numPages ): numOfPages(numPages) {}
 //    void displayNumPages() const { cout << numOfPages << endl; }
 //protected:
 //private:
 //    unsigned numOfPages;
 //};
 //
 //class Magazine : public PrintedMaterial {
 //public:
 //    Magazine( unsigned numPages ): PrintedMaterial(numPages){}
 //protected:
 //private:
 //};
 //
 //class Book : public PrintedMaterial {
 //public:
 //    Book( unsigned numPages ): PrintedMaterial(numPages){}
 //protected:
 //private:
 //};
 //
 //class TextBook : public Book {
 //public:
 //    TextBook( unsigned numPages, unsigned numIndxPgs )
 //    : Book(numPages), numOfIndexPages(numIndxPgs) {}
 //
 //    void displayNumPages() const {
 //        cout << "numOfIndexPages: " << numOfIndexPages << "  numPages: ";
 //        PrintedMaterial::displayNumPages();
 //    }
 //protected:
 //private:
 //    unsigned numOfIndexPages;
 //};
 //
 //class Novel : public Book {
 //public:
 //    Novel( unsigned numPages ): Book(numPages){}
 //protected:
 //private:
 //};
 //
 //// tester/modeler code
 //int main()
 //{
 //    TextBook t(5430, 234);
 //    Novel n(213);
 //    Magazine m(6);
 //
 //    t.displayNumPages();
 //    n.displayNumPages();
 //    m.displayNumPages();
 //}


 //Task 9 

 //#include <iostream>
 //using namespace std;
 //
 //class PrintedMaterial {
 //public:
 //    PrintedMaterial( unsigned numPages ): numOfPages(numPages) {}
 //    virtual void displayNumPages() const = 0;
 ////    { cout << numOfPages << endl; }
 //protected:
 //private:
 //    unsigned numOfPages;
 //};
 //
 //class Magazine : public PrintedMaterial {
 //public:
 //    Magazine( unsigned numPages ): PrintedMaterial(numPages){}
 //    void displayNumPages() const {
 //        PrintedMaterial::displayNumPages();
 //    }
 //protected:
 //private:
 //};
 //
 //class Book : public PrintedMaterial {
 //public:
 //    Book( unsigned numPages ): PrintedMaterial(numPages){}
 //protected:
 //private:
 //};
 //
 //class TextBook : public Book {
 //public:
 //    TextBook( unsigned numPages, unsigned numIndxPgs )
 //    : Book(numPages), numOfIndexPages(numIndxPgs) {}
 //
 //    void displayNumPages() const {
 //        cout << "numOfIndexPages: " << numOfIndexPages << endl <<"numPages: ";
 //        PrintedMaterial::displayNumPages();
 //    }
 //protected:
 //private:
 //    unsigned numOfIndexPages;
 //};
 //
 //class Novel : public Book {
 //public:
 //    Novel( unsigned numPages ): Book(numPages){}
 //    void displayNumPages() const {
 //        PrintedMaterial::displayNumPages();
 //    }
 //protected:
 //private:
 //};
 //
 //
 //void displayNumberOfPages(const PrintedMaterial& aPm){
 //    aPm.displayNumPages();
 //}


 // tester/modeler code
 //int main()
 //{
 //    TextBook t;
 //    Novel n;
 //    Magazine m;

 //    TextBook t(5430, 234);
 //    Novel n(213);
 //    Magazine m(6);
 //
 //    t.displayNumPages();
 //    n.displayNumPages();
 //    m.displayNumPages();

 //    PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
 //    pm.displayNumPages();


 //    cout << "\nA PrintedMaterial material object!\n";
 //    PrintedMaterial pm(2345);
 //    pm.displayNumPages();

 //    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
 //    pm = t; // like putting a t into a vector of PrintedMaterials
 //    pm.displayNumPages();


 //    cout << "Try using pointer to base type\n";
 //    PrintedMaterial* pmPtr;
 //    pmPtr = &t;
	 // instead of putting an actual PrintedMaterial
	 // object into the vector, we put a pointer to
	 // a PrintedMaterial object (t) into a vector
	 // of pointers-to-PrintedMaterial
	 // (that is, pointers to the Base class)
	 // we'll be "managing" our objects by using
	 // pointers to PrintedMaterial values.

 //    pmPtr->displayNumPages();

 //    Recall that the virtual mechanism works with either pointers to base class or reference to base class.????????????

 //    displayNumberOfPages(m);
 //    displayNumberOfPages(n);
 //    displayNumberOfPages(t);

 //}



 #include <iostream>
 #include <vector>
 using namespace std;
 
 class printedmaterial {
 public:
     printedmaterial( unsigned numpages )
     : numofpages(numpages)
     {}
 
     virtual void displaynumpages() const = 0;
 
 protected:
 private:
     unsigned numofpages;
 };
 
 void printedmaterial::displaynumpages() const {
     cout << numofpages << endl;
 }
 
 class magazine : public printedmaterial {
 public:
     magazine( unsigned numpages )
     : printedmaterial(numpages)
     {}
 
     // virtual - note even without writing "virtual"
     // again, this overriden method is virtual
     // viruality cannot be removed once installed
     // also note that the = 0 has is not there
     void displaynumpages() const
     {
         cout << "hi, i'm a magazine object stored\n"
         << "(but i can't know that i am being\n"
         << "stored (by pointer) in a vector of\n"
         << "printedmaterial pointers!\n";
         printedmaterial::displaynumpages();
         cout << "(and i'm very glossy!\n";
     }
 
 protected:
 private:
 };
 
 class book : public printedmaterial {
 public:
     book( unsigned numpages)
     : printedmaterial(numpages)
     {}
 protected:
 private:
 };
 
 class textbook : public book {
 public:
     textbook( unsigned numpages, unsigned numindxpgs  )
     : book(numpages),
     numofindexpages(numindxpgs)
     {}
 
     void displaynumpages() const
     {
         cout << "\nthis is a textbook.\n";
         cout << "it is a very boring textbook.\n";
         cout << "pages: ";
         printedmaterial::displaynumpages();
         cout << "index pages: ";
         cout << numofindexpages << endl;
     }
 protected:
 private:
     unsigned numofindexpages;
 };
 
 class novel : public book {
 public:
     novel( unsigned numpages )
     : book(numpages)
     {}
     void displaynumpages() const
     {
         cout << "\nthis is the story of a very\n"
         << " interesting programmer's quest\n"
         << "  understand inheritance.\n"
         << "   the journey is just beginning\n"
         << "    and already the journeyman\n"
         << "      hacker, no - not a hacker! -\n"
         << "         a programmer who reads, and\n"
         << "             studies and understands code\n"
         << "                 hackers steal and don't even\n"
         << "                      try to understand what they stole\n"
         << "                           before using it.\n"
         << "\n       ...but i digress.\n"
         << "\nthis novel is quite long, there\n"
         << "being this number of pages:\n"
         << "=====================================\n"
         << "                 ";
         printedmaterial::displaynumpages();
         cout << "=====================================\n"
         << "whew!\n"
         << " but there is an exciting\n"
         << "  programming adventure on every\n"
         << "   single one of them!\n"
         << "    and now, let's let the quest continue..."
         << endl << endl << endl;
     }
 protected:
 private:
 };
 
 
 // tester/modeler code
 int main()
 {
     textbook t(5430, 23);
     novel n(213);
     magazine m(6);
 
     t.displaynumpages();
     n.displaynumpages();
     m.displaynumpages();
 
     cout << "\nusing printedmaterial* to \"store\" a textbook object\n";
     cout << "now with the virtual mechanism involved\n";
     printedmaterial* pmptr;
     pmptr = &t; // like putting t into a vector but
     // we are actually putting the address of t
     // into a vector pointers of pointers to
     // printedmaterials. we'll "say" we are putting
     // t into the vector
     // (that is, pointers to the base class)
     pmptr->displaynumpages();
 
     vector<printedmaterial*> pms;
     pms.push_back(pmptr);
     for (size_t i = 0; i < pms.size(); ++i){
         pms[i]->displaynumpages();
     }
 }


