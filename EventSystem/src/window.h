#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <functional>
#include "event.h"
namespace CoreNative
{
	class Window final //�� ���� ������ ����� �������������
	{
	private:
		std::string name;
		int width, height;
		GLFWwindow* window = nullptr;
		std::function<void(Event&)> fnCallback;
	public:
		// ������� copy ������������
		Window(const Window&) = delete;
		Window& operator = (const Window&) = delete;

	private:
		Window(const std::string& name, int width, int height);
		~Window();

	public:
		static Window& getInstanse() {
			static Window instanse("Window", 1280, 720);
			return instanse;
		}

		void init(const std::string& name, int width, int height);
		__forceinline GLFWwindow* getGLFWwindow() const { return window; }
		void setfnCallback(const std::function<void(Event&)>& fn) { fnCallback = fn; }

	public:
		static void mouseMoveCallback(GLFWwindow* window, double x, double y);
		static void mouseScrolledCallback(GLFWwindow* window, double x, double y);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}