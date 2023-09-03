#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
int control = 1;
int strln(char*& arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}
void beauty()
{
	
	system("color 3f");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t=====================================================================" << endl;
	cout << "\t\t\t\t|                                                                   |" << endl;
	cout << "\t\t\t\t|                    MADE BY: MUHAMMAD SAMIULLAH                    |" << endl;
	cout << "\t\t\t\t|                                                                   |" << endl;
	cout << "\t\t\t\t=====================================================================" << endl;
	Sleep(3000);
	system("cls");
	cout << "\t\t\t\t=====================================================================" << endl;
	cout << "\t\t\t\t|                                                                   |" << endl;
	cout << "\t\t\t\t|            WELCOME TO THE UNIVERSITY OF CENTRAL PUNJAB            |" << endl;
	cout << "\t\t\t\t|                                                                   |" << endl;
	cout << "\t\t\t\t=====================================================================" << endl;
	Sleep(1000);
	cout << "\t\t\t\t|  OFFERING 100+ COURSES ON CAMPUS.				    |" << endl;
	Sleep(1000);
	cout << "\t\t\t\t|  450 TOP ASIAN QS RANKING                                         |" << endl;
	Sleep(1000);
	cout << "\t\t\t\t|  82/100 HEC SCORE QUALITY INSURANCE                               |" << endl;
	Sleep(1000);
	cout << "\t\t\t\t|  WITH QUALIFIED FACULTY.					    |" << endl;
	Sleep(1000);
	cout << "\t\t\t\t|  BUILT IN GIRLS HOSTEL                                            |" << endl;
	Sleep(1000); 
	cout << "\t\t\t\t|  OUR MISSION TO PROVIDE QUALITY EDUCATION TO OUR STUDENTS         |" << endl;
	Sleep(1000); 
	cout << "\t\t\t\t=====================================================================" << endl;
	Sleep(4000);
	system("cls");
}
bool EnterIDCheck(char*& arr);
void clearRecords(ifstream& main);
void copyTillSlash(char*& arr, char*& brr, char*& temp_section);
void list_courses(ifstream& main);
void int_del_single(int*& arr);
void char_del_single(char*& arr);
void char_del_double(char**&);
int firstOptions();
int displayOptions(ifstream& main);
void initialize_2D(char**& arr, int& rows, int col);
void initialize_1D(char*& arr, int size);
void enrollment(ifstream& mian, int choice);
void drop(ifstream& main, int choice);
void update_section(ifstream& main, int choice);
void total_students_enrolled(ifstream& main, int choice);
bool char_same(char*& arr, char*& brr, int size);
void la_waris_course(ifstream& main);

int main()
{
	beauty();
	while (control != 0)
	{
		ifstream main;
		int first = 0;
		main.open("courses.txt");
		if (main.is_open())
		{

			first = firstOptions();
			control = first;

			if (first == 1)
			{
				int choice = displayOptions(main);
				Sleep(1000);
				system("cls");
				enrollment(main, choice);
				cout << endl << endl << endl << endl;
				Sleep(5000);
				system("cls");
			}
			else if (first == 2)
			{
				int choice = displayOptions(main);
				Sleep(1000);
				system("cls");
				drop(main, choice);
				cout << endl << endl << endl << endl;
				Sleep(5000);
				system("cls");
			}
			else if (first == 3)
			{
				Sleep(1000);
				system("cls");
				list_courses(main);
				cout << endl << endl << endl << endl;
				Sleep(5000);
				system("cls");
			}
			else if (first == 4)
			{
				int choice = displayOptions(main);
				Sleep(1000);
				system("cls");
				update_section(main, choice);
				cout << endl << endl << endl << endl;
				Sleep(5000);
				system("cls");
			}
			else if (first == 5)
			{
				int choice = displayOptions(main);
				Sleep(1000);
				system("cls");
				total_students_enrolled(main, choice);
				cout << endl << endl << endl << endl;
				Sleep(5000);
				system("cls");
			}
			else if (first == 6)
			{
				la_waris_course(main);
				Sleep(5000);
				system("cls");
			}
		}
		else
		{
			cout << "Source file not found!" << endl;
		}
		main.close();
	}
	system("pause");
	return 0;
}
int firstOptions()
{
	cout << "\t\t\t\t=====================================================================" << endl;
	cout << "\t\t\t\t|                                                                   |" << endl;
	cout << "\t\t\t\t|            WELCOME TO STUDENT COURSE MANAGEMENT SYSTEM            |" << endl;
	cout << "\t\t\t\t|                                                                   |" << endl;
	cout << "\t\t\t\t=====================================================================" << endl;
	Sleep(1000);
	cout << "\t\t\t\t|  PRESS 1 for Enrollment of a student in a course                  |" << endl;
	cout << "\t\t\t\t|  PRESS 2 for dropping a particular course                         |" << endl;
	cout << "\t\t\t\t|  PRESS 3 for displaying courses enrolled by a particular student  |" << endl;
	cout << "\t\t\t\t|  PRESS 4 for updating the section of an already enrolled course   |" << endl;
	cout << "\t\t\t\t|  PRESS 5 for display all students enrolled in a partiular course  |" << endl;
	cout << "\t\t\t\t|  PRESS 6 for displaying a course not enrolled by any student      |" << endl;
	cout << "\t\t\t\t|  PRESS 0 TO EXIT...                                               |" << endl;
	cout << "\t\t\t\t=====================================================================" << endl;
	cout << "\n\t\t\t\tEnter your choice: ";
	int* choice = new int;
	cin >> *choice;
	return *choice;

}
void char_del_single(char*& arr)
{
	delete[]arr;
	arr = nullptr;
}
void char_del_double(char**& arr)
{
	delete[]arr;
	arr = nullptr;
}
void la_waris_course(ifstream& main)
{

	int lines = 0;
	char* garbage = new char[200];
	main.clear();
	main.seekg(ios::beg);
	while (!main.eof())
	{

		main.getline(garbage, 199);
		if (strln(garbage) > 2)
		{
			lines++;
		}
	}
	main.clear();
	main.seekg(ios::beg);

	ifstream fin;
	for (int h = 1; h <= lines; h++)
	{


		char* course_code = new char[50];
		initialize_1D(course_code, 50);
		main >> course_code;
		main.ignore();
		main.getline(garbage, 199);

		int course_size = strln(course_code);
		course_code[course_size] = '.';
		course_code[course_size + 1] = 't';
		course_code[course_size + 2] = 'x';
		course_code[course_size + 3] = 't';
		fin.open(course_code);//inp file opened
		if (!fin.is_open())
		{
			ofstream need;
			need.open(course_code);
			need.close();
			fin.open(course_code);
		}
		int students = 0;
		while (!fin.eof())
		{
			fin.getline(garbage, 199);
			if (strln(garbage) > 5)
			{
				students++;
			}
		}
		course_code[course_size] = 0;
		course_code[course_size + 1] = 0;
		course_code[course_size + 2] = 0;
		course_code[course_size + 3] = 0;
		if (students == 0)
		{
			if (strln(course_code) > 2)
			{

				cout << course_code << " has not been enrolled by any student!" << endl;
			}
		}

		fin.close();


		char_del_single(course_code);
	}







	char_del_single(garbage);


}
void total_students_enrolled(ifstream& main, int choice)
{

	ifstream fin;

	char* garbage = new char[200];
	char* course_code = new char[50];
	//null character initialization
	initialize_1D(course_code, 50);
	for (int i = 0; i < choice; i++)
	{
		main >> course_code;
		main.getline(garbage, 199);
	}
	int course_size = strln(course_code);
	course_code[course_size] = '.';
	course_code[course_size + 1] = 't';
	course_code[course_size + 2] = 'x';
	course_code[course_size + 3] = 't';
	fin.open(course_code);//inp file opened
	if (!fin.is_open())
	{
		ofstream need;
		need.open(course_code);
		need.close();
		fin.open(course_code);
	}
	int students = 0;
	while (!fin.eof())
	{
		fin.getline(garbage, 199);
		if (strln(garbage) > 5)
		{
			students++;
		}
	}
	char_del_single(garbage);
	char_del_single(course_code);
	if (students > 0)
	{
		cout << "Total enrolled students in this course is: " << students << endl;
	}
	else
		cout << "No student has yet enrolled this course!" << endl;
}
void initialize_1D(char*& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = '\0';
	}
}
void list_courses(ifstream& main)
{
	ofstream need;
	bool yes_registered = false;
	char garbage[100] = { 0 };
	int file_lines = 0;
	char waste = 0;
	while (!main.eof())
	{
		main.getline(garbage, 99);
		file_lines++;
	}
	main.clear();
	main.seekg(ios::beg);
	int* credit_hours = new int[file_lines];
	char** course_code = new char* [file_lines];
	char** course_name = new char* [file_lines];
	for (int i = 0; i < file_lines; i++)
	{
		course_name[i] = new char[200];
		course_code[i] = new char[200];
	}
	initialize_2D(course_code, file_lines, 200);
	initialize_2D(course_name, file_lines, 200);
	int i = 0;
	while (!main.eof())
	{
		main >> course_code[i];
		main >> credit_hours[i];
		main >> waste >> waste;
		main.getline(course_name[i], 199);
		i++;
	}
	main.clear();
	main.seekg(ios::beg);





	char* rollnumber = new char[50];
	initialize_1D(rollnumber, 50);
	while (cin)
	{
		cout << "Enter your Student ID: ";
		cin.ignore();
		cin.getline(rollnumber, 49);
		if (!EnterIDCheck(rollnumber))
		{
			cout << "Invalid Roll Number!" << endl;
		}
		else
		{
			break;
		}
	}
	char* temp_roll = new char[50];
	initialize_1D(temp_roll, 50);

	for (int p = 0; p < file_lines; p++)
	{

		ifstream fin;
		int course_size = strln(course_code[p]);
		course_code[p][course_size] = '.';
		course_code[p][course_size + 1] = 't';
		course_code[p][course_size + 2] = 'x';
		course_code[p][course_size + 3] = 't';
		char section[10] = { 0 };
		fin.open(course_code[p]);//opening course file p(0-5)
		if (!fin.is_open())
		{
			need.open(course_code[p]);
			need.close();
			fin.open(course_code[p]);
		}
		course_code[p][course_size] = 0;
		course_code[p][course_size + 1] = 0;
		course_code[p][course_size + 2] = 0;
		course_code[p][course_size + 3] = 0;
		while (!fin.eof())
		{
			fin.getline(temp_roll, 49, '/');
			fin.getline(section, 9);
			if (char_same(temp_roll, rollnumber, strln(rollnumber)))
			{
				cout << "Course code: " << course_code[p] << " (" << credit_hours[p] << " credit hours)" << endl;
				cout << "Section: " << section << endl << endl << endl;
				yes_registered = true;
			}
		}
		fin.close();


	}
	char_del_single(rollnumber);
	char_del_single(temp_roll);
	if (!yes_registered)
	{
		cout << "Student is NOT registered in any course!" << endl;
	}
	char_del_double(course_code);
	char_del_double(course_name);
	int_del_single(credit_hours);

}
void int_del_single(int*& arr)
{
	delete[]arr;
	arr = nullptr;
}
void copyTillSlash(char*& arr, char*& brr, char*& temp_section)
{
	int i = 0;
	while (cin)
	{
		if (arr[i] == '/')
		{
			break;
		}
		brr[i] = arr[i];
		i++;
	}
	int f = 0;
	for (int k = i + 1; arr[k] != '\0'; k++)
	{
		temp_section[f] = arr[k];
		f++;
	}
}
bool EnterIDCheck(char*& arr)
{
	if (strln(arr) == 13)
	{
		return true;
	}
	return false;
}
void update_section(ifstream& main, int choice)
{
	ofstream fout, temp;
	ifstream fin;

	char* garbage = new char[200];
	char* rollnumber = new char[50];
	initialize_1D(rollnumber, 50);
	char* section = new char[20];
	initialize_1D(section, 20);
	char* course_code = new char[50];
	initialize_1D(course_code, 50);
	main.clear();
	main.seekg(ios::beg);
	for (int i = 0; i < choice; i++)
	{
		main >> course_code;//now this has what we wanna open in ifstream
		main.getline(garbage, 199);
	}

	int course_size = strln(course_code);
	course_code[course_size] = '.';
	course_code[course_size + 1] = 't';
	course_code[course_size + 2] = 'x';
	course_code[course_size + 3] = 't';

	char* arr = new char[200];
	initialize_1D(arr, 200);
	while (cin)
	{
		while (cin)
		{
			cout << "Enter your Student ID: ";
			cin.ignore();
			cin.getline(rollnumber, 49);
			if (!EnterIDCheck(rollnumber))
			{
				cout << "Invalid Roll Number!" << endl;
			}
			else
			{
				break;
			}
		}
		if (!EnterIDCheck(rollnumber))
		{
			cout << "Invalid Roll Number! " << endl;
		}
		else
		{
			break;
		}

	}
	char* temp_section = new char[20];
	initialize_1D(temp_section, 20);
	bool record_not_found = false;
	fin.open(course_code);//inp file opened
	if (!fin.is_open())
	{
		ofstream need;
		need.open(course_code);
		need.close();
		fin.open(course_code);
	}
	temp.open("temp.txt");
	while (!fin.eof())
	{
		fin.getline(garbage, 199);
		if (!strln(garbage) > 2)
		{
			continue;
		}

		copyTillSlash(garbage, arr, temp_section);
		if (char_same(rollnumber, arr, strln(rollnumber)))
		{
			if (!record_not_found)
			{
				cout << "Enter your new section: ";
				cin >> section;
				temp << arr << "/" << section << endl;
				record_not_found = true;
			}
		}
		else
		{
			if (strln(arr) > 4 && strln(temp_section) > 0)
			{
				temp << arr << "/" << temp_section << endl;
			}
		}

	}
	if (record_not_found)
	{
		cout << "Section changed successfully!" << endl;
	}
	if (!record_not_found)
	{
		cout << "Student not found!" << endl;
	}
	fin.close();
	temp.close();


	fin.open("temp.txt");
	fout.open(course_code);
	while (!fin.eof())
	{
		fin.getline(arr, 199);
		fout << arr << endl;
	}
	fin.close();
	fout.close();

	char_del_single(garbage);
	char_del_single(rollnumber);
	char_del_single(section);
	char_del_single(course_code);
	char_del_single(arr);
	char_del_single(temp_section);
}
bool char_same(char*& arr, char*& brr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != brr[i])
		{
			return false;
		}
	}
	return true;
}
void drop(ifstream& main, int choice)
{

	ofstream fout, temp, FOUT_NEED;
	ifstream fin;

	char* garbage = new char[200];
	char* rollnumber = new char[50];
	initialize_1D(rollnumber, 50);
	char* section = new char[20];
	initialize_1D(section, 20);
	char* course_code = new char[50];
	initialize_1D(course_code, 50);
	for (int i = 0; i < choice; i++)
	{
		main >> course_code;//now this has what we wanna open in ifstream
		main.getline(garbage, 199);
	}

	int course_size = strln(course_code);
	course_code[course_size] = '.';
	course_code[course_size + 1] = 't';
	course_code[course_size + 2] = 'x';
	course_code[course_size + 3] = 't';

	fin.open(course_code);//inp file opened
	if (!fin.is_open())
	{
		FOUT_NEED.open(course_code);
		FOUT_NEED.close();
		fin.open(course_code);
	}
	temp.open("temp.txt");//now let the searching begin hehe boi
	char* arr = new char[200];
	initialize_1D(arr, 200);
	while (cin)
	{
		cout << "Enter your Student ID: ";
		cin.ignore();
		cin.getline(rollnumber, 49);
		if (!EnterIDCheck(rollnumber))
		{
			cout << "Invalid Roll Number!" << endl;
		}
		else
		{
			break;
		}
	}
	bool record_not_found = false;
	while (!fin.eof())
	{
		fin.getline(arr, 199);
		if (!char_same(rollnumber, arr, strln(rollnumber)))
		{
			temp << arr << endl;
		}
		else
		{
			record_not_found = true;//display an error message
			continue;
		}
	}
	fin.close();
	temp.close();
	fin.open("temp.txt");
	fout.open(course_code);
	while (!fin.eof())
	{
		fin.getline(arr, 199);
		fout << arr << endl;
	}
	fin.close();
	fout.close();
	if (!record_not_found)
	{
		cout << "Student record not found! " << endl;
	}
	else if (record_not_found)
	{
		cout << "Record deleted successfully!" << endl;
	}

	char_del_single(garbage);
	char_del_single(rollnumber);
	char_del_single(section);
	char_del_single(course_code);
	char_del_single(arr);
}
void enrollment(ifstream& main, int choice)
{
	ofstream fout;
	ifstream fin;
	char* garbage = new char[200];
	char* rollnumber = new char[50];
	initialize_1D(rollnumber, 50);
	char* section = new char[20];
	initialize_1D(section, 20);//i was taking file names from ifstream (to open)
	char* course_code = new char[50];
	initialize_1D(course_code, 50);
	char* temp_section = new char[50];
	initialize_1D(temp_section, 50);
	for (int i = 0; i < choice; i++)
	{
		main >> course_code;
		main.getline(garbage, 199);
	}
	int course_size = strlen(course_code);
	course_code[course_size] = '.';
	course_code[course_size + 1] = 't';
	course_code[course_size + 2] = 'x';
	course_code[course_size + 3] = 't';
	//CHECK for already existent
	fin.open(course_code);
	if (!fin.is_open())
	{
		ofstream need;
		need.open(course_code);
		need.close();
		fin.open(course_code);
	}
	cout << "Enter your Student ID: ";
	cin.ignore();
	cin.getline(rollnumber, 49);
	cout << "Enter your Section: ";
	cin.getline(section, 19);
	char* temp_roll = new char[50];
	initialize_1D(temp_roll, 50);
	bool found = false;

	while (!fin.eof())
	{
		fin.getline(garbage, 199);
		copyTillSlash(garbage, temp_roll, temp_section);
		if (char_same(temp_roll, rollnumber, 49))
		{
			cout << "Student cannot enroll in this course twice! " << endl;
			found = true;
			break;
		}
	}
	fin.close();
	if (!found)
	{
		fout.open(course_code, ios::app);


		fout << rollnumber << "/" << section << endl;
		cout << "Student Enrolled Successfully!" << endl;
		fout.close();
	}
	char_del_single(garbage);
	char_del_single(rollnumber);
	char_del_single(section);
	char_del_single(course_code);
	char_del_single(temp_roll);
}
void initialize_2D(char**& arr, int& rows, int col)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = '\0';
		}
	}
}
int displayOptions(ifstream& main)
{
	char garbage[100] = { 0 };
	int file_lines = 0;
	char waste = 0;

	while (!main.eof())
	{
		main.getline(garbage, 99);
		file_lines++;
	}
	main.clear();
	main.seekg(ios::beg);


	int* credit_hours = new int[file_lines];
	char** course_code = new char* [file_lines];
	char** course_name = new char* [file_lines];
	for (int i = 0; i < file_lines; i++)
	{
		course_name[i] = new char[200];
		course_code[i] = new char[200];
	}
	initialize_2D(course_code, file_lines, 200);
	initialize_2D(course_name, file_lines, 200);
	int i = 0;
	while (!main.eof())
	{
		main >> course_code[i];
		main >> credit_hours[i];
		main >> waste >> waste;
		main.getline(course_name[i], 199);
		i++;
	}
	main.clear();
	main.seekg(ios::beg);
	for (int i = 0; i < file_lines; i++)
	{
		cout << i + 1 << ": " << course_name[i] << " (with " << credit_hours[i] << " credit hours)" << endl;
	}
	int choice = 0;
	while (cin)
	{
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice >= 0 && choice <= file_lines)
		{
			int_del_single(credit_hours);
			char_del_double(course_code);
			char_del_double(course_name);
			return choice;
		}
		cout << "Invalid Option!" << endl;
	}
	int_del_single(credit_hours);
	char_del_double(course_code);
	char_del_double(course_name);
	return choice;
}