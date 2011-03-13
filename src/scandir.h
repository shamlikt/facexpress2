using namespace std;
typedef vector<string> filelists;

#ifndef WIN32
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

//search for s2 in s1
static int match(const char* s1, const char* s2)
{
	int diff = strlen(s1) - strlen(s2);
	if(diff >= 0 && !strcasecmp(s1+diff, s2))
		return 1;
	return 0;
}

#endif

// compare function for the qsort() call below
static int str_compare(const void *arg1, const void *arg2)
{
    return strcmp((*(string*)arg1).c_str(), (*(string*)arg2).c_str());
}

// Scan all files with the "extension" under "path" directory and sort them
static filelists ScanNSortDirectory(const char*path, const char*extension)
{
#ifdef WIN32
    WIN32_FIND_DATA wfd;
    HANDLE handle;
    string search_path, search_file;
#else
	struct dirent *d;
	DIR* dir;
	struct stat s;
	char fullpath[1024];
#endif
    filelists allfiles;
	int n = 0;

#ifdef  WIN32   
	search_path = string(path) + "/*" + string(extension);
	handle = FindFirstFile(search_path.c_str(), &wfd);
	if (INVALID_HANDLE_VALUE == handle)
    {
		return allfiles;
    }
    do
    {
        if (wfd.cFileName[0] == '.')
        {
            continue;
        }
        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
	    }
        else
        {
			search_file = string(path) + "/" + string(wfd.cFileName);
			allfiles.push_back(search_file);
			n++;
		}
    }while (FindNextFile(handle, &wfd));

    FindClose(handle);
#else
	
	dir = opendir(path);
	if(dir == NULL)	
	{
		return allfiles;
	}

	while(d = readdir(dir))
	{
		sprintf(fullpath, "%s/%s", path, d->d_name);
		if(stat(fullpath, &s) != -1)
		{
			if(S_ISDIR(s.st_mode))
				continue;
			if(match(d->d_name, extension))
			{
				allfiles.push_back(string(fullpath));
				n++;
			}
		}

	}
	closedir(dir);
#endif

	// sort the filenames
    qsort((void *)&(allfiles[0]), (size_t)n, sizeof(string), str_compare);

    return allfiles;
}

// Scan all subdirectories  under "path" directory and sort them
static filelists directoriesOf(const char*path)
{
#ifdef WIN32
    WIN32_FIND_DATA wfd;
    HANDLE handle;
    string search_path, search_file;
#else
	struct dirent *d;
	DIR* dir;
	struct stat s;
	char fullpath[1024];
#endif
    filelists allfiles;
	int n = 0;

#ifdef  WIN32   
	search_path = string(path) + "/*";
	handle = FindFirstFile(search_path.c_str(), &wfd);
	if (INVALID_HANDLE_VALUE == handle)
    {
		return allfiles;
    }
    do
    {
        if (wfd.cFileName[0] == '.')
        {
            continue;
        }
		if (wfd.cFileName[0] == '..')
        {
            continue;
        }
        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            search_file = string(wfd.cFileName);
			allfiles.push_back(search_file);
			n++;
	    }
        else
        {
			continue;
		}
    }while (FindNextFile(handle, &wfd));

    FindClose(handle);
#else
	
	dir = opendir(path);
	if(dir == NULL)	
	{
		return allfiles;
	}

	while(d = readdir(dir))
	{
		sprintf(fullpath, "%s/%s", path, d->d_name);
		if(stat(fullpath, &s) == -1 && d->d_name!="." && d->d_name!="..")
		{
			allfiles.push_back(string(fullpath));
			n++;
		}

	}
	closedir(dir);
#endif

	// sort the filenames
    qsort((void *)&(allfiles[0]), (size_t)n, sizeof(string), str_compare);

    return allfiles;
}