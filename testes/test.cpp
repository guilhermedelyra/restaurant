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
	vector< pair<char *, char *> > persons, tmp;
	vector< pair<char *, char *> >::iterator it;
	char * tis[3] = {new char[160], new char[160], new char[160]};
	int choice, highlight = 0, interfaces = 1, flag[200], fleg[200], total = 0;
	for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;

	while(1){
		switch(interfaces){
			case 1:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("login");
					choices.push_back("cadastrar funcionario");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 2:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("user: ");
					choices.push_back("pass: ");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 3:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("user: ");
					choices.push_back("pass: ");
					choices.push_back("tel: ");
					choices.push_back("voltar");
					choices.push_back("sair");
					flag[interfaces] = 0;
				}
				break;
			case 4:
				if(flag[interfaces]){
					total = 0;
					highlight = 1;
					choices.clear();
					choices.push_back("--- Refeições ---");
					choices.push_back("1. arroz carne feijao (15$)");
					choices.push_back("2. macarrao frango feijao (17$)");
					choices.push_back("3. stroggonof de carne (21$)");
					choices.push_back("--- Bebidas ---");
					choices.push_back("1. coca cola (5$)");
					choices.push_back("2. sprite (5$)");
					choices.push_back("3. suco de limão (5$)");
					choices.push_back("4. suco de goiaba (5$)");
					choices.push_back("--- Sobremesas ---");
					choices.push_back("1. pudim (8$)");
					choices.push_back("2. sorvete (7$)");
					choices.push_back("\n");
					choices.push_back("encerrar pedido");
					choices.push_back("voltar");
					choices.push_back("sair");
					choices.push_back("\n");
					choices.push_back("                               total = 0");
					flag[interfaces] = 0;
				}
				break;

		}

		wclear(menuwin);
		box(menuwin, 0, 0);
		refresh();
		wrefresh(menuwin);

		for(int i = 0; i < choices.size(); ++i){
			if(i == highlight && choices[i][0] != '-') wattron(menuwin, A_REVERSE);
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
			bool ok = false;
			if(fleg[highlight]){
				getstr(tis[highlight]);
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 2 && ok == false){
				tmp.push_back(make_pair(tis[0], tis[1]));
				ok = true;
				it = find (persons.begin(), persons.end(), tmp[0]);
			    if(it != persons.end()){
					interfaces = 4;
					for(int i = 0; i < 200; ++i) fleg[i] = 1;
				} else {
					for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
					interfaces = 1;
					wclear(menuwin);
					refresh();
					wrefresh(menuwin);
					printw("usuario ou senha incorretos\n(pressione qualquer tecla para voltar)\n");
					refresh();
					getchar();
					wclear(menuwin);
					clear();
					refresh();
				}
			}
		}

		if(interfaces == 3 && (highlight == 2 || highlight == 1 || highlight == 0)){
			bool ok = false;
			if(fleg[highlight]){
				getstr(tis[highlight]);
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 3 && ok == false){
				persons.push_back(make_pair(tis[0], tis[1]));
				for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
				interfaces = 1;
				ok = true;
			}
		}

		if((choice == 10 || choice == 20) && interfaces == 4 && (choices[highlight][0] - '0' >= 0 && choices[highlight][0] - '0' <= 9)){
			int t = choices[highlight].length() - 3, price = 0, i = 0;
			while(choices[highlight][t-i] != '('){
				price += (choices[highlight][t-i] - '0') * pow(10, i++);
			}
			total += price;
			choices[17] = "                               total = " + to_string(total);
		}

		if((choice == 10 || choice == 20) && choices[highlight] == "sair"){
			break;
		}
		if((choice == 10 || choice == 20) && choices[highlight] == "voltar"){
			for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
			interfaces = 1;
		}
		if((choice == 10 || choice == 20) && choices[highlight] == "login"){
			interfaces = 2;
		}
		if((choice == 10 || choice == 20) && choices[highlight] == "cadastrar funcionario"){
			interfaces = 3;
		}

	}
	wclear(menuwin);
	refresh();
	wrefresh(menuwin);
	printw("press any key to leave\n");
	refresh();
	getchar();
	refresh();
	endwin();
	return 0;
}
