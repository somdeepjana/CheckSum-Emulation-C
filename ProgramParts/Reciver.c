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

void data_check();


void main(){
	SetConsoleTitle("Reciver");
	system("COLOR 0B");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 1180, 0, 700, 200, TRUE);
	FILE *checkFile;
LableM0:
	system("cls");
	printf("\n\n	Press any key to check wheather Transporter transfers anything......");
	getch();
	if((checkFile= fopen("reciver.bin", "rb"))== NULL){
		goto LableM0;
	}else{
		fclose(checkFile);
		rename("reciver.bin", "recived.bin");
		data_check();
	}	
	
}

void data_check(){
	system("cls");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 700, 240, 800, 300, TRUE);
	printf("\n\n					Recived Data\n\n");
	FILE *checkData;
	int no=1, checksum=0, i;
	struct send_data check_data;
	if((checkData= fopen("recived.bin", "rb"))== NULL){
		printf("\n\n		recived.bin can not be open");
		getch();
		exit(0);
	}
	while(fread(&check_data, sizeof(check_data), 1, checkData)==1){
		printf("	%d.", no);
		for(i=0; i<10; i++){
			if(check_data.numb_arr[i]!=-1){
				checksum+= check_data.numb_arr[i];
				printf(" %d", check_data.numb_arr[i]);
			}else{
				break;
			}
		}
		if(checksum == check_data.checksum_val){
			printf(" 			No Error	");
		}else{
			printf(" 			Error		");
		}
		printf("%d[recived] %d[calculated]", check_data.checksum_val, checksum);
		printf("\n");
		checksum= 0;
		no++;
	}
	printf("\n	Hit any key to move forward.......");
	getch();
	fclose(checkData);
	remove("recived.bin");
	main();
	
}

//supporting functions
void delay(int sec){
	int milisec= 1000 * sec;
	clock_t start_time= clock();
	while(clock()< (start_time + milisec));
	
}
