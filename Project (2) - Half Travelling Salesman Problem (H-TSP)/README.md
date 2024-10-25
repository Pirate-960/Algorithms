# 🌍🚀 Half Traveling Salesman Problem (H-TSP) Solver
---

## 🌟 Project Overview

Welcome to our cutting-edge Half Traveling Salesman Problem (H-TSP) solver! This project represents a significant advancement in combinatorial optimization, tackling a challenging variation of the classic Traveling Salesman Problem.

The H-TSP involves finding the shortest possible route that visits a subset of cities and returns to the starting point, with the constraint that the route must be divided into two segments: one from the starting point to a designated "halfway" point, and another from the halfway point back to the starting point.

---

## 📚 Table of Contents

- [🌍🚀 Half Traveling Salesman Problem (H-TSP) Solver](#-half-traveling-salesman-problem-h-tsp-solver)
  - [🌟 Project Overview](#-project-overview)
  - [📚 Table of Contents](#-table-of-contents)
    - [🎯 The Challenge: H-TSP Defined](#-the-challenge-h-tsp-defined)
    - [🌐 Real-World Applications](#-real-world-applications)
  - [🚀 Features That Set Us Apart](#-features-that-set-us-apart)
  - [🛠️ Getting Started: Your Journey Begins Here](#️-getting-started-your-journey-begins-here)
    - [Prerequisites: Gear Up!](#prerequisites-gear-up)
    - [Compilation: Forging Your Tool](#compilation-forging-your-tool)
      - [The GCC Way:](#the-gcc-way)
      - [The Make Way (if available):](#the-make-way-if-available)
  - [🏃‍♂️ Usage: Solving H-TSP Like a Pro](#️-usage-solving-h-tsp-like-a-pro)
    - [🔍 Detailed Running Instructions](#-detailed-running-instructions)
  - [🧪 Quality Assurance: Verifying Your Solution](#-quality-assurance-verifying-your-solution)
  - [🧠 Under the Hood: Our Algorithms](#-under-the-hood-our-algorithms)
    - [1. Project.c: The Optimized Powerhouse](#1-projectc-the-optimized-powerhouse)
      - [Algorithm Breakdown:](#algorithm-breakdown)
      - [Key Strengths:](#key-strengths)
      - [Time Complexity:](#time-complexity)
    - [2. Crazy\_Brute.c: The Experimental Explorer](#2-crazy_brutec-the-experimental-explorer)
      - [Algorithm Highlights:](#algorithm-highlights)
      - [Key Strengths:](#key-strengths-1)
      - [Time Complexity:](#time-complexity-1)
  - [📊 Solution Comparison: Project.c vs Crazy\_Brute.c](#-solution-comparison-projectc-vs-crazy_brutec)
    - [Advantages and Disadvantages](#advantages-and-disadvantages)
      - [Project.c (Optimized Solution)](#projectc-optimized-solution)
      - [Crazy\_Brute.c (Experimental Solution)](#crazy_brutec-experimental-solution)
    - [When to Use Each Solution](#when-to-use-each-solution)
  - [🔬 Future Horizons: What's Next?](#-future-horizons-whats-next)
  - [🤝 Join the Quest: How to Contribute](#-join-the-quest-how-to-contribute)
  - [📜 License](#-license)
  - [🙏 Acknowledgements](#-acknowledgements)
  - [📚 Dive Deeper: Further Reading](#-dive-deeper-further-reading)
  - [📬 Connect With Us](#-connect-with-us)

---

### 🎯 The Challenge: H-TSP Defined

The Half Traveling Salesman Problem (H-TSP) is a fascinating variant of the well-known Traveling Salesman Problem. Given a map of `n` cities, your mission is to find the optimal tour that:

- ✅ Visits exactly `⌈n/2⌉` cities (half, rounded up)
- 🔄 Starts and ends at the same city
- 📉 Minimizes the total travel distance

This problem combines the complexity of route optimization with the additional challenge of city selection, making it a formidable task for both theoretical analysis and practical implementation.

> 💡 **Deep Dive**: The H-TSP is classified as NP-hard, placing it in a category of problems for which no known polynomial-time algorithm exists. This classification implies that as the number of cities increases, the computational resources required to find an optimal solution grow exponentially. Our solver employs advanced heuristics and optimization techniques to find near-optimal solutions efficiently, even for large instances.

---

### 🌐 Real-World Applications

The H-TSP and its solutions have wide-ranging applications, including:

1. 📦 Logistics and Supply Chain Optimization
2. 🚗 Ride-sharing and Delivery Route Planning
3. 🏙️ Urban Planning and Infrastructure Development
4. 🧬 Genome Sequencing in Bioinformatics
5. 🖨️ Circuit Board Drilling in Manufacturing

By solving the H-TSP efficiently, we open doors to improvements in these fields and many others.

---

## 🚀 Features That Set Us Apart

Our H-TSP solver is packed with features designed to tackle this complex problem effectively:

1. 🏙️ **Scalability**: 
   - Efficiently handle large-scale H-TSP instances with up to 50,000 cities
   - Utilizes memory-efficient data structures to manage large datasets

2. 🧩 **Hybrid Algorithm**:
   - Combines construction heuristics for initial solutions
   - Employs local search techniques for solution refinement
   - Balances exploration and exploitation in the solution space

3. 🔍 **Advanced Optimization Techniques**:
   - Implements sophisticated perturbation mechanisms to escape local optima
   - Utilizes adaptive parameters that adjust based on the problem instance

4. 📊 **Comprehensive Output**:
   - Provides detailed results, including:
     - Total tour distance
     - Complete city visitation order
     - Time taken for computation
     - Solution quality metrics

5. 🛡️ **Robust Error Handling**:
   - Implements thorough input validation
   - Gracefully handles edge cases and unexpected inputs
   - Provides informative error messages for troubleshooting

6. 📈 **Performance Profiling**:
   - Includes built-in timing and memory usage tracking
   - Allows for easy benchmarking and performance tuning

7. 🔧 **Modular Design**:
   - Clearly separated modules for different algorithm components
   - Easily extensible for testing new heuristics or optimization techniques

---

## 🛠️ Getting Started: Your Journey Begins Here

### Prerequisites: Gear Up!

Before diving into the world of H-TSP, ensure you have the following tools at your disposal:

1. 🖥️ **GCC Compiler**: 
   - Version 7.0 or higher recommended
   - Enables compilation of our C-based solver
   - Supports advanced optimization flags for improved performance

2. 🐍 **Python 3.6+**: 
   - Required for running our solution verifier
   - Ensures compatibility with all verification scripts

3. 🔧 **GNU Make** (optional but recommended):
   - Simplifies the build process
   - Allows for easy compilation with predefined optimization flags

4. 📚 **Additional Libraries**:
   - `libm`: Math library (usually included with GCC)
   - `time.h`: For performance measurements
   - `stdlib.h`: For dynamic memory allocation

### Compilation: Forging Your Tool

#### The GCC Way:
For optimal performance, compile with optimization flags:

```bash
gcc -O3 -march=native -o htsp_solver Project.c -lm
```

> 💪 **Pro Tip**: The `-O3` flag enables aggressive optimizations, while `-march=native` optimizes for your specific CPU architecture.

#### The Make Way (if available):
We provide a Makefile for easier compilation:

```bash
make htsp_solver
```

This command will compile the solver with predefined optimization flags.

---

## 🏃‍♂️ Usage: Solving H-TSP Like a Pro

1. 📝 **Prepare Your Map**: 
   Create an input file (e.g., `cities.txt`) with city coordinates:
   ```
   n
   0 x1 y1
   1 x2 y2
   ...
   n-1 xn yn
   ```
   Where:
   - `n` is the total number of cities
   - Each subsequent line represents a city with its ID and (x, y) coordinates

2. 🚀 **Launch the Solver**:
   ```bash
   ./htsp_solver cities.txt
   ```

3. ⏳ **Watch the Magic Happen**: 
   The solver will process the input and generate an `output.txt` file with your optimized tour:

   ```
   total_distance
   city_id_1
   city_id_2
   ...
   city_id_⌈n/2⌉
   ```

   Additionally, the solver will display progress information and final statistics in the console.

### 🔍 Detailed Running Instructions

***===================================================***

1. **Compile the Code** (if not done already):
   ```bash
   gcc -O3 -march=native -o htsp_solver Project.c -lm
   ```

2. **Run the Program**:
   ```bash
   ./htsp_solver input.txt
   ```
   Replace `input.txt` with your actual input file name.

3. **Monitor Progress**:
   The solver will display progress information:
   ```
   ============***Half-TSP***============
   Reading input file: input.txt
   Number of cities: 1000
   Constructing initial tour...
   Applying 2-opt optimization...
   Iteration 1: Distance = 10500.32
   Iteration 2: Distance = 10200.15
   ...
   ```

4. **Check Your Output**:
   - The program automatically generates `output.txt`
   - Console output will show final tour distance and computation time

5. **Verify the Solution**:
   ```bash
   python half_tsp_verifier.py input.txt output.txt
   ```

***===================================================***

---

## 🧪 Quality Assurance: Verifying Your Solution

Our `half_tsp_verifier.py` script ensures the integrity and correctness of your solution:

```bash
python half_tsp_verifier.py input.txt output.txt
```

The verifier performs the following checks:

1. ✅ **Correct Tour Size**: Ensures exactly `⌈n/2⌉` cities are visited
2. 🔄 **No Repetitions**: Verifies each city is visited at most once
3. 🆔 **Valid City IDs**: Checks that all city IDs in the tour are valid
4. 📏 **Distance Accuracy**: Calculates and compares the reported vs. actual tour distance
5. 🔁 **Cycle Completeness**: Confirms the tour starts and ends at the same city

If any check fails, the verifier will provide detailed error messages to help identify the issue.

---

## 🧠 Under the Hood: Our Algorithms

We offer two powerful implementations, each with its unique approach to conquering the H-TSP:

### 1. Project.c: The Optimized Powerhouse

#### Algorithm Breakdown:

1. 🏗️ **Initial Tour Construction**:
   - Uses the Nearest Neighbor (NN) algorithm
   - Greedily builds a tour by always choosing the closest unvisited city
   - Time Complexity: O(n^2)

2. 🔍 **Local Search Optimization**:
   - Implements the 2-opt algorithm for tour improvement
   - Iteratively swaps pairs of edges to reduce tour length
   - Time Complexity: O(n^2) per iteration

3. 🔄 **Iterative Refinement**:
   - Applies a perturbation mechanism to escape local optima
   - Randomly modifies parts of the tour to explore new solution spaces
   - Accepts improvements and occasionally worse solutions to avoid getting stuck

#### Key Strengths:
- 🚀 Efficiently handles large instances (up to 50,000 cities)
- ⚖️ Balances solution quality and computation speed
- 🧪 Employs sophisticated optimization techniques for consistent results

#### Time Complexity:
- Overall: O(n^2 * k), where k is the number of improvement iterations
- Typically achieves good solutions with k << n, leading to practical efficiency

### 2. Crazy_Brute.c: The Experimental Explorer

#### Algorithm Highlights:

1. 🎲 **Custom Initial Tour**:
   - Uses a unique approach to city selection
   - Incorporates randomness to generate diverse initial solutions
   - Time Complexity: O(n^2)

2. 🔬 **Innovative Optimization**:
   - Implements a variant of local search
   - Explores larger neighborhoods of the current solution
   - Time Complexity: O(n^3) in the worst case

3. 📊 **Mean-based Heuristic**:
   - Utilizes the mean distance between cities as a heuristic
   - Guides the search towards promising areas of the solution space
   - Adds a layer of intelligence to the exploration process

#### Key Strengths:
- 🧪 Explores solution space from novel angles
- 🌌 Potential for discovering unique, high-quality solutions
- 📏 Leverages statistical properties of the city distribution

#### Time Complexity:
- Overall: O(n^3) in the worst case
- May find unique solutions faster for certain problem instances

---

## 📊 Solution Comparison: Project.c vs Crazy_Brute.c

| Aspect | Project.c (Optimized) | Crazy_Brute.c (Experimental) |
|--------|----------------------|---------------------------|
| Approach | 🏛️ Methodical, step-by-step optimization | 🎨 Exploratory, with elements of randomness |
| Scalability | 🚀 Excellent, up to 50,000 cities | 🚶 Good, up to 10,000 cities |
| Solution Quality | 📊 Consistently good across various instances | 🎭 Variable, potentially excellent for some instances |
| Computation Speed | ⚡ Faster, especially for large instances | 🐢 Slower, particularly as problem size grows |
| Memory Usage | 💾 O(n), efficient for large problems | 💽 O(n^2), uses distance matrix |
| Customizability | 🔧 Easily adaptable, modular design | 🛠️ More complex to modify, but offers unique insights |

### Advantages and Disadvantages

#### Project.c (Optimized Solution)

✅ Advantages:
1. Consistent performance across various instance sizes
2. Efficient memory usage, suitable for very large problems
3. Faster execution time, especially for large instances
4. Easy to understand and modify due to modular design
5. Reliable results with good quality guarantees

❌ Disadvantages:
1. May get stuck in local optima for some challenging instances
2. Less exploratory in nature, potentially missing some unique solutions
3. Requires careful tuning of parameters for optimal performance

#### Crazy_Brute.c (Experimental Solution)

✅ Advantages:
1. Potential to find unique, high-quality solutions for certain instances
2. Explores the solution space differently, beneficial for some problem structures
3. Mean-based heuristic provides insights into problem characteristics
4. Can outperform Project.c on specific types of instances

❌ Disadvantages:
1. Higher time complexity, significantly slower for large instances
2. Higher memory usage due to distance matrix, limiting scalability
3. Less predictable performance across different problem types
4. More challenging to modify or extend due to complex structure

### When to Use Each Solution

- Use **Project.c** when:
  - Dealing with large instances (>10,000 cities)
  - Consistent, reliable performance is crucial
  - Memory efficiency is a priority
  - Quick solutions are needed for time-sensitive applications

- Consider **Crazy_Brute.c** when:
  - Working with smaller instances (<10,000 cities)
  - Exploring unique or challenging problem structures
  - Solution quality is prioritized over computation time
  - Investigating the effectiveness of novel heuristics

---

## 🔬 Future Horizons: What's Next?

Our H-TSP solver project is continuously evolving. Here are some exciting directions for future development:

1. 🧠 **Advanced Metaheuristics**:
   - Implement Simulated Annealing for better local optima escape
   - Develop a Genetic Algorithm approach for diverse solution population
   - Explore Ant Colony Optimization for collective intelligence-based solving

2. 🖥️ **Parallel Processing**:
   - Harness multi-core CPUs for parallel tour construction
   - Implement GPU acceleration for distance calculations
   - Develop a distributed version for cluster-based solving of massive instances

3. 🔍 **Smart Preprocessing**:
   - Develop clustering techniques to identify promising city subsets
   - Implement problem reduction methods for faster initial solutions
   - Create adaptive parameter selection based on instance characteristics

4. 🖼️ **Visualization and GUI**:
   - Create an interactive GUI for real-time solution visualization
   - Develop a web-based interface for easy access and result sharing
   - Implement 3D visualization for multi-dimensional TSP variants

5. 🤝 **Hybrid Algorithms**:
   - Combine strengths of Project.c and Crazy_Brute.c
   - Develop an adaptive solver that switches strategies based on instance properties
   - Implement a portfolio-based approach that runs multiple algorithms in parallel

6. 🤖 **Machine Learning Integration**:
   - Train an ML model to predict the best solving strategy for given instances
   - Develop reinforcement learning approaches for adaptive local search
   - Use neural networks for intelligent city selection in tour construction

7. ⚡ **Performance Optimizations**:
   - Implement cache-friendly data structures for improved memory access patterns
   - Develop compression techniques for handling ultra-large instances
   - Optimize critical code paths using assembly-level optimizations

8. 📊 **Benchmarking and Analysis Tools**:
   - Create a comprehensive benchmark suite for H-TSP instances
   - Develop statistical analysis tools for solution quality assessment
   - Implement automated parameter tuning using irace or similar frameworks

---

## 🤝 Join the Quest: How to Contribute

We welcome contributions from optimization enthusiasts, algorithm designers, and software engineers! Here's how you can make a significant impact:

1. 💻 **Implement New Algorithms**:
   - Develop and integrate novel heuristics or metaheuristics
   - Adapt cutting-edge TSP algorithms for the H-TSP variant

2. 🚀 **Optimize Existing Code**:
   - Profile and improve performance-critical sections
   - Implement parallelization strategies for multi-core and distributed systems

3. 📥 **Enhance I/O and Formats**:
   - Add support for various input formats (e.g., TSPLIB)
   - Develop converters for integrating with other TSP solvers

4. 🧪 **Expand Testing and Benchmarking**:
   - Create diverse, challenging test instances for H-TSP
   - Develop automated benchmarking scripts for performance comparison
   - Implement visualization tools for solution quality analysis

5. 📚 **Improve Documentation**:
   - Enhance code comments and function descriptions
   - Create tutorials and usage examples for different scenarios
   - Develop a comprehensive API documentation for the solver

6. 🌐 **Community Building**:
   - Organize coding sprints or hackathons focused on H-TSP
   - Create and maintain a project blog or newsletter
   - Develop educational materials for teaching H-TSP in academic settings

7. 🔗 **Integration and Interoperability**:
   - Develop wrappers for using the solver in other programming languages
   - Create plugins for popular optimization frameworks or IDEs
   - Implement APIs for cloud-based deployment and scaling

Ready to contribute? Here's how to get started:

1. Fork the repository
2. Create a new branch for your feature or bugfix
3. Implement your changes, ensuring they adhere to our coding standards
4. Add or update relevant tests and documentation
5. Submit a Pull Request with a clear description of your changes

We look forward to your contributions and innovative ideas!

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE). 

Key points of the MIT License:
- ✅ Use the software for any purpose
- ✅ Modify, distribute, and sublicense the software
- ✅ Use the software commercially
- ❗ Include the original copyright notice in any copy or substantial portion of the software

We encourage you to use, learn from, and improve this project while respecting the terms of the license.

---

## 🙏 Acknowledgements

Our H-TSP solver stands on the shoulders of giants. We'd like to express our gratitude to:

- 🎓 Our esteemed CSE2046 instructor and teaching assistants for their invaluable guidance and support throughout the development of this project.
- 💡 The creators of the [Concorde TSP Solver](http://www.math.uwaterloo.ca/tsp/concorde.html), whose groundbreaking work has inspired many aspects of our implementation.
- 📘 The pioneering researchers in the field of combinatorial optimization, particularly:
  - Nicos Christofides for his 1976 work on approximation algorithms for TSP
  - Shen Lin and Brian Kernighan for their seminal 1973 paper introducing the Lin-Kernighan heuristic
- 🖥️ The open-source community for providing robust tools and libraries that made this project possible.
- 🧪 Our beta testers and early users who provided valuable feedback and bug reports.

---

## 📚 Dive Deeper: Further Reading

To fully appreciate the depth of the Traveling Salesman Problem and its variants, we recommend the following resources:

1. 📖 Applegate, D. L., Bixby, R. E., Chvátal, V., & Cook, W. J. (2006). The Traveling Salesman Problem: A Computational Study. Princeton University Press.
   - A comprehensive study of the TSP, including cutting-edge techniques and historical perspectives.

2. 📃 Johnson, D. S., & McGeoch, L. A. (1997). The traveling salesman problem: A case study in local optimization. Local search in combinatorial optimization, 1, 215-310.
   - An in-depth exploration of local search techniques for TSP, providing valuable insights applicable to H-TSP.

3. 📄 Helsgaun, K. (2000). An effective implementation of the Lin–Kernighan heuristic for the traveling salesman problem. European Journal of Operational Research, 126(1), 106-130.
   - Describes one of the most effective heuristics for TSP, with concepts extensible to H-TSP.

4. 🎓 Gutin, G., & Punnen, A. P. (Eds.). (2006). The traveling salesman problem and its variations (Vol. 12). Springer Science & Business Media.
   - A collection of advanced topics in TSP, including variations like the H-TSP.

5. 💻 Laporte, G. (1992). The traveling salesman problem: An overview of exact and approximate algorithms. European Journal of Operational Research, 59(2), 231-247.
   - Provides a broad overview of TSP algorithms, useful for understanding the landscape of solution approaches.

---

## 📬 Connect With Us

We're excited to hear from you! Whether you have questions, ideas, or just want to discuss optimization techniques, don't hesitate to reach out:

- �issues GitHub Issues: For bug reports, feature requests, and code-related discussions
- 📧 Email: [a.a.zahran.960@gmail.com](mailto:a.a.zahran.960@gmail.com) for direct communication

Join our community of optimization enthusiasts and help push the boundaries of what's possible in combinatorial optimization!

Happy Optimizing! May your tours be short, your solutions optimal, and your algorithmic journeys exciting! 🚗💨🌟🔬

---

<p align="center">
  Made with ❤️
  <br>
  🌟 Star us on GitHub — it helps!
</p>
<p align="center">
  <img src="https://via.placeholder.com/800x100.png?text=Thank+You+for+Exploring+Our+Project!" alt="Description of image">
</p>
