from environs import Env

# Максимальные скорости и ускорения
env = Env()
env.read_env(".env")
MAX_W_ROLL = int(env("MAX_W_ROLL"))
MAX_W_PITCH = int(env("MAX_W_PITCH"))


def leveling(roll, pitch, dt):
    """Автопилот, который приводит самолет в горизонтальное положение"""

    if roll <= -MAX_W_ROLL / dt:
        w_roll = MAX_W_ROLL
    elif roll >= MAX_W_ROLL / dt:
        w_roll = -MAX_W_ROLL
    else:
        w_roll = -roll / dt

    if pitch <= -MAX_W_PITCH / dt:
        w_pitch = MAX_W_PITCH
    elif pitch >= MAX_W_PITCH / dt:
        w_pitch = -MAX_W_PITCH
    else:
        w_pitch = -pitch / dt

    return w_roll, w_pitch
