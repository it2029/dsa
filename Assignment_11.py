import heapq
import random
import time
import os

W, H = 10, 6
maze = [[0 if random.random() > 0.2 else 1 for _ in range(W)] for _ in range(H)]
start, goal = (0, 0), (W - 1, H - 1)
maze[start[1]][start[0]] = 0
maze[goal[1]][goal[0]] = 0


def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


def astar(maze, start, goal):
    heap = [(0, start)]
    came_from = {start: None}
    g = {start: 0}

    while heap:
        _, current = heapq.heappop(heap)

        if current == goal:
            path = []
            while current:
                path.append(current)
                current = came_from[current]
            return list(reversed(path))

        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nx, ny = current[0] + dx, current[1] + dy

            if 0 <= nx < W and 0 <= ny < H and maze[ny][nx] == 0:
                new_g = g[current] + 1

                if (nx, ny) not in g or new_g < g[(nx, ny)]:
                    g[(nx, ny)] = new_g
                    heapq.heappush(
                        heap,
                        (new_g + heuristic((nx, ny), goal), (nx, ny))
                    )
                    came_from[(nx, ny)] = current

    return None


def show(maze, agent):
    os.system('cls' if os.name == 'nt' else 'clear')

    for y in range(H):
        row = ""
        for x in range(W):
            if (x, y) == agent:
                row += "A "
            elif (x, y) == goal:
                row += "G "
            elif maze[y][x] == 1:
                row += "■ "
            else:
                row += ". "
        print(row)

    time.sleep(0.3)


agent = start

while agent != goal:
    path = astar(maze, agent, goal)

    if not path:
        print("No path found!")
        break

    for step in path[1:]:
        if random.random() < 0.2:
            ox, oy = random.randint(0, W - 1), random.randint(0, H - 1)
            if (ox, oy) not in (agent, goal):
                maze[oy][ox] = 1

        agent = step
        show(maze, agent)

        if agent == goal:
            print("Reached Goal!")
            break
