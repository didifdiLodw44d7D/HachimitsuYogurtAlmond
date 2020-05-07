#pragma once

#include <iostream>
#include <vector>

class FutsuKoma
{
public:
	int type;

	FutsuKoma();
	FutsuKoma(int type);
	~FutsuKoma();
	std::vector<int> getMovablePattern(int type);
	std::vector<int> getMovablePos(int type, int nowPos, std::vector<int> pattern, int *board);
	int convertBoardLogicalArray(int pos);
};

