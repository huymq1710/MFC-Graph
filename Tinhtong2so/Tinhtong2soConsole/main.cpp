#include <iostream>
#include <conio.h>
#include "Giaitoan.h"
using namespace std;

int main(int argc, char* argv[]) {
	Giaitoan objGiaiToan;

	int tong = objGiaiToan.tinhtonghaiso(3, 4);

	cout << "Tong = " <<tong << endl;
	_getch();
	return 0;

}