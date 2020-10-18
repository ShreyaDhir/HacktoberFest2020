#include "./memorymetricscpp.h"

class Object {
    private:
    int id;
    char* name;

    public:
    // Static members cannot access the non static vars of the class
    static void Display(Object* o) {
        std::cout << "id : " << o->id << std::endl << "name : " << o->name << std::endl;
    }
    static void sizes(Object* o) {
        std::cout << sizeof(*o) << std::endl;
    }
};

int main() {
    Object* object;

    object=new Object[1];

    uint32_t cur_mem_usage = current_memory_usage();
    Object::sizes(object);
    std::cout << "Current memory usage : " << cur_mem_usage << std::endl;

    return 0;
}