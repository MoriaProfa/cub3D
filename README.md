*This project has been created as part of the 42 curriculum by astehl, bgebetsb.*

# **Description**
42's project "cub3D" is about creating a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective inspired by the game "Wolfenstein 3D" (1992). It uses the miniLibX graphics library and implements efficient ray-casting to ensure the player can smoothly look around and navigate through a 3D maze with different textured walls.  
The goal of that project is to deepen the knowledge in the use of C, basic algorithms, information research, rigor and some applications of mathematics. It also should improve the skills in graphic design areas like windows, color, fill shapes, events etc..  

# **Instructions**
## Compilation
After cloning the repository the project needs to compile the source files using the Makefile with the cc compiler, including the libft's Makefile, the miniLibX library and the following flags: -Wall, -Wextra and -Werror.  
The Makefile must not perform unnecessary relinking and contain at least the rules $(NAME), all, clean, fclean and re. If a bonus of the project is submitted, there must be a bonus rule included in the Makefile, too.
### TLDR: Compilation (after cloning the repository)
```bash
# Compile mandatory version
make

# Compile bonus version
make bonus

# Clean object and dependency files
make clean

# Full clean (incl. executables and archives)
make fclean

# Recompile
make re
```  

## Execution
After compiling the program named cub3D must expect a file with configuration elements and a map in format *.cub to be able to be executed properly. Some already prepared *.cub files can be found in the scenes folder.    
```bash
# Run mandatory version
./cub3D scenes/minimalist.cub

# Run bonus version
./cub3D_bonus scenes/minimalist.cub
```  

## Configuration and map file format (*.cub)
The *.cub file needs to contain one unique texture for each wall depending on which side the wall is facing (North, East, South, West), two colors (Ceiling, Floor) in R,G,B format with values ranging from 0-255 and as the last element always the map of the maze.  
Each configuration element in the *.cub file needs to start with its own type identifier (`NO`, `EA`, `SO`, `WE`, `C`, `F`). The map must be composed of only 6 possible characters: `0` for an empty space, `1` for a wall and `N`/`E`/`S`/`W` for the player's starting position and spawning orientation. The map must be surrounded by walls, have exactly one player spawn point and empty lines in between the map element are not tolerated.
### TLDR: Configuration and map file format (*.cub)
**Configuration elements**
- `NO`/`EA`/`SO`/`WE`- Unique paths to the texture for each wall direction
- `C`- Ceiling color in R,G,B format (values 0-255)
- `F`- Floor color in R,G,B format (values 0-255)
    
**Map rules**
- Map characters:
    - `0`- Empty space
    - `1`- Wall
    - `N`/`E`/`S`/`W` - Player starting position and spawn orientation  
- needs to be surrounded by walls
- only one player spawn position
- empty lines are invalid

# **Resources**
## Markdown
- [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)
## MiniLibX
- miniLibX man pages
- [42 Docs - MiniLibX Tutorial](https://harm-smits.github.io/42docs/libs/minilibx)
## Ray-Casting
- 
## AI Usage
AI was used to clarify Markdown syntax and formatting rules for the README.md file.