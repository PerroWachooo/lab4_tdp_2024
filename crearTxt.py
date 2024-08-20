
import scipy
import numpy as np
from matplotlib import pyplot as plt
from skimage.transform import resize
from scipy import signal


x=scipy.misc.face() # la imagen de prueba

x=np.array(x,dtype=np.float64) # asegurandose que son float
x=x[:,:,0] # la tercera dimension da cuenta de los tres colores rgb, dejamos solo el rojo 
x=x.reshape(768, 1024)
x=x/np.max(x) # para que los numero queden entre 0 y 1 el algoritmo funciona mejor asi
x=resize(x,(256,int(256*1024/768))) # cambiando el tamaño segun regla de 3
x=x[:,:256] # recortando
y=np.array(x)
K= np.ones(25)
K=np.reshape(K,(5,5))
x = signal.convolve2d(x,K,mode="same")
# generamos un archivo con los valores de la imagen 
x=x.reshape(256*256) # aplanando los datos
x=x+np.random.normal(0,0.8,x.size)
np.savetxt("image.txt", x, fmt="%1.12lf")

#mostramos la imagen
plt.gray() # en escala de grises
plt.imshow(np.reshape(x,(256,256)))
plt.show()
plt.imshow(y)
plt.show()
