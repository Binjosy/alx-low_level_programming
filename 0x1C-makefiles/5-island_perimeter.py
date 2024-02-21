#!/usr/bin/python3
"""Defines an island perimeter measuring func."""

def island_perimeter(grid):
    """Return the perimeter of an island.

    The grid represents water by 0 and land by 1.

    args:
        grid (list): A list of list of intigers representing an island
    
    Returns:
       The perimeter of the island defined in grid
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for b in range(height):
        for y in range(width):
            if grid[b][y] == 1:
                size += 1
                if (y > 0 and grid[b][y - 1] == 1):
                    edges += 1
                    if (b > 0 and grid[b - 1][y] == 1):
                        edges += 1
   return size * 4 - edges * 2                     
