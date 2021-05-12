#include<iostream> 
#include<time.h>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
using namespace std;

int row1player = 21, row2player = 22, row3player = 23, row4player = 24, row5player = 25, row6player = 26;     //-Rows of player's ship
int col1player = 43, col2player = 44, col3player = 45, col4player = 46, col5player = 47;                      //-Columns of player's ship

int row1enemy = 4, row2enemy = 5, row3enemy = 6, row4enemy = 7;                                               //-Rows of enemy's ship 
int col1enemy = 3, col2enemy = 4, col3enemy = 5, col4enemy = 6, col5enemy = 7;                                //-Columns of enemy's ship

int l3r1enemy = 2, l3r2enemy = 3, l3r3enemy = 4, l3r4enemy = 5;                                               //-Lvl 3 enemy ships rows
int l3c1enemy = 33, l3c2enemy = 34, l3c3enemy = 35, l3c4enemy = 36, l3c5enemy = 37;                           //-Lvl 3 enemy ships cols
int l3enemybullet = 7;                                                                                        //-Lvl 3 enemyships bullets

int row1enemy2 = 4, row2enemy2 = 5, row3enemy2 = 6, row4enemy2 = 7;                                           //-Rows of enemy's ship  (wave 2)
int col1enemy2 = 13, col2enemy2 = 14, col3enemy2 = 15, col4enemy2 = 16, col5enemy2 = 17;                      //-Columns of enemy's ship (wave 2)

int r1gift = 2, r2gift = 3;                                                                                   //-Rows of gifts
int c1gift = 34, c2gift = 35, c3gift = 36;                                                                    //-Cols of gifts

int enemybullet = 6;                     //-Enemy's bullets (actually they are also row numbers)
int renemybullet = 6;                    //-Enemy's bullets wave 2(actually they are also row numbers)

int countt = 0;                          //-This counter's work is to keep a check for the renewel of variables after every frame  
int rcount = 0;                          //-This counter's work is to keep a check for the renewel of variables after every frame
int keypressed = 0;

bool escape = true;                     //-This tells that escape key is pressed, which helps to exit the game
bool gifthide1 = true;                 //-Variable to hide the gift when touched by the ship
bool gifthide2 = true;                 //-Variable to hide the gift when touched by the ship

int mybullet1 = row1player, mybullet2 = row1player, mybullet3 = row1player;    //-Player ship's bullets
int countforup = 0, countfordown = 0, countforleft = 0, countforright = 0;     //-Used to prevent glitches in our ships movement
bool deadcheckforship1 = true, deadcheckforship2 = true, deadcheckforship3 = true, deadcheckforship4 = true, deadcheckforship5 = true;  //-Enemy ships death check
bool l2deadcheckforship1 = true, l2deadcheckforship2 = true, l2deadcheckforship3 = true, l2deadcheckforship4 = true;                    //-Enemry ships death check
int invisiblecount = 0;

int health = 10, points = 0, level = 1;             
int bullettrue = 0;
bool healthcorrecter = true,onetimedoublebullet = false,gifthidecheck = true,gifthide2bullets = false;
bool twopointsaddition = false;      //-Used when gift is achieved
bool gifthidel3 = true;              //-For Lvl3 gifts
bool gamened = false;

void moveup(string plane[][115]);          //-Up movement of players ship
void movedown(string plane[][115]);        //-Down movement of players ship
void moveleft(string plane[][115]);        //-Left movement of players ship
void moveright(string plane[][115]);       //-Right movement of players ship
void enemymovedown(string plane[][115]);   //-Enmey ships movement and everything
void layout(string plane[][115]);           //-Layout of the game
void pause(string plane[][115]);            //-Game pause
void shipglitch(string plane[][115]);       //-Player ship glitch preventer
void shipmovement(string plane[][115]);     //-Controls of player ships 
void gift(string plane[][115]);             //-Gifts
void controls(int num);                     //-Main Menu controls list
void mainmenu(int num);                     //-Main menu
void credits(int num);                      
void loading(int num);
void level3enemy(string plane[][115]);

string plane[28][115];                      //-2D Array used to make the 2D plane of the game

int main()
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	mainmenu(1);
	if ((!escape) || health <= 0 || gamened)
	{
		system("pause>0");
		return 0;
	}
	int menuchoice = _getch();
	if (menuchoice != 49 && menuchoice != 50 && menuchoice != 51)
	{
		mainmenu(1);
	}
	{
		system("pause>0");
		return 0;
	}
}
void mainmenu(int num)
{
	system("cls");
	cout << setw(114) << setfill('=') << " " << endl;
	cout << setw(62) << setfill('=') << "SPACE SHOOTER" << setw(51) << setfill('=') << "=" << endl;
	cout << setw(114) << setfill('=') << " " << endl;
	cout << "=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n";
	cout << "=       .                                        PRESS 1. Start Game                              .\t\t=\n=      <|>                                                                                       <|>  \t\t=\n=     <<|>>                                      PRESS 2. Controls                              <<|>>\t\t=\n=      <|>                                                                                       <|> \t\t=\n=     <<|>>                                      PRESS 3. Credits                               <<|>>\t\t=\n=     <   >                                                                                     <   >\t\t=\n=";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n";
	cout << "=       .                             .                             .                             .  \t\t=\n=      <|>                           <|>                           <|>                           <|> \t\t=\n=     <<|>>                         <<|>>                         <<|>>                         <<|>>\t\t=\n=     <   >                         <   >                         <   >                         <   >\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=";
	cout << endl << "=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=" << endl << setw(114) << setfill('=') << " " << endl;
	cout << setw(114) << setfill('=') << " " << endl;
	int menuchoice = _getch();
	if (menuchoice != 49 && menuchoice != 50 && menuchoice != 51)
	{
		mainmenu(1);
	}
	switch (menuchoice)
	{
	case 49:
		loading(1);
		while ((points < 20 && health > 0 && level <= 2) && escape)
		{
			enemymovedown(plane);          //- Level 1 & 2
		}
		if (points >= 20)
		{    //-This is a reinitializing zone used to reinitilize all the variables to prepare them for next round-----------------------
			row1player = 21, row2player = 22, row3player = 23, row4player = 24, row5player = 25, row6player = 26;   
			col1player = 43, col2player = 44, col3player = 45, col4player = 46, col5player = 47;         
			row1enemy = 4, row2enemy = 5, row3enemy = 6, row4enemy = 7;                                 
			col1enemy = 3, col2enemy = 4, col3enemy = 5, col4enemy = 6, col5enemy = 7;              
			l3r1enemy = 2, l3r2enemy = 3, l3r3enemy = 4, l3r4enemy = 5;                                            
			l3c1enemy = 33, l3c2enemy = 34, l3c3enemy = 35, l3c4enemy = 36, l3c5enemy = 37;			
			system("cls");
			loading(1);
			system("cls");
			level = level + 1;
			points = 0;
			health = 10;
			cout << "     <o> \t\t\t\t\t\t<o>\t\t\t\t\t\t<o>\n     <o> \t\t\t\t\t\t<o>\t\t\t\t\t\t<o>";
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t==============\n\t\t\t\t\t\t    Level 2\n\t\t\t\t\t\t==============\n\n\t\t\t\tGifts will appear for a certain time on this level.\n\n\n\n\t\t\t\t\t  Press anything to continue.";
			cout << "\n\n\n\n\n\n     <o> \t\t\t\t\t\t<o>\t\t\t\t\t\t<o>\n     <o> \t\t\t\t\t\t<o>\t\t\t\t\t\t<o>";
			int random = _getch();
			system("cls");
			while ((points < 20 && health > 0) && escape)
			{
				enemymovedown(plane);
			}
			if (points >= 20)
			{
				system("cls");
				loading(1);
				system("cls");
				level = level + 1;
				points = 0;
				health = 10;
				cout << "     {o} \t\t\t\t\t\t{o}\t\t\t\t\t\t{o}\n     {o} \t\t\t\t\t\t{o}\t\t\t\t\t\t{o}";
				cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t==============\n\t\t\t\t\t\t    Level 3\n\t\t\t\t\t\t==============\n\n\t\t\t\t\n\n\n\n\t\t\t\t\t  Press anything to continue.";
				cout << "\n\n\n\n\n\n     {o} \t\t\t\t\t\t{o}\t\t\t\t\t\t{o}\n     {o} \t\t\t\t\t\t{o}\t\t\t\t\t\t{o}";
				int random = _getch();
				system("cls");
				onetimedoublebullet = false;
				twopointsaddition = false;
				while ((points < 20 && health > 0) && escape)
				{
					level3enemy(plane);
				}
				if (points >= 20)
				{
					system("cls");
					gamened = true;
					cout << "\n\n\t\t          .\t\t\t\t\t\t\t\t          .\n\t\t\t <|>\t\t\t\t\t\t\t\t\t <|>\n\t\t\t<<|>>\t\t\t\t\t\t\t\t\t<<|>>\n\t\t\t <|>\t\t\t\t\t\t\t\t\t <|>\n\t\t\t<<|>>\t\t\t\t\t\t\t\t\t<<|>>\n\t\t\t<   >\t\t\t\t\t\t\t\t\t<   >\n\n\n\t\t\t\t\t\t\t=============\n\t\t\t\t\t\t\t   YOU WON!\n\t\t\t\t\t\t\t=============\n\n\n\n\n";
				}
			}
		}
		if (health <= 0)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t=================\n\t\t\t\t\t\t    GAME OVER\n\t\t\t\t\t\t=================\n\n\n\n\n\n" << endl;
		}
		if (!escape)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t=================\n\t\t\t\t\t\t    SAYONARA!\n\t\t\t\t\t\t=================\n\n\n\n\n\n" << endl;
		}
		break;
	case 50:
		controls(1);
		break;
	case 51:
		credits(1);
		break;
	default:
		break;
	}
}
void controls(int num)
{
	loading(1);
	system("cls");
	cout << setw(114) << setfill('=') << " " << endl;
	cout << setw(62) << setfill('=') << "CONTROLS" << setw(51) << setfill('=') << "=" << endl;
	cout << setw(114) << setfill('=') << " " << endl;
	cout << "=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n";
	cout << "=       .                                       Ship Movement: Arrow Keys                         .\t\t=\n=      <|>                                                                                       <|>  \t\t=\n=     <<|>>                                     Game Pause: Space Bar                           <<|>>      \t=\n=      <|>                                                                                       <|> \t\t=\n=     <<|>>                                     Exit: Escape Key                                <<|>>\t\t=\n=     <   >                                                                                     <   >\t\t=\n=";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\tPress Any Key to go Back to the Main Menu          \t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n";
	cout << "=       .                             .                             .                             .  \t\t=\n=      <|>                           <|>                           <|>                           <|> \t\t=\n=     <<|>>                         <<|>>                         <<|>>                         <<|>>\t\t=\n=     <   >                         <   >                         <   >                         <   >\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=";
	cout << endl << "=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=" << endl << setw(114) << setfill('=') << " " << endl;
	cout << setw(114) << setfill('=') << " " << endl;
	int backmenu = _getch();
	mainmenu(1);
}
void credits(int num)
{
	loading(1);
	system("cls");
	cout << setw(114) << setfill('=') << " " << endl;
	cout << setw(60) << setfill('=') << "CREDITS" << setw(53) << setfill('=') << "=" << endl;
	cout << setw(114) << setfill('=') << " " << endl;
	cout << "=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\tGame Developers:\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n";
	cout << "=       .                                      -M Sohaib Khokhar                                  .\t        =\n=      <|>                                                                                       <|>  \t\t=\n=     <<|>>                                    -Abdullah Makki                                  <<|>>      \t=\n=      <|>                                                                                       <|> \t\t=\n=     <<|>>                                    -Arqam Aleem                                     <<|>>\t        =\n=     <   >                                                                                     <   >\t\t=\n=";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\tPress Any Key to go Back to the Main Menu          \t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=\n";
	cout << "=       .                             .                             .                             .  \t\t=\n=      <|>                           <|>                           <|>                           <|> \t\t=\n=     <<|>>                         <<|>>                         <<|>>                         <<|>>\t\t=\n=     <   >                         <   >                         <   >                         <   >\t\t=\n=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=";
	cout << endl << "=\t\t\t\t\t\t\t\t\t\t\t\t\t\t=" << endl << setw(114) << setfill('=') << " " << endl;
	cout << setw(114) << setfill('=') << " " << endl;
	int backmenu = _getch();
	mainmenu(1);
}

void shipglitch(string plane[][115])
{
	if (countforup == 0 && countforright == 0 && countforleft == 0 && countfordown == 0)
	{
		moveup(plane);
	}
	if (countforup >= countfordown && countforup >= countforright && countforup >= countforleft)
	{
		moveup(plane);
	}
	if (countfordown >= countforup && countfordown >= countforright && countfordown >= countforleft)
	{
		movedown(plane);
	}
	if (countforleft >= countfordown && countforleft >= countforright && countforleft >= countforup)
	{
		moveleft(plane);
	}
	if (countforright >= countfordown && countforright >= countforup && countforright >= countforleft)
	{
		moveright(plane);
	}
}

void gift(string plane[][115])
{
	if (!(row1enemy2 > 4 && row1enemy2 < 27))
	{
		if (gifthide1)
		{
			if (r2gift < 27)
			{
				plane[r1gift][c1gift] = "<";
				plane[r1gift][c2gift] = "o";
				plane[r1gift][c3gift] = ">";
				plane[r2gift][c1gift] = "<";
				plane[r2gift][c2gift] = "o";
				plane[r2gift][c3gift] = ">";
			}
		}
	}
	if (row1enemy2 > 4 && row1enemy2 < 27)
	{
		if (gifthide2)
		{
			if (r2gift < 27)
			{
				plane[r1gift][c1gift + 50] = "<";
				plane[r1gift][c2gift + 50] = "o";
				plane[r1gift][c3gift + 50] = ">";
				plane[r2gift][c1gift + 50] = "<";
				plane[r2gift][c2gift + 50] = "o";
				plane[r2gift][c3gift + 50] = ">";
			}
		}
	}
	r1gift++;
	r2gift++;
}
void moveup(string plane[][115])
{
	if (keypressed == 72)
	{
		countforup = countforup + 1;           //-
		countfordown = 0;                      //-some counters to secure the movemnt conditions work perfectly
		countforleft = 0;                      //-
		countforright = 0;                     //-
		if (!(row1player == 5))
		{
			row1player = row1player - 4;   //-
			row2player = row2player - 4;   //-
			row3player = row3player - 4;   //-Ship's speed determining factors
			row4player = row4player - 4;   //-
			row5player = row5player - 4;   //-
			row6player = row6player - 4;   //-
		}
	}
	if (!((row1player == row1enemy && col3player == col3enemy) || (row1player == row1enemy - 4 && col3player == col3enemy + 20) || (row1player == row1enemy - 1 && col3player == col3enemy + 60) || (row1player == row1enemy - 4 && col3player == col3enemy + 80) || (row2player == row2enemy && col3player == col3enemy) || (row2player == row2enemy - 4 && col3player == col3enemy + 20) || (row2player == row2enemy - 1 && col3player == col3enemy + 60) || (row2player == row2enemy - 4 && col3player == col3enemy + 80) || (row3player == row3enemy && col3player == col3enemy) || (row3player == row3enemy - 4 && col3player == col3enemy + 20) || (row3player == row3enemy - 1 && col3player == col3enemy + 60) || (row3player == row3enemy - 4 && col3player == col3enemy + 80) || (row4player == row4enemy && col3player == col3enemy) || (row4player == row4enemy - 4 && col3player == col3enemy + 20) || (row4player == row4enemy - 1 && col3player == col3enemy + 60) || (row4player == row4enemy - 4 && col3player == col3enemy + 80) || (enemybullet == row1player && col3enemy == col3player) || (enemybullet - 3 == row1player && col3enemy + 20 == col3player) || (enemybullet - 1 == row1player && col3enemy + 60 == col3player) || (enemybullet - 1 == row1player && col3enemy + 80 == col3player)))
	{ 
		plane[row1player][col3player] = ".";      //new written coordinates for ship's changing movement 

		plane[row2player][col1player] = " ";
		plane[row2player][col2player] = "<";      //    
		plane[row2player][col3player] = "|";
		plane[row2player][col4player] = ">";

		plane[row3player][col1player] = "<";
		plane[row3player][col2player] = "<";
		plane[row3player][col3player] = "|";      //
		plane[row3player][col4player] = ">";
		plane[row3player][col5player] = ">";

		plane[row4player][col2player] = "<";
		plane[row4player][col3player] = "|";      //
		plane[row4player][col4player] = ">";

		plane[row5player][col1player] = "<";
		plane[row5player][col2player] = "<";
		plane[row5player][col3player] = "|";      //
		plane[row5player][col4player] = ">";
		plane[row5player][col5player] = ">";

		plane[row6player][col1player] = "<";
		plane[row6player][col2player] = " ";
		plane[row6player][col3player] = " ";      //
		plane[row6player][col4player] = " ";
		plane[row6player][col5player] = ">";
	}
	else
	{
		for (int j = row1player; j <= row6player; j++)
		{
			for (int i = col1player; i <= col5player; i++)
			{
				plane[j][i] = " ";
			}
		}
	}
	keypressed = 0;
}
void movedown(string plane[][115])
{
	if (keypressed == 80)
	{
		countfordown = countfordown + 1;
		countforup = 0;
		countforleft = 0;
		countforright = 0;
		if (!(row6player == 26))
		{
			row1player = row1player + 4;
			row2player = row2player + 4;          //-Ship's speed determining factors
			row3player = row3player + 4;
			row4player = row4player + 4;
			row5player = row5player + 4;
			row6player = row6player + 4;
		}
	}
	if (!((row1player == row1enemy && col3player == col3enemy) || (row1player == row1enemy - 4 && col3player == col3enemy + 20) || (row1player == row1enemy - 1 && col3player == col3enemy + 60) || (row1player == row1enemy - 4 && col3player == col3enemy + 80) || (row2player == row2enemy && col3player == col3enemy) || (row2player == row2enemy - 4 && col3player == col3enemy + 20) || (row2player == row2enemy - 1 && col3player == col3enemy + 60) || (row2player == row2enemy - 4 && col3player == col3enemy + 80) || (row3player == row3enemy && col3player == col3enemy) || (row3player == row3enemy - 4 && col3player == col3enemy + 20) || (row3player == row3enemy - 1 && col3player == col3enemy + 60) || (row3player == row3enemy - 4 && col3player == col3enemy + 80) || (row4player == row4enemy && col3player == col3enemy) || (row4player == row4enemy - 4 && col3player == col3enemy + 20) || (row4player == row4enemy - 1 && col3player == col3enemy + 60) || (row4player == row4enemy - 4 && col3player == col3enemy + 80) || (enemybullet == row1player && col3enemy == col3player) || (enemybullet - 3 == row1player && col3enemy + 20 == col3player) || (enemybullet - 1 == row1player && col3enemy + 60 == col3player) || (enemybullet - 1 == row1player && col3enemy + 80 == col3player)))
	{
		plane[row1player][col3player] = ".";       //new written coordinates for ship's changing movement 

		plane[row2player][col2player] = "<";       //    
		plane[row2player][col3player] = "|";
		plane[row2player][col4player] = ">";

		plane[row3player][col1player] = "<";
		plane[row3player][col2player] = "<";
		plane[row3player][col3player] = "|";      //
		plane[row3player][col4player] = ">";
		plane[row3player][col5player] = ">";

		plane[row4player][col2player] = "<";
		plane[row4player][col3player] = "|";      //
		plane[row4player][col4player] = ">";

		plane[row5player][col1player] = "<";
		plane[row5player][col2player] = "<";
		plane[row5player][col3player] = "|";      //
		plane[row5player][col4player] = ">";
		plane[row5player][col5player] = ">";

		plane[row6player][col1player] = "<";
		plane[row6player][col2player] = " ";
		plane[row6player][col3player] = " ";      //
		plane[row6player][col4player] = " ";
		plane[row6player][col5player] = ">";
	}
	else
	{
		for (int j = row1player; j <= row6player; j++)
		{
			for (int i = col1player; i <= col5player; i++)
			{
				plane[j][i] = " ";
			}
		}
	}
	keypressed = 0;
}
void moveright(string plane[][115])
{
	if (keypressed == 77)
	{
		countforright = countforright + 1;
		countfordown = 0;
		countforleft = 0;                          //-Ship's speed determining factors
		countforup = 0;
		if (!(col5player == 97))
		{
			col1player = col1player + 10;
			col2player = col2player + 10;
			col3player = col3player + 10;
			col4player = col4player + 10;
			col5player = col5player + 10;
		}
	}
	if (!((row1player == row1enemy && col3player == col3enemy) || (row1player == row1enemy - 4 && col3player == col3enemy + 20) || (row1player == row1enemy - 1 && col3player == col3enemy + 60) || (row1player == row1enemy - 4 && col3player == col3enemy + 80) || (row2player == row2enemy && col3player == col3enemy) || (row2player == row2enemy - 4 && col3player == col3enemy + 20) || (row2player == row2enemy - 1 && col3player == col3enemy + 60) || (row2player == row2enemy - 4 && col3player == col3enemy + 80) || (row3player == row3enemy && col3player == col3enemy) || (row3player == row3enemy - 4 && col3player == col3enemy + 20) || (row3player == row3enemy - 1 && col3player == col3enemy + 60) || (row3player == row3enemy - 4 && col3player == col3enemy + 80) || (row4player == row4enemy && col3player == col3enemy) || (row4player == row4enemy - 4 && col3player == col3enemy + 20) || (row4player == row4enemy - 1 && col3player == col3enemy + 60) || (row4player == row4enemy - 4 && col3player == col3enemy + 80) || (enemybullet == row1player && col3enemy == col3player) || (enemybullet - 3 == row1player && col3enemy + 20 == col3player) || (enemybullet - 1 == row1player && col3enemy + 60 == col3player) || (enemybullet - 1 == row1player && col3enemy + 80 == col3player)))
	{   
		plane[row1player][col3player] = ".";   //new written coordinates for ship's changing movement 

		plane[row2player][col2player] = "<";      //    
		plane[row2player][col3player] = "|";
		plane[row2player][col4player] = ">";

		plane[row3player][col1player] = "<";
		plane[row3player][col2player] = "<";
		plane[row3player][col3player] = "|";      //
		plane[row3player][col4player] = ">";
		plane[row3player][col5player] = ">";

		plane[row4player][col2player] = "<";
		plane[row4player][col3player] = "|";      //
		plane[row4player][col4player] = ">";

		plane[row5player][col1player] = "<";
		plane[row5player][col2player] = "<";
		plane[row5player][col3player] = "|";      //
		plane[row5player][col4player] = ">";
		plane[row5player][col5player] = ">";

		plane[row6player][col1player] = "<";
		plane[row6player][col2player] = " ";
		plane[row6player][col3player] = " ";      //
		plane[row6player][col4player] = " ";
		plane[row6player][col5player] = ">";
	}
	else
	{
		for (int j = row1player; j <= row6player; j++)
		{
			for (int i = col1player; i <= col5player; i++)
			{
				plane[j][i] = " ";

			}
		}
	}
	keypressed = 0;
}
void moveleft(string plane[][115])
{
	if (keypressed == 75)
	{
		countforleft = countforleft + 1;
		countfordown = 0;
		countforup = 0;
		countforright = 0;
		if (!(col1player == 3))
		{
			col1player = col1player - 10;
			col2player = col2player - 10;           //-Ship's speed determining factors
			col3player = col3player - 10;
			col4player = col4player - 10;
			col5player = col5player - 10;
		}
	}
	if (!((row1player == row1enemy && col3player == col3enemy) || (row1player == row1enemy - 4 && col3player == col3enemy + 20) || (row1player == row1enemy - 1 && col3player == col3enemy + 60) || (row1player == row1enemy - 4 && col3player == col3enemy + 80) || (row2player == row2enemy && col3player == col3enemy) || (row2player == row2enemy - 4 && col3player == col3enemy + 20) || (row2player == row2enemy - 1 && col3player == col3enemy + 60) || (row2player == row2enemy - 4 && col3player == col3enemy + 80) || (row3player == row3enemy && col3player == col3enemy) || (row3player == row3enemy - 4 && col3player == col3enemy + 20) || (row3player == row3enemy - 1 && col3player == col3enemy + 60) || (row3player == row3enemy - 4 && col3player == col3enemy + 80) || (row4player == row4enemy && col3player == col3enemy) || (row4player == row4enemy - 4 && col3player == col3enemy + 20) || (row4player == row4enemy - 1 && col3player == col3enemy + 60) || (row4player == row4enemy - 4 && col3player == col3enemy + 80) || (enemybullet == row1player && col3enemy == col3player) || (enemybullet - 3 == row1player && col3enemy + 20 == col3player) || (enemybullet - 1 == row1player && col3enemy + 60 == col3player) || (enemybullet - 1 == row1player && col3enemy + 80 == col3player)))
	{
		plane[row1player][col1player] = " ";
		plane[row1player][col2player] = " ";       //new written coordinates for ship's changing movement 
		plane[row1player][col3player] = ".";

		plane[row2player][col1player] = " ";
		plane[row2player][col2player] = "<";       //    
		plane[row2player][col3player] = "|";
		plane[row2player][col4player] = ">";

		plane[row3player][col1player] = "<";
		plane[row3player][col2player] = "<";
		plane[row3player][col3player] = "|";      //
		plane[row3player][col4player] = ">";
		plane[row3player][col5player] = ">";

		plane[row4player][col1player] = " ";
		plane[row4player][col2player] = "<";
		plane[row4player][col3player] = "|";      //
		plane[row4player][col4player] = ">";
		plane[row4player][col5player] = " ";

		plane[row5player][col1player] = "<";
		plane[row5player][col2player] = "<";
		plane[row5player][col3player] = "|";      //
		plane[row5player][col4player] = ">";
		plane[row5player][col5player] = ">";

		plane[row6player][col1player] = "<";
		plane[row6player][col2player] = " ";
		plane[row6player][col3player] = " ";      //
		plane[row6player][col4player] = " ";
		plane[row6player][col5player] = ">";
	}
	else
	{
		for (int j = row1player; j <= row6player; j++)
		{
			for (int i = col1player; i <= col5player; i++)
			{
				plane[j][i] = " ";
			}
		}
	}
	keypressed = 0;
}
void shipmovement(string plane[][115])
{
	if (_kbhit() == true)
	{
		int x = _getch();
		keypressed = x;
		switch (keypressed)
		{
		case 72:
			moveup(plane);
			break;
		case 80:
			movedown(plane);
			break;
		case 77:
			moveright(plane);
			break;
		case 75:
			moveleft(plane);
			break;
		case 32:
			pause(plane);
			system("pause>0");
			break;
		case 27:
			escape = false;
			break;
		default:
			break;
		}
	}
}

void layout(string plane[][115])
{
	cout << "    \t\t\tHEALTH: " << health << "    \t\t\tLEVEL: " << level << "    \t\t\tPOINTS: " << points << endl;
	for (int i = 1; i < 27; i++)
	{
		plane[i][0] = "^";
		plane[i][100] = "^";
		plane[i][114] = "^";
	}
	for (int i = 0; i < 115; i++)
	{
		plane[0][i] = "^";
		plane[27][i] = "^";
	}
	plane[4][102] = "S";
	plane[4][103] = "P";
	plane[4][104] = "A";
	plane[4][105] = "C";
	plane[4][106] = "E";
	plane[6][102] = "S";
	plane[6][103] = "H";
	plane[6][104] = "O";
	plane[6][105] = "O";
	plane[6][106] = "T";
	plane[6][107] = "E";
	plane[6][108] = "R";
	plane[16][104] = "<";
	plane[16][105] = "<";
	plane[16][108] = ">";
	plane[16][109] = ">";
}
void enemymovedown(string plane[][115])
{
	//---------------------------------------------------------------------------------------------------------------------------------------
	if (row1enemy < 28 || enemybullet < 28)                       //-A determined Range for Enemy ships after which they will disappear
	{
		for (int i = 0; i < 28; i++)                //- 
		{                                           //-
			for (int j = 0; j < 115; j++)           //-
			{                                       //-Determining a 2-Dimnesional plane and initializing them with empty spaces
				plane[i][j] = " ";                  //-
			}                                       //-
		}
		//--------------------------------------------------------my bullet----------------------------------
		if (mybullet1 == 2)
		{
			mybullet1 = row1player;
		}
		if (mybullet1 > 2)
		{
			mybullet1 = mybullet1 - 1;
			plane[mybullet1][col3player] = "*";

			if (level >= 2)
			{
				if (((row1player == r2gift && col3player == c2gift) || (row2player == r2gift && col3player == c2gift) || (row3player == r2gift && col3player == c2gift) || (row4player == r2gift && col3player == c2gift) || (row5player == r2gift && col3player == c2gift) || (row6player == r2gift && col3player == c2gift)) || onetimedoublebullet)
				{
					if ((row1player == r2gift && col3player == c2gift) || (row2player == r2gift && col3player == c2gift) || (row3player == r2gift && col3player == c2gift) || (row4player == r2gift && col3player == c2gift) || (row5player == r2gift && col3player == c2gift) || (row6player == r2gift && col3player == c2gift))
					{
						gifthide1 = false;
						twopointsaddition = true;       //- When gift is achieved this adds another bullet
					}
					onetimedoublebullet = true;
					plane[mybullet1][col3player + 1] = "*";
				}
			}
		}
		if (mybullet2 == 2)
		{
			mybullet2 = row1player;
		}
		if (mybullet2 > 2)
		{
			mybullet2 = mybullet2 - 1;
			plane[mybullet2 + 4][col3player] = "*";

			if (level >= 2)
			{
				if (((row1player == r2gift && col3player == c2gift) || (row2player == r2gift && col3player == c2gift) || (row3player == r2gift && col3player == c2gift) || (row4player == r2gift && col3player == c2gift) || (row5player == r2gift && col3player == c2gift) || (row6player == r2gift && col3player == c2gift)) || onetimedoublebullet)
				{
					twopointsaddition = true;
					onetimedoublebullet = true;        //- When gift is achieved this adds another bullet
					plane[mybullet2 + 4][col3player + 1] = "*";
				}
			}
		}
		if (mybullet3 == 2)
		{
			mybullet3 = row1player;
		}
		if (mybullet3 > 2)
		{
			mybullet3 = mybullet3 - 1;
			plane[mybullet3 + 6][col3player] = "*";
			if (level >= 2)
			{
				if (((row1player == r2gift && col3player == c2gift) || (row2player == r2gift && col3player == c2gift) || (row3player == r2gift && col3player == c2gift) || (row4player == r2gift && col3player == c2gift) || (row5player == r2gift && col3player == c2gift) || (row6player == r2gift && col3player == c2gift)) || onetimedoublebullet)
				{
					twopointsaddition = true;
					onetimedoublebullet = true;           //- When gift is achieved this adds another bullet
					plane[mybullet3 + 6][col3player + 1] = "*";
				}
			}
		}
		//--------------------------------------------------------my bullet End----------------------------------
		row1enemy = row1enemy + 1;                                //-                     
		row2enemy = row2enemy + 1;                                //-Enemy's ship downward speed 
		row3enemy = row3enemy + 1;                                //-
		row4enemy = row4enemy + 1;                                //-	
		if ((mybullet1 == row4enemy && col3player == col3enemy) || (mybullet2 + 4 == row4enemy && col3player == col3enemy) || (mybullet3 + 6 == row4enemy && col3player == col3enemy) || (mybullet1 == row3enemy && col3player == col3enemy) || (mybullet2 + 4 == row3enemy && col3player == col3enemy) || (mybullet3 + 6 == row3enemy && col3player == col3enemy) || (mybullet3 + 6 == row2enemy && col3player == col3enemy) || (mybullet1 == row2enemy && col3player == col3enemy) || (mybullet2 + 4 == row2enemy && col3player == col3enemy) || (mybullet2 + 4 == row1enemy && col3player == col3enemy) || (mybullet3 + 6 == row1enemy && col3player == col3enemy) || (mybullet1 == row1enemy && col3player == col3enemy))
		{                                 //-These all if conditions tell whether enemy ship has been hit or not
			if (deadcheckforship1)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;         //-To add two more points when gift is achieved
				}
			}
			deadcheckforship1 = false;
		}
		if (!(mybullet1 == row4enemy && col3player == col3enemy) || (mybullet2 + 4 == row4enemy && col3player == col3enemy) || (mybullet3 + 6 == row4enemy && col3player == col3enemy) || (mybullet1 == row3enemy && col3player == col3enemy) || (mybullet2 + 4 == row3enemy && col3player == col3enemy) || (mybullet3 + 6 == row3enemy && col3player == col3enemy) || (mybullet3 + 6 == row2enemy && col3player == col3enemy) || (mybullet1 == row2enemy && col3player == col3enemy) || (mybullet2 + 4 == row2enemy && col3player == col3enemy) || (mybullet2 + 4 == row1enemy && col3player == col3enemy) || (mybullet3 + 6 == row1enemy && col3player == col3enemy) || (mybullet1 == row1enemy && col3player == col3enemy))
		{                                //-These all if conditions tell whether enemy ship has been hit or not
			if (deadcheckforship1)
			{
				if (row4enemy < 28)
				{
					plane[row1enemy][col1enemy] = "<";
					plane[row1enemy][col2enemy] = " ";
					plane[row1enemy][col3enemy] = " ";
					plane[row1enemy][col4enemy] = " ";
					plane[row1enemy][col5enemy] = ">";

					plane[row2enemy][col1enemy] = "<";
					plane[row2enemy][col2enemy] = "<";
					plane[row2enemy][col3enemy] = "|";
					plane[row2enemy][col4enemy] = ">";
					plane[row2enemy][col5enemy] = ">";

					plane[row3enemy][col2enemy] = "<";
					plane[row3enemy][col3enemy] = "|";
					plane[row3enemy][col4enemy] = ">";

					plane[row4enemy][col3enemy] = ".";
				}
				if (enemybullet < 27)
				{
					enemybullet = enemybullet + 2;
				}
				if (enemybullet > 7 && enemybullet < 27)
				{
					plane[enemybullet][col3enemy] = "*";
				}
			}
		}

		if ((mybullet1 == row4enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row4enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row4enemy - 4 && col3player == col3enemy + 20) || (mybullet1 == row3enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row3enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row3enemy - 4 && col3player == col3enemy + 20) || (mybullet1 == row2enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row2enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row2enemy - 4 && col3player == col3enemy + 20) || (mybullet1 == row1enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row1enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row1enemy - 4 && col3player == col3enemy + 20))
		{                                //-These all if conditions tell whether enemy ship has been hit or not
			if (deadcheckforship2)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;
				}
			}
			deadcheckforship2 = false;
		}
		if (!(mybullet1 == row4enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row4enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row4enemy - 4 && col3player == col3enemy + 20) || (mybullet1 == row3enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row3enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row3enemy - 4 && col3player == col3enemy + 20) || (mybullet1 == row2enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row2enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row2enemy - 4 && col3player == col3enemy + 20) || (mybullet1 == row1enemy - 4 && col3player == col3enemy + 20) || (mybullet2 + 4 == row1enemy - 4 && col3player == col3enemy + 20) || (mybullet3 + 6 == row1enemy - 4 && col3player == col3enemy + 20))
		{                                //-These all if conditions tell whether enemy ship has been hit or not
			if (deadcheckforship2)
			{
				if (row4enemy < 27)
				{
					plane[row1enemy - 4][col1enemy + 20] = "<";
					plane[row1enemy - 4][col2enemy + 20] = " ";
					plane[row1enemy - 4][col3enemy + 20] = " ";
					plane[row1enemy - 4][col4enemy + 20] = " ";
					plane[row1enemy - 4][col5enemy + 20] = ">";

					plane[row2enemy - 4][col1enemy + 20] = "<";
					plane[row2enemy - 4][col2enemy + 20] = "<";
					plane[row2enemy - 4][col3enemy + 20] = "|";
					plane[row2enemy - 4][col4enemy + 20] = ">";
					plane[row2enemy - 4][col5enemy + 20] = ">";

					plane[row3enemy - 4][col2enemy + 20] = "<";
					plane[row3enemy - 4][col3enemy + 20] = "|";
					plane[row3enemy - 4][col4enemy + 20] = ">";

					plane[row4enemy - 4][col3enemy + 20] = ".";
				}
				if (enemybullet > 5 && enemybullet < 27)
				{
					plane[enemybullet - 3][col3enemy + 20] = "*";
				}
			}
		}

		if ((mybullet1 == row4enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row4enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row4enemy - 1 && col3player == col3enemy + 60) || (mybullet1 == row3enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row3enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row3enemy - 1 && col3player == col3enemy + 60) || (mybullet1 == row2enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row2enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row2enemy - 1 && col3player == col3enemy + 60) || (mybullet1 == row1enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row1enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row1enemy - 1 && col3player == col3enemy + 60))
		{                                //-These all if conditions tell whether enemy ship has been hit or not
			if (deadcheckforship3)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;
				}
			}
			deadcheckforship3 = false;
		}

		if (!(mybullet1 == row4enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row4enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row4enemy - 1 && col3player == col3enemy + 60) || (mybullet1 == row3enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row3enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row3enemy - 1 && col3player == col3enemy + 60) || (mybullet1 == row2enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row2enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row2enemy - 1 && col3player == col3enemy + 60) || (mybullet1 == row1enemy - 1 && col3player == col3enemy + 60) || (mybullet2 + 4 == row1enemy - 1 && col3player == col3enemy + 60) || (mybullet3 + 6 == row1enemy - 1 && col3player == col3enemy + 60))
		{                                //-These all if conditions tell whether enemy ship has been hit or not
			if (deadcheckforship3)
			{
				if (row4enemy < 27)
				{
					plane[row1enemy - 1][col1enemy + 60] = "<";
					plane[row1enemy - 1][col2enemy + 60] = " ";
					plane[row1enemy - 1][col3enemy + 60] = " ";
					plane[row1enemy - 1][col4enemy + 60] = " ";
					plane[row1enemy - 1][col5enemy + 60] = ">";

					plane[row2enemy - 1][col1enemy + 60] = "<";
					plane[row2enemy - 1][col2enemy + 60] = "<";
					plane[row2enemy - 1][col3enemy + 60] = "|";
					plane[row2enemy - 1][col4enemy + 60] = ">";
					plane[row2enemy - 1][col5enemy + 60] = ">";

					plane[row3enemy - 1][col2enemy + 60] = "<";
					plane[row3enemy - 1][col3enemy + 60] = "|";
					plane[row3enemy - 1][col4enemy + 60] = ">";

					plane[row4enemy - 1][col3enemy + 60] = ".";
				}
				if (enemybullet > 8 && enemybullet < 27)
				{
					plane[enemybullet - 1][col3enemy + 60] = "*";
				}
			}
		}

		if ((mybullet1 == row4enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row4enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row4enemy - 4 && col3player == col3enemy + 80) || (mybullet1 == row3enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row3enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row3enemy - 4 && col3player == col3enemy + 80) || (mybullet1 == row2enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row2enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row2enemy - 4 && col3player == col3enemy + 80) || (mybullet1 == row1enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row1enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row1enemy - 4 && col3player == col3enemy + 80))
		{
			if (deadcheckforship4)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;
				}
			}
			deadcheckforship4 = false;
		}
		if (!(mybullet1 == row4enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row4enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row4enemy - 4 && col3player == col3enemy + 80) || (mybullet1 == row3enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row3enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row3enemy - 4 && col3player == col3enemy + 80) || (mybullet1 == row2enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row2enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row2enemy - 4 && col3player == col3enemy + 80) || (mybullet1 == row1enemy - 4 && col3player == col3enemy + 80) || (mybullet2 + 4 == row1enemy - 4 && col3player == col3enemy + 80) || (mybullet3 + 6 == row1enemy - 4 && col3player == col3enemy + 80))
		{
			if (deadcheckforship4)
			{
				if (row4enemy < 27)
				{
					plane[row1enemy - 4][col1enemy + 80] = "<";
					plane[row1enemy - 4][col2enemy + 80] = " ";
					plane[row1enemy - 4][col3enemy + 80] = " ";
					plane[row1enemy - 4][col4enemy + 80] = " ";
					plane[row1enemy - 4][col5enemy + 80] = ">";

					plane[row2enemy - 4][col1enemy + 80] = "<";
					plane[row2enemy - 4][col2enemy + 80] = "<";
					plane[row2enemy - 4][col3enemy + 80] = "|";
					plane[row2enemy - 4][col4enemy + 80] = ">";
					plane[row2enemy - 4][col5enemy + 80] = ">";

					plane[row3enemy - 4][col2enemy + 80] = "<";
					plane[row3enemy - 4][col3enemy + 80] = "|";
					plane[row3enemy - 4][col4enemy + 80] = ">";

					plane[row4enemy - 4][col3enemy + 80] = ".";
				}
				if (enemybullet < 27)
				{
					plane[enemybullet - 1][col3enemy + 80] = "*";
				}
			}
		}
		shipmovement(plane);         //-Called for controlling ships
		if ((row1player == row1enemy && col3player == col3enemy) || (row1player == row1enemy - 4 && col3player == col3enemy + 20) || (row1player == row1enemy - 1 && col3player == col3enemy + 60) || (row1player == row1enemy - 4 && col3player == col3enemy + 80) || (row2player == row2enemy && col3player == col3enemy) || (row2player == row2enemy - 4 && col3player == col3enemy + 20) || (row2player == row2enemy - 1 && col3player == col3enemy + 60) || (row2player == row2enemy - 4 && col3player == col3enemy + 80) || (row3player == row3enemy && col3player == col3enemy) || (row3player == row3enemy - 4 && col3player == col3enemy + 20) || (row3player == row3enemy - 1 && col3player == col3enemy + 60) || (row3player == row3enemy - 4 && col3player == col3enemy + 80) || (row4player == row4enemy && col3player == col3enemy) || (row4player == row4enemy - 4 && col3player == col3enemy + 20) || (row4player == row4enemy - 1 && col3player == col3enemy + 60) || (row4player == row4enemy - 4 && col3player == col3enemy + 80) || (enemybullet == row1player && col3enemy == col3player) || (enemybullet - 3 == row1player && col3enemy + 20 == col3player) || (enemybullet - 1 == row1player && col3enemy + 60 == col3player) || (enemybullet - 1 == row1player && col3enemy + 80 == col3player))
		{
			health = health - 1;
		}
		shipglitch(plane);          //-To prevent glitches
		countt = countt + 1;
		if (level >= 2)
		{
			gift(plane);
		}
	}
	else //---------------------------------------------------------------------------------------------------------------------------------------
	{
		for (int i = 0; i < 28; i++)
		{
			for (int j = 0; j < 115; j++)
			{
				plane[i][j] = " ";
			}
		}
		//--------------------------------------------------------my bullet ----------------------------------
		if (mybullet1 == 2)
		{
			mybullet1 = row1player;
		}
		if (mybullet1 > 2)
		{
			mybullet1 = mybullet1 - 1;
			plane[mybullet1][col3player] = "*";

			if (level >= 2)
			{
				if (((row1player == r2gift && col3player == c2gift + 50) || (row2player == r2gift && col3player == c2gift + 50) || (row3player == r2gift && col3player == c2gift + 50) || (row4player == r2gift && col3player == c2gift + 50) || (row5player == r2gift && col3player == c2gift + 50) || (row6player == r2gift && col3player == c2gift + 50)) || onetimedoublebullet)
				{
					if ((row1player == r2gift && col3player == c2gift + 50) || (row2player == r2gift && col3player == c2gift + 50) || (row3player == r2gift && col3player == c2gift + 50) || (row4player == r2gift && col3player == c2gift + 50) || (row5player == r2gift && col3player == c2gift + 50) || (row6player == r2gift && col3player == c2gift + 50))
					{
						gifthide2 = false;
						twopointsaddition = true;
					}
					onetimedoublebullet = true;
					plane[mybullet1][col3player + 1] = "*";
				}
			}
		}
		if (mybullet2 == 2)
		{
			mybullet2 = row1player;
		}
		if (mybullet2 > 2)
		{
			mybullet2 = mybullet2 - 1;
			plane[mybullet2 + 4][col3player] = "*";
			if (level >= 2)
			{
				if (((row1player == r2gift && col3player == c2gift + 50) || (row2player == r2gift && col3player == c2gift + 50) || (row3player == r2gift && col3player == c2gift + 50) || (row4player == r2gift && col3player == c2gift + 50) || (row5player == r2gift && col3player == c2gift + 50) || (row6player == r2gift && col3player == c2gift + 50)) || onetimedoublebullet)
				{
					onetimedoublebullet = true;
					twopointsaddition = true;
					plane[mybullet2 + 4][col3player + 1] = "*";
				}
			}
		}
		if (mybullet3 == 2)
		{
			mybullet3 = row1player;
		}
		if (mybullet3 > 2)
		{
			mybullet3 = mybullet3 - 1;
			plane[mybullet3 + 6][col3player] = "*";
			if (level >= 2)
			{
				if (((row1player == r2gift && col3player == c2gift + 50) || (row2player == r2gift && col3player == c2gift + 50) || (row3player == r2gift && col3player == c2gift + 50) || (row4player == r2gift && col3player == c2gift + 50) || (row5player == r2gift && col3player == c2gift + 50) || (row6player == r2gift && col3player == c2gift + 50)) || onetimedoublebullet)
				{
					onetimedoublebullet = true;
					twopointsaddition = true;

					plane[mybullet3 + 6][col3player + 1] = "*";
				}
			}
		}
		//--------------------------------------------------------my bullet End----------------------------------
		row1enemy2 = row1enemy2 + 1;
		row2enemy2 = row2enemy2 + 1;               //-Eneemy ships speed
		row3enemy2 = row3enemy2 + 1;            
		row4enemy2 = row4enemy2 + 1;
		//-----------------------------------------------------Enemy Ship 1----------------------------------------
		if ((mybullet1 == row4enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row4enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row4enemy2 && col3player == col3enemy2) || (mybullet1 == row3enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row3enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row3enemy2 && col3player == col3enemy2) || (mybullet1 == row2enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row2enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row2enemy2 && col3player == col3enemy2) || (mybullet1 == row1enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row1enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row1enemy2 && col3player == col3enemy2))
		{
			if (l2deadcheckforship1)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;
				}
			}
			l2deadcheckforship1 = false;
		}
		if (!(mybullet1 == row4enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row4enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row4enemy2 && col3player == col3enemy2) || (mybullet1 == row3enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row3enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row3enemy2 && col3player == col3enemy2) || (mybullet1 == row2enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row2enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row2enemy2 && col3player == col3enemy2) || (mybullet1 == row1enemy2 && col3player == col3enemy2) || (mybullet2 + 4 == row1enemy2 && col3player == col3enemy2) || (mybullet3 + 6 == row1enemy2 && col3player == col3enemy2))
		{
			if (l2deadcheckforship1)
			{
				if (row4enemy2 < 28)
				{
					plane[row1enemy2][col1enemy2] = "<";
					plane[row1enemy2][col2enemy2] = " ";
					plane[row1enemy2][col3enemy2] = " ";
					plane[row1enemy2][col4enemy2] = " ";
					plane[row1enemy2][col5enemy2] = ">";

					plane[row2enemy2][col1enemy2] = "<";
					plane[row2enemy2][col2enemy2] = "<";
					plane[row2enemy2][col3enemy2] = "|";
					plane[row2enemy2][col4enemy2] = ">";
					plane[row2enemy2][col5enemy2] = ">";

					plane[row3enemy2][col2enemy2] = "<";
					plane[row3enemy2][col3enemy2] = "|";
					plane[row3enemy2][col4enemy2] = ">";

					plane[row4enemy2][col3enemy2] = ".";
				}
				if (renemybullet < 27)
				{
					renemybullet = renemybullet + 2;
				}
				if (renemybullet > 7 && renemybullet < 27)
				{
					plane[renemybullet][col3enemy2] = "*";
				}
			}
		}
		//-----------------------------------------------------Enemy Ship 1 End----------------------------------------
		//-----------------------------------------------------Enemy Ship 2--------------------------------------------
		if ((mybullet1 == row4enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row4enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row4enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet1 == row3enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row3enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row3enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet1 == row2enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row2enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row2enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet1 == row1enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row1enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row1enemy2 - 4 && col3player == col3enemy2 + 20))
		{
			if (l2deadcheckforship2)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;
				}
			}
			l2deadcheckforship2 = false;
		}
		if (!(mybullet1 == row4enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row4enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row4enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet1 == row3enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row3enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row3enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet1 == row2enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row2enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row2enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet1 == row1enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet2 + 4 == row1enemy2 - 4 && col3player == col3enemy2 + 20) || (mybullet3 + 6 == row1enemy2 - 4 && col3player == col3enemy2 + 20))
		{
			if (l2deadcheckforship2)
			{
				if (row4enemy2 < 27)
				{
					plane[row1enemy2 - 4][col1enemy2 + 20] = "<";
					plane[row1enemy2 - 4][col2enemy2 + 20] = " ";
					plane[row1enemy2 - 4][col3enemy2 + 20] = " ";
					plane[row1enemy2 - 4][col4enemy2 + 20] = " ";
					plane[row1enemy2 - 4][col5enemy2 + 20] = ">";

					plane[row2enemy2 - 4][col1enemy2 + 20] = "<";
					plane[row2enemy2 - 4][col2enemy2 + 20] = "<";
					plane[row2enemy2 - 4][col3enemy2 + 20] = "|";
					plane[row2enemy2 - 4][col4enemy2 + 20] = ">";
					plane[row2enemy2 - 4][col5enemy2 + 20] = ">";

					plane[row3enemy2 - 4][col2enemy2 + 20] = "<";
					plane[row3enemy2 - 4][col3enemy2 + 20] = "|";
					plane[row3enemy2 - 4][col4enemy2 + 20] = ">";

					plane[row4enemy2 - 4][col3enemy2 + 20] = ".";
				}
				if (renemybullet > 5 && renemybullet < 27)
				{
					plane[renemybullet - 3][col3enemy2 + 20] = "*";
				}
			}
		}
		//-----------------------------------------------------Enemy Ship 2 End----------------------------------------
		//-----------------------------------------------------Enemy Ship 3--------------------------------------------
		if ((mybullet1 == row4enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row4enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row4enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet1 == row3enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row3enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row3enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet1 == row2enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row2enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row2enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet1 == row1enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row1enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row1enemy2 + 2 && col3player == col3enemy2 + 40))
		{
			if (l2deadcheckforship3)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;
				}
			}
			l2deadcheckforship3 = false;
		}
		if (!(mybullet1 == row4enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row4enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row4enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet1 == row3enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row3enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row3enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet1 == row2enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row2enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row2enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet1 == row1enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet2 + 4 == row1enemy2 + 2 && col3player == col3enemy2 + 40) || (mybullet3 + 6 == row1enemy2 + 2 && col3player == col3enemy2 + 40))
		{
			if (l2deadcheckforship3)
			{
				if (row4enemy2 < 27)
				{
					plane[row1enemy2 + 2][col1enemy2 + 40] = "<";
					plane[row1enemy2 + 2][col2enemy2 + 40] = " ";
					plane[row1enemy2 + 2][col3enemy2 + 40] = " ";
					plane[row1enemy2 + 2][col4enemy2 + 40] = " ";
					plane[row1enemy2 + 2][col5enemy2 + 40] = ">";

					plane[row2enemy2 + 2][col1enemy2 + 40] = "<";
					plane[row2enemy2 + 2][col2enemy2 + 40] = "<";
					plane[row2enemy2 + 2][col3enemy2 + 40] = "|";
					plane[row2enemy2 + 2][col4enemy2 + 40] = ">";
					plane[row2enemy2 + 2][col5enemy2 + 40] = ">";

					plane[row3enemy2 + 2][col2enemy2 + 40] = "<";
					plane[row3enemy2 + 2][col3enemy2 + 40] = "|";
					plane[row3enemy2 + 2][col4enemy2 + 40] = ">";

					plane[row4enemy2 + 2][col3enemy2 + 40] = ".";
				}
				if (renemybullet > 8 && renemybullet < 27)
				{
					plane[renemybullet + 2][col3enemy2 + 40] = "*";

				}
			}
		}
		//-----------------------------------------------------Enemy Ship 3 End----------------------------------------
		//-----------------------------------------------------Enemy Ship 4--------------------------------------------
		if ((mybullet1 == row4enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row4enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row4enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet1 == row3enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row3enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row3enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet1 == row2enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row2enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row2enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet1 == row1enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row1enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row1enemy2 - 4 && col3player == col3enemy2 + 60))
		{
			if (l2deadcheckforship4)
			{
				points = points + 1;
				if (twopointsaddition)
				{
					points = points + 2;
				}
			}
			l2deadcheckforship4 = false;
		}
		if (!(mybullet1 == row4enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row4enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row4enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet1 == row3enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row3enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row3enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet1 == row2enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row2enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row2enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet1 == row1enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet2 + 4 == row1enemy2 - 4 && col3player == col3enemy2 + 60) || (mybullet3 + 6 == row1enemy2 - 4 && col3player == col3enemy2 + 60))
		{
			if (l2deadcheckforship4)
			{
				if (row4enemy2 < 27)
				{
					plane[row1enemy2 - 4][col1enemy2 + 60] = "<";
					plane[row1enemy2 - 4][col2enemy2 + 60] = " ";
					plane[row1enemy2 - 4][col3enemy2 + 60] = " ";
					plane[row1enemy2 - 4][col4enemy2 + 60] = " ";
					plane[row1enemy2 - 4][col5enemy2 + 60] = ">";

					plane[row2enemy2 - 4][col1enemy2 + 60] = "<";
					plane[row2enemy2 - 4][col2enemy2 + 60] = "<";
					plane[row2enemy2 - 4][col3enemy2 + 60] = "|";
					plane[row2enemy2 - 4][col4enemy2 + 60] = ">";
					plane[row2enemy2 - 4][col5enemy2 + 60] = ">";

					plane[row3enemy2 - 4][col2enemy2 + 60] = "<";
					plane[row3enemy2 - 4][col3enemy2 + 60] = "|";
					plane[row3enemy2 - 4][col4enemy2 + 60] = ">";

					plane[row4enemy2 - 4][col3enemy2 + 60] = ".";
				}
				if (renemybullet < 27)
				{
					plane[renemybullet][col3enemy2 + 60] = "*";
				}
			}
		}
		shipmovement(plane);
		if ((row1player == row1enemy2 && col3player == col3enemy2) || (row1player == row1enemy2 - 4 && col3player == col3enemy2 + 20) || (row1player == row1enemy2 + 2 && col3player == col3enemy2 + 40) || (row1player == row1enemy2 - 4 && col3player == col3enemy2 + 60) || (row2player == row2enemy2 && col3player == col3enemy2) || (row2player == row2enemy2 - 4 && col3player == col3enemy2 + 20) || (row2player == row2enemy2 + 2 && col3player == col3enemy2 + 40) || (row2player == row2enemy2 - 4 && col3player == col3enemy2 + 60) || (row3player == row3enemy2 && col3player == col3enemy2) || (row3player == row3enemy2 - 4 && col3player == col3enemy2 + 20) || (row3player == row3enemy2 + 2 && col3player == col3enemy2 + 40) || (row3player == row3enemy2 - 4 && col3player == col3enemy2 + 60) || (row4player == row4enemy2 && col3player == col3enemy2) || (row4player == row4enemy2 - 4 && col3player == col3enemy2 + 20) || (row4player == row4enemy2 + 2 && col3player == col3enemy2 + 40) || (row4player == row4enemy2 - 4 && col3player == col3enemy2 + 60) || (renemybullet == row1player && col3enemy2 == col3player) || (renemybullet - 3 == row1player && col3enemy2 + 20 == col3player) || (renemybullet + 2 == row1player && col3enemy2 + 40 == col3player) || (renemybullet == row1player && col3enemy2 + 60 == col3player))
		{
			health = health - 1;
		}
		shipglitch(plane);
		rcount = rcount + 1;
		if (level >= 2)
		{
			gift(plane);
		}
	}
	//-----------------------------------------------------Enemy Ship 4 End----------------------------------------
	//-----------------------------------------------------Reinitializer zone--------------------------------------
	if (r2gift == 27)
	{
		r1gift = 2;
		r2gift = 3;
		gifthide2 = true;
		gifthide1 = true;
	}
	if (rcount == 27)
	{
		row1enemy = 4;
		row2enemy = 5;
		row3enemy = 6;
		row4enemy = 7;
		col1enemy = 3;
		col2enemy = 4;
		col3enemy = 5;
		col4enemy = 6;
		col5enemy = 7;
		enemybullet = 6;
		rcount = 0;
	}
	if (countt == 27)
	{
		row1enemy2 = 4;
		row2enemy2 = 5;
		row3enemy2 = 6;
		row4enemy2 = 7;
		col1enemy2 = 13;
		col2enemy2 = 14;
		col3enemy2 = 15;
		col4enemy2 = 16;
		col5enemy2 = 17;
		renemybullet = 6;
		countt = 0;
	}
	if (row4enemy == 27)
	{
		deadcheckforship1 = true;
		deadcheckforship2 = true;
		deadcheckforship3 = true;
		deadcheckforship4 = true;
		healthcorrecter = true;
	}
	if (row4enemy2 == 27)
	{
		l2deadcheckforship1 = true;
		l2deadcheckforship2 = true;
		l2deadcheckforship3 = true;
		l2deadcheckforship4 = true;
	}
	//-----------------------------------------------------Reinitializer zone End--------------------------------------
	system("cls");
	layout(plane);
	for (int i = 0; i < 28; i++)
	{
		for (int l = 0; l < 115; l++)
		{
			cout << plane[i][l];
		}
		cout << endl;
	}
}

void pause(string plane[][115])
{
	shipglitch(plane);
	for (int i = 44; i <= 55; i++)
	{
		plane[12][i] = "=";
	}
	for (int i = 44; i <= 55; i++)
	{
		plane[14][i] = "=";
	}
	plane[13][44] = " ";
	plane[13][45] = " ";
	plane[13][46] = " ";
	plane[13][47] = "P";
	plane[13][48] = "A";
	plane[13][49] = "U";
	plane[13][50] = "S";
	plane[13][51] = "E";
	plane[13][52] = "D";
	plane[13][53] = " ";
	plane[13][54] = " ";
	plane[13][55] = " ";

	system("cls");
	layout(plane);
	for (int i = 0; i < 28; i++)
	{
		for (int l = 0; l < 115; l++)
		{
			cout << plane[i][l];
		}
		cout << endl;
	}
}
void loading(int num)
{
	system("cls");
	int x = 0;
	while (!(x == 1))
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading";
		Sleep(0700);
		cout << ".";
		Sleep(0700);
		cout << ".";
		Sleep(0700);
		cout << ".";
		Sleep(0700);
		system("cls");
		x++;
	}
}

void level3enemy(string plane[][115])
{
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < 115; j++)
		{
			plane[i][j] = " ";
		}
	}
	//--------------------------------------------My Bullet----------------------------------
	if (mybullet1 == 2)
	{
		mybullet1 = row1player;
	}
	if (mybullet1 > 2)
	{
		mybullet1 = mybullet1 - 1;
		plane[mybullet1][col3player] = "*";
		if (level >= 2)
		{
			if ((row1player == l3r2enemy && col3player == l3c2enemy + 61) || (row2player == l3r2enemy && col3player == l3c2enemy + 61) || (row3player == l3r2enemy && col3player == l3c2enemy + 61) || (row4player == l3r2enemy && col3player == l3c2enemy + 61) || (row5player == l3r2enemy && col3player == l3c2enemy + 61) || (row6player == l3r2enemy && col3player == l3c2enemy + 61))
			{
				gifthide2 = false;
				gifthide2bullets = true;
			}
			if (((row1player == l3r2enemy && col3player == l3c2enemy - 9) || (row2player == l3r2enemy && col3player == l3c2enemy - 9) || (row3player == l3r2enemy && col3player == l3c2enemy - 9) || (row4player == l3r2enemy && col3player == l3c2enemy - 9) || (row5player == l3r2enemy && col3player == l3c2enemy - 9) || (row6player == l3r2enemy && col3player == l3c2enemy - 9)) || onetimedoublebullet || gifthide2bullets)
			{
				if ((row1player == l3r2enemy && col3player == l3c2enemy - 9) || (row2player == l3r2enemy && col3player == l3c2enemy - 9) || (row3player == l3r2enemy && col3player == l3c2enemy - 9) || (row4player == l3r2enemy && col3player == l3c2enemy - 9) || (row5player == l3r2enemy && col3player == l3c2enemy - 9) || (row6player == l3r2enemy && col3player == l3c2enemy - 9))
				{
					gifthide1 = false;
					twopointsaddition = true;
				}
				onetimedoublebullet = true;
				plane[mybullet1][col3player + 1] = "*";
			}
		}
	}
	if (mybullet2 == 2)
	{
		mybullet2 = row1player;
	}
	if (mybullet2 > 2)
	{
		mybullet2 = mybullet2 - 1;
		plane[mybullet2 + 4][col3player] = "*";

		if (level >= 2)
		{
			if (((row1player == l3r2enemy && col3player == l3c2enemy - 9) || (row2player == l3r2enemy && col3player == l3c2enemy - 9) || (row3player == l3r2enemy && col3player == l3c2enemy - 9) || (row4player == l3r2enemy && col3player == l3c2enemy - 9) || (row5player == l3r2enemy && col3player == l3c2enemy - 9) || (row6player == l3r2enemy && col3player == l3c2enemy - 9)) || onetimedoublebullet)
			{
				twopointsaddition = true;
				onetimedoublebullet = true;
				plane[mybullet2 + 4][col3player + 1] = "*";
			}
		}
	}
	if (mybullet3 == 2)
	{
		mybullet3 = row1player;
	}
	if (mybullet3 > 2)
	{
		mybullet3 = mybullet3 - 1;
		plane[mybullet3 + 6][col3player] = "*";
		if (level >= 2)
		{
			if (((row1player == l3r2enemy && col3player == l3c2enemy - 9) || (row2player == l3r2enemy && col3player == l3c2enemy - 9) || (row3player == l3r2enemy && col3player == l3c2enemy - 9) || (row4player == l3r2enemy && col3player == l3c2enemy - 9) || (row5player == l3r2enemy && col3player == l3c2enemy - 9) || (row6player == l3r2enemy && col3player == l3c2enemy - 9)) || onetimedoublebullet)
			{
				twopointsaddition = true;
				onetimedoublebullet = true;
				plane[mybullet3 + 6][col3player + 1] = "*";
			}
		}
	}
	//--------------------------------------------My Bullet End----------------------------------
	//--------------------------------------------Gift-------------------------------------------
	if (gifthide1)
	{
		plane[l3r1enemy][l3c1enemy - 9] = "{";
		plane[l3r1enemy][l3c2enemy - 9] = "o";
		plane[l3r1enemy][l3c3enemy - 9] = "}";
		plane[l3r2enemy][l3c1enemy - 9] = "{";
		plane[l3r2enemy][l3c2enemy - 9] = "o";
		plane[l3r2enemy][l3c3enemy - 9] = "}";
	}
	if (gifthide2)
	{
		plane[l3r1enemy][l3c1enemy + 61] = "{";
		plane[l3r1enemy][l3c2enemy + 61] = "o";
		plane[l3r1enemy][l3c3enemy + 61] = "}";
		plane[l3r2enemy][l3c1enemy + 61] = "{";
		plane[l3r2enemy][l3c2enemy + 61] = "o";
		plane[l3r2enemy][l3c3enemy + 61] = "}";
	}
	//--------------------------------------------Gift End----------------------------------
	//--------------------------------------------Lvl 3 Enemy-------------------------------
	if ((mybullet1 == l3r4enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy) || (mybullet1 == l3r3enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy) || (mybullet1 == l3r2enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy) || (mybullet1 == l3r1enemy && col3player == l3c3enemy))
	{
		if (deadcheckforship1)
		{
			points = points + 1;
			if (twopointsaddition)
			{
				points = points + 2;
			}
		}
		deadcheckforship1 = false;
	}
	if (!((mybullet1 == l3r4enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy) || (mybullet1 == l3r3enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy) || (mybullet1 == l3r2enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy) || (mybullet1 == l3r1enemy && col3player == l3c3enemy)))
	{
		if (deadcheckforship1)
		{
			if (l3r4enemy < 28)
			{
				//--------------------------------
				plane[l3r1enemy][l3c1enemy] = "<";
				plane[l3r1enemy][l3c2enemy] = " ";
				plane[l3r1enemy][l3c3enemy] = " ";
				plane[l3r1enemy][l3c4enemy] = " ";
				plane[l3r1enemy][l3c5enemy] = ">";

				plane[l3r2enemy][l3c1enemy] = "<";
				plane[l3r2enemy][l3c2enemy] = "<";
				plane[l3r2enemy][l3c3enemy] = "|";
				plane[l3r2enemy][l3c4enemy] = ">";
				plane[l3r2enemy][l3c5enemy] = ">";

				plane[l3r3enemy][l3c2enemy] = "<";
				plane[l3r3enemy][l3c3enemy] = "|";
				plane[l3r3enemy][l3c4enemy] = ">";

				plane[l3r4enemy][l3c3enemy] = "'";
				if (l3enemybullet < 26)
				{
					plane[l3enemybullet][l3c3enemy] = "*";
				}
			}
		}
	}

	if ((mybullet1 == l3r4enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 10) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 10) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 10) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 10))
	{
		if (deadcheckforship2)
		{
			points = points + 1;
			if (twopointsaddition)
			{
				points = points + 2;
			}
		}
		deadcheckforship2 = false;
	}
	if (!((mybullet1 == l3r4enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 10) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 10) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 10) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 10) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 10) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 10)))
	{
		if (deadcheckforship2)
		{
			if (l3r4enemy < 28)
			{
				//--------------------------------
				plane[l3r1enemy][l3c1enemy + 10] = "<";
				plane[l3r1enemy][l3c2enemy + 10] = " ";
				plane[l3r1enemy][l3c3enemy + 10] = " ";
				plane[l3r1enemy][l3c4enemy + 10] = " ";
				plane[l3r1enemy][l3c5enemy + 10] = ">";

				plane[l3r2enemy][l3c1enemy + 10] = "<";
				plane[l3r2enemy][l3c2enemy + 10] = "<";
				plane[l3r2enemy][l3c3enemy + 10] = "|";
				plane[l3r2enemy][l3c4enemy + 10] = ">";
				plane[l3r2enemy][l3c5enemy + 10] = ">";

				plane[l3r3enemy][l3c2enemy + 10] = "<";
				plane[l3r3enemy][l3c3enemy + 10] = "|";
				plane[l3r3enemy][l3c4enemy + 10] = ">";

				plane[l3r4enemy][l3c3enemy + 10] = "'";
				if (l3enemybullet < 26)
				{
					plane[l3enemybullet][l3c3enemy + 10] = "*";
				}
			}
		}
	}
	if ((mybullet1 == l3r4enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 20) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 20) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 20) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 20))
	{
		if (deadcheckforship3)
		{
			points = points + 1;
			if (twopointsaddition)
			{
				points = points + 2;
			}
		}
		deadcheckforship3 = false;
	}
	if (!((mybullet1 == l3r4enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 20) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 20) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 20) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 20) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 20) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 20)))
	{
		if (deadcheckforship3)
		{
			if (l3r4enemy < 28)
			{
				//--------------------------------
				plane[l3r1enemy][l3c1enemy + 20] = "<";
				plane[l3r1enemy][l3c2enemy + 20] = " ";
				plane[l3r1enemy][l3c3enemy + 20] = " ";
				plane[l3r1enemy][l3c4enemy + 20] = " ";
				plane[l3r1enemy][l3c5enemy + 20] = ">";

				plane[l3r2enemy][l3c1enemy + 20] = "<";
				plane[l3r2enemy][l3c2enemy + 20] = "<";
				plane[l3r2enemy][l3c3enemy + 20] = "|";
				plane[l3r2enemy][l3c4enemy + 20] = ">";
				plane[l3r2enemy][l3c5enemy + 20] = ">";

				plane[l3r3enemy][l3c2enemy + 20] = "<";
				plane[l3r3enemy][l3c3enemy + 20] = "|";
				plane[l3r3enemy][l3c4enemy + 20] = ">";

				plane[l3r4enemy][l3c3enemy + 20] = "'";
				if (l3enemybullet < 26)
				{
					plane[l3enemybullet][l3c3enemy + 20] = "*";
				}
			}
		}
	}
	//--------------------------------
	if ((mybullet1 == l3r4enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 30) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 30) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 30) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 30))
	{
		if (deadcheckforship4)
		{
			points = points + 1;
			if (twopointsaddition)
			{
				points = points + 2;
			}
		}
		deadcheckforship4 = false;
	}
	if (!((mybullet1 == l3r4enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 30) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 30) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 30) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 30) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 30) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 30)))
	{
		if (deadcheckforship4)
		{
			if (l3r4enemy < 28)
			{
				plane[l3r1enemy][l3c1enemy + 30] = "<";
				plane[l3r1enemy][l3c2enemy + 30] = " ";
				plane[l3r1enemy][l3c3enemy + 30] = " ";
				plane[l3r1enemy][l3c4enemy + 30] = " ";
				plane[l3r1enemy][l3c5enemy + 30] = ">";

				plane[l3r2enemy][l3c1enemy + 30] = "<";
				plane[l3r2enemy][l3c2enemy + 30] = "<";
				plane[l3r2enemy][l3c3enemy + 30] = "|";
				plane[l3r2enemy][l3c4enemy + 30] = ">";
				plane[l3r2enemy][l3c5enemy + 30] = ">";

				plane[l3r3enemy][l3c2enemy + 30] = "<";
				plane[l3r3enemy][l3c3enemy + 30] = "|";
				plane[l3r3enemy][l3c4enemy + 30] = ">";

				plane[l3r4enemy][l3c3enemy + 30] = "'";
				if (l3enemybullet < 26)
				{
					plane[l3enemybullet][l3c3enemy + 30] = "*";
				}
			}
		}
	}
	//--------------------------------
	if ((mybullet1 == l3r4enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 40) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 40) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 40) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 40))
	{
		if (deadcheckforship5)
		{
			points = points + 1;
			if (twopointsaddition)
			{
				points = points + 2;
			}
		}
		deadcheckforship5 = false;
	}
	if (!((mybullet1 == l3r4enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r4enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r4enemy && col3player == l3c3enemy + 40) || (mybullet1 == l3r3enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r3enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r3enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r2enemy && col3player == l3c3enemy + 40) || (mybullet1 == l3r2enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r2enemy && col3player == l3c3enemy + 40) || (mybullet2 + 4 == l3r1enemy && col3player == l3c3enemy + 40) || (mybullet3 + 6 == l3r1enemy && col3player == l3c3enemy + 40) || (mybullet1 == l3r1enemy && col3player == l3c3enemy + 40)))
	{
		if (deadcheckforship5)
		{
			if (l3r4enemy < 28)
			{
				plane[l3r1enemy][l3c1enemy + 40] = "<";
				plane[l3r1enemy][l3c2enemy + 40] = " ";
				plane[l3r1enemy][l3c3enemy + 40] = " ";
				plane[l3r1enemy][l3c4enemy + 40] = " ";
				plane[l3r1enemy][l3c5enemy + 40] = ">";

				plane[l3r2enemy][l3c1enemy + 40] = "<";
				plane[l3r2enemy][l3c2enemy + 40] = "<";
				plane[l3r2enemy][l3c3enemy + 40] = "|";
				plane[l3r2enemy][l3c4enemy + 40] = ">";
				plane[l3r2enemy][l3c5enemy + 40] = ">";

				plane[l3r3enemy][l3c2enemy + 40] = "<";
				plane[l3r3enemy][l3c3enemy + 40] = "|";
				plane[l3r3enemy][l3c4enemy + 40] = ">";

				plane[l3r4enemy][l3c3enemy + 40] = "'";
				if (l3enemybullet < 26)
				{
					plane[l3enemybullet][l3c3enemy + 40] = "*";
				}
			}
		}
	}
	if ((row1player == l3r1enemy && col3player == l3c3enemy) || (row1player == l3r1enemy && col3player == l3c3enemy + 10) || (row1player == l3r1enemy && col3player == l3c3enemy + 20) || (row1player == l3r1enemy && col3player == l3c3enemy + 30) || (row1player == l3r1enemy && col3player == l3c3enemy + 40) || (row2player == l3r2enemy && col3player == l3c3enemy) || (row2player == l3r2enemy && col3player == l3c3enemy + 10) || (row2player == l3r2enemy && col3player == l3c3enemy + 20) || (row2player == l3r2enemy && col3player == l3c3enemy + 30) || (row2player == l3r2enemy && col3player == l3c3enemy + 40) || (row3player == l3r3enemy && col3player == l3c3enemy) || (row3player == l3r3enemy && col3player == l3c3enemy + 10) || (row3player == l3r3enemy && col3player == l3c3enemy + 20) || (row3player == l3r3enemy && col3player == l3c3enemy + 30) || (row3player == l3r3enemy && col3player == l3c3enemy + 40) || (row4player == l3r4enemy && col3player == l3c3enemy) || (row4player == l3r4enemy && col3player == l3c3enemy + 10) || (row4player == l3r4enemy && col3player == l3c3enemy + 20) || (row4player == l3r4enemy && col3player == l3c3enemy + 30) || (row4player == l3r4enemy && col3player == l3c3enemy + 40) || (l3enemybullet == row1player && l3c3enemy == col3player) || (l3enemybullet == row1player && l3c3enemy + 10 == col3player) || (l3enemybullet == row1player && l3c3enemy + 30 == col3player) || (l3enemybullet == row1player && l3c3enemy + 40 == col3player))
	{
		health = health - 1;
	}
	//--------------------------------------------Lvl 3 Enemy-------------------------------
	shipmovement(plane);
	shipglitch(plane);
	l3r1enemy++;
	l3r2enemy++;
	l3r3enemy++;
	l3r4enemy++;
	l3enemybullet = l3enemybullet + 2;
	if (l3r4enemy == 27)
	{
		l3r1enemy = 2;
		l3r2enemy = 3;
		l3r3enemy = 4;
		l3r4enemy = 5;
		l3enemybullet = 6;
	}
	if (l3r4enemy == 26)
	{
		gifthide1 = true;
		gifthide2 = true;
		gifthide2bullets = false;
	}
	if (l3r4enemy == 26)
	{
		deadcheckforship1 = true;
		deadcheckforship2 = true;
		deadcheckforship3 = true;
		deadcheckforship4 = true;
		deadcheckforship5 = true;
		healthcorrecter = true;
	}
	system("cls");
	layout(plane);
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < 115; j++)
		{
			cout << plane[i][j];
		}
		cout << endl;
	}
}