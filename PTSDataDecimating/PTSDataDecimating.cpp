// PTSDataDecim	ating.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "引数は2つ指定してください" << std::endl;
		return -1;
	}

	std::ifstream ifs(argv[1]);

	if (ifs.fail())
	{
		std::cerr << "ファイル \"" << argv[1] << "\" の読み取りに失敗しました。ファイルを確認してください" << std::endl;
		return -1;
	}

	std::ofstream ofs("./out.pts");

	std::string lineLen;
	std::getline(ifs, lineLen);

	std::string str;

	ofs << lineLen << std::endl;

	int lineCount = 0;
	while (std::getline(ifs, str)) {
		if (lineCount % 3 == 0) {
			ofs << str << std::endl;
		}
		lineCount++;
	}

	return 0;
}

