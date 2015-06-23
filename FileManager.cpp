/*
 * FileManager.cpp
 * Created: Jan-April 2015
 *@Author: James Child
 * Does some file stuff
 */
#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"

using namespace std;

FileManager::FileManager(){
}/*constructor*/
FileManager::~FileManager(void){
	this;
}/*destructor*/

/*
 * reads the ping result
 */
int FileManager::read_echo_result(string addr){
	int result = 1;
	string filename = addr + ".txt";
	string temp;
	string buffer;
	try{
		ifstream input(filename);
		while (getline(input, buffer)){
			if(buffer.find("100% packet loss")!= string::npos){
				result = 0;
			}
		}
		input.close();
	}catch(ifstream::failure e){
			//cout << "\nFile Read Error";
	}
	//remove((addr+".txt").c_str());
	cout.flush();
	//po->notify_echo_result(result, addr);
	return result;
}

void FileManager::remove_file(string filename){
	remove((filename+".txt").c_str());
}/*deletes a file*/

void FileManager::write_file(string name, string ip, string type) {
  ofstream save_file;
  save_file.open ("nrds.csv",ios::app);
  save_file << name << "," << ip << ","<< type <<"\n";
  save_file.close();
}/*creates a file called nrds.csv and then writes to it*/

int FileManager::count_lines(string filename){
	unsigned int num_of_lines = 0;
	string file_line;
	try{
		ifstream load_file(filename);
		while (getline(load_file, file_line)){
			++num_of_lines;
		}
	}catch(ifstream::failure e){
		cout << "\nFile Read Error";
	}
	return num_of_lines;
}/*counts lines in a file*/

void FileManager::delete_save_file(){
	remove("nrds.csv");
}/*deletes the save file*/
