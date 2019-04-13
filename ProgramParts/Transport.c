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

void main_menu();
void transfer();
void error();
void view_all();

void main(){
	SetConsoleTitle("Transportation Medium");
	system("COLOR 0C");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 590, 0, 650, 200, TRUE);
	FILE *checkFile;
LableM0:
	system("cls");
	printf("\n\n\n\n	Press any key to check wheather sender send anything.......");
	getch();
	if((checkFile= fopen("transport.bin", "rb"))== NULL){
		goto LableM0;
	}else{
		fclose(checkFile);
		rename("transport.bin", "transported.bin");
		main_menu();
	}
	
}

void main_menu(){
	system("cls");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 590, 0, 580, 200, TRUE);
	printf("\n\n			Transportation Menu\n\n");
	printf("	01. Transfer			02. Hit with Error");
	printf("\n	03. View All");
	printf("\n\n	Take a step..........");
lableMM01:
	switch(getch()){
		case '1':
			transfer();
			break;
		case '2':
			error();
			break;
		case '3':
			view_all();
			break;
		default:
			system("cls");
	printf("\n\n		Transportation Menu\n\n");
	printf("		01. Transfer			02. Hit with Error");
	printf("\n\n		Wrong step, TryAgain..........");
	goto lableMM01;
	}
}

void transfer(){
	FILE *checkTransport;
LableT0:
	system("cls");
	rename("transported.bin", "reciver.bin");
	printf("\n\n		Data is Transfered");
	printf("\n		Press any key to move forward........");
	getch();
	if(((checkTransport= fopen("transported.bin", "rb"))== NULL) && ((checkTransport= fopen("reciver.bin", "rb"))== NULL) && ((checkTransport= fopen("recived.bin", "rb"))== NULL)){
		fclose(checkTransport);
		main();
	}else{
		goto LableT0;
	}
}

void view_all(){
	system("cls");
	printf("\n\n		Viewing All\n\n");
	FILE *viewData;
	struct send_data view;
	int i, no= 1;
	
	if ((viewData= fopen("transported.bin", "rb"))== NULL){
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

void error(){
	system("cls");
	printf("\n\n		Viewing All\n\n");
	FILE *viewData, *temp;
	struct send_data view;
	int i, no= 1, errorNumb, errorBit, bitNumb=1, bit;
	
	if ((viewData= fopen("transported.bin", "rb"))== NULL){
		printf("\nError in Creating transported.bin file");
		getch();
		exit(0);
	}
	if ((temp= fopen("temp", "wb"))== NULL){
		printf("\nError in Creating temp file");
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
		printf("		C %d", view.checksum_val);
		printf("\n");
		no++;
	}
	printf("\n\n		Hit a Number for Error: ");
	fclose(viewData);
	
lableVA1:
	scanf("%d", &errorNumb);
	fflush(stdin);
	if((errorNumb>(no-1)) || (errorNumb<=0)){
		printf("		Wrong Entry, TryAgain: ");
		goto lableVA1;
	}else{
		no= 1;
		viewData= fopen("transported.bin", "rb");
		while(fread(&view, sizeof(view), 1, viewData)==1){
			if(errorNumb!= no){
				fwrite(&view, sizeof(view), 1, temp);
			}else{
				system("cls");
				printf("\n\n		Making Error in Transfer\n\n");
				printf("		%d.", no);
				for(i=0; i<10; i++){
					if(view.numb_arr[i]!=-1){
						printf(" %d", view.numb_arr[i]);
					}else{
						break;
					}
					bitNumb++;
				}
				printf("		C %d", view.checksum_val);
				printf("\n\n		Enter the Position for error: ");
lableVA2:
				scanf("%d", &bit);
				fflush(stdin);
				if((bit>(bitNumb-1)) || (bit<=0)){
					printf("		Wrong entry, TryAgain: ");
					goto lableVA2;
				}else{
					printf("\n		Change [%d] to: ", view.numb_arr[bit-1]);
					scanf("%d", &view.numb_arr[bit-1]);
				}
				fwrite(&view, sizeof(view), 1, temp);
			}
			no++;
		}
		fclose(temp);
		fclose(viewData);
		remove("transported.bin");
		rename("temp", "transported.bin");
	}
	printf("\n\n		Error is Done, Hit any key to continue.........");
	getch();
	main_menu();	
	
}

//supporting functions
void delay(int sec){
	int milisec= 1000 * sec;
	clock_t start_time= clock();
	while(clock()< (start_time + milisec));
	
}

