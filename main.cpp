#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(const string& name) : name(name) {}
    virtual ~Person() {}
    string getName() const {
        return name;
    }
};

class Candidate : public Person {
private:
    int votes;
public:
    Candidate(const string& name) : Person(name), votes(0) {}
    void addVote() {
        votes++;
    }
    int getVotes() const {
        return votes;
    }
};

class Voter : public Person {
private:
    bool hasVoted;
public:
    Voter(const string& name) : Person(name), hasVoted(false) {}
    bool hasVotedStatus() const {
        return hasVoted;
    }
    void vote() {
        hasVoted = true;
    }
};

class ElectionManager {
private:
    vector<Candidate> candidates;
    vector<Voter> voters;
public:
    void addCandidate(const string& name) {
        candidates.emplace_back(name);
        cout << "Candidate " << name << " added.\n";
    }
    void addVoter(const string& name) {
        voters.emplace_back(name);
        cout << "Voter " << name << " added.\n";
    }
    bool vote(const string& voterName, const string& candidateName) {
        for (auto& voter : voters) {
            if (voter.getName() == voterName) {
                if (voter.hasVotedStatus()) {
                    cout << "Voter has already voted.\n";
                    return false;
                }
                voter.vote();
                for (auto& candidate : candidates) {
                    if (candidate.getName() == candidateName) {
                        candidate.addVote();
                        cout << voterName << " voted for " << candidateName << ".\n";
                        return true;
                    }
                }
                cout << "Candidate not found.\n";
                return false;
            }
        }
        cout << "Voter not found.\n";
        return false;
    }
    void showResults() const {
        cout << "Election Results:\n";
        for (const auto& candidate : candidates) {
            cout << candidate.getName() << ": " << candidate.getVotes() << " votes\n";
        }
    }
    void displayMenu() const {
        cout << "\n--- Election Management System ---\n";
        cout << "1. Add Candidate\n";
        cout << "2. Add Voter\n";
        cout << "3. Vote\n";
        cout << "4. Show Results\n";
        cout << "5. Exit\n";
    }
};

int main() {
    ElectionManager electionManager;
    int choice;
    do {
        electionManager.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string candidateName;
                cout << "Enter Candidate Name: ";
                cin >> candidateName;
                electionManager.addCandidate(candidateName);
                break;
            }
            case 2: {
                string voterName;
                cout << "Enter Voter Name: ";
                cin >> voterName;
                electionManager.addVoter(voterName);
                break;
            }
            case 3: {
                string voterName, candidateName;
                cout << "Enter Voter Name: ";
                cin >> voterName;
                cout << "Enter Candidate Name: ";
                cin >> candidateName;
                electionManager.vote(voterName, candidateName);
                break;
            }
            case 4:
                electionManager.showResults();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}