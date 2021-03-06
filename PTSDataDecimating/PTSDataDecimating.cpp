#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "引数は3つ指定してください [target] [skips] [output]" << std::endl;
		return -1;
	}

	std::ifstream ifs(argv[1]);

	if (ifs.fail())
	{
		std::cerr << "ファイル \"" << argv[1] << "\" の読み取りに失敗しました。ファイルを確認してください" << std::endl;
		return -1;
	}

	std::ofstream ofs(argv[3]);

	if (ofs.fail())
	{
		std::cerr << "ファイル \"" << argv[1] << "\" が開けません。ファイルを確認してください" << std::endl;
		return -1;
	}

	int skips = std::stoi(argv[2]);

	std::string sLineLen;
	std::getline(ifs, sLineLen);
	int lineLen = std::stoi(sLineLen);

	ofs << (int)ceil((float)lineLen / (float)skips) << std::endl;

	std::string str;
	int lineCount = 0;
	while (std::getline(ifs, str)) {
		if (lineCount % skips == 0) {
			ofs << str << std::endl;
		}
		lineCount++;
	}

	return 0;
}

