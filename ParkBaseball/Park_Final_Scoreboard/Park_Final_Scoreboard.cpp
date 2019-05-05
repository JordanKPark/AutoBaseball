//NAME: JORDAN PARK
//DATE: 5/10/2016
//ASSIGNMENT: FINAL
//SUMMARY: FINAL

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ios>
#include <limits>
#include <Windows.h>
#include <MMSystem.h>

using namespace std;

/***************************************
*this file is the main output file with*
*header/footer/eof                     *
****************************************/
ofstream ofs("Park_Final_Scoreboard.txt");
/***************************************
*these files print the results of the  *
*game to csv files                     *
****************************************/
ofstream ofsA("AfterTeamA.csv");
ofstream ofsB("AfterTeamB.csv");
/***************************************
*these files read in names and zeroes  *
*stats from csv files                  *
****************************************/
ifstream ifsA("BaseballNamesA.csv");
ifstream ifsB("BaseballNamesB.csv");
/*************************************
*these files take the results from   *
*the previous game and add it onto   *
*the combined team stats             *
**************************************/
ifstream ifsAA("AfterTeamA.csv");
ifstream ifsBB("AfterTeamB.csv");
/*************************************
*These are files are written to and  *
*collect the combined player stats   *
**************************************/
ofstream ofsAA("CombinedA.csv");
ofstream ofsBB("CombinedB.csv");

/*************************************
*Global variables                    *
**************************************/
string no = "EoF Message ";
string hard = "Jordan Park ";
string coding = "Calculates player/team statistics ";
string of = "5/10/2016 CIS 2541-003 ";
string anything = "Cheese. ";
string labn = "Final ";

string hdr1 = "This program will simuluate a baseball game while you can relax! ";
string ftr1 = "Player stats and Team stats with scores. ";

string pipeline = "|-----------------------------------------------------------------------------------|";
string mpipe = "|------------------------------------------------------------------------------|";
string pipe = "|";
string spaceline = "|                                                                                   |";
string mspace = "|                                                                              |";
string space = " ";

string colon = ":";

//1 ______                _           _ _ 
//2 | ___ \              | |         | | |
//3 | |_/ / __ _ ___  ___| |__   __ _| | |
//4 | ___ \/ _` / __|/ _ \ '_ \ / _` | | |
//5 | |_/ / (_| \__ \  __/ |_) | (_| | | |
//6 \____/ \__,_|___/\___|_.__/ \__,_|_|_|
/***************************************
*Ascii for Baseball                    *
****************************************/
string ascii1 = "		   ______                _           _ _ ";
string ascii2 = "		   | ___ \\              | |         | | |";
string ascii3 = "		   | |_/ / __ _ ___  ___| |__   __ _| | |";
string ascii4 = "		   | ___ \\/ _` / __|/ _ \\ '_ \\ / _` | | |";
string ascii5 = "		   | |_/ / (_| \\__ \\  __/ |_) | (_| | | |";
string ascii6 = "		   \\____/ \\__,_|___/\\___|_.__/ \\__,_|_|_|";  
/*************************************
*Ascii for Cubs                      *
**************************************/
//1                     ``....``                     
//2               `:/osyhhhhhhhhyso/:`               
//3           `-+yhhhhhhhhhhhhhhhhhhhhy+-`           
//4         .+hhhhhhhhhhhhyyyyhhhhhhhhhhhh+.         
//5       .ohhhhhhhhs+:.``    ``.:+shhhhhhhho.       
//6     `+hhhhhhho- `.:+oossssoo+:.` -ohhhhhhh+`     
//7    `yhhhhhh+. -+osssssssssssssso+- .+hhhhhhs`    
//8   `yhhhhhy. -osssssssssssssssssssso- .yhhhhhy`   
//9  `shhhhhs `+sssssso/-``  ``-/ossss+-   shhhhhs`  
//10  /hhhhhy` +ssssso-            -o+-     `yhhhhh/  
//11 `yhhhhh- :ssssso`.:: -:: :::::-` -::::- -hhhhhy` 
//12 -hhhhhy` ssssss. /ss`/ss oss:ss/-ss:/++``yhhhhh- 
//13 -hhhhhs  ssssss` /ss`/ss osssss-.ooooso` shhhhh- 
//14 -hhhhhy` ssssss. :ss/oss oss:ss/-oo:+ss.`yhhhhh- 
//15 `yhhhhh- :ssssso``:::::. ::::::``:::::- -hhhhhy` 
//16  /hhhhhy` +ssssso-            -o/.`-:/ `yhhhhh/  
//17  `shhhhhs `/sssssso/-``  ``-/ossss+.   shhhhhs`  
//18  `yhhhhhy. -osssssssssssssssssssso- .yhhhhhy`   
//19   `shhhhhh+. -+osssssssssssssso+- .+hhhhhhs`    
//20    `+hhhhhhho- `.:+oossssoo+:.` :ohhhhhhh+`     
//21      .ohhhhhhhhs+:.``    ``.:+shhhhhhhho.       
//22        .+hhhhhhhhhhhhyyyyhhhhhhhhhhhh+.         
//23           `-+yhhhhhhhhhhhhhhhhhhhhy+-`           
//24               `:/osyhhhhhhhhyso/:`               
//25                     ```..```                     
string cubs1 = "                     ``....``                     ";
string cubs2 = "               `:/osyhhhhhhhhyso/:`               ";
string cubs3 = "           `-+yhhhhhhhhhhhhhhhhhhhhy+-`           ";
string cubs4 = "          .+hhhhhhhhhhhhyyyyhhhhhhhhhhhh+.         ";
string cubs5 = "       .ohhhhhhhhs+:.``    ``.:+shhhhhhhho.       ";
string cubs61 = "      `+hhhhhhho- ";
string cubs62 = "`.:+oossssoo+:.`";
string cubs63 = " -ohhhhhhh+`     ";
string cubs71 = "     `yhhhhhh+. ";
string cubs72 = "-+osssssssssssssso+-";
string cubs73 = " .+hhhhhhs`    ";
string cubs81 = "    `yhhhhhy. ";
string cubs82 = "-osssssssssssssssssssso-";
string cubs83 = " .yhhhhhy`   ";
string cubs91 = "   `shhhhhs ";
string cubs92 = "`+sssssso/-``  ``-/ossss+-";
string cubs93 = "   shhhhhs`  ";
string cubs101 = "   /hhhhhy` ";
string cubs102 = "+ssssso-            -o+-";
string cubs103 = "     `yhhhhh/  ";
string cubs111 = "  `yhhhhh- ";
string cubs112 = ":ssssso`                      ";
string cubs113 = "-hhhhhy` ";
string cubs121 = "  -hhhhhy` ";
string cubs122 = "ssssss.                         ";
string cubs123 = "yhhhhh- ";
string cubs131 = "  -hhhhhs  ";
string cubs132 = "ssssss`      UBS               ";
string cubs133 = " shhhhh- ";
string cubs141 = "  -hhhhhy` ";
string cubs142 = "ssssss.                         ";
string cubs143 = "yhhhhh- ";
string cubs151 = "  `yhhhhh- ";
string cubs152 = ":ssssso`                       ";
string cubs153 = " -hhhhhy` ";
string cubs161 = "   /hhhhhy` ";
string cubs162 = "+ssssso-            -o/.`-: ";
string cubs163 = " `yhhhhh/  ";
string cubs171 = "  `shhhhhs ";
string cubs172 = "`/sssssso/-``  ``-/ossss+.";
string cubs173 = "   shhhhhs`  ";
string cubs181 = "   `yhhhhhy. ";
string cubs182 = "-osssssssssssssssssssso-";
string cubs183 = " .yhhhhhy`   ";
string cubs191 = "     `shhhhhh+. ";
string cubs192 = "-+osssssssssssssso+-";
string cubs193 = " .+hhhhhhs`    ";
string cubs201 = "      `+hhhhhhho- ";
string cubs202 = "`.:+oossssoo+:.`";
string cubs203 = " :ohhhhhhh+`     ";
string cubs21 = "       .ohhhhhhhhs+:.``    ``.:+shhhhhhhho.       ";
string cubs22 = "          .+hhhhhhhhhhhhyyyyhhhhhhhhhhhh+.         ";
string cubs23 = "            `-+yhhhhhhhhhhhhhhhhhhhhy+-`           ";
string cubs24 = "                `:/osyhhhhhhhhyso/:`               ";
string cubs25 = "                      ```..```                     ";
/*************************************
*Ascii for White Sox                 *
**************************************/
string sox1 ="                       `..`                       ";
string sox2 = "                     `.`yy`.`                     ";
string sox3 = "                    `.+mNhhNm+.`                   ";
string sox4 = "                  ..+mMMMMMMNMm+.`                 ";
string sox5 = "                `.+mMMNho:.  yMMm+.`               ";
string sox6 = "              `.+mMMMy       `mMMMm+.`             ";
string sox7 = "            `.+NMMMMMM:       -MMMMMN+.`           ";
string sox8 = "          ..+NMMMMMMMMm.       +MMMMMMN+..         ";
string sox9 = "        ..+NMMMMMMMMMMMd`       sMMMMMMMNo..       ";
string sox10 = "      ..oNMMMMMMMMMMMMMMs        sMMMMMMMMNo..     ";
string sox11 = "    ..oNMMMMMMMMMMMMMMMMM`        +NMMMMMMMMNo..   ";
string sox12 = "  .-`dMMMMMMMMMMMMMMMMMMm`         .mMMMMMMMMMd`.. ";
string sox13 = " ..h++MMMMMMMMMMMMMMMMNs`           hMMMMMMMMM+sh`.";
string sox14 = "  `.`hMMMMMMMMMMMMMMm+`          `:yMMMMMMMMMMh`.` ";
string sox15 = "    `.:dMMMMMMMMMMh:          -smMMMMMMMMMMMh:.`   ";
string sox16 = "      `.:hMMMMMMM:          /mMMMMMMNMMMMMh:.`     ";
string sox17 = "        `.:hMMMMy         /mMMMMMMMMMMMMh:.`       ";
string sox18 = "          `.:hMMy     `-omMMMMMMMMMMMMh:.`         ";
string sox19 = "            `.:hMNNNNNMMMMMMMMMMMMMMh:.`           ";
string sox20 = "              `.:hMMMMMMMMMMMMMMMMh:.`             ";
string sox21 = "                `.:hMMMMMMMMMMMMh:.`               ";
string sox22 = "                  `.:hMMMMMMMMh:.`                 ";
string sox23 = "                    `.:s/oo/s:.`                   ";
string sox24 = "                      `..yh..`                     ";
string sox25 = "                        ````                       ";

string whoisup;
/*************************************
*Ascii for Cubs Win!                 *
**************************************/
string cubswin1 = "  _____ _    _ ____   _____  __          _______ _   _ _ ";
string cubswin2 = " / ____| |  | |  _ \\ / ____| \\ \\        / /_   _| \\ | | |";
string cubswin3 = "| |    | |  | | |_) | (___    \\ \\  /\\  / /  | | |  \\| | |";
string cubswin4 = "| |    | |  | |  _ < \\___ \\    \\ \\/  \\/ /   | | | . ` | |";
string cubswin5 = "| |____| |__| | |_) |____) |    \\  /\\  /   _| |_| |\\  |_|";
string cubswin6 = " \\_____|\\____/|____/|_____/      \\/  \\/   |_____|_| \\_(_)";
/*************************************
*Ascii for Sox Win!                  *
**************************************/
string soxwin1 ="  _____  ______   __ __          _______ _   _ _ ";
string soxwin2 = " / ____|/ __ \\ \\ / / \\ \\        / /_   _| \\ | | |";
string soxwin3 = "| (___ | |  | \\ V /   \\ \\  /\\  / /  | | |  \\| | |";
string soxwin4 = " \\___ \\| |  | |> <     \\ \\/  \\/ /   | | | . ` | |";
string soxwin5 = " ____) | |__| / . \\     \\  /\\  /   _| |_| |\\  |_|";
string soxwin6 = "|_____/ \\____/_/ \\_\\     \\/  \\/   |_____|_| \\_(_)";

string motwh = "The man on third went home!";
string moswh = "The man on second went home!";
string mostwh = "The guys on second and third made it home!";
string mofwh = "The man on first went home!";
string mofswh = "The guys on first and second went home!";
string moftwh = "The guys on first and third went home!";
string mofstwh = "3 players ran home!";
string grandslam = "GRANDSLAM!";

string cubsBoard = "|Cubs                                |HR  |SO  |S   |D   |T   |AB  |OBA  |BAVG |";
string board2 = "|Player #    |Player name            |                                         |";
string soxBoard = "|White Sox                           |HR  |SO  |S   |D   |T   |AB  |OBA  |BAVG |";
string cubsBoard2 = "|Cubs                                     |HR  |SO  |S   |D   |T   |AB  |OBA  |BAVG |";
string board3 = "|Player #    |Player name                 |                                         |";
string soxBoard2 = "|White Sox                                |HR  |SO  |S   |D   |T   |AB  |OBA  |BAVG |";
string teamBoard1 = "|Team                 |Inning                             |                         |";
string teamBoard12 = "|                     |  1|  2|  3|  4|  5|  6|  7|  8|  9|             |R  |H  |E  |";
string cubbies = "Cubs";
string dasox = "White Sox";
string teamBoard21 = "|Team                 |Inning                             |                    |";
string teamBoard22 = "|                     |  1|  2|  3|  4|  5|  6|  7|  8|  9|        |R  |H  |E  |";

string rsingle = "Single!";
string rdouble = "Double!";
string rtriple = "Triple!";
string rhomerun = "Homerun!";
string rstrike = "Strike!";
string rball = "Ball!";
string rfoul = "Foul!";
string rflyout = "Fly out!";
string rerror = "Error!";

string rinning = "Inning: ";
string ratbat = "At Bat: ";
string rline = "*---------------*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*---------*";
string rdisplay = "|Strikes |Balls |                                                    |Outs     |";
string rbatter = "Batter: ";
string raction = "Action: ";
string rhewalks = "He walks!";
string rstrikeout = "Strikeout!";
string r3outs = "That's 3 outs!";

string ruquit = "|Are you sure you want to quit?                                                |";
string rgoodbye = "Goodbye.";
string rreturn = "Returning to menu...";
string rmusicon = "Music is now on.";
string rmusicoff = "Music is now off";
string rrules1 = "The team with the most points will win.";
string rrules2 = "There are 9 innings with 3 outs per inning. If a player goes";
string rrules3 = "around all 4 bases without getting out, then he scores.";
string rloadG = "Loading Game...";
string rloadS = "Loading Stats...";
string rloadW = "Loading...please wait";

string VSPINA = "Vince Spina";
string PATRICK = "Patrick Star";

/*************************************
*String arrays for menu              *
**************************************/
string MenuA[5] = { "|1.) Rules                                                                     |",
"|2.) Play                                                                      |",
"|3.) Stats                                                                     |",
"|4.) Turn music ON/OFF                                                         |",
"|5.) Quit                                                                      |" };
string GameA[3] = { "|1.) Play an inning                                                            |",
"|2.) Play full game                                                            |",
"|3.) Finish current game                                                       |" };
string StatsA[2] = { "|1.) Player Stats                                                              |",
"|2.) Team stats                                                                |" };
string MusicA[2] = { "|1.) Turn music ON                                                             |",
"|2.) Turn music OFF                                                            |" };
string QuitA[2] = { "|1.) Yes                                                                       |",
"|2.) No                                                                        |" };

string line;

void menu();

double derp;
double nerp;

int innings;
int pointer = 0;
int pointer1 = 0;
int n;
int x;
int t;
int index;
int program = 1;
int program2 = 1;
int i;
int r;
int f;
int a;
int batterRe;
int batterlineA = 0;
int batterlineB = 0;
int strikes = 0;
int outs = 0;
int balls = 0;
int batterhits = 0;
int testing = 0;
int theinning = 0;
int runtotalA;
int hittotalA;
int errortotalA;
int runtotalB;
int hittotalB;
int errortotalB;
int innon = 0;
int obcurrent = -1;
int k;
int boardinn;
int TA;
int TB;


bool isfinish = false;
bool HeOut;
bool HeHit;
bool teamAUP;
bool teamBUP;
bool issingle;
bool isdouble;
bool istriple;
bool isrun;
bool finishedgame = false;

vector<int> runA(9);
vector<int> hitA(9);
vector<int> errorA(9);

vector<int> runB(9);
vector<int> hitB(9);
vector<int> errorB(9);

/*************************************
*Sends Header, Footer, and EOF to file*
**************************************/
void hdr()
{
	ofs << pipeline << endl;
	ofs << pipe << left << setw(83) << hdr1 << pipe << endl;
	ofs << pipe << hard << setw(23) << of << setw(48) << labn << pipe << endl;
	ofs << pipeline << endl;
	ofs << spaceline << endl;
}

void ftr()
{
	ofs << spaceline << endl;
	ofs << pipeline << endl;
	ofs << pipe << left << setw(50) << ftr1 << left << setw(23) << of << left << setw(10) << labn << pipe << endl;
	ofs << pipeline << endl;
	ofs << spaceline << endl;
}

void eof()
{
	ofs << pipeline << endl;
	ofs << pipe << no << hard << left << setw(36) << coding << left << setw(23) << of << pipe << endl;
	ofs << pipe << left << anything << setw(7) << labn << right << setw(69) << pipe << endl;
	ofs << pipeline << endl;
}

/*************************************
*Function to manipulate color of text*
**************************************/
void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
/*************************************
*Colors according to the their number*
**************************************/
/*
1: Blue
2: Green
3: Cyan
4: Red
5: Purple
6: Yellow (Dark)
7: Default white
8: Gray/Grey
9: Bright blue
10: Bright green
11: Bright cyan
12: Bright red
13: Pink/Magenta
14: Yellow
*/

/*************************************
*Structure for Team A which holds    *
*var's for all players stats.        *
**************************************/
struct TeamA
{
	string namesA;
	int HRA;
	int SOA;
	int SA;
	int DA;
	int TA;
	int ABA;
	int hitsbyA;
	double OBAA;
	double BAVGA;
};
/********************************************
*Vector of the Team A structure to hold data*
*********************************************/
vector <TeamA> Ateam(9);
/*************************************
*Temporary structure for previous    *
*Team A player stat values           *
**************************************/
struct TeamAA
{
	string namesA;
	int HRA;
	int SOA;
	int SA;
	int DA;
	int TA;
	int ABA;
	int hitsbyA;
	double OBAA;
	double BAVGA;
};
/*************************************
*Vector to hold previous A player data*
**************************************/
vector <TeamAA> AAteam(9);
/*************************************
*Structure for Team B which holds    *
*var's for all players stats.        *
**************************************/
struct TeamB
{
	string namesB;
	int HRB;
	int SOB;
	int SB;
	int DB;
	int TB;
	int ABB;
	int hitsbyB;
	double OBAB;
	double BAVGB;
};
/********************************************
*Vector of the Team B structure to hold data*
*********************************************/
vector <TeamB> Bteam(9);
/*************************************
*Temporary structure for previous    *
*Team B player stat values           *
**************************************/
struct TeamBB
{
	string namesB;
	int HRB;
	int SOB;
	int SB;
	int DB;
	int TB;
	int ABB;
	int hitsbyB;
	double OBAB;
	double BAVGB;
};
/*************************************
*Vector to hold previous B player data*
**************************************/
vector <TeamBB> BBteam(9);

void initialize()
{
	for (k = 0; k < 9; k++)
	{
		/*************************************
		*Gets 0's data and name from original*
		*csv files                           *
		**************************************/
		getline(ifsA, line, ',');
		Ateam[k].namesA = line;
		getline(ifsA, line, ',');
		Ateam[k].HRA = atoi(line.c_str());
		getline(ifsA, line, ',');
		Ateam[k].SOA = atoi(line.c_str());
		getline(ifsA, line, ',');
		Ateam[k].SA = atoi(line.c_str());
		getline(ifsA, line, ',');
		Ateam[k].DA = atoi(line.c_str());
		getline(ifsA, line, ',');
		Ateam[k].TA = atoi(line.c_str());
		getline(ifsA, line, ',');
		Ateam[k].ABA = atoi(line.c_str());
		getline(ifsA, line, ',');
		Ateam[k].OBAA = atof(line.c_str());
		getline(ifsA, line, '\n');
		Ateam[k].BAVGA = atof(line.c_str());
		/*************************************
		*Gets 0's data and name from original*
		*csv files                           *
		**************************************/
		getline(ifsB, line, ',');
		Bteam[k].namesB = line;
		getline(ifsB, line, ',');
		Bteam[k].HRB = atoi(line.c_str());
		getline(ifsB, line, ',');
		Bteam[k].SOB = atoi(line.c_str());
		getline(ifsB, line, ',');
		Bteam[k].SB = atoi(line.c_str());
		getline(ifsB, line, ',');
		Bteam[k].DB = atoi(line.c_str());
		getline(ifsB, line, ',');
		Bteam[k].TB = atoi(line.c_str());
		getline(ifsB, line, ',');
		Bteam[k].ABB = atoi(line.c_str());
		getline(ifsB, line, ',');
		Bteam[k].OBAB = atof(line.c_str());
		getline(ifsB, line, '\n');
		Bteam[k].BAVGB = atof(line.c_str());

	}
	/*************************************
	*Sets values of scoreboard == 0      *
	**************************************/
	for (boardinn = 0; boardinn < 9; boardinn++)
	{
		runB[boardinn] = 0;
		runA[boardinn] = 0;
	}
}

//**************************************************************************
//this function sets the window size                                       *
//**************************************************************************
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}
void gettemp()
{
	for (k = 0; k < 9; k++)
	{
		/*************************************
		*Gets data and names from previous   *
		*games from csv files.               *
		**************************************/
		getline(ifsAA, line, ',');
		AAteam[k].namesA = line;
		getline(ifsAA, line, ',');
		AAteam[k].HRA = atoi(line.c_str());
		getline(ifsAA, line, ',');
		AAteam[k].SOA = atoi(line.c_str());
		getline(ifsAA, line, ',');
		AAteam[k].SA = atoi(line.c_str());
		getline(ifsAA, line, ',');
		AAteam[k].DA = atoi(line.c_str());
		getline(ifsAA, line, ',');
		AAteam[k].TA = atoi(line.c_str());
		getline(ifsAA, line, ',');
		AAteam[k].ABA = atoi(line.c_str());
		getline(ifsAA, line, ',');
		AAteam[k].OBAA = atof(line.c_str());
		getline(ifsAA, line, '\n');
		AAteam[k].BAVGA = atof(line.c_str());
		/*************************************
		*Gets data and names from previous   *
		*games from csv files.               *
		**************************************/
		getline(ifsBB, line, ',');
		BBteam[k].namesB = line;
		getline(ifsBB, line, ',');
		BBteam[k].HRB = atoi(line.c_str());
		getline(ifsBB, line, ',');
		BBteam[k].SOB = atoi(line.c_str());
		getline(ifsBB, line, ',');
		BBteam[k].SB = atoi(line.c_str());
		getline(ifsBB, line, ',');
		BBteam[k].DB = atoi(line.c_str());
		getline(ifsBB, line, ',');
		BBteam[k].TB = atoi(line.c_str());
		getline(ifsBB, line, ',');
		BBteam[k].ABB = atoi(line.c_str());
		getline(ifsBB, line, ',');
		BBteam[k].OBAB = atof(line.c_str());
		getline(ifsBB, line, '\n');
		BBteam[k].BAVGB = atof(line.c_str());
	}
}
/**************************************
*Adds the previous file to the present*
*to get a combined player stats file  *
**************************************/
void addtemp()
{
	for (k = 0; k < 9; k++)
	{
		AAteam[k].HRA = AAteam[k].HRA + Ateam[k].HRA;
		AAteam[k].SOA = AAteam[k].SOA + Ateam[k].SOA;
		AAteam[k].SA = AAteam[k].SA + Ateam[k].SA;
		AAteam[k].DA = AAteam[k].DA + Ateam[k].DA;
		AAteam[k].TA = AAteam[k].TA + Ateam[k].TA;
		AAteam[k].ABA = AAteam[k].ABA + Ateam[k].ABA;
		AAteam[k].OBAA = (AAteam[k].OBAA + Ateam[k].OBAA) / 2;
		AAteam[k].BAVGA = (AAteam[k].BAVGA + Ateam[k].BAVGA) / 2;

		BBteam[k].HRB = BBteam[k].HRB + Bteam[k].HRB;
		BBteam[k].SOB = BBteam[k].SOB + Bteam[k].SOB;
		BBteam[k].SB = BBteam[k].SB + Bteam[k].SB;
		BBteam[k].DB = BBteam[k].DB + Bteam[k].DB;
		BBteam[k].TB = BBteam[k].TB + Bteam[k].TB;
		BBteam[k].ABB = BBteam[k].ABB + Bteam[k].ABB;
		BBteam[k].OBAB = (BBteam[k].OBAB + Bteam[k].OBAB) / 2;
		BBteam[k].BAVGB = (BBteam[k].BAVGB + Bteam[k].BAVGB) / 2;	
	}
}
/***************************************
*Writes the combined data to a combined*
*data csv file .                       *
**************************************/
void writecombined()
{
		for (k = 0; k < 9; k++)
		{
			ofsAA << Ateam[k].namesA << ",";
			ofsAA << AAteam[k].HRA << ",";
			ofsAA << AAteam[k].SOA << ",";
			ofsAA << AAteam[k].SA << ",";
			ofsAA << AAteam[k].DA << ",";
			ofsAA << AAteam[k].TA << ",";
			ofsAA << AAteam[k].ABA << ",";
			ofsAA << AAteam[k].OBAA << ",";
			ofsAA << AAteam[k].BAVGA << "\n";

			ofsBB << Bteam[k].namesB << ",";
			ofsBB << BBteam[k].HRB << ",";
			ofsBB << BBteam[k].SOB << ",";
			ofsBB << BBteam[k].SB << ",";
			ofsBB << BBteam[k].DB << ",";
			ofsBB << BBteam[k].TB << ",";
			ofsBB << BBteam[k].ABB << ",";
			ofsBB << BBteam[k].OBAB << ",";
			ofsBB << BBteam[k].BAVGB << "\n";
		}
	}
/*************************************
*Writes the results of a the game to *
*a csv file                          *
**************************************/
void writeresults()
{
	for (k = 0; k < 9; k++)
	{
		ofsA << Ateam[k].namesA << ",";
		ofsA << Ateam[k].HRA << ",";
		ofsA << Ateam[k].SOA << ",";
		ofsA << Ateam[k].SA << ",";
		ofsA << Ateam[k].DA << ",";
		ofsA <<  Ateam[k].TA << ",";
		ofsA << Ateam[k].ABA << ",";
		ofsA << Ateam[k].OBAA << ",";
		ofsA << Ateam[k].BAVGA  << "\n";

		ofsB << Bteam[k].namesB << ",";
		ofsB << Bteam[k].HRB << ",";
		ofsB << Bteam[k].SOB << ",";
		ofsB << Bteam[k].SB << ",";
		ofsB << Bteam[k].DB << ",";
		ofsB << Bteam[k].TB << ",";
		ofsB << Bteam[k].ABB << ",";
		ofsB << Bteam[k].OBAB << ",";
		ofsB << Bteam[k].BAVGB << "\n";
	}
}
/*************************************
*initialises a song for us to hear.  *
*"Take me out" instrumental.         *
**************************************/
void playasong()
{
	PlaySound(TEXT("TakeOut.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	//PlaySound(TEXT("TakeOut.wav"), NULL, SND_ASYNC);
	//PlaySound(NULL, 0, 0);
}
/*************************************
*prototype for average calculation.  *
**************************************/
void calculateAverage();
/*****************************************
*Displays the player stats on the screen.*
*****************************************/
void doPlayerstats()
{
	calculateAverage();
	system("cls");
	//TeamA
	cout << endl << endl;
	cout << mpipe;
	cout << cubsBoard;
	cout << mpipe;
	cout << board2;
	cout << mpipe;
	for (TA = 0; TA < 9; TA++)
	{
		//						number							name												HRA                           SO								singles								
		cout << pipe << left << setw(12) << TA + 1 << pipe << setw(23) << Ateam[TA].namesA << pipe << right << setw(4) << Ateam[TA].HRA << pipe << setw(4) << Ateam[TA].SOA << pipe << setw(4) << Ateam[TA].SA << pipe
			//		Doubles							Triples						AB									OBA											BAVG
			<< setw(4) << Ateam[TA].DA << pipe << setw(4) << Ateam[TA].TA << pipe << setw(4) << Ateam[TA].ABA << pipe; 
		cout << setprecision(3) << fixed;
		cout << setw(5) << Ateam[TA].OBAA << pipe << setw(5) << Ateam[TA].BAVGA << pipe;
		cout << setprecision(0) << fixed;
		cout << mpipe;
	}
	system("pause");
	system("cls");

	cout << endl << endl;
	//TeamB
	//counsel
	cout << mpipe;
	cout << soxBoard;
	cout << mpipe;
	cout << board2;
	cout << mpipe;

	for (TB = 0; TB < 9; TB++)
	{

		//						number							name												HRA                           SO								singles								
		cout << pipe << left << setw(12) << TB + 1 << pipe << setw(23) << Bteam[TB].namesB << pipe << right << setw(4) << Bteam[TB].HRB << pipe << setw(4) << Bteam[TB].SOB << pipe << setw(4) << Bteam[TB].SB << pipe
			//		Doubles							Triples						AB									
			<< setw(4) << Bteam[TB].DB << pipe << setw(4) << Bteam[TB].TB << pipe << setw(4) << Bteam[TB].ABB;
		cout << setprecision(3) << fixed; 
		cout << pipe << setw(5) << Bteam[TB].OBAB << pipe << setw(5) << Bteam[TB].BAVGB << pipe;
		cout << setprecision(0) << fixed;
		cout << mpipe;
	}
	cout << endl;
}

/*************************************
*Sends player stats to the files     * 
**************************************/
void ofsPlayerstats()
{
	calculateAverage();
	ofs << cubsBoard2 << endl;
	ofs << pipeline << endl;
	ofs << board3 << endl;
	ofs << pipeline << endl;

	for (TA = 0; TA < 9; TA++)
	{
		//						number							name												HRA                           SO								singles								
		ofs << pipe << left << setw(12) << TA + 1 << pipe << setw(28) << Ateam[TA].namesA << pipe << right << setw(4) << Ateam[TA].HRA << pipe << setw(4) << Ateam[TA].SOA << pipe << setw(4) << Ateam[TA].SA << pipe
			//		Doubles							Triples						AB									OBA											BAVG
			<< setw(4) << Ateam[TA].DA << pipe << setw(4) << Ateam[TA].TA << pipe << setw(4) << Ateam[TA].ABA << pipe;
		ofs << setprecision(3) << fixed;
		ofs << setw(5) << Ateam[TA].OBAA << pipe << setw(5) << Ateam[TA].BAVGA << pipe << endl;
		ofs << setprecision(0) << fixed;
		ofs << pipeline << endl;
	}
	ofs << spaceline << endl;

	ofs << pipeline << endl;
	ofs << soxBoard2 << endl;
	ofs << pipeline << endl;
	ofs << board3 << endl;
	ofs << pipeline << endl;

	for (TB = 0; TB < 9; TB++)
	{
		//						number							name												HRA                           SO								singles								
		ofs << pipe << left << setw(12) << TB + 1 << pipe << setw(28) << Bteam[TB].namesB << pipe << right << setw(4) << Bteam[TB].HRB << pipe << setw(4) << Bteam[TB].SOB << pipe << setw(4) << Bteam[TB].SB << pipe
			//		Doubles							Triples						AB									OBA											BAVG
			<< setw(4) << Bteam[TB].DB << pipe << setw(4) << Bteam[TB].TB << pipe << setw(4) << Bteam[TB].ABB << pipe;
		ofs << setprecision(3) << fixed;
		ofs << setw(5) << Bteam[TB].OBAB << pipe << setw(5) << Bteam[TB].BAVGB << pipe << endl;
		ofs << setprecision(0) << fixed;
		ofs << pipeline << endl;
	}
	ofs << pipeline << endl;
}
/*************************************
*Sends team stats to the file        *
**************************************/
void ofsTeamstats()
{
	ofs << teamBoard1 << endl;
	ofs << pipeline << endl;
	ofs << teamBoard12 << endl;;
	ofs << pipeline << endl;

	runtotalA = accumulate(runA.begin(), runA.end(), 0.0);
	hittotalA = accumulate(hitA.begin(), hitA.end(), 0.0);
	errortotalA = accumulate(errorA.begin(), errorA.end(), 0.0);

	runtotalB = accumulate(runB.begin(), runB.end(), 0.0);
	hittotalB = accumulate(hitB.begin(), hitB.end(), 0.0);
	errortotalB = accumulate(errorB.begin(), errorB.end(), 0.0);

	ofs << left << pipe << setw(21) << cubbies << pipe;
	for (boardinn = 0; boardinn < 9; boardinn++)
	{
		ofs << right << setw(3) << runA[boardinn] << pipe;
	}
	ofs << right << setw(14) << pipe << setw(3) << runtotalA << pipe << setw(3) << hittotalA << pipe << setw(3) << errortotalA << pipe << endl;
	ofs << pipeline << endl;

	ofs << left << pipe << setw(21) << dasox << pipe;
	for (boardinn = 0; boardinn < 9; boardinn++)
	{
		ofs << right << setw(3) << runB[boardinn] << pipe;
	}
	ofs << right << setw(14) << pipe << setw(3) << runtotalB << pipe << setw(3) << hittotalB << pipe << setw(3) << errortotalB << pipe << endl;
	ofs << pipeline << endl;
}
/*************************************
*Displays team stats to the screen   *
**************************************/
void doTeamstats()
{
	cout << mpipe;
	cout << teamBoard21;
	cout << mpipe;
	cout << teamBoard22;
	cout << mpipe;

	//counsel cubs
	cout << left << pipe << setw(21);
	SetColor(12);
	cout << cubbies;
	SetColor(10);
	cout << pipe;

	for (boardinn = 0; boardinn < 9; boardinn++)
	{
		cout << right << setw(3) << runA[boardinn] << pipe;
	}
	runtotalA = accumulate(runA.begin(), runA.end(), 0.0);
	hittotalA = accumulate(hitA.begin(), hitA.end(), 0.0);
	errortotalA = accumulate(errorA.begin(), errorA.end(), 0.0);

	cout << right << setw(9) << pipe << setw(3) << runtotalA << pipe << setw(3) << hittotalA << pipe << setw(3) << errortotalA << pipe;
	cout << mpipe;

	//counsel sox
	cout << left << pipe << setw(21);
	SetColor(7);
	cout << dasox;
	SetColor(10);
	cout << pipe;

	for (boardinn = 0; boardinn < 9; boardinn++)
	{
		cout << right << setw(3) << runB[boardinn] << pipe;
	}
	runtotalB = accumulate(runB.begin(), runB.end(), 0.0);
	hittotalB = accumulate(hitB.begin(), hitB.end(), 0.0);
	errortotalB = accumulate(errorB.begin(), errorB.end(), 0.0);

	cout << right << setw(9) << pipe << setw(3) << runtotalB << pipe << setw(3) << hittotalB << pipe << setw(3) << errortotalB << pipe;
	cout << mpipe;
	cout << endl;	
}

/*************************************
*Function pulls a random number and  *
*then returns it.                    *
**************************************/
int get_number()
{
	int n;

	n = (rand() % 26) + 1;
	return n;
}

/*************************************
*A function that calculates the OBA  *
and the BAVG before displaying it.   *
**************************************/
void calculateAverage()
{
	for (TA = 0; TA < 9; TA++)
	{
		nerp = Ateam[TA].ABA;
		derp = Ateam[TA].HRA  + Ateam[TA].SA + Ateam[TA].DA + Ateam[TA].TA;

		if (nerp == 0)
		{
			Ateam[TA].OBAA = 0.000;
			Ateam[TA].BAVGA = 0.000;
		}
		else
		{
			Ateam[TA].OBAA = (derp / nerp);
			Ateam[TA].BAVGA = (derp / nerp);
		}
	}

	for (TB = 0; TB < 9; TB++)
	{
		nerp = Bteam[TB].ABB;
		derp = Bteam[TB].HRB + Bteam[TB].SB + Bteam[TB].DB + Bteam[TB].TB;

		if (nerp == 0)
		{
			Bteam[TB].OBAB = 0.000;
			Bteam[TB].BAVGB = 0.000;
		}
		else
		{
			Bteam[TB].OBAB = (derp / nerp);
			Bteam[TB].BAVGB = (derp / nerp);
		}
	}
}

/**************************************
*This function translates the random  *
*number into a batting/pitching result*
**************************************/
void determine(int result)
{
	/*************************************
	*Single = 1. Add to player vector    *
	**************************************/
	if (result == 1)
	{ 
		if (isfinish == false) 
		{
			cout << rsingle << endl;	
		}
		HeHit = true;
		batterhits++;
		if (teamAUP == true && teamBUP == false)
		{
			Ateam[batterlineA].SA++;
			hitA[theinning]++;
		}
		if (teamBUP == true && teamAUP == false)
		{
			Bteam[batterlineB].SB++;
			hitB[theinning]++;
		}
	}
	/*************************************
	*Double = 2. Add to player vector    *
	**************************************/
	else if (result == 2)
	{
		if (isfinish == false)
		{
			cout << rdouble << endl;
		}
		HeHit = true;
		batterhits++;
		if (teamAUP == true && teamBUP == false)
		{
			Ateam[batterlineA].DA++;
			hitA[theinning]++;
		}
		if (teamBUP == true && teamAUP == false)
		{
			Bteam[batterlineB].DB++;
			hitB[theinning]++;
		}
	}
	/*************************************
	*Triple = 3. Add to player vector    *
	**************************************/
	else if (result == 3)
	{
		if (isfinish == false) 
		{
			cout << rtriple << endl;
		}
		HeHit = true;
		batterhits++;
		if (teamAUP == true && teamBUP == false)
		{
			Ateam[batterlineA].TA++;
			hitA[theinning]++;
		}
		if (teamBUP == true && teamAUP == false)
		{
			Bteam[batterlineB].TB++;
			hitB[theinning]++;
		}
	}
	/*************************************
	*Homerun = 4. Add to player vector   *
	**************************************/
	else if (result == 4)
	{
		if (isfinish == false)
		{
			cout << rhomerun << endl;
			/*************************************
			*If Cubs are up, play sound effect.  *
			**************************************/
			if (teamAUP == true && teamBUP == false)
			{
				PlaySound(TEXT("CubsHR.wav"), NULL, SND_SYNC);
				PlaySound(TEXT("TakeOut.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);	
			}		
		}
		HeHit = true;
		batterhits++;
		if (teamAUP == true && teamBUP == false)
		{
			Ateam[batterlineA].HRA++;
			hitA[theinning]++;
		}
		if (teamBUP == true && teamAUP == false)
		{
			Bteam[batterlineB].HRB++;
			hitB[theinning]++;
		}
	}
	/*************************************
	*Strike = 5-10 Add strike.           *
	**************************************/
	else if (result >= 5 && result <=10)
	{
		if (isfinish == false) {
			cout << rstrike << endl;	
		}
		strikes++;
	}
	/*************************************
	*Ball = 11-17. Add ball.             *
	**************************************/
	else if (result >= 11 && result <= 17)
	{
		if (isfinish == false) {
			cout << rball << endl;
		}
		balls++;
	}
	/*************************************
	*Foul = 18-21. Add strike. If strikes*
	*are == 2, then don't add strike.    *
	**************************************/
	else if (result >= 18 && result <= 21)
	{
		if (isfinish == false) 
		{
			cout << rfoul << endl;
		}
		if (strikes < 2)
		{
			strikes++;
		}
	}
	/*************************************
	*Fly out = 22-25. Add out.           *
	**************************************/
	else if (result >= 22 && result <= 25)
	{
		if (isfinish == false) {
			cout << rflyout << endl;	
		}
		HeOut = true;
		outs++;
	}
	/*************************************
	*Error = 26. Add error.              *
	**************************************/
	else if (result == 26)
	{
		if (isfinish == false) 
		{
			cout << rerror << endl;		
		}
		if (teamAUP == true && teamBUP == false)
		{
			errorA[theinning]++;
		}
		if (teamBUP == true && teamAUP == false)
		{
			errorB[theinning]++;
		}
	}
}

/*************************************
*If cubs win, displays Cubs ascii and*
*plays sound effect of Harray Caray  *
*saying "Cubs win" and plays song "Go*
*Cubs go".                           *
**************************************/
void cubswon()
{
	//Red
	SetColor(12);
	cout << cubswin1 << endl;
	SetColor(14);
	cout << cubswin2 << endl;
	SetColor(10);
	cout << cubswin3 << endl;
	SetColor(11);
	cout << cubswin4 << endl;
	SetColor(9);
	cout << cubswin5 << endl;
	SetColor(5);
	cout << cubswin6 << endl;
	PlaySound(TEXT("HarryCaray.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("GoCubsGo.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	Sleep(3000);
	SetColor(10);
	system("cls");
}
/*************************************
*If Sox win, displays Sox Win ascii  *
**************************************/
void soxwon()
{
	SetColor(7);
	cout << soxwin1 << endl;
	cout << soxwin2 << endl;
	cout << soxwin3 << endl;
	cout << soxwin4 << endl;
	cout << soxwin5 << endl;
	cout << soxwin6 << endl;
	Sleep(3000);
	SetColor(10);
	system("cls");
}
/********************************************
*Compares runs and determines the winner    *
*********************************************/
void displayWinner()
{
	runtotalA = accumulate(runA.begin(), runA.end(), 0.0);
	runtotalB = accumulate(runB.begin(), runB.end(), 0.0);
	if (runtotalA == runtotalB)
	{
		runtotalA += 1;
	}
	if (runtotalA > runtotalB)
	{
		cubswon();
	}
	else if (runtotalA < runtotalB)
	{
		soxwon();
	}
}
/*************************************
*Creates the Sox Logo                *
**************************************/
void soxlogo()
{
	//7
	cout << endl;
	SetColor(7);
	cout << sox1 << endl;
	cout << sox2 << endl;
	cout << sox3 << endl;
	cout << sox4 << endl;
	cout << sox5 << endl;
	cout << sox6 << endl;
	cout << sox7 << endl;
	cout << sox8 << endl;
	cout << sox9 << endl;
	cout << sox10 << endl;
	cout << sox11 << endl;
	cout << sox12 << endl;
	cout << sox13 << endl;
	cout << sox14 << endl;
	cout << sox15 << endl;
	cout << sox16 << endl;
	cout << sox17 << endl;
	cout << sox18 << endl;
	cout << sox19 << endl;
	cout << sox20 << endl;
	cout << sox21 << endl;
	cout << sox22 << endl;
	cout << sox23 << endl;
	cout << sox24 << endl;
	cout << sox25 << endl;
}
/*************************************
*Creates the Cubs logo               *
**************************************/
void cubslogo()
{
	cout << endl; 
	SetColor(9);
	cout << cubs1 << endl;
	cout << cubs2 << endl;
	cout << cubs3 << endl;
	cout << cubs4 << endl;
	cout << cubs5 << endl;
	cout << cubs61;
	SetColor(12);
	cout << cubs62;
	SetColor(9);
	cout << cubs63 << endl;
	cout << cubs71;
	SetColor(12);
	cout << cubs72;
	SetColor(9);
	cout << cubs73 << endl;
	cout << cubs81;
	SetColor(12);
	cout << cubs82;
	SetColor(9);
	cout << cubs83 << endl;
	cout << cubs91;
	SetColor(12);
	cout << cubs92;
	SetColor(9);
	cout << cubs93 << endl;
	cout << cubs101;
	SetColor(12);
	cout << cubs102;
	SetColor(9);
	cout << cubs103 << endl;
	cout << cubs111;
	SetColor(12);
	cout << cubs112;
	SetColor(9);
	cout << cubs113 << endl;
	cout << cubs121;
	SetColor(12);
	cout << cubs122;
	SetColor(9);
	cout << cubs123 << endl;
	cout << cubs131;
	SetColor(12);
	cout << cubs132;
	SetColor(9);
	cout << cubs133 << endl;
	cout << cubs141;
	SetColor(12);
	cout << cubs142;
	SetColor(9);
	cout << cubs143 << endl;
	cout << cubs151;
	SetColor(12);
	cout << cubs152;
	SetColor(9);
	cout << cubs153 << endl;
	cout << cubs161;
	SetColor(12);
	cout << cubs162;
	SetColor(9);
	cout << cubs163 << endl;
	cout << cubs171;
	SetColor(12);
	cout << cubs172;
	SetColor(9);
	cout << cubs173 << endl;
	cout << cubs181;
	SetColor(12);
	cout << cubs182;
	SetColor(9);
	cout << cubs183 << endl;
	cout << cubs191;
	SetColor(12);
	cout << cubs192;
	SetColor(9);
	cout << cubs193 << endl;
	cout << cubs201;
	SetColor(12);
	cout << cubs202;
	SetColor(9);
	cout << cubs203 << endl;
	SetColor(9);
	cout << cubs21 << endl;
	cout << cubs22 << endl;
	cout << cubs23 << endl;
	cout << cubs24 << endl;
	cout << cubs25 << endl;
}
/*************************************
*The follow code determines each     *
*situation according to a hit where a*
*hit == 1/2/3/4. It then determines  *
*exactly how many people are on what *
*base and then all the possibilities *
*for which a hit and a combination of*
*players on base can be made.        *      
**************************************/
void manipulate(int spot)
{
	/*************************************
	*Single hit                          *
	**************************************/
	if (spot == 1)
	{
		/*************************************
		*No one on base                      *
		**************************************/
		if (issingle == false && isdouble == false && istriple == false)
		{
			issingle = true;
		}
		/*************************************
		*One guy on first                    *
		**************************************/
		else if (issingle == true && isdouble == false && istriple == false)
		{
			isdouble = true;
			issingle = true;
		}
		/*************************************
		*One guy on second                   *
		**************************************/
		else if (issingle == false && isdouble == true && istriple == false)
		{
			istriple = true;
			isdouble = false;
			issingle = true;
		}
		/*************************************
		*One guy on third                   *
		**************************************/
		else if (issingle == false && isdouble == false && istriple == true)
		{
			istriple = false;
			issingle = true;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;		
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;		
				}
				runB[theinning]++;
			}
		}

		/*************************************
		*One guy on first and second         *
		**************************************/
		else if (issingle == true && isdouble == true && istriple == false)
		{
			istriple = true;
			isdouble = true;
			issingle = true;
		}

		/*************************************
		*One guy on first and third          *
		**************************************/
		else if (issingle == true && isdouble == false && istriple == true)
		{
			issingle = true;
			isdouble = true;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;	
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;	
				}
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on second and third         *
		**************************************/
		else if (issingle == false && isdouble == true && istriple == true)
		{
			issingle = true;
			istriple = true;
			isdouble = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;	
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
				}
				runB[theinning]++;
			}
		}
		
		/*************************************
		*Bases are loaded.                   *
		**************************************/
		else if (issingle == true && isdouble == true && istriple == true)
		{
			issingle = true;
			isdouble = true;
			istriple = true;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;		
				}
				runB[theinning]++;
			}		
		}
}

/*************************************
*Double hit        *
**************************************/
	else if (spot == 2)
	{
		/*************************************
		*No one on base                      *
		**************************************/
		if (issingle == false && isdouble == false && istriple == false)
		{
			isdouble = true;
		}
		/*************************************
		*One guy on first                    *
		**************************************/
		else if (issingle == true && isdouble == false && istriple == false)
		{
			istriple = true;
			isdouble = true;
			issingle = false;	
		}
		/*************************************
		*One guy on second                   *
		**************************************/
		else if (issingle == false && isdouble == true && istriple == false)
		{
			isdouble = true;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;
					
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;		
				}
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on third                    *
		**************************************/
		else if (issingle == false && isdouble == false && istriple == true)
		{
			isdouble = true;
			istriple = false;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
				}
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on first and second         *
		**************************************/
		else if (issingle == true && isdouble == true && istriple == false)
		{
			istriple = true;
			isdouble = true;
			issingle = false;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;	
				}
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on first and third          *
		**************************************/
		else if (issingle == true && isdouble == false && istriple == true)
		{
			istriple = true;
			isdouble = true;
			issingle = false;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;	
				}
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on second and third         *
		**************************************/
		else if (issingle == false && isdouble == true && istriple == true)
		{
			issingle = false;
			isdouble = true;
			istriple = false;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mostwh << endl;
				}
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mostwh << endl;
				
				}
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*Bases loaded                        *
		**************************************/
		else if (issingle == true && isdouble == true && istriple == true)
		{
			issingle = false;
			isdouble = true;
			istriple = true;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mostwh << endl;
				}
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mostwh << endl;	
				}
				runB[theinning]++;
				runB[theinning]++;
			}	
		}
	}

	/*************************************
	*Triple Hit                          *
	**************************************/
	else if (spot == 3)
	{
		/*************************************
		*No one on base                      *
		**************************************/
		if (issingle == false && isdouble == false && istriple == false)
		{
			istriple = true;
		}
		/*************************************
		*One guy on first                    *
		**************************************/
		else if (issingle == true && isdouble == false && istriple == false)
		{
			issingle = false;
			istriple = true;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mofwh << endl;	
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mofwh << endl;		
				}
				runB[theinning]++;
			}	
		}
		/*************************************
		*One guy on second                    *
		**************************************/
		else if (issingle == false && isdouble == true && istriple == false)
		{
			isdouble = false;
			istriple = true;
			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;		
				}
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on third                    *
		**************************************/
		else if (issingle == false && isdouble == false && istriple == true)
		{
			istriple = true;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
					
				}
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
					
				}
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on first and second         *
		**************************************/
		else if (issingle == true && isdouble == true && istriple == false)
		{
			issingle = false;
			isdouble = false;
			istriple = true;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false)
				{
					cout << mofswh << endl;	
				}
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mofswh << endl;
				}
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*One guy on first and third          *
		**************************************/
		else	if (issingle == true && isdouble == false && istriple == true)
		{
			issingle = false;
			isdouble = false;
			istriple = true;
			

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << moftwh << endl;	
				}
				if (!finishedgame)
				{
					runA[theinning]++;
					runA[theinning]++;
				}
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					
					cout << moftwh << endl;
				}
				if (!finishedgame)
				{
					runB[theinning]++;
					runB[theinning]++;
				}
			}
		}
		/*************************************
		*One guy on second and third          *
		**************************************/
		else	if (issingle == false && isdouble == true && istriple == true)
		{
			issingle = false;
			isdouble = false;
			istriple = true;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mostwh << endl;	
				}
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mostwh << endl;	
				}
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*Bases loaded                        *
		**************************************/
		else if (issingle == true && isdouble == true && istriple == true)
		{
			issingle = false;
			isdouble = false;
			istriple = true;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mofstwh << endl;
				}
				runA[theinning]++;
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mofstwh << endl;
					
				}
				runB[theinning]++;
				runB[theinning]++;
				runB[theinning]++;
			}
		}
	}

	/*************************************
	*Hit a homerun                       *
	**************************************/
	else if (spot == 4)
	{
		/*************************************
		*No one on base                      *
		**************************************/
		if (issingle == false && isdouble == false && istriple == false)
		{
			issingle = false;
			isdouble = false; 
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				runB[theinning]++;
			}
		}
		/*************************************
		*One man on first                    *
		**************************************/
		else if (issingle == true && isdouble == false && istriple == false)
		{
			issingle = false;
			isdouble = false;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mofwh << endl;		
				}
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mofwh << endl;	
				}
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*One man on second                   *
		**************************************/
		else if (issingle == false && isdouble == true && istriple == false)
		{
			issingle = false;
			isdouble = false;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;	
				}
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << moswh << endl;	
				}
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*One man on third                    *
		**************************************/
		else if (issingle == false && isdouble == false && istriple == true)
		{
			issingle = false;
			isdouble = false;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;
				}
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << motwh << endl;	
				}
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*One man on first and second         *
		**************************************/
		else 	if (issingle == true && isdouble == true && istriple == false)
		{
			issingle = false;
			isdouble = false;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mofswh << endl;		
				}
				runA[theinning]++;
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) {
					cout << mofswh << endl;	
				}
				runB[theinning]++;
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*One man on first and third          *
		**************************************/
		else	if (issingle == true && isdouble == false && istriple == true)
		{
			issingle = false;
			isdouble = false;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) 
				{
					cout << moftwh << endl;
				}
				runA[theinning]++;
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) 
				{
					cout << moftwh << endl;
					
				}
				runB[theinning]++;
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*One man on second and third         *
		**************************************/
		else	if (issingle == false && isdouble == true && istriple == true)
		{
			issingle = false;
			isdouble = false;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false) {
					cout << mostwh << endl;
				}
				runA[theinning]++;
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false) 
				{
					cout << mostwh << endl;	
				}
				runB[theinning]++;
				runB[theinning]++;
				runB[theinning]++;
			}
		}
		/*************************************
		*Bases loaded                        *
		**************************************/
		else	if (issingle == true && isdouble == true && istriple == true)
		{
			issingle = false;
			isdouble = false;
			istriple = false;

			if (teamAUP == true && teamBUP == false)
			{
				if (isfinish == false)
				{
					cout << grandslam << endl;
					
				}
				runA[theinning]++;
				runA[theinning]++;
				runA[theinning]++;
				runA[theinning]++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				if (isfinish == false)
				{
					cout << grandslam << endl;
					
				}
				runB[theinning]++;
				runB[theinning]++;
				runB[theinning]++;
				runA[theinning]++;
			}
		}
	}
	
	if (isfinish == false)
	{
		Sleep(2000);	
	}
}
/*************************************
*Evaluates each batter and what they *
*did.                                *
**************************************/
void batterUP()
{
	/*************************************
	*Reset any previous batter stats     *
	**************************************/
	HeOut = false;
	HeHit = false;
	strikes = 0;
	balls = 0;
	/*************************************
	*Determine which team is up first.   *
	**************************************/
	if (teamAUP == true && teamBUP == false)
	{
		Ateam[batterlineA].ABA++;
	}
	if (teamBUP == true && teamAUP == false)
	{
		Bteam[batterlineB].ABB++;
	}
	/*************************************
	*Throw pitches till either he gets a *
	*hit or an out.                      *
	**************************************/
	while (HeOut == false && HeHit == false)
	{
		if (isfinish == false)
		{
			/*************************************
			*Display Board                       *
			**************************************/
			system("cls");
			cout << rinning << theinning + 1 << endl;
			cout << ratbat;
			if (teamAUP == true && teamBUP == false)
			{
				SetColor(12);
			}
			else if (teamBUP == true && teamAUP == false)
			{
				SetColor(7);
			}
			cout << whoisup << endl;
			SetColor(10);
			cout << endl;
			doTeamstats();

			cout << rline;
			cout << rdisplay;
			cout << rline;
			cout << pipe << right << setw(8) << strikes << pipe << setw(6) << balls << pipe << setw(53) << pipe << setw(9) << outs << pipe;
			cout << rline;
			cout << endl;
			
		}
		/*************************************
		*Display batter                      *
		**************************************/
		if (teamAUP == true && teamBUP == false)
		{
			if (isfinish == false)
			{
				cout << setw(17) << " " << left << setw(17) << rbatter;
				SetColor(13);
				cout << Ateam[batterlineA].namesA << endl;	
			}
		}
		if (teamBUP == true && teamAUP == false)
		{
			if (isfinish == false) 
			{
				cout << setw(17) << " " << left << setw(17) << rbatter;
					SetColor(13);
				cout << Bteam[batterlineB].namesB << endl;		
			}
		}
		/**************************************
		*Get a random number for batting result*
		**************************************/
		batterRe = get_number();
		/***************************************
		*Rig to let Mr. Spina get a HR everytime*
		**************************************/

		if (teamAUP == true && teamBUP == false)
		{
				if(Ateam[batterlineA].namesA == VSPINA)
				{
					batterRe = 4;
				}	
		}
		/**************************************
		*Rig to make Patrick strikeout evertime*
		**************************************/
		if (teamBUP == true && teamAUP == false)
		{
				if (Bteam[batterlineB].namesB == PATRICK)
				{
					batterRe = 7;
				}
		}
		/*************************************
		*Display action                      *
		**************************************/
		if (isfinish == false)
		{
			SetColor(10);

			cout << setw(17) << " " << left << setw(17) << raction;
			SetColor(14);
		}
			determine(batterRe);
			if (isfinish == false)
			{
				cout << setw(34) << " ";
			}
			/*************************************
			*Determine if its a hit and if anyone*
			*is on base at this time.            *
			**************************************/
			manipulate(batterRe);	
			/*************************************
			*Walk player if 4 balls were thrown  *
			**************************************/
		if (balls == 4)
		{
			if (isfinish == false)
			{
				cout << rhewalks << endl;

				if (teamAUP == true && teamBUP == false)
				{
					Ateam[batterlineA].SA++;
					hitA[theinning]++;
				}
				if (teamBUP == true && teamAUP == false)
				{
					Bteam[batterlineB].SB++;
					hitB[theinning]++;
				}	
			}
			/*************************************
			*Reset stats                         *
			**************************************/
			balls = 0;
			strikes = 0;
			batterhits++;
			HeHit = true;
			if (isfinish == false)
			{
				Sleep(2000);	
			}
		}
		/*************************************
		*Strike him out if 3 strikes         *
		**************************************/
		if (strikes == 3)
		{
			if (isfinish == false)
			{
				/*************************************
				*Sound effect of umpire saying OUT!  *
				**************************************/
				cout << rstrikeout << endl; 
				PlaySound(TEXT("CallStrike.wav"), NULL, SND_SYNC);
				PlaySound(TEXT("CallOut.wav"), NULL, SND_SYNC);
				PlaySound(TEXT("TakeOut.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			}
			/*************************************
			*Reset pitching stats                *
			**************************************/
			strikes = 0;
			balls = 0;
			HeOut = true;
			outs++;

			if (teamAUP == true && teamBUP == false)
			{
				Ateam[batterlineA].SOA++;
			}
			if (teamBUP == true && teamAUP == false)
			{
				Bteam[batterlineB].SOB++;
			}
			if (isfinish == false)
			{
				Sleep(2000);
				
			}
		}
		/*************************************
		*Reset Color                         *
		**************************************/
		SetColor(10);
		if (isfinish == false)
		{
			system("cls");	
		}
	}
	/*************************************
	*If the batterline is at 9, re-rotate*
	*This one is for cubs                 *
	**************************************/
	if (teamAUP == true && teamBUP == false)
	{
		batterlineA++;
	}

	if (batterlineA == 9)
	{
		batterlineA = 0;
	}
	/*************************************
	*If the batterline is at 9, re-rotate*
	*This one is for sox                 *
	**************************************/
	if (teamBUP == true && teamAUP == false)
	{
		batterlineB++;
	}

	if (batterlineB == 9)
	{
		batterlineB = 0;
	}
}
/********************************************
*Game function where it allows manipulatable*
*innings and start of loop for the 3 game   *
*options.                                   *
*********************************************/
void doGame()
{
	for (innings = obcurrent; innings < innon; innings++)
	{
		/*************************************
		*Put Cubs up                         *
		**************************************/
		teamAUP = true;
		teamBUP = false;
		while (teamAUP == true)
		{
			if (isfinish == false)
			{
				/*************************************
				*Show the Cubs Logo                  *
				**************************************/
				cubslogo();
				whoisup = cubbies;
				Sleep(3000);
				SetColor(10);
			}

			issingle = false;
			isdouble = false;
			istriple = false;
			/*************************************
			*Do for 3 outs.                      *
			**************************************/
			while (outs < 3)
			{
				testing++;
				strikes = 0;
				balls = 0;
				batterUP();
			}
			if (isfinish == false)
			{
				cout << r3outs << endl;
				Sleep(2000);
				system("cls");
			}
			teamAUP = false;
		}
		/*************************************
		*Put Sox to bat                      *
		**************************************/
		teamBUP = true;
		/*************************************
		*Reset outs/strikes/balls            *
		**************************************/
		outs = 0;
		strikes = 0;
		balls = 0;
		while (teamBUP == true)
		{
			if (isfinish == false)
			{
				/*************************************
				*Show the Sox Logo                  *
				**************************************/
				soxlogo();
				whoisup = dasox;
				Sleep(3000);
				SetColor(10);
			}
			issingle = false;
			isdouble = false;
			istriple = false;
			/*************************************
			*Do for 3 outs.                      *
			**************************************/
			while (outs < 3)
			{
				testing++;
				strikes = 0;
				balls = 0;
				batterUP();
			}
			if (isfinish == false) 
			{
				cout << r3outs << endl; 
				Sleep(2000);
				system("cls");		
			}
			teamBUP = false;
		}

		/*************************************
		*Reset strikes/balls/outs            *
		**************************************/
		outs = 0;
		strikes = 0;
		balls = 0;
		/*************************************
		*Inning is over. Increment           *
		**************************************/
		theinning++;
	}
	/*************************************
	*If we reached the end, decide winner*
	**************************************/
	if (innon == 9)
	{
		/*************************************
		*Show the winner                  *
		**************************************/
		displayWinner();
	}
	/*************************************
	*Show the end board                  *
	**************************************/
	doTeamstats();
	cout << endl;
}
/*************************************
*Menu-scroll for quitting the program*
**************************************/
void menu5()
{
	while (program2 == 1)
	{
		system("cls");
		SetColor(10);
		cout << mpipe;
		cout << ruquit;
		for (i = 0; i < 2; i++)
		{
			if (i == pointer1)
			{
				SetColor(14);
				cout << QuitA[i];
			}
			else
			{
				SetColor(10);
				cout << QuitA[i];
			}
		}
		SetColor(10);
		cout << mpipe;
		/*************************************
		*See what key user is pressing and where*
		**************************************/
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer1 -= 1;
				if (pointer1 == -1)
				{
					pointer1 = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer1 += 1;
				if (pointer1 == 2)
				{
					pointer1 = 0;
				}
				break;
			}
			/*************************************
			*Enter key = selected option         *
			**************************************/
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer1)
				{
					/*************************************
					*Yes or No to quit                   *
					**************************************/
				case 0:
					cout << rgoodbye << endl;
					pointer1 = -1;
					pointer = -1;
					program = 0;
					program2 = 0;
					menu();
					break;
				case 1:
					cout << rreturn << endl;
					Sleep(300);
					pointer = -1;
					program2 = 0;
					menu();
					break;
				}
				
			}
		}
		Sleep(200);		
	}
	/*************************************
	*Reset for future use                *
	**************************************/
	program2 = 1;
}

/*************************************
*Menu-scroll for turning music off/on*
**************************************/
void menu4()
{
	while (program2 == 1)
	{
		system("cls");
		SetColor(10);
		cout << mpipe;
		for (i = 0; i < 2; i++)
		{
			/*************************************
			*Display options                     *
			**************************************/
			if (i == pointer1)
			{
				SetColor(14);
				cout << MusicA[i];
			}
			else
			{
				SetColor(10);
				cout << MusicA[i];
			}
		}

		SetColor(10);
		cout << mpipe;
		/*************************************
		*Determine position of key           *
		**************************************/
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer1 -= 1;
				if (pointer1 == -1)
				{
					pointer1 = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer1 += 1;
				if (pointer1 == 2)
				{
					pointer1 = 0;
				}
				break;
			}
			/*************************************
			*Enter key = selection               *
			**************************************/
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer1)
				{
					/*************************************
					*MUSIC OR OFF/ON                     *
					**************************************/
				case 0:
					cout << rmusicon << endl;
					PlaySound(TEXT("TakeOut.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
					Sleep(300);
					pointer = -1;
					program2 = 0;
					menu();
					break;
				case 1:
					PlaySound(NULL, 0, 0);
					cout << rmusicoff << endl;
					Sleep(300);
					pointer = -1;
					program2 = 0;
					menu();
					break;
				}
			}
		}
		Sleep(200);
	}
	program2 = 1;
}
/*************************************
*Menu-scroll for stats               *
**************************************/
void menu3()
{
	while (program2 == 1)
	{
		system("cls");
		SetColor(10);
		cout << mpipe;
		for (i = 0; i < 2; i++)
		{
			/*************************************
			*Display options                     *
			**************************************/

			if (i == pointer1)
			{
				SetColor(14);
				cout << StatsA[i];
			}
			else
			{
				SetColor(10);
				cout << StatsA[i];
			}
		}
		SetColor(10);
		cout << mpipe;
		while (program2 == 1)
		{
			/*************************************
			*Get key position                    *
			**************************************/
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer1 -= 1;
				if (pointer1 == -1)
				{
					pointer1 = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer1 += 1;
				if (pointer1 == 2)
				{
					pointer1 = 0;
				}
				break;
			}
			/*************************************
			*Enter key for selection             *
			**************************************/
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				/*************************************
				*player stats or team stats          *
				**************************************/
				switch (pointer1)
				{
				case 0:
					Sleep(300);
					doPlayerstats();
					system("pause");
					pointer = -1;
					program2 = 0;
					menu();
					break;
				case 1:
					Sleep(300);
					system("cls");
					SetColor(10);
					doTeamstats();
					system("pause");
					pointer = -1;
					program2 = 0;
					menu();
					break;
				}
			}
		}
		Sleep(200);
	}
	program2 = 1;
}
/*************************************
*Menu-scroll for game options        *
**************************************/
void menu2()
{
	while (program2 == 1)
	{
		system("cls");
		SetColor(10);
		cout << mpipe;
		for (i = 0; i < 3; i++)
		{
			/*************************************
			*Display 3 options. Inning, full     *
			*game, or finish the current game.   *
			**************************************/
			if (i == pointer1)
			{
				SetColor(14);
				cout << GameA[i];
			}
			else
			{
				SetColor(10);
				cout << GameA[i];
			}
		}
		SetColor(10);
		cout << mpipe;
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer1 -= 1;
				if (pointer1 == -1)
				{
					pointer1 = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer1 += 1;
				if (pointer1 == 3)
				{
					pointer1 = 0;
				}
				break;
			}
			/*************************************
			*Enter key to select the option      *
			**************************************/
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				/*************************************
				*inning, full, finish current         *
				**************************************/
				switch (pointer1)
				{
				case 0:
					Sleep(300);
					system("cls");
					innon++;
					obcurrent++;
					isfinish = false;
					doGame();
					system("pause");
					pointer = -1;
					program2 = 0;
					menu();
					break;
				case 1:
					Sleep(300);
					system("cls");
					innon = 9;
					obcurrent = 0;
					isfinish = true;
					doGame();
					system("pause");
					pointer = -1;
					program2 = 0;
					menu();
					break;
				case 2: 
					Sleep(300);
					system("cls");
					innon = 9;
					//finishedgame = true;
					//obcurrent++;
					isfinish = true;
					doGame();
					system("pause");
					pointer = -1;
					program2 = 0;
					menu();
					break;
				}
			}
		}
		Sleep(200);
	}
	program2 = 1;
}
/****************************************
*Main scroll-menu that displays BASEBALL *
*in big letters and has 5 options: Rules,*
*Play, Stats, Music, Quit.               *
******************************************/
void menu()
{
	while (program == 1)
	{
		system("cls");
		SetColor(11);
		/*************************************
		*Baseball in big letters             *
		**************************************/
		cout << ascii1 << endl;
		cout << ascii2 << endl;
		cout << ascii3 << endl;
		cout << ascii4 << endl;
		cout << ascii5 << endl;
		cout << ascii6 << endl;
		SetColor(10);
		cout << mpipe;
		for (i = 0; i < 5; i++)
		{
			/*************************************
			*Display 5 options to the user       *
			**************************************/
			if (i == pointer)
			{
				SetColor(14);
				cout << MenuA[i];
			}
			else
			{
				SetColor(10);
				cout << MenuA[i];
			}
		}
		SetColor(10);																																							
		cout << mpipe;
		while (true)
		{
			/*************************************
			*Get key position                    *
			**************************************/
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}
			/*************************************
			*Enter = user selection               *
			**************************************/
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
				case 0:
					/*************************************
					*Rules*
					**************************************/
					system("cls");
					SetColor(13);
					cout << mpipe;
					cout << pipe << left << setw(78) << rrules1 << pipe;
					cout << pipe << setw(78) << rrules2 << pipe;
					cout << pipe << setw(78) << rrules3 << pipe;
					cout << mpipe;
					system("pause");
					pointer = -1;
					program2 = 0;
					menu();
					break;
				case 1:
					/*************************************
					*Play Game                           *
					**************************************/
					cout << rloadG << endl;
					Sleep(500);
					menu2();
					break;
				case 2:
					/*************************************
					*Stats*
					**************************************/
					cout << rloadS << endl;
					Sleep(500);
					menu3();
		
					//system("pause");
					break;
				case 3: 
					/*************************************
					*Music ON/OFF                        *
					**************************************/
					cout << rloadW << endl;
					Sleep(700);
					menu4();
					system("pause");
					break;
				case 4: 
					/*************************************
					*Quit                                *
					**************************************/
					Sleep(500);
					menu5();
					break;
				}
			}
		}
		Sleep(200);
	}

	ofs << pipeline << endl;
}

int main()
{
	SetWindow(80, 40);
	/*************************************
	*Seed for random number              *
	**************************************/
	srand(time(NULL));
	/*************************************
	*Header                              *
	**************************************/
	hdr();
	/*************************************
	*Get player stats                    *
	**************************************/
	initialize();
	gettemp();
	playasong();
	/*************************************
	*Send user to menu                   *
	**************************************/
	menu();
	/*************************************
	*Write player stats to csvs          *
	**************************************/
	ofsPlayerstats();
	ofsTeamstats();
	addtemp();
	writecombined();
	writeresults();
	/*************************************
	*EOF and FTRs                        *
	**************************************/
	ftr();
	eof();
	ofs.close();
	system("pause");
	return 0;
}