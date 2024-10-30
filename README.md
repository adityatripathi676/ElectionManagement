# Election Management System
This is the Working model of Election Management System using OOPS Concepts 

# Voting System Project Documentation

## Overview
This project simulates a basic voting system. It includes classes to represent `Voters`, `Candidates`, and an `Election` to manage voters and candidates, track votes, and display results. Optionally, it has an `ElectionManager` class to handle the election process and a `User Interface` class for interaction.

## Class Descriptions

### 1. `Voter` Class
The `Voter` class represents an individual eligible to vote in the election.

- **Attributes**:
  - `std::string name`: Stores the name of the voter.
  - `std::string voterID`: Unique ID assigned to each voter.
  - `bool isRegistered`: Flag indicating if the voter is registered.

- **Methods**:
  - `void registerVoter()`: Registers the voter, setting `isRegistered` to `true`.
  - `bool isVoterRegistered() const`: Returns whether the voter is registered.
  - `std::string getVoterID() const`: Retrieves the voter's ID.
  - `std::string getName() const`: Retrieves the voter's name.

### 2. `Candidate` Class
The `Candidate` class represents a candidate running in the election.

- **Attributes**:
  - `std::string name`: Stores the candidate’s name.
  - `std::string party`: The political party the candidate belongs to.
  - `int votes`: Tracks the number of votes the candidate has received.

- **Methods**:
  - `void addVote()`: Increases the candidate's vote count by one.
  - `int getVotes() const`: Retrieves the current number of votes for the candidate.
  - `std::string getName() const`: Retrieves the candidate's name.
  - `std::string getParty() const`: Retrieves the candidate's party.

### 3. `Election` Class
The `Election` class manages the election process by handling voter and candidate registration, vote casting, and results.

- **Attributes**:
  - `Voter voters[100]`: Array of registered voters, with a fixed maximum of 100 voters.
  - `Candidate candidates[100]`: Array of candidates in the election, with a fixed maximum of 100 candidates.
  - `int voterCount`: Tracks the total number of registered voters.
  - `int candidateCount`: Tracks the total number of candidates.
  - `std::map<std::string, int> results`: Maps each candidate’s name to their vote count.

- **Methods**:
  - `void registerVoter(const std::string& name, const std::string& voterID)`: Registers a new voter by adding them to the `voters` array and updating `voterCount`.
  - `void addCandidate(const std::string& name, const std::string& party)`: Registers a new candidate by adding them to the `candidates` array and updating `candidateCount`.
  - `void vote(const std::string& voterID, const std::string& candidateName)`: Casts a vote for a candidate if the voter is registered and has not already voted. Increases the candidate’s vote count in `results`.
  - `void displayResults() const`: Displays the vote count for each candidate and announces the winner.

### 4. `ElectionManager` Class (Optional)
The `ElectionManager` class oversees the election process, from starting to ending an election, and provides a menu interface for election management.

- **Attributes**:
  - `Election currentElection`: Holds the current election instance.

- **Methods**:
  - `void startElection()`: Initializes a new election.
  - `void endElection()`: Ends the election and prevents further voting.
  - `void displayMainMenu()`: Shows the main menu for managing the election.
  - `void handleUserInput()`: Processes user input for election management actions.

### 5. `User Interface` Class (Optional)
The `User Interface` class handles interactions with the user, providing menus and prompts.

- **Attributes**:
  - `ElectionManager electionManager`: Manages the current election process.

- **Methods**:
  - `void displayMenu()`: Displays the main menu for the user.
  - `void getVoterInput()`: Prompts the user to register a voter.
  - `void getCandidateInput()`: Prompts the user to add a candidate.
  - `void showResults()`: Shows the election results to the user.

## Example Usage
1. **Register Voters**: Call `registerVoter()` for each voter with their `name` and `voterID`.
2. **Add Candidates**: Call `addCandidate()` for each candidate with their `name` and `party`.
3. **Cast Votes**: Use `vote()` to cast votes by specifying `voterID` and `candidateName`.
4. **Display Results**: After voting is complete, call `displayResults()` to see the final vote counts and winner.

---

This file provides a clear roadmap of the system’s design, ensuring readability and easy navigation for users working with the code.
