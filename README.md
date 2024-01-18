# shortest_journey_booking_system
# Rail Network Ticket Booking System

This project is a rail network ticket booking system that allows users to find the shortest path between two stations and book tickets for their journey. The system is implemented in C++.

## Features

- Station List Distance: Reads the distances between stations from the "lineDistance.txt" file.
- Station Index Input: Reads the station names from the "stationIndex.txt" file.
- Total Lines: Reads the list of metros and their respective stations from the "totalLine.txt" file.
- Find Line: Finds the line number based on the station index.
- Match the Trains: Matches the trains for the given departure and destination stations.
- Print Train: Prints the matched trains with their line numbers, start, and end stations.
- Ticket Booking: Allows users to book tickets for a given list of stations.

## Prerequisites

- C++ compiler
- Input files: "lineDistance.txt", "stationIndex.txt", "totalLine.txt" (Format and content as specified in the code comments)

## Usage

1. Clone the repository or download the source code.
2. Compile the code using a C++ compiler.
3. Ensure that the required input files ("lineDistance.txt", "stationIndex.txt", "totalLine.txt") are in the same directory as the executable.
4. Run the program.
5. Follow the on-screen instructions to enter the departure and destination stations.
6. The program will display the matched trains for the given journey and prompt for ticket booking.
7. Enter the number of seats and the number of stations for ticket booking.
8. The program will generate and display the booked tickets.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

The project utilizes concepts of graph theory and Dijkstra's algorithm for finding the shortest path between stations. The code is inspired by the Rail Network and Ticket classes provided separately.
