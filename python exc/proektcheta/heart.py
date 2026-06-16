import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

N_POINTS = 500
time = np.linspace(-5, 5, N_POINTS)

heart = np.abs(time) ** (2/3) + 0.9 * np.sin(50 * time) * np.sqrt(25 - time ** 2)

fig, ax = plt.subplots(figsize=(10, 6))

ax.set_xlim(min(time), max(time))
ax.set_ylim(min(heart) - 0.5, max(heart) + 0.5)
ax.set_facecolor('#F5F5DC')

ax.set_title('Animating the Heart Curve')
ax.set_xlabel('$x$')
ax.set_ylabel('$y$')
ax.grid(True)
ax.set_aspect('equal', adjustable='box')

line, = ax.plot(time[0:1], heart[0:1], color='red', linewidth=2)

N_FRAMES = 200

def update(frame):
    end_index = int(N_POINTS * (frame + 1) / N_FRAMES)

    line.set_xdata(time[:end_index])
    line.set_ydata(heart[:end_index])

    return line,

ani = animation.FuncAnimation(
    fig=fig,
    func=update,
    frames=N_FRAMES,
    interval=30,
    blit=True,
    repeat=False
)

plt.show()