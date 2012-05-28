#include <EntityGenerator.h>
#include <DiskFile.h>

TEST(EntityGenerator, EndToEndTest) {
  DiskFile * test_data = new DiskFile("test/test_data/DIRSUMMARY.txt");

  EmailReader reader(test_data);
  EntityGenerator generator;

  boost::signals2::connection conn = reader.AttachSubscriber(boost::bind(&EntityGenerator::ReceiveEmail, &generator, _1));

  reader.Run();
  generator.AnnounceResults();
  conn.disconnect();
}
