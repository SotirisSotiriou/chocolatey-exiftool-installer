//Author: Sotiris Sotiriou


int main(){
	//Chocolatey installer
	DIR* dir = opendir("C:\\ProgramData\\chocolatey");
	
	if(dir){
		//Chocolatey already installed, reinstalling
		printf("Chocolatey already installed\n");
		printf("Reinstalling...\n");
		system("powershell -command \"rmdir C:\\ProgramData\\chocolatey\"");
		system("powershell -command \"mkdir \'C:\\ProgramData\\chocolatey\'\"");
		system("powershell -command \"Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))\"");
		printf("Chocolatey intalled successfully\n");
	}
	else if(ENOENT == errno){
		//Chocolatey does not exist, installing
		system("powershell -command \"mkdir \'C:\\ProgramData\\chocolatey\'\"");
		system("powershell -command \"cd C:\\ProgramData\\chocolatey\"");
		system("powershell -command \"cd C:\\ProgramData\\chocolatey Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))\"");
		printf("Chocolatey intalled successfully\n");
	}
	else{
		//opendir() failed
	}

	
	system("pause");
	return 0;
}
