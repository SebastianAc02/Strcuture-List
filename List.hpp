#ifndef List_hpp
#define List_hpp
#include <iostream>
using namespace std;




template <class T>
class List {

private:
    int partition(int start, int end);
protected:
    T* list;
    int length;
    


public:
    List();
    List(int, T);
    List(T*, int);
    List(List<T>&);//copy constructor
    List(List<T>&&); //move constructor
    ~List();


    T access(int);
    void insert(const int , const T ); //index, value
    void append(T);
    void appendSeq(T*, int);
    void removeFirstorAll(T);
    void removeAt(int);
    int GetLength() const;
    void SetLength(int);




    virtual void quickSort(int start, int end) final;
    virtual int Search(T, int, int); //returns index it is located at

    T* getList();
    void operator-(T);
    void operator--(T);
    void operator+(T);
    List operator+(const List&);
    const List& operator=(const List&); //assignment operator
    List& operator=(List&&); //move assignment operator
    const int& operator[](int) const;



    template<typename U>
    friend ostream& operator<< (ostream& os, const List<U>&);
    
    template<typename F>
    friend const istream& operator>>  (istream& in, List<F>&);
    
};


#endif



