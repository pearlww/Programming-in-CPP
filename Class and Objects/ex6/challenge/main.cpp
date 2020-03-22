#include "include.h"
#define CHALLENGEMODE 0
using namespace std;

int main(void)
{
	int num[255], den[255];
	int opraCnt = 0;
	char opra[255][3];
	char subline;

	for (int i = 0; !cin.fail(); i++) {
		cin >> num[i] >> subline >> den[i] ;
		opra[opraCnt++][0] = cin.get();
		if (opra[opraCnt - 1][0] == 'd') {
			cin >> opra[opraCnt-1][1];
			cin >> opra[opraCnt-1][2];
		}
	}
	fraction f(num[0], den[0]);
	for (int i = 0; i < opraCnt; i++) {
		if (opra[i][0] == '+') {
			fraction f1 = f;
			fraction f2(num[i + 1], den[i + 1]);
#if CHALLENGEMODE
			f1.challengeAdd(f2);
#else
			f1.add(f2);
#endif
			f = f1;
		}
		else if (opra[i][0] == '-') {
			fraction f1 = f;
			fraction f2(num[i + 1], den[i + 1]);
			f1.sub(f2);
			f = f1;
		}
		else if (opra[i][0] == '*') {
			fraction f1 = f;
			fraction f2(num[i + 1], den[i + 1]);
			f1.mult(f2);
			f = f1;
		}
		else if (opra[i][0] == 'd') {
			fraction f1 = f;
			fraction f2(num[i + 1], den[i + 1]);
			f1.div(f2);
			f = f1;
		}
		else if (opra[i][0] == '\n') {
			f.display();
			fraction f1(num[i + 1], den[i + 1]);
			f = f1;
			continue;
		}
	}
	return 0;
}

