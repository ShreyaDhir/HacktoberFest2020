#include "./memorymetricsc.h"

struct struc{
    char* a;
    int x, y;
};

void im(struct struc s) {
    printf("Nothing here\n");
}

int main() {
    //extern bool metrics_on; is use less as its present in the header not in any other file
    //printf("%d\n", metrics_on);
    //metrics_on=false;
    //is_mem_metrics_on();
    struct struc* s;
    s=(struct struc*)metrics_malloc(10, sizeof(struct struc));
    im(*s); // This will not show the allocations sizes please fix that

    return 0;
}