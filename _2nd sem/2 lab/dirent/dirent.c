#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/types.h>
#include <dirent.h>
#include <dir.h>

char *strCopyDir(char *first, char *scnd)
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

void printDir(DIR *ddir, char *path)
{   
    struct dirent *file;
    while ((file = readdir (ddir)))       // читаем имена файлов/папок и выводим
    printf("%s\n", file->d_name);
}

void removeFiles(DIR *ddir, char *path)
{
    DIR *folder;
    char *fpath;
    struct dirent *file;

    rewinddir(ddir);
    while ((file = readdir (ddir)))     
    {
        printf("%s\n", file->d_name);
        fpath = strCopyDir(path, file->d_name);
        if((folder = opendir(fpath)) == NULL)
            remove(fpath);
        else
            closedir(folder);
    }
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

    while ((file = readdir (ddir)))     
    {
        printf("%s\n", file->d_name);
        fpath = strCopyDir(path, file->d_name);
        if((folder = opendir(fpath)) == NULL)
        {
            newfpath = strCopyDir(newpath, file->d_name);
            rename(fpath, newfpath);
        }
        else
            closedir(folder);
    }
}

void removeFolders(DIR *ddir, char *path)
{
    DIR *folder;
    char *fpath;
    struct dirent *file;

    rewinddir(ddir);
    while ((file = readdir (ddir)))     
    {
        printf("%s\n", file->d_name);
        fpath = strCopyDir(path, file->d_name);
        if((folder = opendir(fpath)) != NULL)
        {
            closedir(folder);
            printf("remove folder  ");
            rmdir(fpath);
        }
    }
}

int main()
{
    DIR *ddir;
    printf("Enter directory path:\n");
    char *path;
    path = getStr();
    //printf("%s\n", path);
    ddir = opendir (path);  // открываем директорию
        if (ddir != NULL)
        {
            printDir(ddir, path);
            removeFolders(ddir, path);
            (void) closedir (ddir);   // закрываем директорию
        }
        else
            printf("Couldn\'t open this directory\n");
    getch();
    return 0;
}

//D:/programming/folder