*This project has been created as part of the 42 curriculum by josemigu, mreinald.*

# miniRT — My First RayTracer with MiniLibX

## Description

miniRT is a ray tracing rendering engine written in C, built as part of the 42 School curriculum. The goal is to generate images of 3D scenes by simulating the physical behavior of light rays — tracing their path from the camera through each pixel and computing how they interact with geometric objects and light sources in the scene.

The engine renders scenes described in `.rt` files, supporting three geometric primitives (spheres, planes, cylinders), a configurable camera with field of view, a single point light source, ambient lighting, diffuse shading, and hard shadows. All rendering is displayed in a window managed by the MiniLibX library.

Key features:
- Ray-object intersection for spheres, planes, and cylinders
- Phong-inspired lighting model: ambient + diffuse components
- Hard shadows via shadow ray casting with self-intersection protection (EPSILON offset)
- Camera with arbitrary position, orientation, and FOV
- Scene description parsed from `.rt` files
- Window management with ESC and close-button support
- Debug build mode (400×300) and production mode (800×600)

The project is developed as a two-person team. The workload is split as follows:
- **josemigu**: documentation, integration, header files, testing, Makefile & norm compliance, memory magagement & cleanup, scene validation & error handling, main rendering loop, MiniLibX integration, parser, initial design, color computation, lighting system, scene management, shadow computation
- **mreinald**: documentation, integration, header files, testing, Makefile & norm compliance, memory magagement & cleanup, scene validation & error handling, main rendering loop, camera setup,  cylinder/plane/sphere intersection, library for algebra operations, initial design

---

## Instructions

### Requirements

- Linux (tested on Ubuntu)
- MiniLibX (either system version or from sources)
- X11 development libraries (`libX11`, `libXext`)
- `libft` (included as a dependency)
- C compiler (`cc`) with `-lm` and `-lmlx` flags

### Compilation

```bash
# Standard build (800×600 window)
make

# Clean object files
make clean

# Full clean
make fclean

# Rebuild
make re
```

### Usage

```bash
./bin/miniRT scenes/subject.rt
```

The program takes exactly one argument: a scene description file with the `.rt` extension.

**Window controls:**
- `ESC` — close the window and exit cleanly
- Red cross (window frame) — close the window and exit cleanly

### Scene File Format (`.rt`)

Each element is defined by an identifier, followed by its parameters separated by spaces or newlines. Elements defined by a capital letter (`A`, `C`, `L`) may only appear once.

```
# Ambient light: ratio [0.0–1.0]  R,G,B [0–255]
A 0.2  255,255,255

# Camera: x,y,z  orientation_x,y,z  FOV [0–180]
C 0,0,-5  0,0,1  70

# Light: x,y,z  brightness [0.0–1.0]  R,G,B
L -10,10,-10  0.8  255,255,255

# Sphere: x,y,z  diameter  R,G,B
sp 0,0,3  2  255,0,0

# Plane: point_x,y,z  normal_x,y,z  R,G,B
pl 0,-1,0  0,1,0  128,128,128

# Cylinder: center_x,y,z  axis_x,y,z  diameter  height  R,G,B
cy 0,0,3  0,1,0  1  3  0,0,255
```

---

## Resources

### Ray Tracing

- **The Ray Tracer Challenge** — Jamis Buck. The primary reference for this implementation. Covers ray-object intersections, transformation matrices, lighting, and shadows in a test-driven format. https://pragprog.com/titles/jbtracer/the-ray-tracer-challenge/
- **Scratchapixel** — In-depth, free articles on ray tracing fundamentals, camera models, and shading. https://www.scratchapixel.com
- **Ray Tracing in One Weekend** — Peter Shirley. A short, practical introduction to building a basic ray tracer from scratch. https://raytracing.github.io/books/RayTracingInOneWeekend.html

### MiniLibX

- **MiniLibX documentation** (42 School): https://harm-smits.github.io/42docs/libs/minilibx
- **MiniLibX Linux sources**: https://github.com/42Paris/minilibx-linux

### Math Reference

- **3D Math Primer for Graphics and Game Development** — Dunn & Parberry. Reference for matrix operations, homogeneous coordinates, and transformations.
- `man 3 math` — C standard math library reference (used for `sqrt`, `fabs`, `cos`, `sin`, `tan`, `fmax`, `fmin`).

### AI Usage

Claude (Anthropic) was used as a development tool throughout the project in the following ways:

- **Debugging**: identifying logical errors in matrix inversion, ray transformation, and sphere intersection code; verifying correctness of homogeneous coordinate handling
- **Code review**: reviewing functions for memory leaks, null-pointer dereferences, and 42 norm compliance (25-line limit, style conventions)
- **Architecture guidance**: discussing the rendering pipeline structure, shadow ray offset strategies, and the cylinder local-space intersection approach
- **Documentation**: clarifying expected behavior of MiniLibX functions such as `mlx_get_data_addr` and `mlx_put_image_to_window`

All code was written, understood, and validated by the team. AI-generated suggestions were reviewed, tested, and adapted — not copy-pasted blindly.
