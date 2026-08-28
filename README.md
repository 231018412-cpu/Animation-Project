#Interactive Aquarium Project (OpenGL + GLUT)

This is a **C language-based OpenGL/GLUT project**, where an animated aquarium is shown — fish are swimming, bubbles are moving upward, plants are there, sand is at the bottom, and pressing the `D` button on the keyboard changes the aquarium between **Day/Night mode**.

---

#Screen Recording

##**Project Demo Video:**
[Click here to watch the screen recording](https://drive.google.com/file/d/1Q99jwjwwa3GG4REDq_j_3QNtgkhoOq5_/view?usp=sharing)

---

#Table of Contents**

->Section 1: GLUT Installation & Connect to Codeblocks

->Section 2:  Explained in Simple Language what to do in my project

->Section 3: What Functions are Used in my project code

---

#Section 1: GLUT Installation & Connect to Codeblocks

##Journey — How I Started:

To start this project, the first thing I needed was **OpenGL** and **GLUT (OpenGL Utility Toolkit)**. GLUT makes it easier to create windows, handle keyboard input, and run an animation loop. Without GLUT, these tasks would require writing much more complicated code.

For this project, I used **FreeGLUT** with **Code::Blocks and MinGW** on Windows.

###  Step 1: Download FreeGLUT

First, I downloaded the **FreeGLUT** package from the official FreeGLUT website. After downloading and extracting the FreeGLUT files, I found the required **include** and **lib** folders.

###  Step 2: Copy the Header Files

Inside the FreeGLUT `include/GL` folder, I found these important header files:
* `freeglut.h`
* `glut.h`
* `freeglut_ext.h`
* `freeglut_std.h`

I copied these files and went to:
`C:\Program Files\CodeBlocks\MinGW\include\GL`
Then, I pasted the four header files into the `GL` folder. These header files are necessary because they contain the declarations and definitions required to use GLUT functions in the C/C++ program.

### Step 3: Copy the Library Files

Next, I went to the **lib** folder of FreeGLUT. Inside the `x64` folder, I found two library files:

* `libfreeglut.a`
* `libfreeglut_static.a`

I copied these files and placed them in the MinGW library folder used by Code::Blocks. The library files allow the compiler and linker to connect the program with the FreeGLUT library.

### Step 4: Create a Project in Code::Blocks

After setting up the FreeGLUT files, I opened **Code::Blocks**. Then I created a new project by following these steps:

**File → New → Project → Empty Project**

After creating the empty project, I added my C/C++ source file to the project.

### Step 5: Configure Search Directories

Next, I opened the project settings and configured the **Search Directories**. I added the necessary **include** and **library** directories so that Code::Blocks and MinGW could find the FreeGLUT header and library files during compilation.This step is important because the compiler needs to know where the GLUT files are located.

### Step 6: Configure the Linker Settings

Finally, I configured the linker settings so that the project could link with the required OpenGL and FreeGLUT libraries.
The required libraries are:

```text
freeglut
opengl32
glu32
```

After completing these settings, the Code::Blocks project was ready to use **OpenGL and FreeGLUT**. 

###  Final Setup

So, my overall process was:

**Download FreeGLUT → Copy header files → Copy library files → Create an Empty Project in Code::Blocks → Configure Search Directories → Configure Linker Settings → Write and Run the OpenGL program.**

This setup allowed me to use GLUT functions for creating the OpenGL window, handling user input, and controlling the program's display and animation. Then I checked a simple code like : a four-colored square will continuously rotate and scale up and down. Then i applied my project idea .Finally, i confirmed this set up ready to GLUT project.

---

#Section 2: Detailed in the Code What i doing in my project 
 
 ### First, What Does This Program Do?
This program creates an **Interactive Aquarium** using OpenGL and GLUT. It shows a simple underwater scene where **two fish swim across the aquarium, two bubbles move upward, four underwater plants are displayed, and sand is placed at the bottom**. The aquarium has a blue water background, and the user can press **D/d** to switch between **Day and Night mode**. Pressing the **ESC key** closes the program. The title **“MY AQUARIUM”** is also displayed at the top of the screen. The easiest way to understand the program is: **first it draws everything, then it moves the fish and bubbles, then it draws the scene again, and this process keeps repeating**. This repeated process creates the animation and makes the aquarium look alive and interactive.
I show the whole process in one line: Draw everything → Move the fish and bubbles → Draw again → Repeat. This repeated process creates the animation.

---

##1. Header Files

```
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
```

### `#include <GL/glut.h>` This is the main graphics toolbox. It gives us functions from **OpenGL and GLUT**. We use it for things like: Creating the window, Drawing shapes, Choosing colors, Taking keyboard input, Running animation, Displaying text.

### `#include <stdlib.h>` This is a general-purpose C library. In our program, it is mainly used for: exit(0); 
This command closes the program.

### `#include <math.h>` This library gives us mathematical functions. We use: Sin(),Cos()

 ###`drawCircle()` These mathematical functions help us calculate the points needed to make a circle. So: `math.h`→ helps us calculate the circle.

---

## 2. Fish Position

`float fishX = -0.8f;` is a variable that stores the **horizontal position of the fish**. In our coordinate system, the horizontal direction goes from **-1.0 on the left side to +1.0 on the right side**, with 0 in the middle. Since the initial value of `fishX` is `-0.8`, the fish starts near the left side of the aquarium. Later, in the `update()` function, we use `fishX += 0.01f;`, which means the value of `fishX` increases by 0.01 each time. As the value becomes bigger, the fish moves toward the right side of the screen.

---

## 3. Bubble Position

`float bubbleY = -0.7f;` is a variable that stores the **vertical position of the bubble**. The vertical coordinate goes from **-1.0 at the bottom to +1.0 at the top**. Since the initial value of `bubbleY` is `-0.7`, the bubble starts near the bottom of the aquarium. Later, in the `update()` function, we use `bubbleY += 0.01f;`, which increases the value of `bubbleY` gradually. As the value increases, the bubble moves upward on the screen. In this way, the changing value of `bubbleY` creates the bubble's upward animation.

---

## 4. Day/Night Variable

`int night = 0;` is a variable that works like a **switch** to control the Day and Night modes of the aquarium. When `night` is `0`, the aquarium is in **Day mode**, and when it is `1`, the aquarium is in **Night mode**. When the user presses the `D` or `d` key, the value of this variable changes from 0 to 1 or from 1 to 0. As a result, the background color changes between light blue for daytime and dark blue for nighttime. In simple words, this variable works like a light switch: **DAY → NIGHT → DAY → NIGHT**.

---

## 5. `drawCircle()` Function

`void drawCircle(float cx, float cy, float r)` is a function used to **draw a circle**. This function takes three values as input. `cx` represents the **X-position of the center** of the circle, `cy` represents the **Y-position of the center**, and `r` represents the **radius**, which means the size of the circle.  I draw a bubble in my project , so,we can give its center position and radius to this function, and the function will create the bubble. The radius is the distance from the center of the circle to its outer edge.

### `glBegin(GL_TRIANGLE_FAN)`

`glBegin(GL_TRIANGLE_FAN);` tells OpenGL that we are going to start drawing a shape using a group of connected triangles. `GL_TRIANGLE_FAN` is useful for creating a **filled circular shape** because many small triangles can be arranged around one common center point. Imagine a pizza cut into many slices; the center of the pizza is the common point, and each slice is like a triangle. When many such triangles are placed together, they form a round shape. Therefore, `GL_TRIANGLE_FAN` helps us create the filled circle used for the fish body, fish eye, and bubbles.

### `glVertex2f(cx, cy)`

`glVertex2f(cx, cy);` gives OpenGL the **center point of the circle**. The function `glVertex2f()` is used to specify a point using two coordinates: X and Y. Here, `cx` tells the horizontal position and `cy` tells the vertical position. This center point is important because the other points of the circle will be created around it.

### The `for` Loop

```c
for(int i = 0; i <= 100; i++)
```

This loop runs from `0` to `100`, so it runs **101 times**. During every loop, the program calculates one point around the circle. We use many points because a circle made with only a few points may look like a polygon or a rough shape. But when we use many points, the shape becomes smoother and looks more like a real circle. You can think of it like drawing a circle with many tiny dots around its edge. The more dots we use, the smoother the circle looks.

### Calculating the Angle

```c
float angle = 2.0f * 3.1416f * i / 100;
```

This line calculates the **angle for each point** around the circle. Here, `3.1416` is approximately the value of **π (pi)**, and one complete circle is equal to **360 degrees or 2π radians**. As the value of `i` increases from `0` to `100`, the angle also increases gradually. In this way, the program moves around the complete circle and finds the position of each point. In simple words, **this line tells the program where each point should be placed around the circle**.

### Finding the X and Y Position

```c
float x = cx + r * cos(angle);
float y = cy + r * sin(angle);
```

These two lines calculate the **exact X and Y position of each point on the circle**. The `cos(angle)` function is used to calculate the horizontal or **X-position**, while `sin(angle)` is used to calculate the vertical or **Y-position**. The `r` value controls how far the point is from the center, so it controls the size of the circle. Finally, `cx` and `cy` move the circle to the required position on the screen. In simple words, **`cos()` helps find where the point goes left or right, and `sin()` helps find where the point goes up or down**.

For example, if `cx` and `cy` are the center of the circle and `r` is its size, these calculations create many points around that center. When all the points are given to OpenGL, they form the complete circular shape.

## 6. drawCircle() — To draw circles
This function is used to draw circles. I use circles for the fish body, fish eye, and bubbles. cos() helps find the X-position and sin() helps find the Y-position of the circle points.

## 7. drawFish() — To create the fish
The fish is made using simple shapes: circle = body, triangle = tail, small circle = eye. So, instead of drawing a complicated fish, I combine simple shapes.

## 8. drawPlant() — To create underwater plants
I use GL_LINES to draw some green lines. These lines together look like underwater plants.

## 9. display() — To draw the whole aquarium
This is the main drawing function. It draws the water, sand, fish, plants, bubbles, and title. So, everything we see in the aquarium is drawn inside display().

## 10.update() — To create movement
This function moves the fish and bubbles. fishX += 0.01 moves the fish to the right, and bubbleY += 0.01 moves the bubbles upward.

## 11. glutTimerFunc() — To repeat the animation
It calls update() again after about 30 milliseconds. Because this happens repeatedly, the fish and bubbles keep moving.

## 12. keyboard() — For user control
When the user presses D/d, the aquarium changes from Day to Night or Night to Day. Pressing ESC closes the program.

## 13. night — Day/Night switch
night = 0 means Day, and night = 1 means Night. The statement night = !night changes one into the other.

## 14. gluOrtho2D() — To set the 2D coordinate system
It creates a simple coordinate system from -1 to +1 for both X and Y. This makes it easier to position the fish, plants, bubbles, and other objects.

## 15. glutMainLoop() — To keep the program running
It keeps the program running and allows drawing, animation, and keyboard input to work continuously.

---

# Section 3: Functions Used

###`glutInit(&argc, argv)` is used to initialize the GLUT library. It is called at the beginning of the program to start the graphics and window system.

###`glutInitDisplayMode()` is used to set the display mode of the program. In this project, `GLUT_DOUBLE` is used for double buffering to make the animation smooth, and `GLUT_RGB` is used for color display.

###`glutInitWindowSize(800,600)` is used to set the size of the window. In this project, it creates an 800×600 pixel window for the aquarium.

###`glutInitWindowPosition(100,100)` is used to set the initial position of the window on the screen. It helps the aquarium window open at a specific location.

###`glutCreateWindow("...")` is used to create the main application window with a title. In this project, it is used to create the **"Interactive Aquarium"** window.

###`glutDisplayFunc(display)` is used to register the `display()` function with GLUT. This function is responsible for drawing the aquarium objects on the screen whenever the screen needs to be refreshed.

###`glutKeyboardFunc(keyboard)` is used to handle keyboard input. In this project, it is used so that pressing `D` changes the Day/Night mode and pressing `ESC` closes the program.

###`glutTimerFunc(30, update, 0)` is used to call the `update()` function after a specific amount of time. In this project, it is called every 30 milliseconds to create animation by moving the fish and bubbles.

###`glutMainLoop()` keeps the program running continuously. It handles different events such as keyboard input, screen refresh, and animation until the user exits the program.

###`glutPostRedisplay()` tells GLUT to redraw the screen. It is used to update the aquarium according to the new positions of the fish and bubbles.

###`glutSwapBuffers()` swaps the front and back buffers. Since double buffering is used in this project, this function helps display the newly drawn frame smoothly without flickering.

###`glutBitmapCharacter()` is used to draw individual characters on the screen. In this project, it is used to display the **"MY AQUARIUM"** text.

###`glClear(GL_COLOR_BUFFER_BIT)` is used to clear the previously drawn frame from the color buffer. It is called before drawing a new frame so that the old image does not remain on the screen.

###`glClearColor()` is used to set the background color of the window. It determines which color will appear when the color buffer is cleared.

###`glColor3f(r,g,b)` is used to set the color of the objects that will be drawn. In this project, it is used to give different colors to the fish, water, sand, plants, bubbles, and other aquarium objects.

###`glBegin()` and `glEnd()` are used to define the beginning and ending of a shape. In this project, they are used with different OpenGL drawing modes such as `GL_TRIANGLE_FAN`, `GL_TRIANGLES`, `GL_QUADS`, and `GL_LINES`.

###`glVertex2f(x,y)` is used to specify the position of a vertex using x and y coordinates. It is used to define the points and corners of different shapes such as triangles, quadrilaterals, circles, and lines.

###`glLineWidth(5)` is used to set the thickness of lines. In this project, it is mainly used to make the aquarium plants and their leaves look thicker.

###`glMatrixMode(GL_PROJECTION)` is used to select the projection matrix. It is needed when setting up the 2D coordinate system for the aquarium.

###`glLoadIdentity()` is used to reset the current transformation matrix to its default state. It ensures that any previous transformations do not affect the new coordinate system.

###`gluOrtho2D(-1,1,-1,1)` is used to create a 2D orthographic coordinate system. In this project, it maps the aquarium screen area between `-1` and `1` on both the x-axis and y-axis.

###`exit(0)` is used to terminate the program completely. In this project, it is used when the user presses the `ESC` key to close the aquarium.

###`cos()` and `sin()` from `math.h` are mathematical functions used to calculate x and y coordinates from an angle. In this project, they are mainly used to calculate the points needed to draw circular objects such as bubbles.

---

#Conclusion

This project successfully demonstrates a simple **Interactive Aquarium** using OpenGL and GLUT. The program creates an underwater environment with animated fish, bubbles, aquatic plants, sand, and an aquarium title. The fish and bubbles move continuously to create a simple animation effect. It also includes a **Day/Night mode**, which can be switched using the `D` key, and the `ESC` key can be used to exit the program.

Overall, this project helped demonstrate basic concepts of **2D computer graphics, shape drawing, animation, keyboard interaction, and color/background changes using OpenGL and GLUT**. The final output provides a simple and visually interactive aquarium scene.
