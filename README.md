# SOFE 3950U: Operating Systems
## Tutorial #4: Jeopardy

### Objectives
- Learn the fundamentals of C.
- Gain experience writing C programs with multiple source files.
- Create a command line version of the game Jeopardy.

### Important Notes
- Work in groups of four students.
- All reports must be submitted as a PDF on Blackboard. If source code is included, submit everything as an archive (e.g., zip, tar.gz).
- Save the file as `<tutorial_number>_<first student’s id>.pdf` (e.g., tutorial4_100123456.pdf).
- If you cannot submit the document on Blackboard, please contact the TA Omar Hemied: Omar.hemied@ontariotechu.ca.

### Notice
- Recommended resources:
  - [C Reference](http://en.cppreference.com/w/c)
  - [C Standard Library Reference](http://www.cplusplus.com/reference/clibrary/)
  - [C Reference Card](http://users.ece.utexas.edu/~adnan/c-refcard.pdf)
  - [C Bootcamp](http://gribblelab.org/CBootcamp)
- Helpful resources for string tokenization and POSIX functions:
  - [String Tokenization](http://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)

### Tutorial Setup
1. Create a new repository on GitHub for the course if you haven't already. Add all tutorial group members as collaborators.
2. Add the provided source code template for this tutorial to your GitHub repository. Use `git add`, `git commit`, and `git push` commands. For help, refer to:
   - [Set up Git](https://help.github.com/articles/set-up-git)
   - [Git Tutorial](http://git-scm.com/docs/gittutorial)
3. Ensure you can use the Makefile and C source code examples to build the code using `make`. If needed, modify the Makefile and set the CC variable to gcc instead of clang. Alternatively, try using the CMake tool:
   - [Using CMake](https://earthly.dev/blog/using-cmake/)
   - [CMake Tutorial](https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b)

### Tutorial Activity
- Work in a group to create a command line version of Jeopardy with support for up to four players using the provided source files and project requirements.
- Frequently push your code to GitHub to keep other group members in sync. Each group member should work on separate source files to avoid merge conflicts.

### Project Requirements
1. Implement a command line prompt for all interactions with the Jeopardy system.
2. Ask for the names of the four players, record each name, and set initial earnings to 0.
3. Start the game, print question categories, and display dollar values for each question.
4. Accept the name of the person selecting the category and question. Validate the entered name matches one of the players.
5. Prompt the player for the category and dollar amount question, verifying that they haven't already been answered.
6. Display the question for the player to answer. Questions and answers can be predefined or randomly selected from a question bank.
7. Prompt the player for the answer, starting with "what is" or "who is". Use string tokenization to parse the answer.
8. Display whether the answer is correct or incorrect. Update the player's score accordingly.
9. Print remaining categories and question dollar amounts. Repeat steps 4 to 9 until all questions are completed.
10. Print each player from first to last place and their total earnings. The player with the highest earnings wins.
11. Bonus marks for enhancements such as randomly chosen categories/questions, double jeopardy, or colored terminal output.

### Project Guidelines
- Organize questions, players, and game-related functions in separate source files.
- Implement necessary functions for interacting with questions and players.

#### Questions Source Files
- Store categories, questions, and answers.
- Use a struct called `question` with members: `category`, `question`, `answer`, `value`, and `answered`.
- Implement functions like `initialize_game`, `display_categories`, `display_question`, `valid_answer`, and `already_answered`.

#### Players Source Files
- Store player data in a struct called `player` with members: `name` and `score`.
- Implement functions like `player_exists` and `update_score`.

#### Jeopardy Source Files
- Store player structs and buffers for processing command line input.
- Implement functions like `tokenize` and `show_results`.

