import matplotlib.pyplot as plt
import csv

# Function to plot line graph
def plot_line(x, y, title, x_label, y_label, ax):
    ax.plot(x, y, '-b', label=title)
    ax.set_xlabel(x_label)
    ax.set_ylabel(y_label)
    ax.set_title(title)
    ax.grid(True)

# Read data from CSV file
with open('generated/spring.csv', 'r') as file:
    reader = csv.reader(file, delimiter=',')

    velocity = []
    length = []
    time = []

    for row in reader:
        if row[0] == 'time':
            continue
        time.append(float(row[0]))
        velocity.append(round(float(row[1]), 3))
        length.append(round(float(row[2]), 3))

# Create a figure with two subplots
fig, axs = plt.subplots(2, 1, figsize=(10, 10))

# Plot velocity
plot_line(time, velocity, 'Velocity of a spring over time', 'Time (s)', 'Velocity (m/s)', axs[0])

# Plot length
plot_line(time, length, 'Length of a spring over time', 'Time (s)', 'Length (m)', axs[1])

# Adjust layout for better spacing
plt.tight_layout()

# Save the figure
plt.savefig('generated/spring_plots.png')