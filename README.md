# SimplC
A simple UNIX-based memory manipulation program that allows users to modify memory values, save/load memory to a file, reset memory, and view memory dumps. Supports basic operations (=, +, -) and handles user input efficiently. Ideal for learning basic file handling, memory management, and command parsing in C. 🚀
Features:
✅ Memory Operations (=, +, -) – Assign, add, or subtract values at memory addresses.
✅ Memory Dump (D) – Displays all non-zero memory addresses.
✅ Reset Memory (R) – Clears the memory by setting all values to zero.
✅ Save & Load Memory (S filename / L filename) – Store and retrieve memory states from files.
✅ Comment Support (*) – Ignore comment lines for better readability.
✅ Exit Command (X) – Stops execution.

Enter commands to modify memory:
10 = 50    # Set address 10 to 50
10 + 5     # Add 5 to address 10
D          # Display memory
S mem.dat  # Save memory to file
L mem.dat  # Load memory from file
X          # Exit

Why Use This?
This project is great for understanding low-level memory management, file handling, and basic emulation techniques in C.
