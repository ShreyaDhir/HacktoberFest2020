#include "./uss_stl.hpp"

#define BENCHMARKING 1
#include "../../dsa/execution_analysis/benchmarking.h"

#include<cstring>

struct Vector3 {
    private:
    float x, y, z;
    int* m_Block;

    public:
    Vector3() : x(0), y(0), z(0), m_Block(new int[5]) {
        //m_Block=new int[5];
    }
    
    Vector3(const float scalar) : x(scalar), y(scalar), z(scalar), m_Block(new int[5]) {
        //m_Block=new int[5];
    }
    
    Vector3(const float x, const float y, const float z)
        : x(x), y(y), z(z), m_Block(new int[5]) {
            //m_Block=new int[5];
        }
    
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z), m_Block(new int[5]) {
        std::cout << "Copied\n";
    }
    
    Vector3(Vector3&& v) : x(v.x), y(v.y), z(v.z), m_Block(new int[5]) {
        std::cout << "Moved\n";
        /* x=v.x;
        y=v.y;
        z=v.z;
        m_Block=new int[5]; */
    }
    
    ~Vector3() {
        delete[] m_Block;
        // ? What shoud i do if i delete then double delete will happen and if i dont delete memor leak occours
        std::cout << "Destoryed\n";
    }
    
    Vector3& operator=(const Vector3& o) {
        std::cout << "Copy\n";
        x=o.x;
        y=o.y;
        z=o.z;

        return *this;
    }

    Vector3& operator=(Vector3&& other) {
        std::cout << "Move\n";
        x=other.x;
        y=other.y;
        z=other.z;

        m_Block=new int[5];

        return *this;
    }

    //template<>
    friend void display_vector(const uss_stl::lineards::Vector<Vector3>& v);

    friend std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
        os << vec.x << " ," << vec.y << " ," << vec.z << " ";
        return os;
    }
};

// ! Always pass by const reference other wise we have a problem releated to deep copy and shallow copy and some data might get deleted and again when the object goes out of scope destructor is called twice which is a big problem as it tries to free data which is already freed in the previous function call
template<typename T>
void display_vector(const uss_stl::lineards::Vector<T>& vector) /* const Note : const qualifiers are only applicable to member functions of classes as they prevent the member function to modify any class data bt accident */ {
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "\n";
    }
    std::cout << std::endl;
    
}

template<typename T>
void display_vector(const uss_stl::lineards::Vector<T*> vector) /* const Note : const qualifiers are only applicable to member functions of classes as they prevent the member function to modify any class data bt accident */ {
    for (size_t i = 0; i < vector.size(); i++)
    {
        if (uss_stl::lineards::is_pointer<T>::value == 1) {
            std::cout << *vector[i] << "\n";
        }
        else {
            std::cout << vector[i] << "\n";
        }
    }
    std::cout << std::endl;
    
}

//template<> //No not for classes findout why in future ok
void display_vector(const uss_stl::lineards::Vector<Vector3>& vector) /* const Note : const qualifiers are only applicable to member functions of classes as they prevent the member function to modify any class data bt accident */ {
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " \n";
    }
    std::cout << std::endl;
    // ! This wont work for pointers im still trying so that this wotks for pointer help me please
}

int main() {
    #if BENCHMARKING
        timer t("Program execution time");
    #endif
    Vector3* v3ptr = new Vector3[100]; // I Think i can say pointer type template arguments sorted
    uss_stl::lineards::Vector<Vector3> v3;
    /* v3.push_back(Vector3(1, 32, 443)); */
    /* v3.push_back(Vector3(1, 32, 443)); */
    /* v3.push_back(Vector3(1, 32, 443)); */
    /* v3.push_back(Vector3(1, 32, 443)); */
    /* v3.Call_in_uss_stl_stackframe();
    v3.Call_in_uss_stl_stackframe();
    v3.Call_in_uss_stl_stackframe();
    v3.Call_in_uss_stl_stackframe();
    v3.pop_back(); */

    // * This is actually faster than push_back as it reduces stack calling overhead
    //std::cout << v3.size() << std::endl;
    //display_vector(v3);

    {uss_stl::lineards::Vector<int> vintl;
    vintl.push_back(1);
    vintl.push_back(1);
    /* vintl.push_back(1);
    vintl.push_back(1);
    vintl.push_back(1); */
    //vintl.pop_back();
    display_vector(vintl);} // ! When this scope is finished the program crashes
    std::cout << "Reached safely" << std::endl;
    //v3[2342]; // Really unsafe dude dont do this for now deal with this using assert when exporting as dynamic linked lib make the boundaries solid

    //int a[100] = { [0 ... 99] {1} };
    
    return 0;
}

// Litreally lifesaver : https://stackoverflow.com/questions/28129260/copy-constructor-is-being-called-instead-of-the-move-constructor
// * Look up copy constructors again
// * Look up const again
// * look up move semantics again
// * Look up Classes series by Cherno again just for reference