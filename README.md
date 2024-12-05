# Sorting Algorithm Visualizer
A graphical tool to visualize various sorting algorithms (Bubble Sort, Selection Sort, QuickSort) using a dynamic and interactive interface. This tool helps in understanding how sorting algorithms work by visually showing each step of the algorithm in action. Additionally, you can implement other sorting algorithms to visualize them.

## Features
* **Bubble Sort Visualization**: Shows the step-by-step process of sorting an array using Bubble Sort.
* **Selection Sort Visualization**: Visualizes the Selection Sort algorithm, displaying the process of finding the minimum element.
* **QuickSort Visualization**: Demonstrates how the QuickSort algorithm partitions and sorts the array.
* **Real-time Visualization**: Watch the array change visually as the algorithm progresses.

**Keybinds**:
* **Spacebar**: Start the Bubble Sort algorithm.
* **S**: Start the Selection Sort algorithm.
* **Q**: Start the QuickSort algorithm.

## Dependencies
The project requires the following C++ libraries:
* `SFML` for graphical rendering and event handling.

### For Windows Users with WSL:
* **VcXsrv**: A Windows-based X server to display graphics from WSL.

## Usage
1. **Install Dependencies**:
   * **For WSL**:
     Ensure you have an X server installed on your Windows machine (like VcXsrv) to allow graphical output.
   
     If using **VcXsrv**, install it from [here](https://sourceforge.net/projects/vcxsrv/). Ensure you select "Disable access control" when launching it.

   * **For Ubuntu** (or other Linux distros in WSL):
     Install SFML by running the following command:

     ```bash
     sudo apt update
     sudo apt install libsfml-dev
     ```

2. **Clone the Repository and Build**:
   Clone the repository and build the project using `g++`:
   
   ```bash
   git clone https://github.com/spencerboggs/sorting-algorithm-visualizer.git
   cd algorithm-visualizer
   g++ main.cpp SortingAlgorithms.cpp Visualizer.cpp -o visualizer -lsfml-graphics -lsfml-window -lsfml-system
