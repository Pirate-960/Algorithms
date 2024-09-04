import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class ChessPiecePlacementGA {
    // Constants for board size and number of each type of chess piece
    private static final int BOARD_SIZE = 8;
    private static final int NUM_QUEENS = 4;
    private static final int NUM_ROOKS = 2;
    private static final int NUM_BISHOPS = 2;
    private static final int NUM_KNIGHTS = 2;

    // Constants representing chess piece symbols
    private static final char QUEEN = 'Q';
    private static final char ROOK = 'R';
    private static final char BISHOP = 'B';
    private static final char KNIGHT = 'K';
    private static final char EMPTY = 'E';

    // Mutation and crossover rates, and a Random object for random number generation
    private static final double MUTATION_RATE = 0.1;
    private static final double CROSSOVER_RATE = 0.8;
    private static final Random random = new Random();

    public static void main(String[] args) {
        // User input for number of generations and chromosomes
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of generations: ");
        int numGenerations = scanner.nextInt();
        System.out.print("Enter number of chromosomes: ");
        int numChromosomes = scanner.nextInt();

        // Initialize the population
        List<char[]> population = initializePopulation(numChromosomes);

        // Evolve the population over multiple generations
        for (int generation = 0; generation < numGenerations; generation++) {
            System.out.println("Generation " + (generation + 1));
            population = evolvePopulation(population);
            printFitness(population);
        }

        // Print the best solution found
        char[] bestSolution = getBestSolution(population);
        printBoard(bestSolution);
        scanner.close();
    }

    // Initialize the population with random chromosomes
    private static List<char[]> initializePopulation(int numChromosomes) {
        List<char[]> population = new ArrayList<>();
        for (int i = 0; i < numChromosomes; i++) {
            population.add(generateRandomChromosome());
        }
        return population;
    }

    // Generate a random chromosome representing a chessboard configuration
    private static char[] generateRandomChromosome() {
        char[] chromosome = new char[BOARD_SIZE * BOARD_SIZE];
        for (int i = 0; i < chromosome.length; i++) {
            chromosome[i] = getRandomPiece();
        }
        return chromosome;
    }

    // Generate a random chess piece symbol
    private static char getRandomPiece() {
        int rand = random.nextInt(NUM_QUEENS + NUM_ROOKS + NUM_BISHOPS + NUM_KNIGHTS + 1);
        if (rand < NUM_QUEENS) {
            return QUEEN;
        } else if (rand < NUM_QUEENS + NUM_ROOKS) {
            return ROOK;
        } else if (rand < NUM_QUEENS + NUM_ROOKS + NUM_BISHOPS) {
            return BISHOP;
        } else if (rand < NUM_QUEENS + NUM_ROOKS + NUM_BISHOPS + NUM_KNIGHTS) {
            return KNIGHT;
        } else {
            return EMPTY;
        }
    }

    // Evolve the population by selecting parents, performing crossover and mutation
    private static List<char[]> evolvePopulation(List<char[]> population) {
        List<char[]> newPopulation = new ArrayList<>();
        for (int i = 0; i < population.size(); i++) {
            char[] parent1 = selectParent(population); // Select first parent randomly
            char[] parent2 = selectParent(population); // Select second parent randomly
            char[] offspring = crossover(parent1, parent2); // Create offspring from parents
            mutate(offspring); // Mutate offspring
            newPopulation.add(offspring); // Add mutated offspring to the new population
        }
        return newPopulation;
    }

    // Select a parent from the population randomly
    private static char[] selectParent(List<char[]> population) {
        return population.get(random.nextInt(population.size())); // Randomly select a chromosome from the population
    }

    // Perform crossover between two parent chromosomes
    private static char[] crossover(char[] parent1, char[] parent2) {
        char[] offspring = new char[parent1.length];
        for (int i = 0; i < parent1.length; i++) {
            if (random.nextDouble() < CROSSOVER_RATE) { // Perform crossover with a certain probability
                offspring[i] = parent1[i]; // Inherit gene from parent 1
            } else {
                offspring[i] = parent2[i]; // Inherit gene from parent 2
            }
        }
        return offspring;
    }

    // Perform mutation on a chromosome
    private static void mutate(char[] chromosome) {
        for (int i = 0; i < chromosome.length; i++) {
            if (random.nextDouble() < MUTATION_RATE) { // Perform mutation with a certain probability
                chromosome[i] = getRandomPiece(); // Randomly change gene
            }
        }
    }
    
    // Find the chromosome with the highest fitness in the population
    private static char[] getBestSolution(List<char[]> population) {
        char[] bestSolution = population.get(0); // Assume the first chromosome has the best fitness initially
        double bestFitness = evaluateFitness(bestSolution); // Evaluate fitness of the first chromosome
        for (char[] chromosome : population) {
            double fitness = evaluateFitness(chromosome); // Evaluate fitness of each chromosome in the population
            if (fitness > bestFitness) { // If current chromosome has better fitness
                bestSolution = chromosome; // Update best solution
                bestFitness = fitness; // Update best fitness
            }
        }
        return bestSolution;
    }

    // Evaluate the fitness of a chromosome
    private static double evaluateFitness(char[] chromosome) {
        int numConflicts = countConflicts(chromosome); // Count the number of conflicts on the chessboard
        return 1.0 / (1 + numConflicts); // Fitness is inversely proportional to the number of conflicts
    }

    // Count the number of conflicts in a chromosome
    private static int countConflicts(char[] chromosome) {
        int conflicts = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                char piece = chromosome[i * BOARD_SIZE + j];
                if (piece != EMPTY) {
                    conflicts += countPieceConflicts(chromosome, i, j, piece); // Count conflicts for each piece on the board
                }
            }
        }
        return conflicts;
    }

    // Count conflicts for a specific piece in the chromosome
    private static int countPieceConflicts(char[] chromosome, int row, int col, char piece) {
        int conflicts = 0;
        // Check conflicts in the same row
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i != col && chromosome[row * BOARD_SIZE + i] == piece) {
                conflicts++;
            }
        }
        // Check conflicts in the same column
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i != row && chromosome[i * BOARD_SIZE + col] == piece) {
                conflicts++;
            }
        }
        // Check conflicts in the same main diagonal
        for (int i = -BOARD_SIZE; i < BOARD_SIZE; i++) {
            int newRow = row + i, newCol = col + i;
            if ((i != 0) && (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) &&
                    chromosome[newRow * BOARD_SIZE + newCol] == piece) {
                conflicts++;
            }
        }
        // Check conflicts in the same secondary diagonal
        for (int i = -BOARD_SIZE; i < BOARD_SIZE; i++) {
            int newRow = row - i, newCol = col + i;
            if ((i != 0) && (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) &&
                    chromosome[newRow * BOARD_SIZE + newCol] == piece) {
                conflicts++;
            }
        }
        return conflicts;
    }

    // Print the chessboard representation of a chromosome
    private static void printBoard(char[] chromosome) {
        char[][] board = new char[BOARD_SIZE][BOARD_SIZE];
        for (int i = 0; i < chromosome.length; i++) {
            board[i / BOARD_SIZE][i % BOARD_SIZE] = chromosome[i];
        }
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Print the fitness of each chromosome in the population
    private static void printFitness(List<char[]> population) {
        for (int i = 0; i < population.size(); i++) {
            System.out.println("Chromosome " + (i + 1) + " Fitness: " + evaluateFitness(population.get(i)));
        }
        System.out.println();
    }
}
