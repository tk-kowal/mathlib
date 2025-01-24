# Tom's Math Lib

My header-only math library. This is a learning project. I'm using this to learn modern C++ and to build some intuition around the math I'm studying.

# Build

```shell
# 1. Check if cmake is installed
cmake --version

# 2. Create the build directory
mkdir build && cd build

# 3. Configure the project with cmake
cmake ..

# 4. Build the project
make

# 5. Run the tests
make runtests

# 6. Install the library in /usr/local
cmake --install .
```

# Inspiration

Some of these implementations are loosely inspired by [OpenGL Mathematics](https://github.com/g-truc/glm)
