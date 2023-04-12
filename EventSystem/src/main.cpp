#include <iostream>
#include <GLFW/glfw3.h>
#include "window.h"
int main()
{
	CoreNative::Window& window = CoreNative::Window::getInstanse();
	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		glfwPollEvents();
		glfwSwapBuffers(window.getGLFWwindow()); // отвечает за то, как рендерится картинка (я пока не особо понял)

	}
	return 0;
}
