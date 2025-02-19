# Minitalk

**Minitalk** is a project from 42cursus where you implement a simple client-server communication system using Unix signals. The server will receive a string from the client and display it on the terminal. This communication is done exclusively with Unix signals, specifically `SIGUSR1` and `SIGUSR2`.

## Project Overview

- **Server:** The server listens for signals and displays the received string.
- **Client:** The client sends a string to the server by sending signals corresponding to each character.

## Requirements

- Use Unix signals (`SIGUSR1`, `SIGUSR2`) for communication.
- Implement signal handling and proper memory management.
- Only the following functions are allowed:
  - `malloc`
  - `free`
  - `write`
  - `getpid`
  - `signal`
  - `sigemptyset` & `sigaddset`
  - `sigaction`
  - `pause`
  - `kill`
  - `sleep`
  - `usleep`
  - `exit`

## Compilation

To compile the project, run the following commands:

1. Clone the repository:
    ```bash
    git clone https://github.com/saidfaouzi//minitalk.git
    ```

2. Navigate to the project directory:
    ```bash
    cd minitalk
    ```

3. Compile the project using `Makefile`:
    ```bash
    make
    ```

## Usage

### Server

To start the server, run the following command:
```bash
./server
