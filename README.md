# AnThropology Club Enrollment System


## Overview
This project is a simple C++ program that allows students to enroll in an Anthropology Club if they are registered in an Anthropology course. The program collects student information, verifies eligibility, and writes the details of enrolled students to a text file.

## Features
- Allows students to enter their ID, name, and course information.
- Checks if the student is eligible to enroll in the Anthropology Club.
- Stores eligible student information in an output file (`anthropology_club_members.txt`).
- Uses object-oriented programming principles such as encapsulation and inheritance.
- Prevents object copying using deleted copy constructor and assignment operator.

## Project Structure
- **`Student` Class**
  - Stores student ID, name, and course.
  - Provides setter and getter methods for student information.
  - Implements a `display` method to print student details.
  - Implements a `read` method to take user input for student details.
  - Checks if a student object is empty.

- **`AnthropologyClub` Class (Derived from `Student`)**
  - Stores an additional `memberID` for club members.
  - Implements an `enroll` method to check if a student is eligible for the club.
  - Overrides the `display` method to include club member information.

- **Main Function (`main`)**
  - Loops to accept multiple student entries.
  - Calls the `enroll` function to verify if a student is eligible.
  - Writes eligible student data to `anthropology_club_members.txt`.

## Usage
1. Compile the program using a C++ compiler:
   ```sh
   g++ -o anthropology_club main.cpp
   ```
2. Run the program:
   ```sh
   ./anthropology_club
   ```
3. Enter student details when prompted.
4. If the student is enrolled in "Anthropology," they will be added to the club.
5. The program writes enrolled student details to `anthropology_club_members.txt`.
6. Repeat the process for multiple students.
7. Enter "no" when asked if you want to add another student to exit the program.

## File Output
The program appends the following format to `anthropology_club_members.txt`:
```
Member ID: [Student ID]
Name: [Student Name]
Course: Anthropology
------------------------------------------
```

## Example Interaction
```
Enter student ID: 12345
Enter student name: Alice Brown
Enter student course: Anthropology
Student Alice Brown enrolled in Anthropology Club.
Output written to file.
Do you want to add another student? (yes/no): no
```

## Dependencies
- Standard C++ libraries (`iostream`, `fstream`, `cstring`).

## Notes
- The program does not handle duplicate entries in the file.
- Only students with "Anthropology" as their course are eligible for club membership.
- Ensure the output file (`anthropology_club_members.txt`) is in the same directory as the executable.

## AuthorS
- Developed by [Preeya S.]

