#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/types.h>
#include <dirent.h>
#include <dir.h>

char *strCopyDir(char *first, char *scnd)		//склеиваем две строки и добавляем '/'
{
    int size1 = strLen(first);
    int size2 = strLen(scnd);
    char *str = (char*)malloc(size1 + size2 + 2);
    for(int i = 0; i < size1; i++)
        str[i] = first[i];
	str[size1] = '/';
	for(int i = size1 + 1; i <= size1 + size2; i++)
		str[i] = scnd[i - size1 - 1];
    str[size1 + size2 + 1] = '\0';
	return str;
}

void printDir(DIR *ddir)
{   
	printf("There are in this directory:\n");
    struct dirent *file;
    while ((file = readdir (ddir)))       // читаем имена файлов/папок и выводим
    printf("%s\n", file->d_name);
	printf("\n");
}

void removeFiles(DIR *ddir, char *path)
{
    DIR *folder;
    char *fpath;
    struct dirent *file;
	printf("Deletion...\n");
    rewinddir(ddir);
    while ((file = readdir (ddir)))     
    {
        fpath = strCopyDir(path, file->d_name);
        if((folder = opendir(fpath)) == NULL)			//проверяем папка или нет, если не открывается как папка, то это файл
		{
			printf("%s\n", file->d_name);
            remove(fpath);
		}
        else
            closedir(folder);
    }
	printf("...Check the directory in explorer!\n");
}

void moveDir(DIR *ddir, char *path)
{
    DIR *folder;
    char *fpath;
    struct dirent *file;
    char *newpath;
    char *newfpath;

    rewinddir(ddir);
    printf("Enter new directory path:\n");
    newpath = getStr();
	printf("Moving files...\n");
    while ((file = readdir (ddir)))     
    {
        fpath = strCopyDir(path, file->d_name);
        if((folder = opendir(fpath)) == NULL)				//проверяем папка или нет, если не открывается как папка, то это файл
        {
			printf("%s\n", file->d_name);
            newfpath = strCopyDir(newpath, file->d_name);	//новый путь к файлу
            rename(fpath, newfpath);						//переименовываем файл на то же имя, но с другим путем
        }
        else
            closedir(folder);
    }
	printf("...Check the directory in explorer!\n");
}

void removeFolders(DIR *ddir, char *path)
{
    DIR *folder;
    char *fpath;
    struct dirent *file;
	printf("Deletion...\n");
    rewinddir(ddir);
    while ((file = readdir (ddir)))     
    {
        fpath = strCopyDir(path, file->d_name);
        if((folder = opendir(fpath)) != NULL)			//проверяем папка или нет, если не открывается как папка, то это файл
        {
			printf("%s\n", file->d_name);
            closedir(folder);
            rmdir(fpath);
        }
    }
	printf("...Check the directory in explorer!\n");
}

void (*functions[])(DIR *ddir, char *path) = {removeFiles, moveDir, removeFolders};

int main()
{
    DIR *ddir;
    char *path;	
	int task = 0;
	do
	{
		system("chcp 1251");
		system("CLS");
		printf("Given the path. Presumably to a folder.\n\
Find all files and folders inside. Further optional:\n\
1 - delete all files; 2 - move all files to the root (given path);\n\
3 - delete empty folders. No system/powershell etc...(to exit enter -1): ");
		
		task = inputInt();
		if(task == -1)
			exit(0);

		printf("Enter directory path:\n");
    	path = getStr();
			
		ddir = opendir (path);  						// открываем директорию
		if (ddir != NULL)
    	{
			printDir(ddir);
    		(*functions[task-1])(ddir,path);
			closedir (ddir);   							// закрываем директорию
			getch();
        }
		else
        	printf("Unable to open this directory\n");
	}
	while(task != -1);
    getch();
    return 0;
}

//D:/programming/folder