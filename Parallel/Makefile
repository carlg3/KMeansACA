# Makefile for compiling 'kmeans_parallel' program

TARGET = kmeans_parallel

SRCS = Centroid.cpp Cluster.cpp kmeans_parallel.cpp Point.cpp Tupla.cpp

CXX = mpic++ 

$(TARGET): 
	$(CXX) $(SRCS) -o $(TARGET)

clean:
	@echo "Pulizia del file.."
	rm $(TARGET)
