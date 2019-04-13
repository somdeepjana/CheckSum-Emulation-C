#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

struct send_data{
	int numb_arr[10]; //numbers in the array of a record
	int numb_bin[10][5]; //for holding binary equvalent fro each number of privious array
	int checksum_val;
	int checksum_bin;
};


void delay(int );
void DecBinary(int );

void add_data();
void main_menu();
void send_data();
void view_all();
void next();


void welcom(){
	SetConsoleTitle("HELLO");
	system("cls");
	system("COLOR 0E");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 186.5, 124, 993, 518, TRUE);
	printf("\n\n\n\n");
	printf("              _____                      _____                      _____            _____           _______         \n");
	printf("             /     :                    /     :                    /     :          /     :         /::     :        \n");
	printf("            /:: ____:                  /::     :                  /:: ____:        /:: ____:       /::::     :       \n");
	printf("           /:::/    /                 /::::     :                /:::/    /       /:::/    /      /::::::     :      \n");
	printf("          /:::/    /                 /::::::     :              /:::/    /       /:::/    /      /::::::::     :     \n");
	printf("         /:::/    /                 /:::/::::     :            /:::/    /       /:::/    /      /:::/~~::::     :    \n");
	printf("        /:::/____/                 /:::/__::::     :          /:::/    /       /:::/    /      /:::/    ::::     :   \n");
	printf("       /::::.    :                /::::    ::::     :        /:::/    /       /:::/    /      /:::/    / ::::     :  \n");
	printf("      /::::::.    :   _____      /::::::    ::::     :      /:::/    /       /:::/    /      /:::/____/   :::: ____: \n");
	printf("     /:::/::::.    : /     .    /:::/::::    ::::     :    /:::/    /       /:::/    /      |:::|    |     |:::|    |\n");
	printf("    /:::/  ::::.    /:: ____.  /:::/__::::    :::: ____:  /:::/____/       /:::/____/       |:::|____|     |:::|    |\n");
	printf("     ::/    ::::.  /:::/    /  ::::    ::::    :::/    /  ::::     :       ::::     :        ::::    :    /:::/    / \n");
	printf("      /____/ ::::./:::/    /    ::::    ::::    :/____/    ::::     :       ::::     :        ::::    :  /:::/    /  \n");
	printf("              :::::::/    /      ::::    ::::     :         ::::     :       ::::     :        ::::    :/:::/    /   \n");
	printf("               :::::/    /        ::::    :::: ____:         ::::     :       ::::     :        :::: __/:::/    /    \n");
	printf("               /:::/    /          ::::    :::/    /          ::::     :       ::::     :        :::::::::/    /     \n");
	printf("              /:::/    /            ::::    :/____/            ::::     :       ::::     :        :::::::/    /      \n");
	printf("             /:::/    /              ::::     :                 ::::     :       ::::     :        :::::/    /       \n");
	printf("            /:::/    /                :::: ____:                 :::: ____:       :::: ____:        :::/____/        \n");
	printf("            '::/    /                  :::/    /                  :::/    /        :::/    /         ~~              \n");
	printf("             '/____/                    :/____/                    :/____/          :/____/                          \n");
	getch();
	system("cls");
    MoveWindow(wh, 200, 200, 1335, 325, TRUE);
	printf("\n        CCCCCCCCCCCCChhhhhhh                                                     kkkkkkkk              SSSSSSSSSSSSSSS                                           ");
	printf("\n     CCC::::::::::::Ch:::::h                                                     k::::::k            SS:::::::::::::::S                                          ");
	printf("\n   CC:::::::::::::::Ch:::::h                                                     k::::::k           S:::::SSSSSS::::::S                                          ");
	printf("\n  C:::::CCCCCCCC::::Ch:::::h                                                     k::::::k           S:::::S     SSSSSSS                                          ");
	printf("\n C:::::C       CCCCCC h::::h hhhhh           eeeeeeeeeeee        cccccccccccccccc k:::::k    kkkkkkkS:::::S            uuuuuu    uuuuuu     mmmmmmm    mmmmmmm   ");
	printf("\nC:::::C               h::::hh:::::hhh      ee::::::::::::ee    cc:::::::::::::::c k:::::k   k:::::k S:::::S            u::::u    u::::u   mm:::::::m  m:::::::mm ");
	printf("\nC:::::C               h::::::::::::::hh   e::::::eeeee:::::ee c:::::::::::::::::c k:::::k  k:::::k   S::::SSSS         u::::u    u::::u  m::::::::::mm::::::::::m");
	printf("\nC:::::C               h:::::::hhh::::::h e::::::e     e:::::ec:::::::cccccc:::::c k:::::k k:::::k     SS::::::SSSSS    u::::u    u::::u  m::::::::::::::::::::::m");
	printf("\nC:::::C               h::::::h   h::::::he:::::::eeeee::::::ec::::::c     ccccccc k::::::k:::::k        SSS::::::::SS  u::::u    u::::u  m:::::mmm::::::mmm:::::m");
	printf("\nC:::::C               h:::::h     h:::::he:::::::::::::::::e c:::::c              k:::::::::::k            SSSSSS::::S u::::u    u::::u  m::::m   m::::m   m::::m");
	printf("\nC:::::C               h:::::h     h:::::he::::::eeeeeeeeeee  c:::::c              k:::::::::::k                 S:::::Su::::u    u::::u  m::::m   m::::m   m::::m");
	printf("\n C:::::C       CCCCCC h:::::h     h:::::he:::::::e           c::::::c     ccccccc k::::::k:::::k                S:::::Su:::::uuuu:::::u  m::::m   m::::m   m::::m");
	printf("\n  C:::::CCCCCCCC::::C h:::::h     h:::::he::::::::e          c:::::::cccccc:::::ck::::::k k:::::k   SSSSSSS     S:::::Su:::::::::::::::uum::::m   m::::m   m::::m");
	printf("\n   CC:::::::::::::::C h:::::h     h:::::h e::::::::eeeeeeee   c:::::::::::::::::ck::::::k  k:::::k  S::::::SSSSSS:::::S u:::::::::::::::um::::m   m::::m   m::::m");
	printf("\n     CCC::::::::::::C h:::::h     h:::::h  ee:::::::::::::e    cc:::::::::::::::ck::::::k   k:::::k S:::::::::::::::SS   uu::::::::uu:::um::::m   m::::m   m::::m");
	printf("\n        CCCCCCCCCCCCC hhhhhhh     hhhhhhh    eeeeeeeeeeeeee      cccccccccccccccckkkkkkkk    kkkkkkk SSSSSSSSSSSSSSS       uuuuuuuu  uuuummmmmm   mmmmmm   mmmmmm");
	getch();
}

void main(){
	welcom();
	system("cls");
	remove("transport.bin");
	SetConsoleTitle("Sender");
	FILE *checkFile;
	printf("\n\n		CheckSum Generator\n\n");
	checkFile= fopen("send.bin","rb");
	if(checkFile== NULL){
		fclose(checkFile);
		add_data();
	}else{
		fclose(checkFile);
		main_menu();
	}
}

void add_data(){
	system("cls");
	FILE *addData;
	struct send_data entry;
	entry.checksum_val= 0;
	int numb_entry= 0, i;
	if ((addData= fopen("send.bin", "ab+"))== NULL){
		printf("\nError in Creating send.bin file");
		getch();
		exit(0);
	}
	printf("\n\n				Adding Data\n");
	for(i=0; i<10; i++){
		printf("\n	Enter the numbers to Send[-1 to stop]: ");
		scanf("%d", &numb_entry);
		fflush(stdin);
		if(numb_entry!=-1){
			entry.numb_arr[i]= numb_entry;
			entry.checksum_val += numb_entry;
		}else{
			entry.numb_arr[i]= -1;
			break;
		}
	}
	fwrite(&entry, sizeof(entry), 1, addData);
	fclose(addData);
	main_menu();
}


void main_menu(){
	system("cls");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 0, 0, 580, 200, TRUE);
	printf("\n\n				Main Menu\n\n");
	printf("	01. Add Another Data			02. Send Data\n");
	printf("	03. View All Data			04. Exit\n");
	printf("\n	Take a Step.........");
lableMMO:
	switch(getch()){
		case '1':
			add_data();
			break;
		case '2':
			send_data();
			break;
		case '3':
			view_all();
			break;
		case '4':
			remove("send.bin");
			exit(1);
			break;
		default:
			system("cls");
			printf("\n\n		Main Menu\n\n");
			printf("	01. Load Another Data			02. Send Data\n");
			printf("	03. View All Data				04.Exit\n");
			printf("\n	Wrong Step, TryAgain.........");
			goto lableMMO;
	}
	
}


void view_all(){
	system("cls");
	printf("\n\n		Viewing All\n\n");
	FILE *viewData;
	struct send_data view;
	int i, no= 1;
	
	if ((viewData= fopen("send.bin", "rb"))== NULL){
		printf("\nError in Creating send.bin file");
		getch();
		exit(0);
	}
	while(fread(&view, sizeof(view), 1, viewData)==1){
		printf("		%d.", no);
		for(i=0; i<10; i++){
			if(view.numb_arr[i]!=-1){
				printf(" %d", view.numb_arr[i]);
			}else{
				break;
			}
		}
		printf(" 			C %d", view.checksum_val);
		printf("\n");
		no++;
	}
	printf("\n\n		Hit a Key for Back..........");
	fclose(viewData);
	getch();
	main_menu();
	
}

void send_data(){
	system("cls");
	FILE *checkTransport;
	int dotcount= 0, reState=5 ;
	printf("\n\n		Sending Data\n\n");
	reState= rename("send.bin", "transport.bin");	
	if(reState== 0){
		printf("\n		Data sent to the Transpotation Medium");
	}else{
		printf("\n		Data Sending Fail");
	}
LableSD0:
	system("cls");
	printf("\n\n		Sending Data\n\n");
	printf("\n		Data sent to the Transpotation Medium");
	printf("\n		Press any key to move forward......");
	getch();
	if(((checkTransport= fopen("transport.bin", "rb"))== NULL) && ((checkTransport= fopen("transported.bin", "rb"))== NULL) && ((checkTransport= fopen("reciver.bin", "rb"))== NULL) && ((checkTransport= fopen("recived.bin", "rb"))== NULL)){
		fclose(checkTransport);
		main();
	}else{
		goto LableSD0;
	}
	
}

//supporting functions
void delay(int sec){
	int milisec= 1000 * sec;
	clock_t start_time= clock();
	while(clock()< (start_time + milisec));
	
}

