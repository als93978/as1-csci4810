#include <iostream>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void drawPixel(int x, int y);
void draw();

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    
    glVertex2f(x + 0.5, y + 0.5);

    glEnd();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            drawPixel(i, j);
        }
    }
    
    glFlush();
}

int main() {
    GLFWwindow* window;

    int width, height;
    
    if(!glfwInit()) {
        cerr << "GLFW initialization failed" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(800, 600, "GLFW-OpenGL Test", NULL, NULL);
    if(!window) {
        cerr << "OpenGL Context/Window creation failed" << endl;
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cerr << "GLAD initialization failed" << endl;
        return -1;
    }
        
    glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, width, height);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, width, height, 0, 0, 1);
    
    glMatrixMode(GL_MODELVIEW);
    
    glDisable(GL_DEPTH_TEST);
    
    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 1.0f, 1.0f);
        draw();
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
