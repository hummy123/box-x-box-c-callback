#include "export.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>

// Define macros according to their position in array
#define KEY_I 0
#define KEY_J 1
#define KEY_K 2
#define KEY_L 3

// Global state array indicating state of relevant keys
bool keysPressed[4] = {
  false, 
  false, 
  false, 
  false,
};

// Functions to get state of specific key
bool isPressedI() {
  return keysPressed[KEY_I];
}
bool isPressedJ() {
  return keysPressed[KEY_J];
}
bool isPressedK() {
  return keysPressed[KEY_K];
}
bool isPressedL() {
  return keysPressed[KEY_L];
}

// Returns whether the action should be considered pressed.
// We only really care about GLFW_PRESS and GLFW_RELEASE for this,
// and can consider GLFW_REPEAT the same as GLFW_PRESS.
bool isPressed(int action) {
  switch (action) {
    case GLFW_PRESS:
    case GLFW_REPEAT:
      return true;
    default:
      return false;
  }
}

// Sets relevant part of global state array.
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  switch (key) {
    case GLFW_KEY_I:
      keysPressed[KEY_I] = isPressed(action);
      break;
    case GLFW_KEY_J:
      keysPressed[KEY_J] = isPressed(action);
      break;
    case GLFW_KEY_K:
      keysPressed[KEY_K] = isPressed(action);
      break;
    case GLFW_KEY_L:
      keysPressed[KEY_L] = isPressed(action);
      break;
    default:
      break;
  }
}

// Call this from MLton to register key callback with GLFW.
void setKeyCallback(GLFWwindow *window) {
  glfwSetKeyCallback(window, keyCallback);
}
