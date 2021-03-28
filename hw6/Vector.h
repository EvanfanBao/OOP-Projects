//Vector template
#include<exception>
using namespace std;

template <class T>
class Vector {
public:
  Vector();                      // creates an empty vector
  Vector(int size);              // creates a vector for holding 'size' elements
  Vector(const Vector& r);       // the copy ctor
  ~Vector();                     // destructs the vector 
  T& operator[](int index);      // accesses the specified element without bounds checking
  T& at(int index);              // accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
  int size() const;		         // return the size of the container
  void push_back(const T& x);    // adds an element to the end 
  void clear();                  // clears the contents
  bool empty() const;            // checks whether the container is empty 
private:
  void inflate();                // expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
  T *m_pElements;                // pointer to the dynamically allocated storage
  int m_nSize;                   // the number of elements in the container
  int m_nCapacity;               // the number of elements that can be held in currently allocated storage
};

//create an empty vector
template <class T>
Vector<T>::Vector():m_nSize(0),m_nCapacity(0),m_pElements(NULL){}   //Initialization list

//creates a vector for holding 'size' elements
template <class T>
Vector<T>::Vector(int size):m_nSize(size),m_nCapacity(size){
    m_pElements = new T[size]();    //Initialize to 0, with sizeof(T) space
}


//the copy ctor
template <class T>
Vector<T>::Vector(const Vector<T>& r){
    m_nSize = r.m_nSize;                    //copy vector size
    m_nCapacity = r.m_nCapacity;            //copy vector capacity
    m_pElements = new T[m_nSize];           //new space 
    for(int i = 0;i < m_nSize;i++){
        m_pElements[i] = *(r.m_pElements + i);//copy the content -- note r is const Vector<T> cannot use operator[] or at() -- so we use pointer
    }
}

//destructs the vector
template <class T>
Vector<T>::~Vector(){
    delete[] m_pElements;                   //delete the space allocated from heap
}

//accesses the specified element without bounds checking
template <class T>
T& Vector<T>:: operator[](int index){
    return m_pElements[index];             //without bound checking -- array index
}

//accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
template <class T>
T& Vector<T>:: at(int index){
    
    try{
        if(index >= m_nSize || index < 0)
            throw out_of_range("vector::_M_range_check: __n >= this->size()");      //exception throw
        return m_pElements[index];
    }catch(exception &e){                                                           //handle the exception
        cout << "terminate called after throwing an instance of 'std::out_of_range'"<<endl;
        cout << "what():  "<<e.what()<< endl;
    }
}

//return the size of the container
template <class T>
int Vector<T>::size()const{
    return m_nSize;         //simply return the size
}

//adds an element to the end
template <class T>
void Vector<T>::push_back(const T& x){
    if(m_nCapacity == 0){                   //no elements, new one, and set size and capacity
        m_nCapacity = 1;
        m_nSize = 1;
        m_pElements = new T[100];             //new one space -- just like the std::vector
        m_pElements[0] = x;
    }
    else{
        m_nSize++;                          //size++
        if(m_nSize == m_nCapacity)          //if the container is full
            inflate();                      //then inflate -- twice larger
        m_pElements[m_nSize-1] = x;         //set the value to back of container
    }
}

//clears the contents
template <class T>
void Vector<T>::clear(){
    for(int i = 0;i < m_nSize;i++){     //call destructor of each elements O(N)
        m_pElements[i].~T();
    }
    m_nSize = 0;                        //set size to 0, without changing the capacity -- just like the std::vector
}

//checks whether the container is empty 
template <class T>
bool Vector<T>::empty()const{       
    return m_nSize == 0;               
}

//expand the storage of the container to a new capacity, 2*m_nCapacity
template <class T>
void Vector<T>::inflate(){
    T* Inflated_pElement = new T[2*m_nCapacity];        //double the storage
    for(int i = 0;i < m_nCapacity;i++)
        Inflated_pElement[i] = m_pElements[i];          //copy the content
    delete[] m_pElements;                               //free old space
    m_pElements = Inflated_pElement;                    //set new pointer
}