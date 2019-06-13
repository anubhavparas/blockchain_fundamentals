#ifndef UTILS_H
#define UTILS_H

#include<string>
#include <sstream>
#include <vector>

using namespace std;

namespace utils {

    template <class T>
    std::string vectorToString(vector<T> vec) {
        string vecStr = "[\n";
        for (T elem : vec) {
            vecStr += elem.toString() + ", \n"; 
        }
        vecStr += "\n]\n";
        return vecStr;
    }


    template < typename T > std::string to_String( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }

}

#endif