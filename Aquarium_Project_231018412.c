#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// Fish position
float fishX = -0.8f;

// Bubble position
float bubbleY = -0.7f;

// Day/Night
int night = 0;

// Draw circle
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(cx, cy);

    for(int i = 0; i <= 100; i++)
    {
        float angle = 2.0f * 3.1416f * i / 100;

        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

// Draw fish
void drawFish(float x, float y)
{
    // Fish body
    glColor3f(1.0f, 0.5f, 0.0f);

    drawCircle(x, y, 0.12f);

    // Tail
    glColor3f(1.0f, 0.3f, 0.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(x - 0.10f, y);
    glVertex2f(x - 0.25f, y + 0.10f);
    glVertex2f(x - 0.25f, y - 0.10f);

    glEnd();

    // Eye
    glColor3f(0.0f, 0.0f, 0.0f);

    drawCircle(x + 0.05f, y + 0.04f, 0.02f);
}

// Draw plant
void drawPlant(float x)
{
    glColor3f(0.0f, 0.8f, 0.2f);

    glLineWidth(5);

    glBegin(GL_LINES);

    glVertex2f(x, -0.9f);
    glVertex2f(x - 0.05f, -0.5f);

    glVertex2f(x, -0.9f);
    glVertex2f(x + 0.08f, -0.55f);

    glVertex2f(x, -0.9f);
    glVertex2f(x + 0.02f, -0.45f);

    glEnd();
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Water background
    if(night)
        glColor3f(0.0f, 0.05f, 0.15f);
    else
        glColor3f(0.0f, 0.5f, 0.8f);

    glBegin(GL_QUADS);

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);

    glEnd();

    // Sand
    glColor3f(0.8f, 0.7f, 0.3f);

    glBegin(GL_QUADS);

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.85f);
    glVertex2f(-1.0f, -0.85f);

    glEnd();

    // Fish
    drawFish(fishX, 0.2f);
    drawFish(fishX + 0.5f, -0.1f);

    // Plants
    drawPlant(-0.7f);
    drawPlant(-0.4f);
    drawPlant(0.6f);
    drawPlant(0.8f);

    // Bubbles
    glColor3f(0.8f, 0.9f, 1.0f);

    drawCircle(0.3f, bubbleY, 0.03f);
    drawCircle(0.4f, bubbleY + 0.2f, 0.02f);

    // Title
    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.25f, 0.9f);

    const char *text = "MY AQUARIUM";

    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glutSwapBuffers();
}

// Animation
void update(int value)
{
    // Move fish
    fishX += 0.01f;

    if(fishX > 1.2f)
        fishX = -1.2f;

    // Move bubble upward
    bubbleY += 0.01f;

    if(bubbleY > 1.0f)
        bubbleY = -0.8f;

    glutPostRedisplay();

    glutTimerFunc(30, update, 0);
}

// Keyboard
void keyboard(unsigned char key, int x, int y)
{
    // Press D to switch between day and night
    if(key == 'd' || key == 'D')
    {
        night = !night;
        glutPostRedisplay();
    }

    // Press ESC to exit
    if(key == 27)
    {
        exit(0);
    }
}

// Initialize
void init()
{
    glClearColor(0.0f, 0.5f, 0.8f, 1.0f);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Main
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Interactive Aquarium");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutTimerFunc(30, update, 0);

    glutMainLoop();

    return 0;
}
