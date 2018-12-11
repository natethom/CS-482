# kf.py updated file for robot estimation assignment
# pset[3]
# (C) 2017 David Feil-Seifer


import numpy as np
import math
from scipy import stats
import scipy.stats

# kf_update: update state estimate [u, sigma] with new control [xdot] and measurement [z]
# 	parameters:
#			u : 2x1 vector with state estimate (x) at time t-1 and control (xdot) at time t
#			sigma: 2x2 matrix with covariance at time t-1
#			z (int): observed (uncertain) measurement of state (x) at time t
#	returns: [u sigma] updated state with estimate at time t

def kf_update(u, sigma, z):

    F = np.matrix('1 1; 0 1')

    H = np.matrix('1 0')

    I = np.matrix('1 0; 0 1')

    G = np.matrix('1; .5')

    sigma_x = (G * G.T)

    sigma_z = 25

    K_tplus1 = ((((F * sigma) * F.T) + sigma_x) * H.T) * np.linalg.inv((H*(((F*sigma)*F.T) + sigma_x)* H.T) + sigma_z)

    u_tplus1 = (F*u) + (K_tplus1 * (z - ((H * F) * u)))

    sigma_tplus1 = ((I - (K_tplus1 * H)) * ((F * sigma) * F.T) + sigma_x)

    return [u_tplus1, sigma_tplus1]


# door_update: update estimate of door locations
# 	parameters:
#			u : 2x1 vector with state estimate (x) at time t-1 and control (xdot) at time t-1
#			sigma: 2x2 matrix with covariance at time t-1
#			d (binary): door sensor at time t-1
#			door_dist (array of size 10): probability (0..1) that a door exists at each location (0..9)
#	returns: [door_dist] updated door distribution

def door_update(u, sigma, d, door_dist):

    current_door = (int)(u[0] / 100)

    if current_door < 0 or current_door > 9:
        return door_dist

    probability_true_given_d = 0.6
    probability_not_true_given_not_d = 0.8

    probability_d = door_dist[current_door]

    probability_true = probability_true_given_d * probability_d + (
    (1 - probability_not_true_given_not_d) * (1 - probability_d))

    if(d == 1):
        door_dist[current_door] = probability_true_given_d * probability_d / (
        probability_true)
    else:
        door_dist[current_door] = 1 - (probability_not_true_given_not_d * (
        (1 - probability_d) / (1 - probability_true)))

    return door_dist
