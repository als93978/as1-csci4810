FLAGS = -g -Wall -O0 -pedantic-errors
GLFWCFLAGS = `pkg-config --cflags glfw3`
GLFWLIBS = `pkg-config --static --libs glfw3`

compile: as1.cpp
	g++ $(FLAGS) $(GLFWCFLAGS) -o as1.out as1.cpp glad.c $(GLFWLIBS)

run: as1.out
	./as1.out

clean:
	rm as1.out
