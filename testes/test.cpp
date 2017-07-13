#include <ncurses.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char ** argv){
	initscr();
	noecho();
	cbreak();
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	WINDOW * menuwin;
	int y = 24, x = 78;
	menuwin = newwin(y - 4 - 2, x, 1, 1);
	wresize(menuwin, y, x);
	box(menuwin, 0, 0);

	refresh();
	wrefresh(menuwin);

	keypad(menuwin, true);

	vector<string> choices;

	int choice, highlight = 0, interfaces = 1, flag[200];
	for(int i = 0; i < 200; ++i) flag[i] = 1;

	while(1){
		switch(interfaces){
			case 1:
				if(flag[interfaces]){
					choices.push_back("login");
					choices.push_back("cadastrar funcionario");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 2:
				wclear(menuwin);
				if(flag[interfaces]){
					choices.clear();
					choices.push_back("user: ");
					choices.push_back("pass: ");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
		}
		box(menuwin, 0, 0);
		refresh();
		wrefresh(menuwin);
		for(int i = 0; i < choices.size(); ++i){
			if(i == highlight) wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i+1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);

		switch(choice){
			case KEY_UP:
				highlight--;
				if(highlight == -1) highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == choices.size()) highlight = choices.size()-1;
				break;
			default:
				break;
		}
		if(interfaces == 2){
			string x = "", y = "";
			int p, l = 10;
			while((p = getch()) != '\n'){
				x += p;
				mvwprintw(menuwin, 1, 1, x.c_str());
			}
			mvwprintw(menuwin, 1, l++, "\n");
			l = 10;
			while((p = getch()) != '\n'){
				y += p;
				mvwprintw(menuwin, 2, l++, y.c_str());
			}
		}
		if((choice == 10 || choice == 20) && choices[highlight] == "sair"){
			break;
		}
		if((choice == 10 || choice == 20) && choices[highlight] == "login"){
			interfaces = 2;
		}

	}

	printw("lala %s", choices[highlight].c_str());
	getch();
	endwin();

	return 0;
}
