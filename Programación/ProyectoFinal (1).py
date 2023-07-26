import numpy as np
from scipy.integrate import odeint
from pylab import figure, plot, xlabel, legend, title, savefig
import matplotlib.pyplot as plt
def vectorfield(w, t, p): #encontré esta forma de acoplar los parámetros en la referencia 1
     x1, y1, x2, y2 = w #variables a resolver
     m1, m2, k, L1, L2, g, F, a, b = p #parámetros

    
     f = [y1,
         -b*y1-(g/L1)*x1-(k/m1)*(x1-x2)+(F/m1)*(np.cos(a*t)),
         y2,
         -b*y2-(g/L2)*x2+(k/m2)*(x1-x2)]
     return f

N=6000
t=np.linspace(0,25,N)

#Parámetros
m1 = 1.0 #masas
m2 = 1.0
k = 1.0 #constante elástica
L1 = 1.0 #largo de los péndulos
L2 = 1.0
g=9.81 #aceleración de gravedad

F=0 #amplitud del término de forzamiento
a=0 #frecuencia de forzamiento

b=0 #coeficiente de disipación


#Condiciones iniciales
x1 = np.pi/3
y1 = 0
x2 = np.pi/3
y2 = 0.0

#parámetros y condiciones iniciales para las figuras:
#1. x1=pi/3; x2=pi/3; F,a,b=0             t=np.linspace(0,25,N)
#2. x1=pi/3; x2=-pi/3
#3. x1=pi/3: x2=0                     t=np.linspace(0,50,N)
#4. x1=pi/3; x2=pi/6
#5. x1=pi/3; x2=pi/6; b=0.5; F=1, a=1
#6. x1=pi/3; x2=pi/6; b=0.5; F=1, a=3.2


#odeint
p = [m1, m2, k, L1, L2, g, F, a, b]
w0 = [x1, y1, x2, y2]
solucion = odeint(vectorfield, w0, t, args=(p,))
#soluciones de cada péndulo
x1data=solucion[:,0]
v1data=solucion[:,1]
x2data=solucion[:,2]
v2data=solucion[:,3]


#figuras
figure(1)

plt.plot(t,x1data,'r')
plt.plot(t,x2data,'c')
plt.xlabel('Tiempo s', fontsize=20)
plt.ylabel('Posición rad', fontsize=20)
#plt.title('Posición angular de los péndulos en función del tiempo',fontsize=12)
plt.legend((r'$\Theta_1$', r'$\Theta_2$'))
savefig('Modo1.pdf')

plt.show()