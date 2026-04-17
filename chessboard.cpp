// GROUP 16
// ALVIN GIKUNJU - SCT211-0011/2023
// ETHAN KISANG - SCT211-0012/2023

#include <GL/glut.h>

void drawKing(float x, float y, bool isWhitePiece) {
    if (isWhitePiece) {
        // Gold-like color for white pieces to contrast with board
        glColor3f(0.9f, 0.8f, 0.2f);
    } else {
        // Dark gray for black pieces
        glColor3f(0.2f, 0.2f, 0.2f);
    }
    
    // King base
    glBegin(GL_QUADS);
        glVertex2f(x + 0.2f, y + 0.1f);
        glVertex2f(x + 0.8f, y + 0.1f);
        glVertex2f(x + 0.8f, y + 0.3f);
        glVertex2f(x + 0.2f, y + 0.3f);
    glEnd();
    
    // Vertical part of cross
    glBegin(GL_QUADS);
        glVertex2f(x + 0.45f, y + 0.3f);
        glVertex2f(x + 0.55f, y + 0.3f);
        glVertex2f(x + 0.55f, y + 0.8f);
        glVertex2f(x + 0.45f, y + 0.8f);
    glEnd();
    
    // Horizontal part of cross
    glBegin(GL_QUADS);
        glVertex2f(x + 0.35f, y + 0.55f);
        glVertex2f(x + 0.65f, y + 0.55f);
        glVertex2f(x + 0.65f, y + 0.65f);
        glVertex2f(x + 0.35f, y + 0.65f);
    glEnd();
}

void drawQueen(float x, float y, bool isWhitePiece) {
    if (isWhitePiece) {
        glColor3f(0.9f, 0.8f, 0.2f);
    } else {
        glColor3f(0.2f, 0.2f, 0.2f);
    }
    
    // Crown base
    glBegin(GL_QUADS);
        glVertex2f(x + 0.2f, y + 0.1f);
        glVertex2f(x + 0.8f, y + 0.1f);
        glVertex2f(x + 0.75f, y + 0.3f);
        glVertex2f(x + 0.25f, y + 0.3f);
    glEnd();
    
    // Crown points
    glBegin(GL_POLYGON);
        glVertex2f(x + 0.25f, y + 0.3f);
        glVertex2f(x + 0.75f, y + 0.3f);
        glVertex2f(x + 0.9f, y + 0.8f);
        glVertex2f(x + 0.65f, y + 0.5f);
        glVertex2f(x + 0.5f, y + 0.9f);
        glVertex2f(x + 0.35f, y + 0.5f);
        glVertex2f(x + 0.1f, y + 0.8f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Flag to alternate colors
    bool isWhite = true;
    
    // Loop through the 8x8 grid
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            // Set color for the current square
            if (isWhite) {
                // White color
                glColor3f(1.0f, 1.0f, 1.0f);
            } else {
                // Brown color
                glColor3f(0.54f, 0.27f, 0.07f);
            }
            
            // Draw a 1x1 square at (x, y)
            glBegin(GL_QUADS);
                glVertex2i(x, y);
                glVertex2i(x + 1, y);
                glVertex2i(x + 1, y + 1);
                glVertex2i(x, y + 1);
            glEnd();
            
            // Toggle color for the next square in the row
            isWhite = !isWhite;
        }
        // At the end of a row, toggle color again to stagger the pattern
        isWhite = !isWhite;
    }
    
    // Draw pieces
    // White pieces (Row 0)
    drawQueen(3.0f, 0.0f, true); // White Queen
    drawKing(4.0f, 0.0f, true);  // White King
    
    // Black pieces (Row 7)
    drawQueen(3.0f, 7.0f, false); // Black Queen
    drawKing(4.0f, 7.0f, false);  // Black King
    
    glFlush();
}

void init() {
    // Set background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Set coordinate system from 0 to 8 on both axes
    // This maps exactly to our 8x8 squares
    gluOrtho2D(0.0, 8.0, 0.0, 8.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // A square window to keep aspect ratio correct
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("8x8 Chessboard - Brown and White");
    
    init();
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
