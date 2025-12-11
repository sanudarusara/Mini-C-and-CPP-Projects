# ♟️ Chess Game in C

![Game Start](images/game_start1.png)

A simple console-based Chess program that displays an ASCII chessboard, allows you to move pieces using coordinate inputs, and tracks captured black and white pieces.
This was one of my earliest programming projects created during my first year of university using only basic C concepts.

📌 Overview

This program runs entirely in the command line. It prints a visual 8×8 chessboard and shows the initial positions of all pieces.
You can select a piece and then choose a destination square to “move” it.

✔️ The board updates after each move<br>
✔️ Captured pieces are recorded and displayed<br>
✔️ Both white and black pieces can be moved<br>
✔️ No OOP or advanced rules — simple logic only

# 📍 How the Program Works
1. Board Display<br>
The program prints a stylized chessboard using ASCII formatting.

  Black squares are drawn with ******<br>
  White squares are drawn with spaces<br>
  Pieces use 2-letter codes:

  R = Rook<br>
  N = Knight<br>
  B = Bishop<br>
  Q = Queen<br>
  K = King<br>
  P = Pawn<br>
  W = White piece<br>
  B = Black piece

Example:

  PW = White Pawn<br>
  RB = Black Rook

# 📍 How to Play / Input Format<br><br>
➤ Step 1: Enter the position of the piece you want to move

  Format : row.column<br>
  Example: 2.1
  
  This means: Row 2, Column 1 on the printed board.

➤ Step 2: Enter the destination position<br>
  Again in the same format: row.column

# 📍 Important: Coordinate System Explanation<br><br>
The board is displayed with rows numbered 8 to 1 (top to bottom).<br>
So the input uses the visual row numbers shown on the left side.

Example:
If you want to move the white pawn at row 7, column 2:  
  Enter the PIECE: 7.2
Then move it to row 5, column 2:
  Enter the MOVE: 5.2

✔️ Example 1: Moving a White Pawn
  White pawn at 7.1 → move to 5.1<br>
    Enter the PIECE: 7.1<br>
    Enter the MOVE: 5.1<br>
  Board updates, pawn appears on new square.

# 📍 Capture System Explained

If you move onto a square containing an opponent’s piece, the program automatically:<br>
✔️ Detects the color<br>
✔️ Stores the piece into the correct captured-list array<br>
✔️ Increments the capture count<br>
✔️ Replaces that square with your piece<br>

Two lists are maintained:

  Black pieces captured<br>
  White pieces captured<br>

Example output:<br>
  Captured Black PIECES: 2 --> PB, NB,<br>
  Captured White PIECES: 1 --> PW,<br>

✔️ Example 2: Capturing an Opponent Piece<br>
Let’s say a white piece moves onto a black piece’s square:<br>
  Enter the PIECE: 5.3<br>
  Enter the MOVE: 4.3<br>
  
If a black piece exists at (4,3):<br>
  ➡️ It is added to the Captured Black Pieces list.<br>
  ➡️ The white piece replaces it on the board.<br>

Captured pieces print like:<br>
  Captured Black PIECES: 1 --> PB,

# 📍 Stopping the Program

To exit the game:<br>
  Enter the PIECE: 0.0<br>
The program prints:<br>
  Congratulations WINNER!!!<br>

# ⚠️ Limitations (Because This Is a Beginner Project)

This program does NOT enforce the rules of chess:

  ❌ No check/checkmate rules<br>
  ❌ No movement validation (knight moves, diagonal rules, etc.)<br>
  ❌ No turns (you can move any piece anytime)<br>
  ❌ No en passant, castling, promotions<br>
  ❌ No game-end logic<br>

It’s purely a manual movement simulator with capture tracking — but perfect for a beginner-level C project.

# 📍 How to Compile & Run

  Compile with GCC<br>
    gcc chess.c -o chess<br><br>
  Run<br>
    Linux/Mac: ./chess<br>
    Windows CMD: chess.exe<br>
      
# 📍 Demo<br>
A short demo video showing gameplay is included.

# 📚 What I Learned from This Project

- Working with 2D arrays<br>
- String manipulation in C<br>
- Designing a CLI-based board layout<br>
- Handling coordinates and mapping user input<br>
- Basic game-state updates<br>
- Tracking captures with arrays<br>
