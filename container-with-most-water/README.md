## Building with CMake

**Configure** step. Reads CMakeLists.txt, detects compiler, resolves settings, and generates the actual build system
files (Makefiles, Ninja files, etc.) inside the `build/` directory.

**Build** step. Invokes the generated build system (make, ninja, etc.) inside `build/` to actually compile and link code
into an executable.

```bash
# Configure
cmake -S . -B build

# Build
cmake --build build

# Run
./build/cpp-project
```

## Building without CMake

### Using clang++ (default on macOS)

```bash
clang++ -std=c++20 -o main src/main.cpp
./main
```

### Using g++ (install via Homebrew: `brew install gcc`)

```bash
g++-14 -std=c++20 -o main src/main.cpp
./main
```

> Note: On macOS, `g++` is typically aliased to Apple Clang. Use the versioned binary (e.g. `g++-14`) for actual GCC.

### Using Apple Clang directly (via Xcode Command Line Tools)

```bash
xcrun clang++ -std=c++20 -o main src/main.cpp
./main
```

### Cleaning object and executable files

```bash
cmake --build build --target clean
```

### Full cleaning

```bash
rm -rf build
```

## Testing

```cd build && ctest```

## Project Structure

```
.
├── CMakeLists.txt
├── README.md
└── src/
    └── main.cpp
```
