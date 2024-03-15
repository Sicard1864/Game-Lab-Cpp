// -- TEST -------------------------------------------------------------------------------------- //

#define CATCH_CONFIG_MAIN

#include <cassert>
#include "test_module.hpp"
using namespace std;


// -- Main Test --------------------------------------------------------------------------------- //

/*  */
int main()
{
    cout << endl << "Running tests..." << endl;
    test_module();
    cout << endl << endl << "All tests passed!";

    cout << endl << endl;
    return 0;
}