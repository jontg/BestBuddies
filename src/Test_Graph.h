#include "Graph.h"

bool test_find_or_insert_graph() {
    Graph g;

    int n1 = g.FindOrInsertContact("Alfred@test1.com"),
        n2 = g.FindOrInsertContact("Betty@test1.com"),
        n3 = g.FindOrInsertContact("Charles@test1.com"),
        n4 = g.FindOrInsertContact("Dexter@test1.com"),
        n5 = g.FindOrInsertContact("Alfred@test1.com");
    int a1 = g.FindOrInsertAsset("Message-ID-2398poiyiu28307640"),
        a2 = g.FindOrInsertAsset("Message-ID-09283709"),
        a3 = g.FindOrInsertAsset("Message-ID-09283709");

    assert(n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4);
    std::cout<<"\tTest 1 PASSED"<<std::endl;
    assert(n1 == n5);
    std::cout<<"\tTest 2 PASSED"<<std::endl;
    assert(a1 != a2 && a1 != a3);
    std::cout<<"\tTest 3 PASSED"<<std::endl;
    assert(a2 == a3);
    std::cout<<"\tTest 4 PASSED"<<std::endl;
    return true;
}

bool test_attach_asset() {
    std::cout<<"Test AttachAsset()"<<std::endl;
    Graph g;
    int n1 = g.FindOrInsertContact("Alfred@test1.com"),
        n2 = g.FindOrInsertContact("Betty@test1.com");
    int a1 = g.FindOrInsertAsset("Message-ID-92807309");

    g.AttachAsset(a1, n1);
    g.AttachAsset(a1, n2);
    std::cout<<"\tTest 1 PASSED"<<std::endl;

    try {g.AttachAsset(100, 50);
    } catch(std::exception& e) {
        std::cout<<"\tTest 2 PASSED"<<std::endl;}

    try {g.AttachAsset(-1, n1);
    } catch(std::exception& e) {
        std::cout<<"\tTest 3 PASSED"<<std::endl;}

    return true;
}

bool test_fetch_asset_or_contact() {
    std::cout<<"Test Fetch...()"<<std::endl;
    Graph g;
    int n1 = g.FindOrInsertContact("Alfred@test1.com"),
        n2 = g.FindOrInsertContact("Betty@test1.com");
    int a1 = g.FindOrInsertAsset("Message-ID-23987");

    assert(g.FetchContact(n1).email_address == "Alfred@test1.com");
    std::cout<<"\tTest 1 PASSED"<<std::endl;
    assert(g.FetchContact(n2).email_address != "Alfred@test1.com");
    std::cout<<"\tTest 2 PASSED"<<std::endl;
    assert(g.FetchAsset(a1).message_id == "Message-ID-23987");
    std::cout<<"\tTest 3 PASSED"<<std::endl;

    try {g.FetchAsset(-1);
    } catch(std::exception& e) {
        std::cout<<"\tTest 4 PASSED"<<std::endl;}

    try {g.FetchAsset(5);
    } catch(std::exception& e) {
        std::cout<<"\tTest 5 PASSED"<<std::endl;}

    try {g.FetchContact(-1);
    } catch(std::exception& e) {
        std::cout<<"\tTest 6 PASSED"<<std::endl;}

    try {g.FetchContact(5);
    } catch(std::exception& e) {
        std::cout<<"\tTest 7 PASSED"<<std::endl;}

    return true;
}
