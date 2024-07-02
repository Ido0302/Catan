CXX = g++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion
SOURCES = Player.cpp Board.cpp Catan.cpp Demo.cpp Vertex.cpp Edge.cpp Tile.cpp Board.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

catan: demo
	./$^

demo: Demo.o $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o demo

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test