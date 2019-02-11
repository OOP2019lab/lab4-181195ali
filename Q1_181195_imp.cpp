#include <iostream>
#include <fstream>
#include <string.h>
#include "Q1_181195.h"
using namespace std;
int CricketTeam :: getNo_of_members()//Getting number of members
{
	return no_of_members;
}
void CricketTeam :: setNo_of_members(int n)// Setting the number of members
{
	no_of_members = n;
}
int CricketTeam :: getRank() //Getting the rank
{
	return Rank;
}
void CricketTeam :: setRank(int r)//Setting the rank
{
	Rank = r;
}
string CricketTeam :: getCaptain() // Getting the captain
{
	return captain;
}
void CricketTeam :: setCaptain(string c) // Setting the captain
{
	captain = c;
}
void CricketTeam :: getTeamName(char * name) const
{
	strcpy(name, this->teamName);
}

void CricketTeam :: setTeamName(char * name)//Setting the teamname
{
	if (this->teamName)
		delete[] this->teamName;
	this->teamName = new char[strlen(name) + 1];
	strcpy(this->teamName, name);
}
CricketTeam::CricketTeam()// Default constuctor
{
	no_of_members = -1;
	membernames = new string[no_of_members];
	for (int i = 0; i < no_of_members; i++)
		membernames[i] = "";
	teamName = new char[25];
	string str(teamName);
	str = "";
	for (int i = 0; i < 10; i++)
		Scoreinlast10matches[i] = 0;
	Rank = 0;
	captain = "";


}
CricketTeam::CricketTeam(string Name, int No_of_Members)// Constuctor
{
	no_of_members = No_of_Members;
	membernames = new string[No_of_Members];
	for (int i = 0; i < No_of_Members; i++)
		membernames[i] = "";
	teamName = new char[25];
	string str(teamName);
	str = Name;
	for (int i = 0; i < 10; i++)
		Scoreinlast10matches[i] = 0;
	Rank = 0;
	captain = "";

}
CricketTeam::CricketTeam(string filename)// Constuctor // Do Check my text file

{
	ifstream fin("filename.txt");
	//Out of time plus brain coming to a halt
	//Leaving this empty was better than plaigiarism
	//tried to do it but was useless
}
void CricketTeam::inputTeamMember(string name)// Inputs a team member in the 'TeamMember' array
{
	int a = -1;
	for (int i = 0; i < no_of_members; i++)
		if (membernames[i].empty())
			a = i;
	if (a == -1)
	{
		for (int i = 0; i < no_of_members; i++)
			if (membernames[i].empty())
				a = i;
		membernames[a] = name;

	}
	else
		cout << "The array is full, No more names can be added. ";
}
int CricketTeam::averageScore(int arr[], int size)// Calculates the average score of the last 10 matches
{
	int avg, sum = 0;
	for (int i = 0; i < size; i++)
		sum = sum + arr[i];
	avg = sum / size;
	return avg;
}
bool CricketTeam::Compare(CricketTeam team)// This tells us which team is better by comparing their averages
{
	int avg1 = averageScore(Scoreinlast10matches, 10);
	int avg2 = averageScore(team.Scoreinlast10matches, 10);
	if (avg1 >= avg2)
		return true;
	else
		return false;

}
void CricketTeam::inputScore(int score)// Inputs the score in the 'Scoreinlast10matches' array if not full else discards one and input the given
{
	int a = 0;
	for (int i = 0; i < 10; i++)
		if (Scoreinlast10matches[i] == 0)
		{
			a = i;
			Scoreinlast10matches[a] = score;
		}
		else
		{
			for (int i = 9; i > 0; i--)
				Scoreinlast10matches[i - 1] = Scoreinlast10matches[i];
			Scoreinlast10matches[9] = score;
		}
}
void CricketTeam :: latestScore(int arr[]) // This prints the latest score of the team
{
	cout << "Latest score: "<< arr[9]<<endl;
	cout << "Team name: ";
	for (int i = 0; teamName[i] != 0; i++)
		cout << teamName[i];
	cout << endl << "captain: "<<getCaptain;
}
void CricketTeam :: teamInfo(CricketTeam team) // This prints the teams overall information
{
	cout <<"Team Name: ";
	for (int i = 0; teamName[i] != 0; i++)
		cout << teamName[i];
	cout << endl << "Total members: "<< getNo_of_members()<<endl;
	for (int i = 0; i < no_of_members; i++)
		cout << membernames[i];
	//Mind trolling
}
CricketTeam :: ~CricketTeam() //Destruction of CricketTeam was invoked
{
	delete[] membernames;
	delete[] teamName;

}