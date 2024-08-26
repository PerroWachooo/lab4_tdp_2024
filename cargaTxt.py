import numpy as np
from matplotlib import pyplot as plt

y = np.loadtxt("Salida.txt",dtype=np.float64) # volviendo a cargar la imagen.txt que esta en el disco
y=y.reshape((256,256)) # pasa de ser 1d a 2d
plt.gray() # para que se vea en escala de grises
plt.imshow(y)
plt.show()
