// -- TEST -------------------------------------------------------------------------------------- //

#include <test_module.hpp>


// -- Prototypes -------------------------------------------------------------------------------- //

static void test_module_create();


// -- Tests ------------------------------------------------------------------------------------- //

bool test_module() {
    cout << endl << "Running module tests...";

    test_module_create();

    cout << endl << "All module tests passed!";

    return true;
}

static void test_module_create() {
    Module module;
    assert(module.getInt() == 0);
    cout << endl << "\ttest_module_create()";
}