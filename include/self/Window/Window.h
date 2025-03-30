#ifndef __WINDOW_H__
#define __WINDOW_H__


#include "../../GL/glad.h"
#include "../../GLFW/glfw3.h"
#include "Event.h"
#include "../Objects/Sprite.h"
#include "../Error/Error.h"

class WindowHints
{
   int* hints;
   int* values;
   int size;
   friend class Window;
   public:
   WindowHints();

  WindowHints(int* hints,int* values,int size);

   WindowHints(int hint,int value);

  

   static const WindowHints defaultSettings;

  ~WindowHints() noexcept;
};




class Window
{
   GLFWwindow* window;

   GLFWimage icon;

   GLFWimage cursorImage;

   GLFWcursor* cursor;

   static Event events;
   //callbacks

  static void perspectiveGL(GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar);

   static void keyboardCallback(GLFWwindow* window,int key,int scancode,int action,int mode);

   static void mouseButtonCallback(GLFWwindow* window,int button,int action,int mode);

   static void windowResizeCallback(GLFWwindow* window,int width,int height);

   static void windowMoveCallback(GLFWwindow*window,int x,int y);

   static void windowFocusCallback(GLFWwindow* window, int focus);

   static void windowMaximizeCallback(GLFWwindow* window, int maximized);

   static void windowCloseCallback(GLFWwindow* window);

   //end callbacks

   public:
   Window(int width,int height,const char* title,const WindowHints& settings = WindowHints::defaultSettings);

   bool isOpen() const;

   void close();

  void setClearColor(Color color);

  void inputMode(int mode,int value);

   void clear();

   void render(const Renderable& renderable);

   void display();

   bool pollEvents(Event& event);

   void getWindowSize(int& width,int& height) const; 

   void resizeWindow(int newWidth,int newHeight);
  
   void getRelativeCursorPosition(double& x, double& y) const;

   void getAbsoluteCursorPosition(double& x, double& y) const;
  
   void setWindowIconImage(const char* filepath);

   void setCursorImage(const char* filepath);
   
   bool isKeyPressed(int key) const;

   bool isMouseButtonPressed(int button) const;
      
   GLFWwindow* getWindow();

   ~Window();
};
#endif // __WINDOW_H__