import csv
import sys
import pygame
import math

# Check for correct usage
if len(sys.argv) != 2:
    print("Usage: python visualize.py <csv_file>")
    sys.exit(1)

# CSV file path
csv_file = sys.argv[1]

# Pygame setup
pygame.init()
screen_width, screen_height = 800, 600
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Mass Cell Simulation Visualization")
clock = pygame.time.Clock()

# Read CSV data
cell_data = {}
with open(csv_file, 'r') as file:
    reader = csv.reader(file)
    headers = next(reader)
    for row in reader:
        cell_id = int(row[0])
        mass = float(row[1])
        x = float(row[2])
        y = float(row[3])
        speed = float(row[4])
        direction = float(row[5])
        if cell_id not in cell_data:
            cell_data[cell_id] = []
        cell_data[cell_id].append((x, y, speed, direction))

# Extract number of frames and cells
num_frames = max(len(history) for history in cell_data.values())
num_cells = len(cell_data)

# Visualization loop
running = True
time_index = 0
cell_radius = 5

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 0))  # Clear screen

    # Draw each cell at the current time_index
    for cell_id, cell_history in cell_data.items():
        if time_index < len(cell_history):
            x, y, speed, direction = cell_history[time_index]
            pygame.draw.circle(screen, (0, 255, 0), (int(x), int(y)), cell_radius)

    pygame.display.flip()  # Update the display

    clock.tick(60)  # Cap the frame rate

    time_index += 1
    if time_index >= num_frames:
        time_index = 0  # Loop the animation

pygame.quit()
