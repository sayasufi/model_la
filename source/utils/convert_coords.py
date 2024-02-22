import numpy as np


def geographic_to_local(lat, lon):
    """Географические в локальные"""
    x = lon * 20037508.34 / 180
    y = np.log(np.tan((90 + lat) * np.pi / 360)) / (np.pi / 180)
    y = y * 20037508.34 / 180
    return x, y


def local_to_geographic(x, y):
    """Локальные в географические"""
    lon = (x / 20037508.34) * 180
    lat = (y / 20037508.34) * 180
    lat = 180 / np.pi * (2 * np.arctan(np.exp(lat * np.pi / 180)) - np.pi / 2)
    return lat, lon
