import time
import os


class Bubble:
    
    tam = 10
    archivos = [100, 500, 1000, 2000, 3000, 4000,
                5000, 6000, 7000, 8000, 9000,
                10000, 20000, 30000, 40000, 50000,
                60000, 70000, 80000, 90000, 100000]
    
    def ejecutar(self):

        file = open('tiempo_bubble_sort_python.txt', "w")  
        for archivo in self.archivos:
        
            line = ""
            tam = 0 
            arr = []
            i = 0
            j = 0
            
            
            # RECORRER TXT Y RECOLECTAR DATOS 
            with open("../../1_preparacion_datos/generatedTestData/example_" + str(archivo) + ".txt") as file_in:
                for line in file_in:
                    arr.append(int(line))
                    tam += 1
         
            # BUBBLE SORT Y TIEMPO
            tiempo_ini = time.time()
            for i in range(tam):
                for j in range(0, tam - i - 1):
                    if arr[j] > arr[j + 1] :
                        arr[j], arr[j + 1] = arr[j + 1], arr[j]
            tiempo_fin = time.time()
            
            # IMPRIMIR TIEMPO
            file.write(str(archivo) + ' ' + str(round((float)(tiempo_fin - tiempo_ini), 5)) +"\n")
            print(str(archivo) + " " + str(round((float)(tiempo_fin - tiempo_ini), 5)))
        file.close()
        
objeto = Bubble()
objeto.ejecutar()