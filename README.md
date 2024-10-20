# miniRT - My First RayTracer

## Overview
**miniRT** is a simple ray tracing project that generates 3D images using the Raytracing protocol. The program renders scenes composed of geometric objects such as planes, spheres, and cylinders, with basic lighting and transformations.

## Features
- Rendering of planes, spheres, and cylinders.
- Support for resizing, translation, and rotation (for objects and cameras).
- Ambient and diffuse lighting, including hard shadows.
- Scene input from a `.rt` file.
- Window display using MiniLibX with support for:
  - ESC key to close the window.
  - Red cross to quit the program.

## File Format
The `.rt` scene file must define the objects and their properties (coordinates, size, color), along with lighting and camera setup. Each element is represented by a specific identifier followed by its attributes.

### Example:
```rt
A 0.2 255,255,255  # Ambient lighting
C -50.0,0,20 0,0,1 70  # Camera
L -40.0,50.0,0.0 0.6 10,0,255  # Light
sp 0.0,0.0,20.6 12.6 10,0,255  # Sphere
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225  # Plane
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255  # Cylinder
```

## Compilation

To compile the project, use the provided Makefile:

```make```

The Makefile includes the following rules:
- all: compiles the program.
- clean: removes object files.
- fclean: removes object files and binaries.
- re: recompiles the project.

## Requirements
- No memory leaks (except for those caused by MiniLibX).
- Follow the C coding Norm.
- Implement correct object intersections and transformations.

## External Libraries
- MiniLibX for window management.
- Math library for geometric calculations.

## Reference
For additional information, refer to the MiniLibX documentation and the Raytracing protocol.
