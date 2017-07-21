#include <ncurses.h>
#include "Person.hpp"
#include "Product.hpp"
#include "Stock.hpp"

string fto_string(float x){
    stringstream stream;
    stream << fixed << setprecision(2) << x;
    return stream.str();
}
string getinput(){
	char ch = getch();
	string input = "";
    if (ch != '\n') input += ch;
	while (1){
		ch = getch();
		if (ch == '\n'){
			break;
		}
		if (ch >= 33 && ch <= 122){
			input.push_back(ch);
		}
	}

	return input;
}

void init_productstocks(vector<Product> & p, vector<Stock> & st){
    int l = 1;
    p.clear(); st.clear();

    Product * p0 = new Product("arroz carne feijao", 15.00);
    Stock * d0 = new Stock(l++, 50, 20);
    st.push_back(*d0);
    p.push_back(*p0);
    Product * p1 = new Product("macarrao frango feijao", 17.00);
    Stock * d1 = new Stock(l++, 35, 10);
    st.push_back(*d1);
    p.push_back(*p1);
    Product * p2 = new Product("stroggonof de carne", 21.50);
    Stock * d2 = new Stock(l++, 20, 5);
    st.push_back(*d2);
    p.push_back(*p2);
    Product * p3 = new Product("coca cola", 5.00);
    Stock * d3 = new Stock(l++, 60, 25);
    st.push_back(*d3);
    p.push_back(*p3);
    Product * p4 = new Product("sprite", 5.00);
    Stock * d4 = new Stock(l++, 20, 5);
    st.push_back(*d4);
    p.push_back(*p4);
    Product * p5 = new Product("suco de limao", 5.00);
    Stock * d5 = new Stock(l++, 35, 10);
    st.push_back(*d5);
    p.push_back(*p5);
    Product * p6 = new Product("suco de laranja", 5.00);
    Stock * d6 = new Stock(l++, 35, 10);
    st.push_back(*d6);
    p.push_back(*p6);
    Product * p7 = new Product("pudim", 8.50);
    Stock * d7 = new Stock(l++, 10, 3);
    st.push_back(*d7);
    p.push_back(*p7);
    Product * p8 = new Product("sorvete", 4.99);
    Stock * d8 = new Stock(l, 15, 4);
    st.push_back(*d8);
    p.push_back(*p8);
}

int main(){
    fstream outfili("users.txt", fstream::in | fstream::out | fstream::app);
    ofstream func, client;
    func.open ("users.txt", std:: ofstream::out | std:: ofstream::app);
    client.open ("client.txt", std:: ofstream::out | std:: ofstream::app);
    vector<Client> c;
    vector<Functionary> f;
    vector<Product> p;
    vector<Stock> st, cp_st;
    vector<Order> orders;

    Order * pedido = new Order(0, "", false);
    orders.push_back(* pedido);

    init_productstocks(p, st);

    initscr();
    raw();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
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

	vector<string> choices, cpy;
	string tis[5], tos[5];
	pair<string, string> tmp;

	int choice, highlight = 0, interfaces = 1, flag[200], fleg[200], qtd[12] = {0};
    float daily_balance = 0;
    bool logged = false;

    while(getline(outfili, tis[0])){
        getline(outfili, tis[1]);
        Functionary * temp = new Functionary("", tis[0], tis[1], "");
        f.push_back(*temp);
    }

	for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;

	while(1){
		switch(interfaces){
			case 1:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("login");
					choices.push_back("register employee");
					choices.push_back("exit");
					flag[interfaces] = 0;
				}
				break;
			case 2:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("user: ");
					choices.push_back("pass: ");
					choices.push_back("exit");
                    choices.push_back("\n");
                    choices.push_back("---- first key when filling any field is ignored ----");
					flag[interfaces] = 0;
				}
				break;
			case 3:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
                    choices.push_back("* name: ");
					choices.push_back("* user: ");
					choices.push_back("* pass: ");
					choices.push_back("* tel: ");
					choices.push_back("back");
					choices.push_back("exit");
                    choices.push_back("\n");
                    choices.push_back("---- first key when filling any field is ignored ----");
					flag[interfaces] = 0;
				}
				break;
			case 4:
				if(flag[interfaces]){
					(orders.back()).totalvalue = 0;
					highlight = 0;
                    logged = true;
					choices.clear();
                    choices.push_back(to_string(st[0].id) + ". " + p[0].name + "      (" + fto_string(p[0].price) + "$) [" + to_string(st[0].quantity) + "] x 0");
                    choices.push_back(to_string(st[1].id) + ". " + p[1].name + "  (" + fto_string(p[1].price) + "$) [" + to_string(st[1].quantity) + "] x 0");
                    choices.push_back(to_string(st[2].id) + ". " + p[2].name + "     (" + fto_string(p[2].price) + "$) [" + to_string(st[2].quantity) + "] x 0");
                    choices.push_back(to_string(st[3].id) + ". " + p[3].name + "               (" + fto_string(p[3].price) + "$)  [" + to_string(st[3].quantity) + "] x 0");
                    choices.push_back(to_string(st[4].id) + ". " + p[4].name + "                  (" + fto_string(p[4].price) + "$)  [" + to_string(st[4].quantity) + "] x 0");
                    choices.push_back(to_string(st[5].id) + ". " + p[5].name + "           (" + fto_string(p[5].price) + "$)  [" + to_string(st[5].quantity) + "] x 0");
                    choices.push_back(to_string(st[6].id) + ". " + p[6].name + "         (" + fto_string(p[6].price) + "$)  [" + to_string(st[6].quantity) + "] x 0");
                    choices.push_back(to_string(st[7].id) + ". " + p[7].name + "                   (" + fto_string(p[7].price) + "$)  [" + to_string(st[7].quantity) + "] x 0");
                    choices.push_back(to_string(st[8].id) + ". " + p[8].name + "                 (" + fto_string(p[8].price) + "$)  [" + to_string(st[8].quantity) + "] x 0");
					choices.push_back("\n");
					choices.push_back("close order");
                    choices.push_back("back");
					choices.push_back("exit");
					choices.push_back("\n");
					choices.push_back("                               total = 0");
					cpy = choices;
                    cp_st = st;
					flag[interfaces] = 0;
				}
				break;
			case 5:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("register client");
                    choices.push_back("add observation");
					choices.push_back("credit card payment");
					choices.push_back("cash payment");
					choices.push_back("back");
					choices.push_back("exit");
					flag[interfaces] = 0;
				}
			case 6:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("* name: ");
					choices.push_back("* tel: ");
					choices.push_back("back");
					choices.push_back("exit");
                    choices.push_back("\n");
                    choices.push_back("---- first key when filling any field is ignored ----");
					flag[interfaces] = 0;
				}
				break;
			case 7:
				if(flag[interfaces]){
					highlight = 0;
					choices.clear();
					choices.push_back("* observation: ");
					choices.push_back("back");
					choices.push_back("exit");
					flag[interfaces] = 0;
				}
				break;
            case 8:
                if(flag[interfaces]){
                    highlight = 0;
                    choices.clear();
                    choices.push_back("* pass: ");
                    choices.push_back("back");
                    choices.push_back("exit");
                    flag[interfaces] = 0;
                }
                break;
            case 9:
                if(flag[interfaces]){
                    highlight = 6;
                    choices.clear();
                    (orders.back()).ok = true;
                    daily_balance += (orders.back()).totalvalue;
                    choices.push_back("order closed!");
                    choices.push_back("total = " + fto_string((orders.back()).totalvalue));
                    choices.push_back("observation = " + (orders.back()).observation);
                    choices.push_back("\n");
                    choices.push_back("--- daily balance: " + fto_string(daily_balance) + " ---");
                    orders.push_back(* pedido);
                    choices.push_back("\n");
                    choices.push_back("back");
                    choices.push_back("exit");
                    flag[interfaces] = 0;
                }
                break;
            case 10:
                if(flag[interfaces]){
                    highlight = 2;
                    choices.clear();
                    client << c.back().name << " " << c.back().tel << endl;
                    choices.push_back("name: " + c.back().name);
                    choices.push_back("tel: " + c.back().tel);
                    choices.push_back("back");
                    flag[interfaces] = 0;
                }
                break;

            case 11:
                if(flag[interfaces]){
                    highlight = 1;
                    choices.clear();
                    choices.push_back("observation: " + orders.back().observation);
                    choices.push_back("back");
                    flag[interfaces] = 0;
                }
                break;
            case 12:
                if(flag[interfaces]){
                    highlight = 1;
                    choices.clear();
                    choices.push_back("user and/or password incorrect(s)");
                    choices.push_back("retry");
                    flag[interfaces] = 0;
                }
                break;
            case 13:
                if(flag[interfaces]){
                    highlight = 2;
                    choices.clear();
                    choices.push_back("password correct!");
                    choices.push_back("please take out the card.");
                    choices.push_back("proceed");
                    flag[interfaces] = 0;
                }
                break;

            case 14:
                if(flag[interfaces]){
                    highlight = 5;
                    choices.clear();
                    choices.push_back("name: " + f.back().name);
                    choices.push_back("user: " + f.back().employee.first);
                    choices.push_back("password: " + f.back().employee.second);
                    choices.push_back("tel: " + f.back().tel);
                    choices.push_back("\n");
                    choices.push_back("register");
                    choices.push_back("cancel");
                    flag[interfaces] = 0;
                }
                break;

		}

		wclear(menuwin);
		box(menuwin, 0, 0);
		refresh();
		wrefresh(menuwin);

		for(int i = 0; i < (int)choices.size(); ++i){
			if(i == highlight) wattron(menuwin, A_REVERSE);
            if(interfaces == 4){
                if(i < 9){
                    if(st[i].quantity <= st[i].min_amount) wattron(menuwin, COLOR_PAIR(1));
                    else wattron(menuwin, COLOR_PAIR(2));
                }
            }
			mvwprintw(menuwin, i+1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
            if(interfaces == 4){
                if(i < 9){
                    if(st[i].quantity <= st[i].min_amount) wattroff(menuwin, COLOR_PAIR(1));
                    else wattroff(menuwin, COLOR_PAIR(2));
                }
            }
		}

		choice = wgetch(menuwin);
		switch(choice){
			case KEY_UP:
				highlight--;
				if(highlight == -1) highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == (int)choices.size()) highlight = choices.size()-1;
				break;
			default:
				break;
		}

		if(interfaces == 2 && (highlight == 1 || highlight == 0)){
			bool ok = false;
			if(fleg[highlight]){
                tos[highlight] = getinput();
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 2 && ok == false){
				tmp = make_pair(tos[0], tos[1]);
				ok = true;
                bool fleger = false;
				for(int i = 0; i < (int)f.size(); ++i){
                    if(f[i].employee.first == tmp.first && f[i].employee.second == tmp.second) fleger = true;
                }
			    if(fleger){
					interfaces = 4;
					for(int i = 0; i < 200; ++i) fleg[i] = 1;

				} else {
					for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
					interfaces = 12;
				}
			}
		}

		if(interfaces == 3 && choices[highlight][0] == '*'){
			bool ok = false;
			if(fleg[highlight]){
				tis[highlight] = getinput();
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 4 && ok == false){
                Functionary * temp = new Functionary(tis[0], tis[1], tis[2], tis[3]);
                f.push_back(*temp);
				for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
				interfaces = 14;
				ok = true;
			}
		}

		if((choice == '\n') && interfaces == 4 && (choices[highlight][0] - '0' >= 0 && choices[highlight][0] - '0' <= 9)){
			if(st[highlight].quantity > 0){
                (orders.back()).totalvalue += p[highlight].price;
                qtd[highlight]++;
                st[highlight].quantity--;
            }
			choices.back() = "                               total = " + fto_string((orders.back()).totalvalue) + "$";
			choices[highlight] = (cpy[highlight].substr(0, cpy[highlight].size()-7)) + to_string(st[highlight].quantity) + "] x " + to_string(qtd[highlight]);
		}
		if((choice == 'R' || choice == 'r') && interfaces == 4 && (choices[highlight][0] - '0' >= 0 && choices[highlight][0] - '0' <= 9)){
			if(qtd[highlight] - 1 >= 0){
                qtd[highlight]--;
                st[highlight].quantity++;
                (orders.back()).totalvalue -= p[highlight].price;
            }
			choices.back() = "                               total = " + fto_string((orders.back()).totalvalue) + "$";
            choices[highlight] = (cpy[highlight].substr(0, cpy[highlight].size()-7)) + to_string(st[highlight].quantity) + "] x " + to_string(qtd[highlight]);
		}
        if(interfaces == 6 && choices[highlight][0] == '*'){
			bool ok = false;
			if(fleg[highlight]){
                tos[highlight] = "";
				tos[highlight] = getinput();
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight >= 2 && ok == false){
                Client * cemp = new Client(tos[0], tos[1]);
                c.push_back(*cemp);
				for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
				interfaces = 10;
				ok = true;
			}
		}
        if(interfaces == 7 && choices[highlight][0] == '*'){
            bool ok = false;
			if(fleg[highlight]){
                tos[highlight] = "";
                tos[highlight] = getinput();
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 1 && ok == false){
                (orders.back()).observation = tos[0];
				for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
				interfaces = 11;
				ok = true;
			}
        }
        if(interfaces == 8 && choices[highlight][0] == '*'){
            bool ok = false;
			if(fleg[highlight]){
                tos[highlight] = "";
                tos[highlight] = getinput();
				fleg[highlight] = 0;
				highlight++;
			}
			if(highlight == 1 && ok == false){
                (orders.back()).observation = tos[0];
				for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
				interfaces = 13;
				ok = true;
			}
        }

		if((choice == 10) && choices[highlight] == "exit"){
			break;
		}
		if((choice == 10) && choices[highlight] == "back"){
			for(int i = 0; i < 200; ++i) fleg[i] = flag[i] = 1;
            if(!(orders.back()).ok && interfaces <= 5) {
                st = cp_st;
                memset(qtd, 0, sizeof(qtd));
                (orders.back()).totalvalue = 0;
            }
            if(logged){
                if(interfaces == 4){
                    logged = false;
                    interfaces = 1;
                }
                if(interfaces == 5 || interfaces == 9) interfaces = 4;
                if(interfaces > 5 && interfaces != 9) interfaces = 5;
            }
		}

        if((choice == 10) && choices[highlight] == "retry"){
			interfaces = 1;
		}
		if((choice == 10) && choices[highlight] == "login"){
			interfaces = 2;
		}
        if((choice == 10) && choices[highlight] == "register employee"){
			interfaces = 3;
		}
        if((choice == 10) && choices[highlight] == "close order"){
			interfaces = 5;
		}
        if((choice == 10) && choices[highlight] == "register client"){
			interfaces = 6;
		}
        if((choice == 10) && choices[highlight] == "add observation"){
			interfaces = 7;
		}
        if((choice == 10) && choices[highlight] == "credit card payment"){
            interfaces = 8;
        }
        if((choice == 10) && choices[highlight] == "proceed"){
            interfaces = 9;
        }
        if((choice == 10) && choices[highlight] == "cash payment"){
            interfaces = 9;
        }
        if((choice == 10) && choices[highlight] == "register"){
            interfaces = 1;
            func << tis[1] << endl << tis[2] << endl;
        }
        if((choice == 10) && choices[highlight] == "cancel"){
            f.pop_back();
            interfaces = 1;
        }
	}
	wclear(menuwin);
	refresh();
	wrefresh(menuwin);
    attron(COLOR_PAIR(3));
    printw("press any key to leave");
    attroff(COLOR_PAIR(3));
    refresh();
	getchar();
    func.close();
    client.close();
    outfili.close();
	refresh();
	endwin();
	return 0;
}
