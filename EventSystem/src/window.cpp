#include "window.h"
#include "mouseEvent.h"
#include "keyEvent.h"
#include <iostream>
namespace CoreNative 
{
	std::string str = "";
	Window::Window(const std::string& name, int width, int height)
	{
		init(name, width, height);
		setfnCallback([this](Event& e)
			{
				if (e.getType() == Event::EventType::WINDOW_CLOSED_EVENT)
				{
					glfwSetWindowShouldClose(window, GL_TRUE);
				}
				std::cout << e.format() << std::endl;
			});
	}

	void Window::init(const std::string& name, int width, int height)
	{
		this->name = name;
		this->width = width;
		this->height = height;
		if (!glfwInit())
		{
			__asm {
				int 3
			}
		}
		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

		if (!window)
		{
			__asm {
				int 3
			}
		}

		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, this);
		glfwSetCursorPosCallback(window, mouseMoveCallback);
		glfwSetScrollCallback(window, mouseScrolledCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetKeyCallback(window, keyCallback);
	}
	void Window::mouseMoveCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseMovedEvent e(x, y);
		handle.fnCallback(e);
	}
	void Window::mouseScrolledCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseScrolledEvent e(y);
		handle.fnCallback(e);
	}
	void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		
		if (action == GLFW_PRESS) { MouseButtonPressedEvent e(button); handle.fnCallback(e); }
		else { MouseBttunReleasedEvent e(button); handle.fnCallback(e);  }

	}
	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS) { KeyPressedEvent e(key); handle.fnCallback(e); }
		else {
			if (key == GLFW_KEY_BACKSPACE) {
				if (str.size() != 0)
				{
					str.pop_back();
					std::cout << str << std::endl;
				}
			}
			else {
				KeyReleasedEvent e(key);
				handle.fnCallback(e);
				str += char(key);
				std::cout << str << std::endl;
			}

		}
	}


	Window::~Window()
	{
		glfwWindowShouldClose(window);
	}
}
