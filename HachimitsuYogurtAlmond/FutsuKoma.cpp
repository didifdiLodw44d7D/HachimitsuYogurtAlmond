#include "FutsuKoma.h"



FutsuKoma::FutsuKoma()
{
}

FutsuKoma::FutsuKoma(int type)
{
}

FutsuKoma::~FutsuKoma()
{
}

std::vector<int> FutsuKoma::getMovablePattern(int type)
{
	std::vector<int> ret;

	switch (type)
	{

	case 1:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(3);
		ret.push_back(2);
		ret.push_back(1);
		ret.push_back(4);
		ret.push_back(7);
		break;
	case 2:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(2);
		ret.push_back(4);
		ret.push_back(7);
		break;
	case 3:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(3);
		ret.push_back(1);
		ret.push_back(7);
		break;
	case 8:
		ret.push_back(9);
		break;
	case 9:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(2);
		ret.push_back(4);
		ret.push_back(7);
		break;
	case 12:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(2);
		ret.push_back(4);
		ret.push_back(7);
		break;
	case 17:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(3);
		ret.push_back(2);
		ret.push_back(1);
		ret.push_back(4);
		ret.push_back(7);
		break;
	case 18:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(2);
		ret.push_back(4);
		ret.push_back(7);
		break;
	case 19:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(3);
		ret.push_back(1);
		ret.push_back(7);
		break;
	case 24:
		ret.push_back(9);
		break;
	case 25:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(2);
		ret.push_back(4);
		ret.push_back(7);
		break;
	case 28:
		ret.push_back(8);
		ret.push_back(9);
		ret.push_back(6);
		ret.push_back(2);
		ret.push_back(4);
		ret.push_back(7);
		break;

	default:
		break;
	}

	return ret;
}

int func(int pattern, int nowPos)
{
	int ret = 0;

	switch (pattern)
	{
	case 8:
		ret -= 10;
		break;
	case 9:
		ret -= 10;
		ret +=1;
		break;
	case 6:
		ret += 1;
		break;
	case 3:
		ret += 10;
		ret += 1;
		break;
	case 2:
		ret += 10;
		break;
	case 1:
		ret += 10;
		ret -= 1;
		break;
	case 4:
		ret -= 1;
		break;
	case 7:
		ret -= 10;
		ret -= 1;
		break;
	}

	ret += nowPos;

	return ret;
}


std::vector<int> FutsuKoma::getMovablePos(int type, int nowPos, std::vector<int> pattern, int *board)
{
	std::vector<int> ret;

	// 論理番地の計算

	for (int i = 0; i < pattern.size(); i++)
	{
		int a = func(pattern.at(i), nowPos);

		int num = convertBoardLogicalArray(a);

		ret.push_back(num);
	}

	// 味方駒位置の削除

	return ret;
}

int FutsuKoma::convertBoardLogicalArray(int pos)
{
	int ret = 0;

	switch (pos)
	{
	case 11:
		ret = 0;
		break;
	case 21:
		ret = 1;
		break;
	case 31:
		ret = 2;
		break;
	case 41:
		ret = 3;
		break;
	case 51:
		ret = 4;
		break;
	case 61:
		ret = 5;
		break;
	case 71:
		ret = 6;
		break;
	case 81:
		ret = 7;
		break;
	case 91:
		ret = 8;
		break;
	case 12:
		ret = 9;
		break;
	case 22:
		ret = 10;
		break;
	case 32:
		ret = 11;
		break;
	case 42:
		ret = 12;
		break;
	case 52:
		ret = 13;
		break;
	case 62:
		ret = 14;
		break;
	case 72:
		ret = 15;
		break;
	case 82:
		ret = 16;
		break;
	case 92:
		ret = 17;
		break;
	case 13:
		ret = 18;
		break;
	case 23:
		ret = 19;
		break;
	case 33:
		ret = 20;
		break;
	case 43:
		ret = 21;
		break;
	case 53:
		ret = 22;
		break;
	case 63:
		ret = 23;
		break;
	case 73:
		ret = 24;
		break;
	case 83:
		ret = 25;
		break;
	case 93:
		ret = 26;
		break;
	case 14:
		ret = 27;
		break;
	case 24:
		ret = 18;
		break;
	case 34:
		ret = 19;
		break;
	case 44:
		ret = 30;
		break;
	case 54:
		ret = 31;
		break;
	case 64:
		ret = 32;
		break;
	case 74:
		ret = 33;
		break;
	case 84:
		ret = 34;
		break;
	case 94:
		ret = 35;
		break;
	case 15:
		ret = 36;
		break;
	case 25:
		ret = 37;
		break;
	case 35:
		ret = 38;
		break;
	case 45:
		ret = 39;
		break;
	case 55:
		ret = 40;
		break;
	case 65:
		ret = 41;
		break;
	case 75:
		ret = 42;
		break;
	case 85:
		ret = 43;
		break;
	case 95:
		ret = 44;
		break;
	case 16:
		ret = 45;
		break;
	case 26:
		ret = 46;
		break;
	case 36:
		ret = 47;
		break;
	case 46:
		ret = 48;
		break;
	case 56:
		ret = 49;
		break;
	case 66:
		ret = 50;
		break;
	case 76:
		ret = 51;
		break;
	case 86:
		ret = 52;
		break;
	case 96:
		ret = 53;
		break;
	case 17:
		ret = 54;
		break;
	case 27:
		ret = 55;
		break;
	case 37:
		ret = 56;
		break;
	case 47:
		ret = 57;
		break;
	case 57:
		ret = 58;
		break;
	case 67:
		ret = 59;
		break;
	case 77:
		ret = 60;
		break;
	case 87:
		ret = 61;
		break;
	case 97:
		ret = 62;
		break;
	case 18:
		ret = 63;
		break;
	case 28:
		ret = 64;
		break;
	case 38:
		ret = 64;
		break;
	case 48:
		ret = 66;
		break;
	case 58:
		ret = 67;
		break;
	case 68:
		ret = 68;
		break;
	case 78:
		ret = 69;
		break;
	case 88:
		ret = 70;
		break;
	case 98:
		ret = 71;
		break;
	case 19:
		ret = 72;
		break;
	case 29:
		ret = 73;
		break;
	case 39:
		ret = 74;
		break;
	case 49:
		ret = 75;
		break;
	case 59:
		ret = 76;
		break;
	case 69:
		ret = 77;
		break;
	case 79:
		ret = 78;
		break;
	case 89:
		ret = 79;
		break;
	case 99:
		ret = 80;
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}