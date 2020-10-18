#ifndef BENCHMARKING
//#pragma message "Please define macro named BENCHMARKING and set it to 1 or 0 for using time class form this header file in you unit where you are using this library"
#error Define macro BENCHMARKING 0 or 1 in your main file
#endif
#ifndef bench_marking
#define bench_marking

#include<iostream>
#include<chrono>
#include<cstring>
//#include<thread>

struct timer {

    std::string m_str;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    //std::chrono::time_point<std::chrono::steady_clock> start, end;  This will not work in linux and unix
    std::chrono::duration<float> duration;
    timer(std::string str) : m_str(str), start(std::chrono::high_resolution_clock::now()), end(std::chrono::high_resolution_clock::now()), duration(0) {
        //m_str.append(str);
        //start = std::chrono::high_resolution_clock::now();
    }
    ~timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Execution information header : "<<m_str << std::endl;
        std::cout << "Total execution time : " << duration.count()*1000 << "ms" << " " << std::endl;
    }
    float snap_of_current_time() {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> start_till_now = end - start;
        // start_till_now = start_till_now*1000;
        return float(start_till_now.count()*1000);
    }
};

#endif

// #endif