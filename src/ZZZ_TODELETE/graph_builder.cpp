#include <cassert>
#include <iostream>

#include "Graph.h"
#include "Test_Graph.h"

#include "Email.h"
#include "Test_Email.h"

#include "EmailBuilder.h"

int main(int argc, char ** argv) {
    test_find_or_insert_graph();
    test_attach_asset();
    test_fetch_asset_or_contact();
    test_read_email();

    EmailBuilder::Instance().BuildEmailDataBase(argv[1]);
}
