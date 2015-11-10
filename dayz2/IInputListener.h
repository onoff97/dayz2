#pragma once

struct GLFWwindow;

struct IInputListener
{
	virtual bool key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;
};
