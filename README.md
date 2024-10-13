# Garden Simulator

Welcome to **Garden Simulator**, a fun and interactive garden simulation project built with Xcode! This project lets you design, grow, and maintain your very own virtual garden, offering a relaxing experience and a chance to flex your green thumb—all in a digital environment.

This C++ application demonstrates modern object-oriented programming such as poliymorphism and inheritance patterns in order to efficiently and cleanly simulate the caretaking of a garden. The project was designed for Syracuse University's CIS-554 Object Oriented Programming course, taught by Professor Jonathan Weissman, during the January 2024 term.

<img width="723" alt="Screenshot 2024-10-13 at 2 59 55 PM" src="https://github.com/user-attachments/assets/edc5e9fb-e263-4906-b79d-023beacb23fc">

*Snapshots of sample program execution.*

## Features

- **Plant Variety**: Choose from a range of plants and flowers to grow in your garden.
- **Dynamic Environment**: Watch your plants grow and thrive in different soil conditions and changes.
- **Growth Simulation**: Plants go through stages of growth based on environmental factors and care.
- **Garden Care**: Take care of your garden by watering, pruning, and weeding for maximum growth!

## Project Structure
This project follows a clear separation between interface and implementation, ensuring modularity and ease of maintenance. The core files are organized as follows:

- **`main.cpp`**: The entry point of the application. This file contains the main logic for running the garden simulation, handling user inputs, and managing the garden state.
  
- **Plant Files**:
  - **`plant.h`**: Defines the base class `Plant` and its interface, which is inherited by all other plant types.
  - **`plant.cpp`**: Implements the core functionality common to all plants, such as growth stages, watering, and environmental interactions.

- **Flower Files**:
  - **`flower.h`**: Declares the `Flower` class, inheriting from `Plant`, and introduces flower-specific attributes like bloom number and frequency.
  - **`flower.cpp`**: Implements the flower-specific growth and behavior, including blooming logic.

- **Vegetable Files**:
  - **`vegetable.h`**: Declares the `Vegetable` class, a subclass of `Plant`, focusing on crop growth and harvest cycles.
  - **`vegetable.cpp`**: Implements vegetable-specific behavior, such as ripening, harvesting, and regrowth.

- **Shrub Files**:
  - **`shrub.h`**: Declares the `Shrub` class, another subclass of `Plant`, which handles bushy plant growth patterns and trimming.
  - **`shrub.cpp`**: Implements the shrub-specific growth cycle, including pruning maintenance.

Each plant type has its own set of files to encapsulate its behavior, making it easy to extend the garden with new plant varieties.

## Getting Started

1. **Clone the Repository**:  
   ```bash
   git clone https://github.com/hcharise/Garden-Simulator.git

2. **Open the Project**:
Open 'Garden Simulator.xcodeproj' in Xcode.

3. **Run the Simulator**:
Run to start your virtual gardening experience, following the command line prompts.
