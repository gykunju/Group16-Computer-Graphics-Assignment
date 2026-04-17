# Computer Graphics Group 16 Assignment

Link to slides; [Graphic Coordinate systems and Homogenous Coordinates](https://canva.link/v599sb649wsvo9f)

# OpenGL Chessboard

This repository contains two equivalent implementations of an 8x8 chessboard visualization using basic OpenGL primitives: one written in **C++** and the other ported to **Python**.

## Project Overview

The objective of this project is to render a top-down view of a classic 8x8 chessboard with alternating **White** and **Brown** squares. Additionally, it renders a set of chess pieces (specifically a King and a Queen for both White and Black sides) stationed at their respective starting ranks. 

Both applications utilize the exact same coordinate math, structural logic, and OpenGL drawing calls (`GL_QUADS`, `GL_POLYGON`, etc.), demonstrating how graphic visualization logic carries seamlessly across different host languages via language bindings.

---

## Implementations

### 1. C++ Version (`chessboard.cpp`)
The original implementation built using C++ and the GLUT (OpenGL Utility Toolkit) library. 

**Requirements:**
- A C++ Compiler (e.g., GCC/G++, MSVC)
- OpenGL and GLUT/freeglut libraries installed on your system.

**Compilation and execution (example using g++ on Linux/MinGW):**
```bash
# Compile the application
g++ chessboard.cpp -o chessboard -lGL -lGLU -lglut

# Run the executable
./chessboard
```

### 2. Python Version (`chessboard.py`)
A direct port of the C++ logic to Python using the **PyOpenGL** library. It renders the exact identical visual frame and maintains the same 1:1 ratio 640x640 resolution window.

**Requirements:**
- Python 3.x
- `PyOpenGL` library

**Installation and execution:**
```bash
# Install PyOpenGL dependencies
pip install PyOpenGL PyOpenGL_accelerate

# Run the python script
python chessboard.py
```

---

## Features
- **Window Initialization**: Creates a 640x640 fixed-aspect ratio window using GLUT.
- **Orthographic Projection**: Uses a custom `0.0` to `8.0` 2D coordinate system mapping exactly to the 8x8 squares required for a chessboard.
- **Alternating Palette**: Dynamically loops through an 8x8 nested loop to paint alternating tiles.
- **Primitive Drawing**: Models custom polygonal 2D shapes for a King and a Queen on both the White and Dark armies.
