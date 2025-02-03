# fdf - 1337 Project

[![1337 Badge](https://img.shields.io/badge/1337-Project-blue)](https://www.42network.org/)

## 📜 Project Overview

**fdf** is a core project in the **1337 curriculum** (part of the 42 Network) that challenges students to create a 3D wireframe visualization from a 2D map file. The project uses the **minilibx** graphics library to render a wireframe representation of a landscape defined by altitude data. This project emphasizes efficient rendering, transformation (rotation, scaling, translation), and interactive controls to navigate through the 3D model.

---

## 🚀 Features

- **3D Wireframe Rendering:** Displays a 3D map using a wireframe model.
- **Bresenham’s Line Algorithm:** Implements an efficient algorithm to draw lines between points.
- **Interactive Controls:**  
  - Rotate the map on various axes.
  - Zoom in and out.
  - Translate the view within the window.
- **Map Parsing:** Reads and processes altitude values from map files.
- **Bonus Enhancements:**  
  - Color gradients based on altitude.
  - Additional keyboard controls for advanced transformations.

---

## 📂 Repository Structure

```plaintext
|-- maps                          // Directory containing sample map files
|-- minilibx                      // Minilibx library for graphical rendering
|-- Makefile                      // Compilation rules for building the project
|-- README.md                     // Project documentation

|-- bresenham.c                  // Implementation of Bresenham's line algorithm
|-- color_bonus.c                // Bonus: Color manipulation based on altitude
|-- draw.c                       // Functions for drawing the wireframe
|-- fdf.c                        // Main implementation of the fdf program
|-- fdf.h                        // Header file containing structures and function prototypes

|-- free.c                       // Functions for memory deallocation
|-- ft_atoi.c                    // Custom atoi implementation
|-- ft_split.c                   // Custom string splitting function
|-- get_map.c                    // Parsing and processing of map files

|-- get_next_line.c              // Get Next Line function for file reading
|-- get_next_line_utils.c        // Utilities for Get Next Line

|-- handle_keyboard_bonus.c      // Bonus: Keyboard event handling for interactive controls
|-- initialize.c                 // Initialization functions for setting up the environment
|-- macros.h                     // Macros and constants definitions
|-- rotation_bonus.c             // Bonus: Functions for rotation transformations
|-- utils.c                      // General utility functions
```  

---

## 🛠️ How to Use  

### 1. Clone the Repository  
```bash  
git clone https://github.com/Mohaben-1/42-fdf_1337.git
cd 42-fdf_1337
```

### 2. Compile the Program  

Use the provided `Makefile` to compile:  
- **Without Bonus**  
  ```bash  
  make  
  ```  

- **With Bonus**  
  ```bash  
  make bonus  
  ```

### 3. Run the Program

The executable takes a map file as an argument. Map files are provided in the maps directory.

```bash
./fdf maps/your_map_file.fdf
```
Replace your_map_file.fdf with the desired map file to visualize. The program will open a window displaying the 3D wireframe of the map.

Bonus Features
Interactive Controls:
- Rotation: Rotate the model along the x, y, or z axes.
- Zoom: Increase or decrease the scale of the rendered map.
- Translation: Move the map within the window.

Make sure your system supports the graphical environment required by minilibx.

---

## 🎨 Rendering and Transformation

### Rendering Algorithm
  The program utilizes **Bresenham's line algorithm** to efficiently render lines between the calculated points of the map. This ensures a smooth and continuous wireframe, even when working with large maps.
  
  ### Transformation Techniques
  - **Scaling:** Adjust the size of the rendered map.
  - **Rotation:** Rotate the map to view it from different angles.
  - **Translation:** Move the rendered image to center it or focus on a specific area.
  
  Bonus modules add refined controls for dynamic transformations based on real-time keyboard inputs.

---

## 📖 Bresenham's line algorithm

### Idea Behind Bresenham's Line Algorithm:

  - The objective is to draw a straight line between two points on a pixel grid efficiently.
  - Instead of using floating-point arithmetic, the algorithm uses simple integer operations to choose the best pixels that approximate the line.
  - It calculates the horizontal and vertical distances (dx and dy) between the endpoints to understand the line’s steepness.
  - Depending on whether the line is steep or shallow, the algorithm may swap the roles of x and y to handle both scenarios uniformly.
  - An error term is used to determine when to step in the secondary direction, ensuring that the drawn line remains as close as possible to the ideal straight line.
  - This approach is computationally efficient and well-suited for real-time graphics rendering in projects like fdf.

### Concept of Bresenham's Algorithm:

  Bresenham's algorithm incrementally determines the points of a raster display that should be selected to form a close approximation to a straight line between two points. It uses an error term to decide when to move in the y-direction as it steps through the x-coordinates (or vice versa for steep lines). This approach avoids floating-point arithmetic, relying solely on integer calculations, which makes it both efficient and well-suited for computer graphics applications.
  
  By handling lines with slopes of all magnitudes and directions through axis swapping and careful error management, Bresenham's algorithm ensures that lines are rendered accurately and efficiently on raster displays.


### Understanding the Key Concepts:

1. **The Need for Efficient Line Drawing**  

      When drawing a line on a raster display, the challenge is determining which pixels best represent the ideal straight-line path. Since pixels are discrete units, a continuous line must be approximated by selecting the closest possible pixel positions.


2. **Identifying and Categorizing Line Slopes**

      line can either be steep or shallow depending on its slope:

      - shallow line moves more horizontally than vertically.

      - steep line moves more vertically than horizontally.

      For shallow lines, the algorithm progresses along the x-axis, deciding when to step in the y-direction. For steep lines, it is more natural to progress along the y-axis instead.

      To ensure a consistent approach for all lines, the algorithm swaps the x and y calculations when a line is steep. This means that instead of stepping in the x-direction and adjusting y when necessary, it steps in the y-direction and adjusts x when necessary.


3. **Handling Steep and Shallow Lines**

      The algorithm starts by calculating the absolute difference in x-coordinates (dx) and y-coordinates (dy) of the two endpoints:

      - dx represents how far the line moves horizontally.

      - dy represents how far the line moves vertically.
        

      If dy is greater than dx, it means the line is steep. Instead of treating x as the primary axis of movement, the algorithm switches roles and treats y as the primary axis. This ensures that the algorithm consistently advances in small steps along the dominant direction while making adjustments to follow the ideal line path.

      **By swapping dx and dy, the algorithm:**

      - Keeps the logic uniform for all types of lines.

      - Avoids issues where one axis moves faster than the other, leading to uneven line drawing.

      - Ensures the line appears smooth and consistent regardless of its slope.



4. **The Error Term**

      Since pixels are discrete, the algorithm must decide when to move in the secondary direction (y for shallow lines, x for steep lines). This decision is controlled by an error term.

      **How the Error Term Works:**

      - The error term starts with an initial value based on the slope of the line.

      - As the algorithm moves along the primary axis (either x or y), the error accumulates.

      - If the error crosses a certain threshold (becomes greater than or equal to zero), it means the algorithm has deviated too far from the ideal line.

      - To correct this, the algorithm moves one step in the secondary direction and reduces the error to compensate.

      This error-based approach ensures that the drawn line stays as close as possible to the mathematically perfect straight line.

5. **Detailed Steps:**

      The initial value of the error term in Bresenham’s algorithm is calculated as: **error=2×dy − dx**

      **Error Adjustment**

      - After moving in the secondary direction (y for shallow lines, x for steep lines), the error term is adjusted by subtracting 2×𝑑𝑥 (or 2×𝑑𝑦 in steep cases).
      - This reduction brings the error term back within an acceptable range, ensuring that future steps stay close to the ideal line.

      **Primary Axis Movement Continues**

      - Regardless of whether a correction was made, the algorithm always increments in the primary axis direction (x for shallow lines, y for steep lines).
      - This ensures continuous progression toward the endpoint.
      
      **Error Increases Again**

      - The error term is then updated by adding 2×𝑑𝑦 (or 2×𝑑𝑥 for steep lines).
      - This accumulation keeps track of how much deviation is occurring and determines when the next correction should happen.

      
      **Repeat Until Endpoint is Reached**

      - The algorithm loops through this process—checking the error, making corrections if needed, and advancing pixel by pixel—until the start and end points are the same.
      - At this point, the full line has been drawn.


6. **Summary of Bresenham’s Algorithm**

      - Determine the dominant direction: Check whether the line is steep or shallow.

      - Swap x and y calculations if needed: This ensures a uniform approach for all slopes.

      - Use an error term to decide when to step in the secondary direction: This keeps the line accurate.

      - Move pixel by pixel, adjusting as necessary: This creates a smooth and visually appealing line.

      By efficiently managing pixel selection through integer calculations, Bresenham’s algorithm remains one of the most widely used techniques for rendering lines in computer graphics.
   


---

## 🌟 Achievements  

- Developed a complete 3D wireframe rendering engine.
- Implemented efficient algorithms for line drawing and 3D transformations.
- Enhanced user experience with interactive controls and dynamic rendering.
- Robust map file parsing and error handling.
- Integrated bonus features for advanced graphical manipulation.

---

## 🛡️ Makefile Targets  

- `make` – Compiles the program.
- `make bonus` – Compiles the bonus program.
- `make clean` – Removes object files.
- `make fclean` – Removes object files and the executable.
- `make re` – Cleans and recompiles everything.

---

## 📋 Objectives  

- Render a 3D wireframe representation of a landscape from a 2D map.
- Implement efficient line drawing and transformation algorithms.
- Provide interactive controls for real-time manipulation of the 3D model.
- Ensure robust error handling and memory management.
- Explore and implement advanced graphical techniques with the minilibx library.


---

## 🛡️ License 

This project is part of the 1337 curriculum. It is shared here for educational purposes and should not be used for plagiarism.
