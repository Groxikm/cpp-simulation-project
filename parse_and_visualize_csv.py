import csv
import sys
import pygame
import math
import threading

# Simulation parameters
time_step = 120
gravity = -9.8
reaction = 0.98
ceiling = True
screen_width = 800
screen_height = 600

if len(sys.argv) != 2:
    print("Usage: python visualize.py <csv_file>")
    sys.exit(1)

csv_file = sys.argv[1]

pygame.init()
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Mass Cell Simulation Visualization")
clock = pygame.time.Clock()

cell_data = {}
with open(csv_file, 'r') as file:
    reader = csv.reader(file)
    headers = next(reader)
    for row in reader:
        if len(row) < 6:
            print(f"Skipping incomplete row: {row}")
            continue
        try:
            cell_id = int(row[0])
            mass = float(row[1])
            x = float(row[2])
            y = float(row[3])
            speed = float(row[4])
            direction = float(row[5])
            if cell_id not in cell_data:
                cell_data[cell_id] = []
            cell_data[cell_id].append((x, y, speed, direction, mass))
        except ValueError as e:
            print(f"Error parsing row {row}: {e}")
            continue

# Visualization parameters
selected_cell_index = 0
selected_cell_id = list(cell_data.keys())[selected_cell_index]
num_cells = len(cell_data)
num_frames = len(next(iter(cell_data.values())))
time_index = 0

# This variable will be used to indicate a key press
key_pressed = False
key_pressed_lock = threading.Lock()

def handle_key_presses():
    global selected_cell_index, selected_cell_id, key_pressed
    while True:
        with key_pressed_lock:
            if key_pressed:
                key_pressed = False
                selected_cell_index = (selected_cell_index + 1) % num_cells
                selected_cell_id = list(cell_data.keys())[selected_cell_index]

key_thread = threading.Thread(target=handle_key_presses)
key_thread.daemon = True
key_thread.start()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_n:
            with key_pressed_lock:
                key_pressed = True

    screen.fill((0, 0, 0))

    for cell_id, cell_history in cell_data.items():
        if time_index < len(cell_history):
            x, y, speed, direction, mass = cell_history[time_index]
            color = (255, 0, 0) if cell_id == selected_cell_id else (0, 255, 0)
            pygame.draw.circle(screen, color, (int(x), int(y)), 10)

            if cell_id == selected_cell_id:
                font = pygame.font.Font(None, 36)
                text_id = font.render(f"ID: {cell_id}", True, (255, 255, 255))
                screen.blit(text_id, (10, 10))
                text_x = font.render(f"X: {x:.2f}", True, (255, 255, 255))
                screen.blit(text_x, (10, 50))
                text_y = font.render(f"Y: {y:.2f}", True, (255, 255, 255))
                screen.blit(text_y, (10, 90))
                text_speed = font.render(f"Speed: {speed:.2f}", True, (255, 255, 255))
                screen.blit(text_speed, (10, 130))
                vx = speed * math.cos(direction)
                vy = speed * math.sin(direction)
                text_vx = font.render(f"Vx: {vx:.2f}", True, (255, 255, 255))
                screen.blit(text_vx, (10, 170))
                text_vy = font.render(f"Vy: {vy:.2f}", True, (255, 255, 255))
                screen.blit(text_vy, (10, 210))
                text_mass = font.render(f"Mass: {mass:.2f}", True, (255, 255, 255))
                screen.blit(text_mass, (10, 250))

    pygame.display.flip()
    clock.tick(time_step)

    time_index += 1
    if time_index >= num_frames:
        time_index = 0

pygame.quit()
