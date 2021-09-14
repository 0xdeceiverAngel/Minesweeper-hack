#include<iostream>
#include<windows.h>
#include <iomanip>
using namespace std;
int main(){
	
	DWORD pid=0;
	HANDLE hProcess=0;
	
	HWND hwnd = FindWindow(NULL,"Minesweeper");
	GetWindowThreadProcessId(hwnd,&pid);
	hProcess= OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
	
	
	
	cout<<hwnd<<endl<<hProcess;
	
	
	
	DWORD mine_addr=0x01005360,size=768;
	PBYTE pbyte=(PBYTE)malloc(mine_addr);
	
	ReadProcessMemory(hProcess,(LPVOID)mine_addr,pbyte,size,0);
	
	DWORD info=0x1005330,h=0,w=0;
	ReadProcessMemory(hProcess,(LPVOID)info,&w,sizeof(DWORD),0);
	ReadProcessMemory(hProcess,(LPVOID)info,&h,sizeof(DWORD),0);
	w++;
	
	cout<<h<<" "<<w<<endl;
	int k=0;
	int t=0;
	PBYTE ptmp=(PBYTE)malloc(h*w);
	for(int i=0;i<768;i++){
		if(i%32==0){
			for(int q=0;q<w;q++)
			{
//				cout<<hex<<(int)pbyte[i+q]<<" ";
				ptmp[t]=pbyte[i+q];
				t++;
			}
//		cout<<endl;
		k++;
		if(k==h-1){
		break;} 
		
		} 
		
		}
//		cout<<hex<<setw(2)<<setfill('0')<<(int)pbyte[i]<<" ";
	
	cout<<oct<<endl;
	
	int x=0,y=0,x1=0,y1=0;
	
	for(int i=0;i<h*w;i++)
	{
		 
		if(ptmp[i]!=0x8F){
			
			x1=i%(w);
			y1=i/(w);
			x=x1*16;
			y=y1*16+61;
//			cout<<(int)pbyte[i]<<" "<<x1<<" "<<y1<<" "<<x<<" "<<y<<" "<<endl; 
			SendMessage(hwnd,WM_LBUTTONDOWN,MK_LBUTTON,MAKELONG(x,y));
			SendMessage(hwnd,WM_LBUTTONUP,MK_LBUTTON,MAKELONG(x,y));
		}
	}




//	cout<<endl;
//	for(int i=0;i<768;i++){
//		if(i%32==0){
//		cout<<endl;} 
//		
////		cout<<hex<<setw(2)<<setfill('0')<<(int)pbyte[i]<<" ";
//		cout<<hex<<(int)pbyte[i]<<" ";
//	}
	
	
}


