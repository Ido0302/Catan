CXX = g++
CXXFLAGS = -g -std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES = Person.cpp Player.cpp Demo.cpp TestCounter.cpp Test.cpp Vertex.cpp Edge.cpp Tile.cpp Board.cpp Catan.cpp Knight.cpp VictoryPoint.cpp ProgressCard.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

catan: demo
	./$^

demo: Demo.o $(filter-out TestCounter.o Test.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(filter-out demo.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test