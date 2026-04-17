# GROUP 16
# ALVIN GIKUNJU - SCT211-0011/2023
# ETHAN KISANG - SCT211-0012/2023

import sys
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

def drawKing(x, y, isWhitePiece):
    if isWhitePiece:
        # Gold-like color for white pieces to contrast with board
        glColor3f(0.9, 0.8, 0.2)
    else:
        # Dark gray for black pieces
        glColor3f(0.2, 0.2, 0.2)
        
    # King base
    glBegin(GL_QUADS)
    glVertex2f(x + 0.2, y + 0.1)
    glVertex2f(x + 0.8, y + 0.1)
    glVertex2f(x + 0.8, y + 0.3)
    glVertex2f(x + 0.2, y + 0.3)
    glEnd()
    
    # Vertical part of cross
    glBegin(GL_QUADS)
    glVertex2f(x + 0.45, y + 0.3)
    glVertex2f(x + 0.55, y + 0.3)
    glVertex2f(x + 0.55, y + 0.8)
    glVertex2f(x + 0.45, y + 0.8)
    glEnd()
    
    # Horizontal part of cross
    glBegin(GL_QUADS)
    glVertex2f(x + 0.35, y + 0.55)
    glVertex2f(x + 0.65, y + 0.55)
    glVertex2f(x + 0.65, y + 0.65)
    glVertex2f(x + 0.35, y + 0.65)
    glEnd()

def drawQueen(x, y, isWhitePiece):
    if isWhitePiece:
        glColor3f(0.9, 0.8, 0.2)
    else:
        glColor3f(0.2, 0.2, 0.2)
        
    # Crown base
    glBegin(GL_QUADS)
    glVertex2f(x + 0.2, y + 0.1)
    glVertex2f(x + 0.8, y + 0.1)
    glVertex2f(x + 0.75, y + 0.3)
    glVertex2f(x + 0.25, y + 0.3)
    glEnd()
    
    # Crown points
    glBegin(GL_POLYGON)
    glVertex2f(x + 0.25, y + 0.3)
    glVertex2f(x + 0.75, y + 0.3)
    glVertex2f(x + 0.9, y + 0.8)
    glVertex2f(x + 0.65, y + 0.5)
    glVertex2f(x + 0.5, y + 0.9)
    glVertex2f(x + 0.35, y + 0.5)
    glVertex2f(x + 0.1, y + 0.8)
    glEnd()

def display():
    glClear(GL_COLOR_BUFFER_BIT)
    
    # Flag to alternate colors
    isWhite = True
    
    # Loop through the 8x8 grid
    for y in range(8):
        for x in range(8):
            # Set color for the current square
            if isWhite:
                # White color
                glColor3f(1.0, 1.0, 1.0)
            else:
                # Brown color
                glColor3f(0.54, 0.27, 0.07)
                
            # Draw a 1x1 square at (x, y)
            glBegin(GL_QUADS)
            glVertex2i(x, y)
            glVertex2i(x + 1, y)
            glVertex2i(x + 1, y + 1)
            glVertex2i(x, y + 1)
            glEnd()
            
            # Toggle color for the next square in the row
            isWhite = not isWhite
            
        # At the end of a row, toggle color again to stagger the pattern
        isWhite = not isWhite
        
    # Draw pieces
    # White pieces (Row 0)
    drawQueen(3.0, 0.0, True) # White Queen
    drawKing(4.0, 0.0, True)  # White King
    
    # Black pieces (Row 7)
    drawQueen(3.0, 7.0, False) # Black Queen
    drawKing(4.0, 7.0, False)  # Black King
    
    glFlush()

def init():
    # Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0)
    
    # Set up the projection matrix
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    
    # Set coordinate system from 0 to 8 on both axes
    # This maps exactly to our 8x8 squares
    gluOrtho2D(0.0, 8.0, 0.0, 8.0)

def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
    
    # A square window to keep aspect ratio correct
    glutInitWindowSize(640, 640)
    glutInitWindowPosition(100, 100)
    
    # Note: Some versions of PyOpenGL require a byte string here
    glutCreateWindow(b"8x8 Chessboard - Brown and White")
    
    init()
    glutDisplayFunc(display)
    
    glutMainLoop()

if __name__ == "__main__":
    main()
