# MacOS

```brew install sdl3```

Run it once after first cloning the project and then when build parameters change.

```cmake -B build -S .```

Link

```ln -s build/compile_commands.json .```

Compile/Link

```cmake --build build```

## Controls

### Keyboard Controls

- **`Space`**: Pause / Resume the simulation.
- **`R`**: Randomize the grid (20% of the cells will be set to alive).
- **`C`**: Clear the grid (kill all cells).
- **`Escape`**: Exit the application.

### Mouse Controls

- **`Left Click`**: Toggle the state of a cell (alive / dead) under the cursor.