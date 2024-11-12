#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define NAME_LENGTH 50

// Structure to represent a candidate
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int votes;
} Candidate;

// Function prototypes
void addCandidate(Candidate candidates[], int *count);
void displayCandidates(Candidate candidates[], int count);
void castVote(Candidate candidates[], int count);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int candidateCount = 0;
    int choice;

    do {
        printf("\n--- Election Management System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate(candidates, &candidateCount);
                break;
            case 2:
                displayCandidates(candidates, candidateCount);
                break;
            case 3:
                castVote(candidates, candidateCount);
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a candidate
void addCandidate(Candidate candidates[], int *count) {
    if (*count >= MAX_CANDIDATES) {
        printf("Cannot add more candidates. Maximum limit reached.\n");
        return;
    }
    
    Candidate newCandidate;
    newCandidate.id = *count + 1; // Assigning ID based on current count
    printf("Enter candidate name: ");
    getchar(); // To consume newline character left by previous scanf
    fgets(newCandidate.name, NAME_LENGTH, stdin);
    newCandidate.name[strcspn(newCandidate.name, "\n")] = 0; // Remove newline character
    newCandidate.votes = 0; // Initialize votes to 0

    candidates[*count] = newCandidate;
    (*count)++;
    printf("Candidate added successfully!\n");
}

// Function to display all candidates
void displayCandidates(Candidate candidates[], int count) {
    if (count == 0) {
        printf("No candidates available.\n");
        return;
    }

    printf("\n--- List of Candidates ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// Function to cast a vote for a candidate
void castVote(Candidate candidates[], int count) {
    if (count == 0) {
        printf("No candidates available to vote for.\n");
        return;
    }

    int id;
    printf("Enter the candidate ID you want to vote for: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid candidate ID!\n");
    } else {
        candidates[id - 1].votes++;
        printf("Vote casted successfully for %s!\n", candidates[id - 1].name);
    }
}