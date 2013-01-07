OBJS = build/Graph.o build/DataStorage.o build/EmailReader.o build/EntityGenerator.o build/DiskFile.o
DATA = build/Data_Structures/Email.obj build/Data_Structures/Entity.obj
DATA_HEADERS = src/Data_Structures/Email.pb.h
CXX = g++
OPT = -O3
OPTDEBUG = -g
CFLAGS = -Wall -c -Isrc
LFLAGS = -Wall -lprotobuf -lre2

ifeq ($(DEBUG),1)
	CFLAGS += $(OPTDEBUG)
	LFLAGS += $(OPTDEBUG)
else
	CFLAGS += $(OPT)
	LFLAGS += $(OPT)
endif

TEST_CFLAGS = $(CFLAGS) -Itest
TEST_LFLAGS = $(LFLAGS) -lgtest
TEST_HEADERS = test/EmailReader_test.h test/EntityGenerator_test.h test/Graph_test.h
TEST_OBJS = build/tester.o test/Mock_Implementations/MockFile.o

.PHONY: clean test

test: $(DATA) $(OBJS) $(TEST_HEADERS) $(TEST_OBJS) bin/tester
	./bin/tester

graph_builder: $(OBJS)
	$(CXX) $(LFLAGS) src/graph_builder.cpp -o bin/graph_builder

build/tester.o: test/main.cpp $(TEST_HEADERS)
	$(CXX) $(TEST_CFLAGS) test/main.cpp -o build/tester.o

bin/tester: $(DATA) $(OBJS) $(TEST_OBJS)
	$(CXX) $(TEST_LFLAGS) $(OBJS) $(TEST_OBJS) $(DATA) -o bin/tester
	chmod a+x bin/tester

clean:
	\rm -rf $(OBJS) $(TEST_OBJS) $(DATA) bin/tester

build/%.obj: src/%.proto
	protoc -Isrc --cpp_out=src $^
	$(CXX) $(CFLAGS) src/$*.pb.cc -o $@

test/%.o: test/%.cpp
	$(CXX) $(TEST_CFLAGS) $^ -o $@

build/%.o: src/%.cpp
	$(CXX) $(CFLAGS) $^ -o $@
