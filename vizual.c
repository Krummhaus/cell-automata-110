#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Somthing to read shader files from disc
const char *slurp_file(const char *file_path) {
    FILE *f = fopen(file_path, "r");
    if (f == NULL) {
        // END TODO: https://www.youtube.com/watch?v=z9y1SDjl0YQ&t=1688s 1:14:00
    }
    fclose(f);
}

int main() {
    if (glfwInit()) {
        fprintf(stderr, "ERROR: could not initialize GLFW");
        exit(1);
    }
    // clang-format off
    GLFWwindow* window = glfwCreateWindow(
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"Automata 110",
			NULL,
			NULL);
    // clang-format on
    if (window == NULL) {
        fprintf(stderr, "ERROR: could not create window.\n");
        glfwTerminate();
        exit(1);
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    return 0;
}
