# Railway Seat Reservation System

## Overview

A console-based Railway Seat Reservation System implemented in C++. This application manages seat bookings for a railway service, allowing users to reserve seats, cancel reservations, and view the current seat availability status.

## Features

- **Seat Booking**: Reserve available seats by specifying seat number and passenger name
- **Booking Cancellation**: Cancel existing reservations and release seats back to available pool
- **Seat Status Display**: View the complete list of all 50 seats and their current reservation status
- **Data Persistence**: Automatically saves reservation data to file for persistence across sessions
- **Exception Handling**: Robust error handling for invalid operations and user input validation
- **Interactive Menu**: User-friendly command-line interface for easy navigation

## System Requirements

- C++ compiler (C++98 or later)
- Standard C++ libraries (iostream, fstream, string, stdexcept)
- macOS/Linux/Windows operating system

## Project Structure

```
.
├── mini.cpp              # Main application source code with Railway class
├── railway_data.txt      # Data persistence file storing seat reservation records
└── README.md             # Project documentation
```

## Compilation and Execution

### Compile
```bash
g++ -o mini mini.cpp
```

### Run
```bash
./mini
```

## Usage

Upon execution, the application presents an interactive menu with the following options:

1. **Book Seat**: Enter seat number (1-50) and passenger name to reserve a seat
2. **Cancel Seat**: Enter seat number to cancel an existing booking
3. **Display Seats**: View all 50 seats and their current status
4. **Exit**: Terminate the application

All changes are automatically saved to `railway_data.txt` for data persistence.

## Technical Details

- **Maximum Capacity**: 50 seats
- **Data Storage**: Text file-based persistence
- **Architecture**: Object-oriented design using a Railway class
- **Input Validation**: Seat numbers must be within range (1-50)
- **Error Handling**: Uses C++ exception handling for invalid operations

## Notes

- Seat availability is indicated as "Available"
- Reserved seats display the passenger's name
- The application requires read/write access to the `railway_data.txt` file in the working directory
