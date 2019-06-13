#include<iostream>
#include <sstream>
#include<string>

#include <vector>

#include "sha256.h"



using namespace std;
//using namespace utility;
//using namespace utils;
int main() {

    std::ostringstream stm ;
    stm << 20 ;
    cout << "Hello" + sha256("ABC") << endl;
    //vector<int> vec {1,2,3};
    //cout << toString(vec) << endl;


};

//namespace utility {
    

//}
