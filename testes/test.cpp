#include <ncurses.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char ** argv){
	initscr();
	noecho();
	cbreak();
	WINDOW * menuwin;
	int y = 24, x = 78;
	menuwin = newwin(y - 4 - 2, x, 1, 1);
	wresize(menuwin, y, x);
	box(menuwin, 0, 0);

	refresh();
	wrefresh(menuwin);

	keypad(menuwin, true);

	vector<string> choices;
	char* tis[2] = {new char[160], new char[160]};

	int choice, highlight = 0, interfaces = 1, flag[200], fleg[2] = {1, 1};
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

		if(interfaces == 2 && (highlight == 1 || highlight == 0)){
			int p;
			if(fleg[highlight]){
				getstr(tis[highlight]);
				fleg[highlight] = 0;
				highlight++;
			}
		}
		if((choice == 10 || choice == 20) && choices[highlight] == "sair"){
			break;
		}
		if((choice == 10 || choice == 20) && choices[highlight] == "login"){
			interfaces = 2;
		}

	}
	wclear(menuwin);
	refresh();
	wrefresh(menuwin);
	printw( "Press any key to leave\n");
	refresh();
	getchar();
	refresh();
	endwin();
	return 0;
}
