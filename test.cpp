#include <stdio.h>
#include <string>
//this is StopWattch app
//コマンドによって、Run・Stop・リセットの状態を切り替える。
//遷移条件はソースコードから読み取ってください。


using namespace std;

int ChangeMode(int *p, int order_num){//1:遷移、2:遷移なし
	if (*p == 0 && order_num == 1){
		*p = 1;
		printf("Now movements mode >>> RUN\n");
		return 1;
	}
	if (*p == 1 && order_num == 1){
		*p = 2;
		printf("Now movements mode >>> STOP\n");
		return 1;
	}
	if (*p == 2 && order_num == 1){
		*p = 1;
		printf("Now movements mode >>> RUN\n");
		return 1;
	}
	if (*p == 2 && order_num == 2){
		*p = 0;
		printf("Now movements mode >>> RESET\n");
		return 1;
	}
	printf("No Changed \n");
	return 2;
}


int InputCommand(int *p){//標準入力からコマンド（s・r・q）を入力する
	char input[100];
	int Order_num = 0;
	
	if (*p == 0){ printf("Initial movements mode >>> RESET\n"); }
	if (*p == 1){ printf("Initial movements mode >>> RUN\n"); }
	if (*p == 2){ printf("Initial movements mode >>> STOP\n"); }
	
	printf("Input command : ");
	gets(input);
	int i = 0;//文字数カウント
	for (i = 0; input[i] != '\0'; ++i);
	if (i == 1){
		if (input[0] == 'S' || input[0] == 's'){
			Order_num = 1;
			ChangeMode(p, Order_num);
			return 1;
		}
		else if (input[0] == 'R' || input[0] == 'r'){
			Order_num = 2;
			ChangeMode(p, Order_num);
			return 2;
		}
		else if (input[0] == 'Q' || input[0] == 'q'){
			return 3;
		}
		else{//規定外のコード入力によるエラー
			printf("Error : Your Input is   %s\n", input);
		}
	}
	else{ printf("Error : Your Input is   %s\n", input); }//文字数によるエラー
	return 4;
}



int main(){
	int mode_num = 0; // 0:RESETmode, 1:RUNmode, 2:STOPmode
	int Order_num = 1;// 1:S, 2:R, 3:Q
	int *p = &mode_num;//モードのポインタ
	int *q = &Order_num;//入力ののポインタ
	
	while (Order_num != 3){
		Order_num = InputCommand(p);
	}
	printf("program End \n");
	getchar();
	

	return 0;
}