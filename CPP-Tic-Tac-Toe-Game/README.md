# 🎮 Tic Tac Toe in C++

A simple console-based Tic Tac Toe game built using basic C++ concepts.
Players take turns entering grid positions, and the program validates moves, updates the board, detects wins, and identifies draw situations.

This was created purely for fun as part of my mini C++ practice projects.

# 📌 Features

✔️ Console-based 3×3 Tic Tac Toe grid<br>
✔️ Player vs Player (X and O take turns)<br>
✔️ Input validation<br>
&nbsp;&nbsp;&nbsp;&nbsp;- Invalid cell range (must be 1–3)<br>
&nbsp;&nbsp;&nbsp;&nbsp;- Prevents placing on an occupied cell<br>
✔️ Win detection<br>
✔️ Draw detection (no empty cells left)<br>
✔️ Clean ASCII board display updated after every move<br>

# 📍 How the Game Works<br>

Board & Input<br>

- The board is a 3×3 grid initialized with _ to indicate empty spaces.<br>
- Players enter coordinates in the "x y" format:<br>
&nbsp;&nbsp;&nbsp;&nbsp;Where x = row (1–3) and y = column (1–3).
- The program automatically converts inputs into 0-indexed array positions.

# 📍 Game Logic Overview<br>

#Move Validation:-
- Checks if the entered row/column is within the valid 1–3 range.
- Checks if the selected cell is already taken.

#Win Detection:-

The game checks for:
- 3 in a row (horizontal)
- 3 in a column (vertical)
- 3 in a diagonal (two directions)

If a player gets three matching symbols, the game prints:<br>
&nbsp;&nbsp;&nbsp;&nbsp;"Congratulations X (or O). You are the Winner!!!"

#Draw Detection:- 

If no empty spaces ( _ ) remain and there is no winner, the game prints:<br>
&nbsp;&nbsp;&nbsp;&nbsp;"Great game X and O. The Game is Drawn!!!"

# 📍 How to Compile & Run

Compile:<br>
g++ tictactoe.cpp -o tictactoe

Run:<br>
./tictactoe

# 📚 What I Learned

- Using 2D arrays in C++
- Building simple game loops
- Input handling & validation
- Designing readable ASCII UI
- Implementing win/draw logic
