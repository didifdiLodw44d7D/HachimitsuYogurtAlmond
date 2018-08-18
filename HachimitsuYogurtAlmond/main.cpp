#include <iostream>
#include "FutsuKoma.h"

using namespace std;

int main(void)
{
	FutsuKoma *futsukoma = new FutsuKoma();

	futsukoma->Hello();

	int s;

	cin >> s;

	delete(futsukoma);

	return 0;
}