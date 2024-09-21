# Player Auction Software

This repository contains two C++ programs designed to simulate a player auction system. These programs are particularly useful for scenarios such as sports tournaments where players are auctioned to captains with predefined budgets and requirements. 

The auction system includes functionalities like random player selection, captain bidding, and ensuring captains meet minimum team requirements. The second program allows for player auctions by categories, adding an additional layer of organization and strategy to the auction process.

## Features

### Program 1: General Auction System
- **Captains and Players**: The program takes as input the names of captains, the list of players, base price, the total money each captain has, and the minimum number of players each captain needs to take.
- **Randomized Player Selection**: Players are randomly selected using the `mt19937_64` random number generator until they are sold. Unsold players are returned to the pool for future bidding rounds. 
- **Bidding and Money Tracking**: After each player is sold, the program updates and displays the captain's remaining budget and the maximum bid price.
- **Manual Auction Input**: The final values at which each player is sold and to which captain are inputted offline. Enter `-1` incase a player is unsold.
- **Round-Robin Distribution**: If players need to be distributed randomly at any point, a round-robin mechanism is available to allocate players evenly among captains.
- **Precautions for crashing**: There are already checks within the code, so that the code does not crash incase there is spelling mistake and confirmation for a major step taken . But, the input should be given carefully.

### Program 2: Category-Based Auction System
- **Player Categorization**: Players are divided into categories (e.g., marquee players, Player1, Player2, etc.).
- **Sequential Auction by Category**: The auction process is conducted category by category, with players within each category being auctioned before moving to the next.
- **Flexible Auction Flow**: This method allows for more strategic planning and bidding based on the importance of the player category.

## Technologies Used
- **C++**: The core logic of the auction is implemented in C++ for efficient handling of auction processes and bidding.
- **Randomization**: The `mt19937_64` engine is used for robust random number generation to ensure the random selection of players.
