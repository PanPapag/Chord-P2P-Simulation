# Chord-P2P-Simulation-
In this section, a simple form of Chord is implemented, the most known type of distributed hash table. Even if Chord is used as a distributed network system, we will implement it in a computer using C programming language. All information about Chord are presented in the following link: https://pdos.csail.mit.edu/papers/ton:chord/paper-ton.pdf . You have to read up to the page 6 to understand its functionality.  

We define an abstract data type DHT that implements Chord which has the following interface:

- ```void initialize(void)```: This function creates a Chord network with as many nodes as the value of a constant MAXNODENUMBER.
- ```void insert(nodeType, keyType, valueType)```: This function asks a node of type nodeType to insert a (key, value) pair of types (keyType, valueType) into the network.
- ```void delete(nodeType, keyType)```: This function asks a node of type nodeType to delete the (key, value) pair that corresponds to a given key of type keyType from the network.
- ```valueType lookup(nodeType, keyType)```: This function asks a node of type nodeType to find the value of type valueType that corresponds to a given key of type keyType in the network.
- ```void print()```: This function asks every node to print its identifier and the (key, value) pairs it stores.

### Installing

Download source code by typing:

```
git clone https://github.com/PanPapag/Chord-P2P-Simulation-.git
```
### Compilation

While being in project directory, compile by typing:   

```
make
```

## Running 

A new directory `build` has been created. Cd to build by typing `cd build` . After that, run Chord System simulation simply by typing:

```
./Chord
```
Select the option 3: Construct a Chord network giving an input file. 
For your help Ι have created a .txt file with random 4-bit alpharithmetic codes.
This 4-bit codes are being given to the hash function in order to generate the Ip's of each node of the Chord network.
 

### Clean

While being in project directory, delete all objects files and executable by typing:   

```
make clean
```

