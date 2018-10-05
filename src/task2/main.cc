#include <iostream>
#include <fstream>
#include "vec.cc"
#include <random>
#include <algorithm>

int main(void){
    

    std::random_device rd;
    
    Vector<std::ofstream> vecs;
    vecs.push_back(std::ofstream ("a"));
    vecs.push_back(std::ofstream ("b"));
    vecs.push_back(std::ofstream ("c"));

    std::shuffle(vecs.begin(), vecs.end(), rd);
    vecs[0] << 0;
    vecs[1] << 1;
    vecs[2] << 2;
   
//    Vector<std::ofstream> vecs2(vecs);
    Vector<std::ofstream> vecs3;
    vecs3 = std::move(vecs);
    std::cout  << vecs3.size();
    return 0;
}

