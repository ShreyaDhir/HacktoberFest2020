
#ifndef USS_STL
#define USS_STL
#include<iostream>

#define NDEBUG //defined before including casser files or else asserts wont work
#include<cassert>


namespace uss_stl { namespace lineards{
    template<typename T, size_t S>
    class Array {
        private:
        T array[S];

        public:
        // Constructor of this class
        Array() = default;
        // Destructor
        ~Array() = default;

        // constrexp because this will just return size which will be evalauted at the compile time so yeah no need to take stress
        constexpr size_t size() const {
            return S;
        }

        // Overloaded opereator to print the element present at the index
        T& operator [] (size_t index) { // ? Why adding const here causes error find
            if(index < 0 || index >= S) {
                std::cout << "RT error : Cant access values outside the size of uss_stl::Array<typename T, size_t S>" << std::endl;
                exit(0);
            }
            return array[index];
        }
        const T& operator[] (size_t index) const { return array[index]; }
    };


    template<typename T>
    struct is_pointer { static const bool value = false; };

    template<typename T>
    struct is_pointer<T*> { static const bool value = true; };


    template<typename T>
    class Vector {
        private:
        T* m_data;
        int called=0;
        size_t m_size, m_capacity;

        public:
        //Constructor
        Vector() : m_data(nullptr), m_size(0), m_capacity(0) {};
        //Destructor
        // ? Why in the case of a single pointer destructor is called two times
        ~Vector() {
            if(called==1) return;
            called=1;
            //std::cin.get();
            Clear_Vector();
            bool x;
            x=is_pointer<T>::value;
            std::cout << x << std::endl;
            (x) ? void(0) : ::operator delete(m_data, m_capacity * sizeof(T)); // ! Dont call this while using pointers as template params
            // ! This will delete all pointers but not the memory blocks they are pointing to, here by pointers i mean if its like called uss_stl::lineards::Vector<pointer*>
        };

        // * If a lvalue is passed here instead of rvalue nothing will go wrong
        // * Template deduction will be done and I wil be safe both ways
        T* push_back(T&& data) { // ? Dont use const T&& else the copy cinstructor will be called
            if(m_size == 0) {
                m_data = (T*)::operator new(2 * sizeof(T));
                m_data[m_size] = std::move(data);
                m_size++;
                m_capacity=m_size*2;;
            }
            else {
                if(m_size > m_capacity) {
                    std::cout << "Reallocating memory" << std::endl;
                    re_allocate();
                }
                m_data[m_size] = std::move(data);
                m_size++;
            }

            return m_data;
        }

        // ! Required for storing pointers here
        T* push_back(T& data) {
            if(m_size == 0) {
                m_data = (T*)::operator new(2 * sizeof(T));
                m_data[m_size] = data;
                m_size++;
                m_capacity=m_size*2;;
            }
            else {
                if(m_size >= m_capacity) {
                    //std::cout << "Reallocating memory" << std::endl;
                    re_allocate();
                }
                m_data[m_size] = data;
                m_size++;
            }

            return m_data;
        }
        
        void pop_back() {
            if(m_size > 0) {
                m_size--;
                m_data[m_size].~T();
            }
        }

        void Clear_Vector() {
            for (size_t i = 0; i < m_size; i++)
            {
                m_data[i].~T();
                //m_size--;
            }
            m_size=0;
            
        }

        // ? This really saves performance think why you know the answer HINT : Its realeated to stack calls when a obj is created and when the Vector class function is called
        // ? Never allocates for pointer types needs some improvement : This shoud only store pointers and not call obj cinstructs and destructs in case of pointers
        template<typename... args>
        T& Call_in_uss_stl_stackframe(args&&... arguments) {

            if(is_pointer<T>::value == 1) {
                std::cout << "This method cannot be called when template type is pointer" << std::endl;
                exit(0);
            }

            // ! According to my method comparing m_size with 0 is nessesary or else it will cause the third re_alloc function call to access heap memory that is not ours
            //std::cout << m_size << " " << m_capacity << std::endl;
            if(m_size == 0) {
                m_data = (T*)::operator new(2 * sizeof(T));
                //m_data[m_size] = T(std::forward<args>(arguments)...);
                new(&m_data[m_size]) T(std::forward<args>(arguments)...);
                m_size++;
                m_capacity=m_size*2;
                return m_data[m_size];
            }
            if(m_size >= m_capacity) {
                std::cout << "Reallocating memory" << std::endl;
                re_allocate();
            }
            //m_data[m_size] = T(std::forward<args>(arguments)...); // ? need to learn more about this and also about the fatures of C++14
            if(m_size != 0) {
                //m_data[m_size] = T(std::forward<args>(arguments)...);
                new(&m_data[m_size]) T(std::forward<args>(arguments)...);
                return m_data[m_size++]; // Return first then increment
            }
            return m_data[-1]; // This will never be called i just added this to remove warnings
            // * If i havent used the approach of starting with 0 size maybe i coud have avoided this headache
        }


        // * This here need some serious work
        //template<typename T> // ! Need to find a way to store pointers in this array else i will drop that idea
        /* T& Call_in_uss_stl_stackframe() {
            // ! According to my method comparing m_size with 0 is nessesary or else it will cause the third re_alloc function call to access heap memory that is not ours
            if(m_size == 0) {
                m_data = new T[2];
                //m_data[m_size] = T(std::forward<args>(arguments)...);
                //new(&m_data[m_size]) T(std::forward<args>(arguments)...);
                m_size++;
                m_capacity=m_size*2;
            }
            if(m_size >= m_capacity) {
                std::cout << "Reallocating memory" << std::endl;
                re_allocate();
            }
            //m_data[m_size] = T(std::forward<args>(arguments)...); // ? need to learn more about this and also about the fatures of C++14
            if(m_size == 0){
                //m_data[m_size] = T(std::forward<args>(arguments)...);
                //new(&m_data[m_size]) T(std::forward<args>(arguments)...);
                return m_data[m_size++];
            }
            return m_data[m_size];
            // * If i havent used the approach of starting with 0 size maybe i coud have avoided this headache
        } */

        constexpr size_t size() const { return m_size; }

        // Dont use fn() const here as function having spec ret types wrt same data type cannot be overloaded (NOTE : For bettter error desc use clang++ as your compiler)
        T& operator[](size_t index) { 
            assert(index < m_size);
            
            return m_data[index]; 
        }
        const T& operator[](size_t index) const { return m_data[index]; }

        private:
        // ! For now re_allocate is written in bad way which is not performance friendly
        void re_allocate() {
            //std::cin.get();
            char x;
            //m_capacity += m_size/2;
            //T* new_Data = (T*)::operator new((m_capacity+(m_size/2)) * sizeof(T)); // ? What will this do
            T* new_Data = (T*)malloc((m_capacity+(m_size/2)) * sizeof(T)); // ? What will this do
            // * Later i will use move semantics for this purpose and make the process fast and efficient
            for (size_t i = 0; i < m_size; i++)
            {
                new_Data[i] = std::move(m_data[i]);
                // * Try to prevent moving and destructing and move dataq directly to the new_Data address
                //new(&new_Data[i]) T(m_data[i]); // ! Dude this just invoked copy constructor damn no no no no no i dont want that
            }

            for (size_t i = 0; i < m_size; i++)
            {
                m_data[i].~T();
            }
            
            if(x=='y'){::operator delete(m_data ,m_capacity * sizeof(T));} x='y';// ? Why i did this. It teached me a very important thing
            m_data = new_Data;
            m_capacity += m_size/2;
            //new_Data=nullptr;  // * Just a safety check
            //delete[] new_Data; //no need to delete this as it will automatically get deleate as soon as function returns and gets popped from the stack framr
            // ! This delete : if it use thid delete than i will get some undesred output whys that
            // * Found 3 error possiblities here 1) delete[] without making new_Data a nullpointer will cause freeing tcache2 error 2) when realloc is popped out of stackframe new_Data pointer is freed whic was initially pointing to the m_datas first pointer 3) Third is same as two when reallocation is done always the foirst point of memory be freed this can cause serious issues and head data corruption in inevident
            // * Analyse the abouve statements PnC its intresting as how if i dont assign new_Data as nullptr at the end of the stack frame the data there is not deleted
        }
    };
} }
// If we get any functions which call other functions which may call even more functions after processing some data and produncing cinditions which the final function will use to process data for and return data which will be used by the previous function ib  basis of true we can use stack unwinding in case if the condition becomes fasle that will save us some executuin time
// Shallow copy
// Deep copy
// I really need to understand how those move and destroys are called really

#endif