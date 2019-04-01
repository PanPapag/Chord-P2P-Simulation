# Chord-P2P-Simulation-
In this section, a simple form of Chord is implemented, the most known type of distributed hash table. Even if Chord is used as a distributed network system, we will implement it in a computer using C programming language. All information about Chord are presented in the following link: https://pdos.csail.mit.edu/papers/ton:chord/paper-ton.pdf . You have to read up to the page 6 to understand its functionality.  
### Installing

Download source code by typing:

```
git clone https://github.com/PanPapag/Ecosystem-Simulation.git
```
### Compilation

While being in project directory, compile by typing:   

```
make
```

## Running 

A new directory `build` has been created. Cd to build by typing `cd build` . After that, run ecosystem simulation simply by typing:

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

