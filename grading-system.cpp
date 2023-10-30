#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class Node{
    public:
    int student_number;
    string student_name;
    int english;
    int science;
    int math;
    double average_grade;
    string evaluation;
    Node* next;
};

ofstream file, deleted_record;
Node* head = NULL;

void printMessage(string message, bool printTop = true, bool printBottom = true)
{
    if(printTop){
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    
    bool front = true;
    for(int i = message.length(); i < 33; i++){
        if(front){
        message = " " + message;
        }
        else{
        message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();

    if(printBottom){
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
}

string gradeEvaluation(int grade)
{
    string eval;
    if(grade >= 99)
        eval = "A+";
    else if(grade >= 96)
        eval = "A";
    else if(grade >= 93)
        eval = "A-";
    else if(grade >= 90)
        eval = "B+";
    else if(grade >= 87)
        eval = "B";
    else if(grade >= 84)
        eval = "B-";
    else if(grade >= 81)
        eval = "C+";
    else if(grade >= 78)
        eval = "C";
    else if(grade >= 75)
        eval = "C-";
    else if(grade < 75)
        eval = "F";
    return eval;
}

void addStudent()
{
    string evaluation;
    Node* temp = new Node;
    cout << "Enter Student number: " << endl;
    cin >> temp -> student_number;
    cin.ignore();
    cout << "Enter Student name: " << endl;
    getline(cin, temp -> student_name);
    cout << "Enter english grade: " << endl;
    cin >> temp -> english;
    cout << "Enter science grade: " << endl;
    cin >> temp -> science;
    cout << "Enter math grade: " << endl;
    cin >> temp -> math;
    temp -> average_grade = (temp -> english + temp -> science + temp -> math)/3.0;
    temp -> next = NULL;

    //if list is empty
    if(head == NULL){
        head = temp;
        temp -> evaluation = gradeEvaluation(temp -> average_grade);
        return;
    }

    //find the last node
    Node* last = head;
    while(last -> next != NULL ){
        last = last -> next;
    }

    //add new node to last node at the end of the list
    last -> next = temp;

    temp -> evaluation = gradeEvaluation(temp -> average_grade);
}

void checkStudentRecord()
{
    int choice, number;
    string name;
    Node* temp = head;
    cout << "[1] Enter Student Number\n";
    cout << "[2] Enter Student Name\n";
    cout << "> "; cin >> choice;
    switch(choice){
        case 1:
            cout << "Enter number: ";
            cin >> number;
            while(temp != NULL){
                if(number == temp -> student_number){
                cout << "Student Number: " << temp -> student_number << endl;
                cout << "Student Name: " << temp -> student_name << endl;
                cout << "English: " << temp -> english << endl;
                cout << "Science: " << temp -> science << endl;
                cout << "Math: " << temp -> math << endl;
                return;
                }
                temp = temp -> next;
            }
            cout << "Student not found" << endl;
            break;
        case 2:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            while(temp != NULL){
                if(name == temp -> student_name){
                cout << "Student Number: " << temp -> student_number << endl;
                cout << "Student Name: " << temp -> student_name << endl;
                cout << "English: " << temp -> english << endl;
                cout << "Science: " << temp -> science << endl;
                cout << "Math: " << temp -> math << endl;
                return;
                }
                temp = temp -> next;
            }
            cout << "Student not found" << endl;
            break;  
    }
}

void displayStudentRecord()
{
    Node* temp = head;
    file.open("record.txt", ios::trunc);
    file << left << setw(20) << "Student Number"  
         << left << setw(25) << "Student Name" 
         << left << setw(15) << "English" 
         << left << setw(15) << "Science" 
         << left << setw(15) << "Math" 
         << left << setw(25) << "Average Grade"
         << left << setw(15) << "Evaluation" << endl;
    file << "+====================================================================================================================================+" << endl;
    
    cout << left << setw(20) << "Student Number"  
         << left << setw(25) << "Student Name" 
         << left << setw(15) << "English" 
         << left << setw(15) << "Science" 
         << left << setw(15) << "Math" 
         << left << setw(25) << "Average Grade"
         << left << setw(15) << "Evaluation" << endl;
    cout << "+====================================================================================================================================+" << endl;
    
    while(temp != NULL){
        file << left << setw(20) << temp -> student_number 
             << left << setw(25) << temp -> student_name
             << left << setw(15) << temp -> english
             << left << setw(15) << temp -> science
             << left << setw(15) << temp -> math 
             << left << setw(25) << temp -> average_grade 
             << left << setw(15) << temp -> evaluation << endl;
        cout << left << setw(20) << temp -> student_number 
             << left << setw(25) << temp -> student_name
             << left << setw(15) << temp -> english
             << left << setw(15) << temp -> science
             << left << setw(15) << temp -> math 
             << left << setw(25) << temp -> average_grade 
             << left << setw(15) << temp -> evaluation << endl;             
        temp = temp -> next;
    }
    file.close();
}

void editStudentRecord()
{
    int number, choice;
    string name;
    Node* temp = head;
    cout << "Enter Student number: "; cin >> number;
    while(temp != NULL){
        if(number == temp -> student_number){
            do{
                cout << "What would you like to edit?" << endl;
                cout << "[1] Edit Student Name\n";
                cout << "[2] Edit English Grade\n";
                cout << "[3] Edit Science Grade\n";
                cout << "[4] Edit Math Grade\n";
                cout << "[5] Exit\n";
                cout << "> "; cin >> choice;
                switch(choice){
                    case 1:
                        cout << "Enter New Student Name: ";
                        cin.ignore();
                        getline(cin, temp -> student_name);
                        break;  
                    case 2:
                        cout << "Enter New English Grade: ";
                        cin >> temp -> english;
                        break;
                    case 3:
                        cout << "Enter New Science Grade: ";
                        cin >> temp -> science;
                        break;
                    case 4:
                        cout << "Enter New Math Grade: ";
                        cin >> temp -> math;                       
                        break;
                    case 5:
                        cout << "Edit successful\n";  
                        break;
                }
            }while(choice != 5);
            temp -> average_grade = (temp -> english + temp -> science + temp -> math)/3.0;
            temp -> evaluation = gradeEvaluation(temp -> average_grade);
        }
        temp = temp -> next;
    }
}

int getPosition()
{
    Node* temp = head;
    int pos = 0, number;
    cout << "Enter Student Number to be deleted: ";
    cin >> number;
    //code to find the positon of the node to be deleted
    deleted_record.open("deleted record.txt", ios::app);
    deleted_record << left << setw(20) << "Student Number"  
                   << left << setw(25) << "Student Name" 
                   << left << setw(15) << "English" 
                   << left << setw(15) << "Science" 
                   << left << setw(15) << "Math"
                   << left << setw(25) << "Average Grade"
                   << left << setw(15) << "Evaluation" << endl;
    while(temp != NULL){
        pos++;
        if(number == temp -> student_number){
            deleted_record << left << setw(20) << temp -> student_number 
                           << left << setw(25) << temp -> student_name
                           << left << setw(15) << temp -> english
                           << left << setw(15) << temp -> science
                           << left << setw(15) << temp -> math
                           << left << setw(25) << temp -> average_grade 
                           << left << setw(15) << temp -> evaluation << endl;
            deleted_record.close();
            break;
        }
        temp = temp -> next;
    }
    return pos;
}

void deleteStudentRecord(int pos)
{
    Node* temp1;
    Node* temp2 = new Node;
    temp1 = head;

    if(pos == 1){
        head = temp1 -> next;
        delete temp1;
        return;
    }

    for(int i = 1; i < pos -1; i++){
        temp1 = temp1 -> next;// points to n-1 node to be deleted
    }
    temp2 = temp1 -> next;// points to the node to be deleted
    temp1 -> next = temp2 -> next;//connects the gap in the nodes
    delete temp2;
}

int main(){
    int choice, pos;
        do{
            printMessage("GRADING SYSTEM");
            cout << "[1] Add Student Record\n";
            cout << "[2] Check Student Record\n";
            cout << "[3] Display All Student Record\n";
            cout << "[4] Edit Student Record\n";
            cout << "[5] Delete Student Record\n";
            cout << "[6] Exit\n";
            cout << "Enter a number > "; cin >> choice;
            switch(choice){
                case 1:
                    addStudent();
                    break;
                case 2:
                    checkStudentRecord();
                    break;
                case 3:
                    displayStudentRecord();
                    break;
                case 4:
                    editStudentRecord();
                    break;
                case 5:
                    pos = getPosition();
                    deleteStudentRecord(pos);
                    break;
                default:
                    break;
            }
        }while(choice != 6);
    return 0;
}