#include <Graph.h>

// test_find_or_insert_graph();
// test_attach_asset();
// test_fetch_asset_or_contact();
// test_read_email();

namespace {
TEST(GraphTest,FindOrInsert) {
    Graph g;

    int n1 = g.FindOrInsertContact("Alfred@test1.com"),
        n2 = g.FindOrInsertContact("Betty@test1.com"),
        n3 = g.FindOrInsertContact("Charles@test1.com"),
        n4 = g.FindOrInsertContact("Dexter@test1.com"),
        n5 = g.FindOrInsertContact("Alfred@test1.com");
    int a1 = g.FindOrInsertAsset("Message-ID-2398poiyiu28307640"),
        a2 = g.FindOrInsertAsset("Message-ID-09283709"),
        a3 = g.FindOrInsertAsset("Message-ID-09283709");

    EXPECT_TRUE(n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4);
    EXPECT_EQ(n1, n5);
    EXPECT_NE(a1, a2);
    EXPECT_NE(a1, a3);
    EXPECT_EQ(a2, a3);
}
};


