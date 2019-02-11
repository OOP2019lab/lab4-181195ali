#include <iostream>
using namespace std;
class CricketTeam
{
private:
	string * membernames;
	int no_of_members;
	char *teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
public:
	int getRank();
	void setRank(int r);
	string getCaptain();
	void setCaptain(string c);
	int getNo_of_members();
	void setNo_of_members(int n);
	void getTeamName(char * name) const;
	void setTeamName(char * name);
	CricketTeam();
	CricketTeam(string name, int no_of_members);
	CricketTeam(string filename);
	void inputTeamMember(string name);
	void inputScore(int score);
	int averageScore(int arr[], int size);
	bool Compare(CricketTeam a);
	void latestScore(int arr[]);
	void teamInfo(CricketTeam team);
	~CricketTeam();
};
