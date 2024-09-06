# Chess Piece Placement Genetic Algorithm

## Table of Contents
1. [Overview](#overview)
2. [Problem Statement](#problem-statement)
3. [Genetic Algorithm Approach](#genetic-algorithm-approach)
4. [Features](#features)
5. [Prerequisites](#prerequisites)
6. [Installation and Usage](#installation-and-usage)
7. [Code Structure](#code-structure)
8. [Algorithm Details](#algorithm-details)
9. [Configuration](#configuration)
10. [Output Explanation](#output-explanation)
11. [Performance Considerations](#performance-considerations)
12. [Limitations and Future Improvements](#limitations-and-future-improvements)
13. [Contributing](#contributing)
14. [License](#license)

## Overview

This project implements a Genetic Algorithm (GA) to solve the complex problem of placing multiple chess pieces on an 8x8 chessboard with minimal conflicts. The algorithm evolves a population of potential solutions over multiple generations to find an optimal or near-optimal placement of chess pieces.

## Problem Statement

The goal is to place 4 Queens, 2 Rooks, 2 Bishops, and 2 Knights on an 8x8 chessboard in such a way that the number of conflicts (pieces threatening each other) is minimized. This is a challenging combinatorial optimization problem with a vast search space, making it suitable for a genetic algorithm approach.

## Genetic Algorithm Approach

Genetic Algorithms are inspired by the process of natural selection. They work with a population of potential solutions (chromosomes) and evolve them over generations using genetic operators like selection, crossover, and mutation. In this project:

- Each chromosome represents a complete board configuration.
- Fitness is determined by the number of conflicts (fewer conflicts = higher fitness).
- Parents are selected randomly for breeding.
- Crossover combines parent chromosomes to create offspring.
- Mutation introduces random changes to maintain genetic diversity.

## Features

- Genetic Algorithm implementation for chess piece placement
- Configurable number of generations and population size
- Support for multiple chess piece types: Queens, Rooks, Bishops, and Knights
- Fitness evaluation based on the number of conflicts between pieces
- Crossover and mutation operations for evolving the population
- Visual representation of the best solution found

## Prerequisites

To run this project, you need:

- Java Development Kit (JDK) 8 or higher
- A Java IDE (e.g., IntelliJ IDEA, Eclipse) or command-line tools to compile and run Java programs

## Installation and Usage

1. Clone the repository or download the `ChessPiecePlacementGA.java` file.

2. Compile the Java file:
   ```
   javac ChessPiecePlacementGA.java
   ```

3. Run the compiled program:
   ```
   java ChessPiecePlacementGA
   ```

4. When prompted, enter:
   - The number of generations to run the algorithm
   - The number of chromosomes (population size) for each generation

5. The program will display the fitness of each chromosome in the population for each generation and finally show the best solution found.

## Code Structure

The `ChessPiecePlacementGA` class contains the following key components:

- `main`: Entry point of the program, handles user input and runs the GA
- `initializePopulation`: Creates the initial population of random chromosomes
- `evolvePopulation`: Performs one generation of evolution
- `selectParent`, `crossover`, `mutate`: Genetic operators
- `evaluateFitness`, `countConflicts`: Fitness evaluation functions
- `printBoard`, `printFitness`: Output functions

## Algorithm Details

1. **Chromosome Representation**: Each chromosome is a char array of length 64 (8x8 board), where each character represents a piece or an empty square.

2. **Population Initialization**: Random chromosomes are generated ensuring the correct number of each piece type.

3. **Fitness Evaluation**: 
   - Fitness = 1 / (1 + number of conflicts)
   - Conflicts are counted for each piece based on chess movement rules

4. **Parent Selection**: Parents are selected randomly from the population.

5. **Crossover**: 
   - Uniform crossover is used
   - Each gene has a CROSSOVER_RATE chance of being inherited from the first parent, otherwise from the second parent

6. **Mutation**: 
   - Each gene has a MUTATION_RATE chance of being randomly changed to a different piece or empty square

7. **Termination**: The algorithm runs for a fixed number of generations specified by the user.

## Configuration

You can modify the following constants in the `ChessPiecePlacementGA` class to adjust the algorithm's behavior:

- `BOARD_SIZE`: Size of the chessboard (default: 8x8)
- `NUM_QUEENS`, `NUM_ROOKS`, `NUM_BISHOPS`, `NUM_KNIGHTS`: Number of each type of chess piece
- `MUTATION_RATE`: Probability of mutation for each gene in a chromosome (default: 0.1)
- `CROSSOVER_RATE`: Probability of crossover between parent chromosomes (default: 0.8)

## Output Explanation

The program outputs:
1. Fitness scores for each chromosome in every generation
   - Fitness ranges from 0 to 1, with 1 being a perfect solution (no conflicts)
2. A visual representation of the best solution found, where:
   - 'Q' represents a Queen
   - 'R' represents a Rook
   - 'B' represents a Bishop
   - 'K' represents a Knight
   - 'E' represents an empty square

## Performance Considerations

- **Time Complexity**: O(G * P * N^2), where G = number of generations, P = population size, N = board size
- **Space Complexity**: O(P * N^2), where P = population size, N = board size
- Performance can be improved by optimizing the fitness evaluation function, which is the most computationally intensive part of the algorithm

## Limitations and Future Improvements

Limitations:
- The algorithm may not always find the optimal solution, especially for complex arrangements or with a small number of generations
- The random nature of genetic algorithms means that results may vary between runs
- The current implementation uses a simple random parent selection method, which may not be optimal

Future Improvements:
- Implement more sophisticated selection methods (e.g., tournament selection, roulette wheel selection)
- Add support for different board sizes and piece configurations
- Optimize the fitness evaluation function for better performance
- Implement parallelization to speed up the evolution process
- Add visualization of the evolution process over generations
- Implement elitism to ensure the best solutions are not lost between generations
- Experiment with adaptive mutation and crossover rates

## Contributing

Contributions to improve the Chess Piece Placement Genetic Algorithm are welcome. Please feel free to submit pull requests or open issues to suggest improvements or report bugs.

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).
