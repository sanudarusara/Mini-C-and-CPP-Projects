# 🧩 Console-Based Maze Path Finder (C++)

A simple console-based maze visualization and path-finding program built using basic C++ concepts.
This project was created during my early university days to understand 2D arrays, conditional logic, and coordinate-based movement — without using advanced algorithms or OOP.

The program displays a maze using ASCII graphics, marks a start (S) and end (E) point, and then prints a step-by-step path from start to end using simple directional logic.

# 📌 Overview

This program runs entirely in the command line.

You define:
- The size of the maze<br>
- The maze layout (walls and paths)<br>
- A starting point<br>
- An ending point<br>

The program then:<br>
✔️ Visually prints the maze using ASCII characters<br>
✔️ Marks walls, empty paths, start, and end positions<br>
✔️ Calculates a path from start to end<br>
✔️ Outputs the directions taken (up, down, left, right)<br>

# 📍 Maze Representation

The maze is stored in a 2D integer array.

- 1 → Wall (blocked path)
- 0 → Free path (walkable)

Visual Symbols Used

- ***** → Wall
- Empty spaces → Free path
- S → Start point
- E → End point
- \* → Maze borders

# 📍 How the Program Works

**Step 1: Enter Maze Size<br>**

Enter the no.of rows of the maze   : 5<br>
Enter the no.of columns of the maze: 6<br>

**Step 2: Enter Maze Values<br>**

You enter each row manually using 0 and 1.

Enter row 1: 1 1 1 1 1 1<br>
Enter row 2: 1 0 0 0 0 1<br>
Enter row 3: 1 0 1 1 0 1<br>
Enter row 4: 1 0 0 0 0 1<br>
Enter row 5: 1 1 1 1 1 1<br>

**Step 3: Enter Start & End Points**

Coordinates are entered as row column (1-based indexing).

Enter the start point : 2 2<br>
Enter the end point   : 4 5

The program internally converts these to 0-based indices.

# 📍 Maze Rendering

The program dynamically:

- Draws top and bottom borders
- Draws left and right borders
- Expands each maze cell into a 3-line ASCII block
- Places S and E at the correct positions

This makes the maze visually clearer inside the terminal.

# 📍 Path-Finding Logic

⚠️ This is not a BFS, DFS, or shortest-path algorithm.
The program follows a simple directional priority:

- Go up
- Go down
- Go right
- Go left

When a move is made:

- The current cell is marked as visited (1)
- The position updates
- The direction is printed

Example Output:
Go down, Go down, Go right, Go right, Go up.

The loop continues until the end point (E) is reached.

# 📍 Stopping Condition

The program stops automatically when:<br>
✔️ The current position matches the end coordinates

# ⚠️ Limitations (Beginner Project)

This project is intentionally simple and has several limitations:

❌ No shortest-path guarantee<br>
❌ No backtracking<br>
❌ No detection for unsolvable mazes<br>
❌ May fail if the path requires revisiting cells<br>
❌ No visualization of the path traversal itself<br>

Still, it served as a strong foundational exercise for myself.

# 📍 How to Compile & Run

Compile<br>
g++ maze.cpp -o maze

Run<br>
Linux / Mac: ./maze<br>
Windows: maze.exe<br>

# 📚 What I Learned from This Project

- Working with 2D arrays<br>
- ASCII-based UI design in the terminal<br>
- Handling dynamic user input<br>
- Mapping real-world coordinates to array indices<br>
- Basic path traversal logic<br>
- Structuring a full CLI program from scratch<br>
