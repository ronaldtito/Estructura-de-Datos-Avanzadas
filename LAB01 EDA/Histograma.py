import matplotlib.pyplot as plot

def plot_dimension(distances,dimension):
  plot.hist(x =distances, bins=24,edgecolor='black')
  plot.title('Histograma de distancias entre puntos con dimension '+str(dimension))
  plot.xlabel('Distancias')
  plot.ylabel('Frecuencias')
  plot.xlim(0)
  plot.grid(alpha=1)
  plot.show()


dimension = [2,10,50,100,500,1000,2000,5000]

for i in range (len(dimension)):
  distances = []
  name_file = "dimension_" + str(dimension[i]) + ".txt"
  with open(name_file) as file:
    for line in file:
      distances.append(float(line))
  plot_dimension(distances,dimension[i])