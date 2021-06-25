import array
import os
import sys
from tqdm import tqdm  
import matplotlib.pyplot as plt
import numpy as np

# (cmd) python -m pip install numpy
# (cmd) pip install tqdm
# (cmd) python -m pip install -U pip setuptools
# (cmd) python -m pip install matplotlib

line = ""
x = []
y_python = []
y_cpp = []
y_java = []

# RECORRER TXT Y RECOLECTAR DATOS 
with open("bubble_sort_python" + ".txt") as file_in:
    for line in file_in:
        x.append(int(line[0:line.index(",")]))
        y_python.append(float(line[line.index(",") + 1:len(line)]))
        
with open("bubble_sort_cpp" + ".txt") as file_in:
    for line in file_in:
        y_cpp.append(float(line[line.index(",") + 1:len(line)]))
        
with open("bubble_sort_java" + ".txt") as file_in:
    for line in file_in:
        y_java.append(float(line[line.index(",") + 1:len(line)]))

# EJES, LEYENDA, GRAFICAR, GUARDAR
plt.plot(x, y_python, label='python')
plt.plot(x, y_cpp, label='c++')
plt.plot(x, y_java, label='java')

plt.xlabel('Data Procesada')
plt.ylabel('Tiempo (Segundos)')
plt.title("Bubble Sort")
plt.legend()
plt.grid()

plt.savefig('grafica_bubble_sort.png')
plt.show()
