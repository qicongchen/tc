import numpy as np
import cPickle
f = open('model.pckl', 'rb')
model = cPickle.load(f)
f.close()
W = model.W
np.savetxt('coeff.txt', W)
