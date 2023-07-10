# raylib-pong

A pong game written in C++ with Raylib! I started this as a practice project. Works on Windows, I have not tested this on Linux/MacOS.

# Build

```bash
git clone https://github.com/fahlerile/raylib-pong.git
cd raylib-pong/build
cmake ..
./pong.exe
```

# TODO

- Refactor the code (manage class' access modifiers)
- Add randomness to ball initializing (and get rid of `initial_x` and `initial_y`)
- Think about fixing collision