#include <graphics.h>
#include <stdio.h>
#include <conio.h>
int main(){
	int mh=0;
	int mode=0;
	initgraph(&mh,&mode,"C:\Program Files (x86)\Dev-Cpp\Templates\6-ConsoleAppGraphics.template");
	closegraph();
	printf("gt mh: %d",mh);
	getch();
}
