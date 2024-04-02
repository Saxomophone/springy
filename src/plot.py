import matplotlib.pyplot as plt
import csv

with open ('generated/spring.csv', 'r') as file:
  reader = csv.reader(file, delimiter=',')

  velocity = [];
  time = [];

  for row in reader:
    if row[0] == 'time':
      continue
    time.append(row[0])
    velocity.append(row[1])

plt.figure(figsize=(8,6))
plt.plot(time, velocity)
plt.xlabel('Time')
plt.ylabel('Velocity')
plt.title('Spring Velocity')

plt.grid(True)
plt.savefig('generated/spring_velocity.png')