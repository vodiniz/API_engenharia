#include "unit_Flow.hpp"
#include "unit_Model.hpp"
#include "unit_System.hpp"
#include "unit_Handle_Body.hpp"

int main(void){

    run_unit_test_handle_body();
    run_unit_test_System();
    run_unit_test_Flow();
    run_unit_test_Model();

    return 0;
}

