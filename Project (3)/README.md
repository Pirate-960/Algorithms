# ChessPiecePlacementGA - Genetic Algorithm for Chess Piece Placement

## Overview

The `ChessPiecePlacementGA` program implements a **Genetic Algorithm (GA)** to find an optimal placement of chess pieces on an 8x8 chessboard. The goal is to minimize conflicts between the pieces, such as multiple pieces being in a position to attack each other. The algorithm places **Queens**, **Rooks**, **Bishops**, and **Knights** in various configurations, evolving solutions over multiple generations to improve the placement.

## How It Works

### Genetic Algorithm Basics

A **Genetic Algorithm** is a search heuristic that mimics the process of natural selection. This algorithm reflects the process of natural evolution, where the fittest individuals are selected for reproduction in order to produce offspring of the next generation.

The key components of the Genetic Algorithm in this program are:

1. **Population Initialization**: 
   - The algorithm starts with a randomly generated population of chessboard configurations (chromosomes).

2. **Selection**: 
   - Two parent configurations are selected randomly from the population to produce offspring.

3. **Crossover**: 
   - The offspring inherit genes from both parents, with a probability defined by the crossover rate.

4. **Mutation**: 
   - Random changes are introduced to the offspring's genes to maintain diversity within the population, controlled by the mutation rate.

5. **Fitness Evaluation**: 
   - Each configuration's fitness is evaluated based on the number of conflicts between chess pieces. The goal is to minimize these conflicts.

6. **Evolution**: 
   - Over multiple generations, the population evolves to produce configurations with fewer conflicts.

### Chess Pieces and Conflict Calculation

- **Queens (Q)**, **Rooks (R)**, **Bishops (B)**, and **Knights (K)** are placed on the board.
- The program calculates the number of conflicts for each piece by checking for other pieces that it can attack.
- The fitness of a board configuration is inversely proportional to the number of conflicts.

### Program Structure

- **`initializePopulation()`**: Creates an initial set of random board configurations.
- **`evolvePopulation()`**: Applies selection, crossover, and mutation to evolve the population.
- **`evaluateFitness()`**: Calculates the fitness of each configuration based on conflicts.
- **`getBestSolution()`**: Identifies the configuration with the highest fitness.
- **`printBoard()`**: Displays the chessboard configuration.

## Getting Started

### Prerequisites

- **Java**: Make sure you have Java installed on your machine. You can download it from the [official website](https://www.java.com/).

### Running the Program

1. **Clone or Download** this repository.
2. **Compile** the `ChessPiecePlacementGA.java` file:
   ```bash
   javac ChessPiecePlacementGA.java
