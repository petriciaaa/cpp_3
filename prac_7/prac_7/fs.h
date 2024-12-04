#include <fstream>
using namespace std;


class FileStream
{
private:
	ofstream writer;
	ifstream reader;
public:
	FileStream(const char* filteToRead, const char* filteToWrite)
	{
		reader.open(filteToRead);
		writer.open(filteToWrite);
	}
	void read(const char* filteToRead)
	{
		reader.close();
		reader.open(filteToRead);
	}
	void rewrite()
	{
		writer << reader.rdbuf();
	}
};