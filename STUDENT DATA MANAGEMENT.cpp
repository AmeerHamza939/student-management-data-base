#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;

int counter = 0;
int increment(int c)
{
	c++;
	counter = c;
	return counter;
}

int decrement(int c)
{
	c--;
	counter = c;
	return counter;
}

class enterdata{

private:
	string name, section, semester, phone_num, enrollment, DOB, email;
public:
	enterdata(){
		name = "0";
		section = "0";
		semester = "0";
		phone_num = "0";
		enrollment = "0";
		DOB = "0";
		email = "0";
	}



	void setname(string na){
		name = na;
	}

	void setsection(string sec){
		section = sec;
	}

	void setsemester(string sem){
		semester = sem;
	}

	void setphone_num(string ph){
		phone_num = ph;
	}

	void setenrollment(string enroll){
		enrollment = enroll;
	}

	void setdob(string d){
		DOB = d;
	}

	void setemail(string em){
		email = em;

	}

	string getname(){
		return name;
	}

	string getsection(){
		return section;
	}

	string getsemester(){
		return semester;
	}

	string getphone_num(){
		return phone_num;
	}
	string getenrollment(){
		return enrollment;
	}

	string getemail(){
		return email;
	}

	string getDob(){
		return DOB;
	}
	~enterdata(){
		cout << "distructor run:" << endl;
	}

};

class  addstudent :virtual public enterdata{
public:
	void Addstudent(int counter){

		string name, section, semester, phone_num, enrollment, DOB, email;

		cout << "\t\t\t ADD Students RECORDS " << endl;
		if (counter == 1000)
		{
			cout << "PLEASE ENTER THE VALID NUMBER OF STUDENTS.S" << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}

		else
		{
			cin.ignore();
			cout << "ENTER STUDENT NAME: " << endl;
			getline(cin, name);
			cout << "ENTER STUDENT SECTION: " << endl;
			getline(cin, section);
			cout << "ENTER STUDENT SEMESTER: " << endl;
			getline(cin, semester);
			cout << "ENTER STUDENT PHONE NO: " << endl;
			getline(cin, phone_num);
			cout << "ENTER STUDENT ENROLLMENT: " << endl;
			getline(cin, enrollment);
			cout << "ENTER STUDENT DOB (dd/mm/yyyy): " << endl;
			getline(cin, DOB);
			cout << "ENTER STUDENT EMAIL: " << endl;
			getline(cin, email);

			setname(name);
			setenrollment(enrollment);
			setsection(section);
			setsemester(semester);
			setphone_num(phone_num);
			setdob(DOB);
			setemail(email);
			increment(counter);
			cout << "Student DATA HAS BEEN ADDED SUCCESFULLY!" << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}
	}
};

class deletestudent :virtual public enterdata, virtual public addstudent{
public:
	void deleteStudent(int counter, deletestudent student[1000])
	{
		string enroll;
		int choice;
		cout << "DELETE STUDENT RECORD \n\n";
		if (counter == 0)
		{
			cout << "THERE IS NO STUDENT RECORD TO BE DELETED " << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}	cin.ignore();
		cout << "ENTER ENROLLMENT  OF STUDENT: " << endl;
		getline(cin, enroll);
		for (int i = 0; i < counter; i++)
		{
			if (student[i].getenrollment() == enroll)
			{
				cout << "STUDENT RECORD HAS BEEN FOUND!" << endl;
				cout << "Do You Want to delete this Student record:" << endl;
				cout << "1. YES." << endl;
				cout << "2. NO." << endl;
				cin >> choice;
				if (choice == 1)
				{
					student[i].setname("");
					student[i].setphone_num("");
					student[i].setsection("");
					student[i].setsemester("");
					student[i].setdob("");
					student[i].setemail("");
					student[i].setenrollment("");
					decrement(counter);
					cout << "STUDENT RECORD DELETED SUCCESFULLY!" << endl;
					cout << "Press any key to continue.." << endl;
					_getch();


					for (int a = i; a < counter; a++)
					{
						student[a] = student[a + 1];
					}

					student[9].setname("");
					student[9].setphone_num("");
					student[9].setsection("");
					student[9].setsemester("");
					student[9].setdob("");
					student[9].setemail("");
					student[9].setenrollment("");
				}

				else
				{

				}
			}
		}
		cout << "STUDENT RECORD has NOT FOUND " << endl;
		cout << "Press any key to continue.." << endl;
		_getch();

	}


};

class editstudent :virtual public enterdata, virtual public deletestudent, virtual public addstudent{
public:
	void editStudent(int counter, editstudent student[1000])
	{
		string editenroll;
		string name, section, semester, phone_num, enrollment, DOB, email;
		string choice;
		cout << "\t\t\tEDIT STUDENT RECORD " << endl;
		if (counter == 0)
		{
			cout << "THERE IS NO STUDENT RECORD TO BE EDITED FIRST ADD THE RECORD!" << endl;
			cout << "Press any key to continue... " << endl;
			_getch();

		}
		cin.ignore();
		cout << "ENTER ENROLLMENT OF STUDENT: " << endl;
		getline(cin, editenroll);

		for (int i = 0; i < counter; i++)
		{
			if (student[i].getenrollment() == editenroll)
			{
				cout << "STUDENT RECORD FOUND!" << endl;
				cout << "DO YOU WANT TO EDIT THIS RECORD" << endl;
				cout << "1. YES." << endl;
				cout << "2. NO." << endl;
				getline(cin, choice);
				if (choice == "1")
				{

					cout << "ENTER STUDENT NAME: " << endl;
					getline(cin, name);
					cout << "ENTER STUDENT SECTION: " << endl;
					getline(cin, section);
					cout << "ENTER STUDENT SEMESTER: " << endl;
					getline(cin, semester);
					cout << "ENTER STUDENT PHONE NO: " << endl;
					getline(cin, phone_num);
					cout << "ENTER STUDENT ENROLLMENT: " << endl;
					getline(cin, enrollment);
					cout << "ENTER STUDENT DOB (dd/mm/yyyy): " << endl;
					getline(cin, DOB);
					cout << "ENTER STUDENT EMAIL: " << endl;
					getline(cin, email);

					student[i].setname(name);
					student[i].setenrollment(enrollment);
					student[i].setsection(section);
					student[i].setsemester(semester);
					student[i].setphone_num(phone_num);
					student[i].setdob(DOB);
					student[i].setemail(email);
					cout << "Press any key to proceed.." << endl;
					_getch();

				}
				else if (choice != "1")
				{
					cout << "Alright ! PRESS ANY KEY TO CONTINUE.." << endl;
					_getch();
				}
			}

			else
			{


			}
		}
	}


};

class searchstudent :virtual public enterdata, virtual public deletestudent, virtual public editstudent, virtual public addstudent{
public:
	void searchStudent(int counter, searchstudent student[1000])
	{
		string enroll;

		bool print = false;
		cout << "SEARCH STUDENT RECORD " << endl;
		if (counter == 0)
		{
			cout << "THERE IS NO STUDENT RECORD TO SEARCH " << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}	cin.ignore();
		cout << "ENTER STUDENT ENROLLMENT : " << endl;
		getline(cin, enroll);
		for (int i = 0; i < counter; i++)
		{
			if (student[i].getenrollment() == enroll)
			{
				cout << "STUDENT FOUND " << endl;
				cout << "Name  : " << student[i].getname() << endl;
				cout << "SECTION : " << student[i].getsection() << endl;
				cout << "SEMESTER : " << student[i].getsemester() << endl;
				cout << "ENROLLMENT : " << student[i].getenrollment() << endl;
				cout << "DATE OF BIRTH : " << student[i].getDob() << endl;
				cout << "PHONE NUMBER : " << student[i].getphone_num() << endl;
				cout << "EMAIL : " << student[i].getemail() << endl;
				print = true;
			}
			if (print)
			{
				cout << "PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();

			}
			else
			{
				cout << "STUDENT RECORD NOT FOUND " << endl;
				cout << "PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();

			}
		}
	}
};


class viewstudent :virtual public enterdata, virtual public deletestudent, virtual public editstudent, virtual public searchstudent, virtual public addstudent{
public:
	void viewAllStudent(int counter, viewstudent student[10])
	{
		cout << "VIEW ALL THE STUDENT RECORDS " << endl;
		if (counter == 0)
		{
			cout << "THERE IS NO STUDENT RECORDS TO VIEW FIRST ADD THE STUDENT RECORDS!" << endl;
			cout << " Press any key to continue..." << endl;
			_getch();

		}
		else
		{

			system("cls");
			cout << setw(50) << setfill('*') << "*" << endl;
			cout << "\tStudents  DETAILS " << endl;
			cout << setw(50) << setfill('*') << "*" << endl;


			for (int i = 0; i < counter; i++)
			{

				cout << "STUDENT NAME :" << student[i].getname() << endl;
				cout << "STUDENT ENROLLMENT :" << student[i].getenrollment() << endl;
				cout << "STUDENT SECTION :" << student[i].getsection() << endl;
				cout << "STUDENT SEMESTER :" << student[i].getsemester() << endl;
				cout << "STUDENT PHONR NO :" << student[i].getphone_num() << endl;
				cout << "STUDENT DATE OF BIRTH :" << student[i].getDob() << endl;
				cout << "STUDENT EMAIL :" << student[i].getemail() << endl << endl;
				cout << setw(50) << setfill('=') << "=" << endl;
			}cout << "Press any key to continue . . .";
			_getch();

		}
	}


};


void quit(void)
{
	system("cls");
	cout << "\t\t" << setw(50) << setfill('=') << "=" << endl;
	cout << "\t\t             THE PROGRAM HAS BEEN ENDED \n";
	cout << "\t\t" << setw(50) << setfill('=') << "=" << endl;

	system("pause");
	exit(1);
}

int main(){
	system("color 06");
	viewstudent student[1000];
	string select;

	system("cls");
	do
	{
		system("cls");
		cout << "\t\t\t\t" << setw(50) << setfill('=') << "=" << endl;
		cout << "\t\t\t\t\tSTUDENT DATABASE MANAGEMENT SYSTEM\n";
		cout << "\t\t\t\t" << setw(50) << setfill('=') << "=" << endl;
		cout << "\t\t\t\t     Prepared by:  Umair Raza(Leader)   (105)\n";
		cout << "\t\t\t\t                   Muhammad Ameer Hamza (043)\n";


		cout << "\n\n\n1. ADD STUDENT RECORD " << endl;
		cout << "2. DELETE STUDENT RECORD " << endl;
		cout << "3. EDIT STUDENT RECORD  " << endl;
		cout << "4. SEARCH STUDENT RECORD  " << endl;
		cout << "5. VIEW STUDENT RECORD PROFILE " << endl;
		cout << "6. QUIT" << endl;
		cout << "7. main " << endl;

		cout << "\nEnter your choice here : ";
		cin >> select;

		if (select == "1")
		{
			student[counter].Addstudent(counter);

		}
		else if (select == "2")
		{
			student[counter].deleteStudent(counter, student);
		}

		else if (select == "3")
		{
			student[counter].editStudent(counter, student);
		}

		else if (select == "4")
		{
			student[counter].searchStudent(counter, student);
		}

		else if (select == "5")
		{

			student[counter].viewAllStudent(counter, student);
		}

		else if (select == "6")
		{
			quit();

		}

		else
		{
			main();
		}


	} while (select != "6");


	system("pause");
}
