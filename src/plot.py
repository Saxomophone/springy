import matplotlib.pyplot as plt
import csv

with open ('generated/spring.csv', 'r') as file:
  reader = csv.reader(file, delimiter=',')

  velocity = []
  length = []
  time = []

  for row in reader:
    if row[0] == 'time':
      continue
    time.append(int(row[0]))
    velocity.append(round(float(row[1]), 3))
    length.append(round(float(row[2]), 3))


plt.plot(time, velocity, '-b', label='Velocity')
plt.xlabel('Time (s)')
plt.ylabel('Velocity (m/s)')
plt.title('Velocity of a spring over time')
plt.grid(True)
plt.savefig('generated/spring_velocity.png')