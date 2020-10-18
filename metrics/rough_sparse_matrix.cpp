// ! FULLY DEPRICATED PROGRAM (CRYING FROM INSIDE) NEED TO MAKE A BETTER ONE SOON
// ? SHOUD I GO FOR IMPROVING THIS
// TODO : FOR NOW JUST REUSE THE SNIPPETS FROM THIS CODE IN OTHER CODES IT WILL BE A TIMESAVER
// * ALAS BYE BYE THIS PROGRAM I WILL MAKE A BETTER ONE AFTER READING SOME MORE BOOKS
// ? WHYNOT USE THIS CODE FOR ML DATA GENERATION AND ALGO ANALYSIS FOR THIS PARTICULAIR PROBLEM

#include "./benchmarking.h"
#include "./colorcoding.h"
#include<fstream>

#define method 2
// Not yet integrated in to the program i will add them later its such a headache fornow
#define s_mx_r_size 34
#define s_mx_c_size 34

Color::Modifier red(Color::FG_RED);
Color::Modifier yellow(Color::FG_YELLOW);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier def(Color::FG_DEFAULT);

// Functions please add secutiry for passed args which are not supposed to be changed at all costs
// Actually remove color params no need to create unnecessary overheads and execution times

// TODO : Convert generate_triplet to linked list

void s_mx_addition(int (*)[], int (*)[]);
void s_mx_display(int (*)[], Color::Modifier&, Color::Modifier&);
void generate_triplet(int (*)[], int (*)[], int&);
void merge_sort_triplets(int (*)[], int (*)[], int&, int&, int (*)[], int&);
void display_s_mx_triplet(int (*)[], const int&, const Color::Modifier&, const Color::Modifier&, const Color::Modifier&);

void data_output_init(void) __attribute__ ((constructor));

/* #include<iostream>
#include<chrono>

struct timer {

    std::chrono::time_point<std::chrono::system_clock> start, end;
    //std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        std::cout << "Total execution time : " << duration.count()*200 << "s" << " " << std::endl;
    }
}; */

// Make a template of array which is more optimizes than std::array and probably more optimized than std::vector actually this concept works only for this as it is more secific to what we are doing and not to a general purpose to perform data structure and algorithms
template <typename T, size_t size>
struct fast_array{
    // Working i will use this for s_mx_triplet_table management it will give me proper and fast management for now jake book pakh salle
};

void data_output_init() {
    std::ofstream record;
    record.open("execution_information.txt", std::ios::out | std::ios::app);
    record << s_mx_r_size << "," << s_mx_c_size << ",";
    record.close();
}

void s_mx_addition(int (*a)[s_mx_c_size], int (*b)[s_mx_c_size]) {
    for (int i = 0; i < s_mx_r_size; i++)
    {
        for (int j = 0; j < s_mx_c_size; j++)
        {
            a[i][j]+=b[i][j];
        }
        
    }
}

void s_mx_display(int (*a)[s_mx_c_size], Color::Modifier& color0, Color::Modifier& color1) { // For some reason pass by address * prints the address vals of the a[i][j] var i think its someething releated to ostream we need to open that lib as soon as possible
    // Anyways i optimized my code and memory as im conditionally using 4bytes instead of 8 bytes i also avoided copying here win : win
    for (int i = 0; i < s_mx_r_size; i++)
    {
        for (int j = 0; j < s_mx_c_size; j++)
        {
            (a[i][j] >= 1) ? std::cout << color0 << a[i][j] << " " << def : std::cout << color1 << a[i][j] << " " << def;
            //std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
    
}

void generate_triplet(int (*target_matrix)[s_mx_c_size], int (*p)[3], int& triplet_size) {
    enum current_val {
        row_index,
        column_index,
        value
    };

    int pos_pointer=1;
    for (int i = 0; i < s_mx_r_size; i++)
        {
            for (int j = 0; j < s_mx_c_size; j++)
            {
                if (target_matrix[i][j] != 0)
                {
                    p[pos_pointer][row_index] = i;
                    p[pos_pointer][column_index] = j;
                    p[pos_pointer][value] = target_matrix[i][j]; //valloc() function
                    pos_pointer+=1;
                    *(&triplet_size)=*(&triplet_size)+1;
                }
                
            }
            
        }
}

void display_s_mx_triplet(int (*triplet)[3], const int& triplet_size, const Color::Modifier& color1, const Color::Modifier& color2, const Color::Modifier& color3) {
    for (int i = 0; i < triplet_size; i++)
    {
        std::cout << color1 << triplet[i][0] << " " << def << color2 << triplet[i][1] << " " << def << color3 << triplet[i][2] << def;
        std::cout << std::endl;
    }
}

void merge_sort_triplets(int (*triplet_1)[3], int (*triplet_2)[3], int& s1, int& s2, int (*triplet_3)[3], int& triplet_size) 
{ 
    int i = 0, j = 0, k = 0; 

    while (i<s1 && j <s2) 
    { 
        if (triplet_1[i][0] < triplet_2[j][0]) {// triplet_1[i][0] will be correct for proper and row wise merge sorting
            triplet_3[k++][0] = triplet_1[i++][0];
            triplet_3[k][1] = triplet_1[i][1];
            triplet_3[k][2] = triplet_1[i][2];
            *(&triplet_size)=*(&triplet_size)+1;
        }
        else {
            triplet_3[k++][0] = triplet_2[j++][0];
            triplet_3[k][1] = triplet_2[j][1];
            triplet_3[k][2] = triplet_2[j][2];
            *(&triplet_size)=*(&triplet_size)+1;
        }
    } 

    while (i < s1) {
        triplet_3[k++][0] = triplet_1[i++][0]; 
        triplet_3[k][1] = triplet_1[i][1]; 
        triplet_3[k][2] = triplet_1[i][2]; 
        *(&triplet_size)=*(&triplet_size)+1;
    }

    while (j < s2) {
        triplet_3[k++][0] = triplet_2[j++][0]; 
        triplet_3[k][1] = triplet_2[j][1]; 
        triplet_3[k][2] = triplet_2[j][2]; 
        *(&triplet_size)=*(&triplet_size)+1;
    }
}

void algorithm() {
    timer s("1");

    enum current_val {
        row_index,
        column_index,
        value
    };

    // Making first array
    int a[s_mx_r_size][s_mx_c_size];
    int randomNumber = (rand() % 200) + 1;
    for (int i = 0; i < s_mx_r_size; i++)
    {
        for (size_t j = 0; j < s_mx_c_size; j++)
        {
            randomNumber = (rand() % 200) + 1;
            if(randomNumber%7==0) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 0;
            }
        }
        
    }
    timer d("2");
    for (int i = 0; i < s_mx_r_size; i++)
    {
        for (int j = 0; j < s_mx_c_size; j++)
        {
            (a[i][j] == 1) ? std::cout << red << a[i][j] << " " << def : std::cout << blue << a[i][j] << " " << def;
        }
        std::cout << std::endl;
        
    }
    //s_mx_display(a, red, blue);  ?? Why can i display this properly BUG BUG BUG BUG BUG BUG BUG BUG BUG BUG

    std::cout << std::endl;

    // Making second array
    int b[s_mx_r_size][s_mx_c_size];
    for (int i = 0; i < s_mx_r_size; i++)
    {
        for (size_t j = 0; j < s_mx_c_size; j++)
        {
            randomNumber = (rand() % 200) + 1;
            if(randomNumber%7==0) {
                b[i][j] = 1;
            }
            else {
                b[i][j] = 0;
            }
        }
        
    }

    /* for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            (b[i][j] == 1) ? std::cout << red << b[i][j] << " " << def : std::cout << blue << b[i][j] << " " << def;
        }
        std::cout << std::endl;
        
    } */
    s_mx_display(b, red, blue);

    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Both the algos will be implimented here

    if(method == 1) {
        //Addition store in a[][]
        {
            timer add("Addition and conversion");
            s_mx_addition(a, b);
        // de comment it later after you know the execution time of method a
        
        /* for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                (a[i][j] >= 1) ? std::cout << yellow << a[i][j] << " " << def : std::cout << blue << a[i][j] << " " << def;
            }
            std::cout << std::endl;
            
        } */

        s_mx_display(a, yellow, blue);

        // Making triplet table
        int (*p)[3];

        //int ** a = malloc(**)maccloc(x*sizeof(int*));

        int triplet_size=0, current_row=0;
        p=new int[400][3];
        
        //timer triplet_time("Creating triplet matrix once");
        for (int i = 0; i < s_mx_r_size; i++)
        {
            for (int j = 0; j < s_mx_c_size; j++)
            {
                if (a[i][j] != 0)
                {
                    p[current_row][row_index] = i;
                    p[current_row][column_index] = j;
                    p[current_row][value] = a[i][j]; //valloc() function
                    current_row+=1;
                    triplet_size+=1;
                }
                
            }
            
        }
        }

        /* // Printing the triplet table
        for (int i = 0; i < triplet_size; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << p[i][j] << " ";
            }
            std::cout << std::endl;
            
        } */
    }
    
    if(method == 2) {
        int (*p)[3];
        int (*q)[3];
        int (*merged_and_fairly_optimized_triplet)[3];
        int triplet_sizep=0, triplet_sizeq=0,merged_and_fairly_optimized_triplet_size=0;
        p=new int[400][3];
        q=new int[400][3];
        merged_and_fairly_optimized_triplet=new int[800][3]; // I really need to optimise these three or my memory goes blah blah also foor large input size thrashing may occour and it will cause page faults tab toh maja hi aa jayega baat ka ek dum aaj lag jayegi processor mei
        // Making the blockscope for the timer datatype to analyse execution time
        {
            timer t("Method 2 generate triplets then merge sort them");
            generate_triplet(a, p, triplet_sizep);
            generate_triplet(b, q, triplet_sizeq);
            // merged_and_fairly_optimized_triplet_size=triplet_sizep+triplet_sizeq; Maybe this is logically incorrect
            merge_sort_triplets(p, q, triplet_sizep, triplet_sizeq, merged_and_fairly_optimized_triplet, merged_and_fairly_optimized_triplet_size);
            /* for (int i = 0; i < merged_and_fairly_optimized_triplet_size; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    std::cout << merged_and_fairly_optimized_triplet[i][j] << " ";
                }
                std::cout << std::endl;
            } */
            std::ofstream record;
            record.open("execution_information.txt", std::ios::out | std::ios::app);
            record << t.snap_of_current_time() << "\n";
            record.close();
        }
        display_s_mx_triplet(p, triplet_sizep, blue, yellow, red); // Args to display all in colors i will add definatels but not now please god its 3:59 in morning
        std::cout << std::endl;
        display_s_mx_triplet(q, triplet_sizeq, blue, yellow, red);
        std::cout << std::endl;
        display_s_mx_triplet(merged_and_fairly_optimized_triplet, merged_and_fairly_optimized_triplet_size, blue, yellow, red);
        
        // Is there a function to display triplets ? Yes added on the day it self
        // I achived increment of triplet size fot just 4 bytes instead of 8 bytes
        // I achived fair speed optimizations at the cost of memory but the tradeoff coud by reduced if i knew a little more coding
    }
    
}

int main() {
    std::system("clear");
    auto algo = algorithm;
    algo();

    return 0;
}

// Yay its still incomplete 