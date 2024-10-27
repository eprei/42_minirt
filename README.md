# miniRT - 3D Ray Tracing Engine

A ray tracing engine written in C that renders 3D scenes with basic geometric objects. This project implements foundational ray tracing concepts including vector mathematics, light physics calculations, and object intersection algorithms.

![Ray Tracing Example](https://github.com/eprei/42_minirt/blob/8272039dd4365be07017b68b24a1a41810760fd8/render/render_scene1.png)
![Ray Tracing Example](https://github.com/eprei/42_minirt/blob/8272039dd4365be07017b68b24a1a41810760fd8/render/render_scene2.png)
![Ray Tracing Example](https://github.com/eprei/42_minirt/blob/8272039dd4365be07017b68b24a1a41810760fd8/render/render_scene3.png)

## Features

- **Geometric Objects:**
  - Spheres (with diameter control)
  - Planes (with normal vector orientation)
  - Cylinders (with height, diameter, and orientation control)

- **Lighting System:**
  - Ambient lighting
  - Diffuse lighting with intensity control
  - Hard shadows
  - Light position and brightness adjustment

- **Camera Controls:**
  - Configurable field of view (FOV)
  - Adjustable position and orientation
  - Vector-based view calculations

- **Scene Management:**
  - Scene description via .rt configuration files
  - Object translation and rotation
  - Color configuration (RGB)

## Technical Details

### Mathematics & Physics Implementation

- Vector operations (addition, subtraction, multiplication, dot product)
- Normalization and vector transformations
- Ray-object intersection calculations
- Light intensity and shadow computations
- 3D space coordinate handling

### Dependencies

- **minilibX:** Graphics library for window management and pixel rendering
- **libft:** Custom C library with utility functions
- **Math Library:** Used for mathematical operations

## Building the Project

```bash
# Clone the repository
git clone https://github.com/eprei/42_minirt.git

# Build the project
make

# Clean object files
make clean

# Clean all compiled files
make fclean

# Rebuild the project
make re
```

## Usage

```bash
./miniRT <scene_file.rt>
```

### Scene File Format (.rt)

Scene files use specific identifiers for different elements:

```
# Ambient Light
A 0.2 255,255,255         # [ratio] [R,G,B]

# Camera
C -50.0,0,20 0,0,1 70    # [position] [orientation] [FOV]

# Light
L -40.0,50.0,0.0 0.6     # [position] [brightness]

# Sphere
sp 0.0,0.0,20.6 12.6 10,0,255    # [center] [diameter] [R,G,B]

# Plane
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225    # [point] [normal] [R,G,B]

# Cylinder
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255    # [center] [axis] [diameter] [height] [R,G,B]
```

### Controls

- `ESC`: Close window and exit program
- Red cross button: Close window and exit program

## Project Structure

- `src/`: Source files containing the main ray tracing implementation
- `include/`: Header files
- `libft/`: Custom C library implementation
- `mlx/`: minilibX graphics library
- `files_rt/`: Example scene files

## Implementation Details

- Written in C with a focus on performance and memory management
- Implements ray-object intersection algorithms for each geometric shape
- Uses vector mathematics for light calculations and object transformations
- Handles multiple object rendering with proper depth and shadow calculations

## Error Handling

The program includes comprehensive error checking for:
- File format and parsing
- Memory allocation
- Scene configuration validation
- Window management

## Acknowledgments

- School 42 for the project subject and minilibX library
- The ray tracing community for algorithms and mathematical formulas

