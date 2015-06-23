/*
 * FileManager.h *
 *Created: Jan-April 2015
 *@Author: James Child
 * Does some file stuff
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <string>
using namespace std;

class FileManager{
private:

public:
	FileManager();
	~FileManager(void);
	void remove_file(string filename);
	int read_echo_result(string addr);
	void write_file(string name, string ip, string type);
	int count_lines(string filename);
	void delete_save_file();
};



#endif /* FILEMANAGER_H_ */
