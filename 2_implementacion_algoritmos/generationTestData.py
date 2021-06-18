import numpy as np
import os
from tqdm import tqdm
save_path_generatedFiles = "generatedTestData"
if (os.path.isfile(save_path_generatedFiles)==False):
  os.mkdir(save_path_generatedFiles)

nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

dicPaths = {}
for namefile in nameFiles_idx:
  dicPaths.update({namefile:'generatedTestData/example_'+str(namefile)+".txt"})
  #create specific file

  f = open(dicPaths[namefile], "w")
    #generar un nro aleatorio de 1 y 100'000
  for i in tqdm(range(1,namefile+1)):
    f.write(str(np.random.randint(1,100000,1)[0])+"\n")
  f.close()
