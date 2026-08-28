#🐠 Interactive Aquarium Project (OpenGL + GLUT)

This is a **C language-based OpenGL/GLUT project**, where an animated aquarium is shown — fish are swimming, bubbles are moving upward, plants are there, sand is at the bottom, and pressing the `D` button on the keyboard changes the aquarium between **Day/Night mode**.

---

#Screen Recording

##🎥 **Project Demo Video:**
[Click here to watch the screen recording](https://drive.google.com/file/d/1Q99jwjwwa3GG4REDq_j_3QNtgkhoOq5_/view?usp=sharing)

---

#📚 Table of Contents**

->Section 1: GLUT Installation & Complete Code

->Section 2:  Explained in Simple Language what to do in my project
->Section 3: Functions Used in my project code

---

#Section 1: GLUT Installation & Complete Code

##🧭Journey — How I Started:

To start this project, the first thing I needed was **OpenGL** and **GLUT (OpenGL Utility Toolkit)**. GLUT makes it easier to create windows, handle keyboard input, and run an animation loop. Without GLUT, these tasks would require writing much more complicated code.

For this project, I used **FreeGLUT** with **Code::Blocks and MinGW** on Windows.

### ✅ Step 1: Download FreeGLUT

First, I downloaded the **FreeGLUT** package from the official FreeGLUT website. After downloading and extracting the FreeGLUT files, I found the required **include** and **lib** folders.

### ✅ Step 2: Copy the Header Files

Inside the FreeGLUT `include/GL` folder, I found these important header files:
* `freeglut.h`
* `glut.h`
* `freeglut_ext.h`
* `freeglut_std.h`

I copied these files and went to:
`C:\Program Files\CodeBlocks\MinGW\include\GL`
Then, I pasted the four header files into the `GL` folder. These header files are necessary because they contain the declarations and definitions required to use GLUT functions in the C/C++ program.

### ✅ Step 3: Copy the Library Files

Next, I went to the **lib** folder of FreeGLUT. Inside the `x64` folder, I found two library files:

* `libfreeglut.a`
* `libfreeglut_static.a`

I copied these files and placed them in the MinGW library folder used by Code::Blocks. The library files allow the compiler and linker to connect the program with the FreeGLUT library.

### ✅ Step 4: Create a Project in Code::Blocks

After setting up the FreeGLUT files, I opened **Code::Blocks**. Then I created a new project by following these steps:

**File → New → Project → Empty Project**

After creating the empty project, I added my C/C++ source file to the project.

### ✅ Step 5: Configure Search Directories

Next, I opened the project settings and configured the **Search Directories**.
I added the necessary **include** and **library** directories so that Code::Blocks and MinGW could find the FreeGLUT header and library files during compilation.This step is important because the compiler needs to know where the GLUT files are located.

### ✅ Step 6: Configure the Linker

Finally, I configured the linker settings so that the project could link with the required OpenGL and FreeGLUT libraries.
The required libraries are:

```text
freeglut
opengl32
glu32
```

After completing these settings, the Code::Blocks project was ready to use **OpenGL and FreeGLUT**. 

### 🎯 Final Setup

So, my overall process was:

**Download FreeGLUT → Copy header files → Copy library files → Create an Empty Project in Code::Blocks → Configure Search Directories → Configure Linker Settings → Write and Run the OpenGL program.**

This setup allowed me to use GLUT functions for creating the OpenGL window, handling user input, and controlling the program's display and animation. Then i checked a simple code like : a four-colored square will continuously rotate and scale up and down.Then i applied my project idea .Finally, i confirmed this set up ready to GLUT project.

---
#
