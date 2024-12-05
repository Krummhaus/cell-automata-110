# Helper command for this project

## Git

```
eval `ssh-agent`
ssh-add ~/.ssh/krumm
```
## Using GLFW
- an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan

```sh
pkg-config --libs glfw3
# output: -lglfw

pkg-config --libs glew
# output:-L/usr/lib64 -lGLEW -lGL -lX11 -lGLU
```
