#include <iostream>
#include <GLFW/glfw3.h>
#include "window.h"
int main()
{
	CoreNative::Window& window = CoreNative::Window::getInstanse();
	while (true)
	{
		glfwPollEvents();
		glfwSwapBuffers(window.getGLFWwindow()); // �������� �� ��, ��� ���������� �������� (� ���� �� ����� �����)



	}
	return 0;
}
