//Author: Sotiris Sotiriou

#include <stdio.h>
#include <dirent.h>
#include <errno.h>

int main(){
	//Check if chocolatey is installed
	DIR* chocodir = opendir("C:\\ProgramData\\chocolatey");
	DIR* exifdir = opendir("C:\\ProgramData\\chocolatey\\lib\\exiftool");
	
	if(chocodir){
		//Chocolatey is installed	
	}
	else if(ENOENT == errno){
		printf("Chocolatey is not installed in your computer\n");
		printf("Installing chocolatey...\n");
		system("powershell -command \"mkdir \'C:\\ProgramData\\chocolatey\'\"");
		system("powershell -command \"cd C:\\ProgramData\\chocolatey\"");
		system("powershell -command \"cd C:\\ProgramData\\chocolatey Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))\"");
		printf("Chocolatey intalled successfully\n");
	}
	else{
		//opendir() failed
	}
	
	//Exiftool installer
	
	//check if exiftool is already installed
	if(exifdir){
		//remove exiftool
		printf("Exiftool already installed\n");
		printf("Reinstalling...");
		system("powershell -command \"rmdir C:\\ProgramData\\chocolatey\\lib\\exiftool\"");
		
	}
	
	system("powershell -command \"choco install exiftool -y\"");
	
	
	system("pause");
	return 0;
}
