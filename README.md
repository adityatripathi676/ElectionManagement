# Election Management System

This is a simple command-line Election Management System in C that allows users to:

1. **Add candidates** for an election.
2. **Display a list of candidates** along with their votes.
3. **Cast votes** for a candidate.

## Features

- **Add Candidates**: Adds a new candidate to the election system with a unique ID and initializes their votes to 0.
- **Display Candidates**: Lists all candidates with their IDs, names, and vote counts.
- **Cast Vote**: Allows a user to vote for a candidate using the candidate's ID.

## Usage

1. **Run the program**:
    ```bash
    g++ election_management.cpp 
    ./election_management
    ```

2. **Choose an option**:
    - **1**: Add a candidate by entering the candidate’s name.
    - **2**: Display all candidates with their current vote counts.
    - **3**: Cast a vote by entering the candidate's ID.
    - **4**: Exit the program.

## Code Explanation

- `Candidate`: Struct to store information about each candidate (ID, name, and votes).
- `addCandidate`: Function to add a new candidate.
- `displayCandidates`: Function to show the list of all candidates.
- `castVote`: Function to cast a vote for a candidate.

## Example

1. **Add a Candidate**: Select option 1, then enter the candidate's name.
2. **Display Candidates**: Select option 2 to view all registered candidates.
3. **Cast a Vote**: Select option 3 and enter the candidate’s ID to cast a vote.

## Limitations

- Maximum of **100 candidates** can be added due to the `MAX_CANDIDATES` limit.
- IDs are assigned sequentially starting from 1, based on the order of entry.

## Notes

- **Compile and run** on any system with a C compiler.
- Code structure is modular with function-based separation of tasks, improving readability and maintainability.

## Sample Output

```plaintext
--- Election Management System ---
1. Add Candidate
2. Display Candidates
3. Cast Vote
4. Exit
Enter your choice: 1
Enter candidate name: John Doe
Candidate added successfully!

--- Election Management System ---
1. Add Candidate
2. Display Candidates
3. Cast Vote
4. Exit
Enter your choice: 2

--- List of Candidates ---
ID: 1, Name: John Doe, Votes: 0
```
## Authors

This project was created by:
1. Aditya Tripathi
2. Brijesh Kumar
3. Taranjeet Singh
4. Mansi Rawat
5. Ishpreet Singh
