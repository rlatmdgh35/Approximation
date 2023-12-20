#include "stdafx.h"

bool bLoop = true;
int Loop;
int targetValue;
int teamNum;
int nearlyValue;

vector<int> teamWriteValue;
vector<int> distanceValue;
vector<int> victoryTeamIndex;


void ClearVariables()
{
	targetValue = 0;
	teamNum = 0;
	nearlyValue = 35000;

	teamWriteValue.clear();
	distanceValue.clear();
	victoryTeamIndex.clear();
}

int main()
{
	while (bLoop)
	{
		system("cls");
		ClearVariables();

		cout << "몇 개의 팀이 있는지 입력해주세요." << endl;
		cin >> teamNum;

		system("cls");

		for (int i = 1; i <= teamNum; i++)
		{
			int preNum = 0;

			cout << i << "번째 팀이 적은 값을 넣어주세요." << endl;
			cin >> preNum;
			
			teamWriteValue.push_back(preNum);
		}

		system("cls");

		cout << "물건의 값을 입력해주세요." << endl;
		cin >> targetValue;

		for (int i = 0; i < teamNum; i++)
		{
			if (teamWriteValue[i] == targetValue)
				distanceValue.push_back(0);
			else
				distanceValue.push_back(abs(teamWriteValue[i] - targetValue));
		}


		for (int i = 0; i < teamNum; i++)
		{
			if (nearlyValue > distanceValue[i])
			{
				victoryTeamIndex.clear();
				nearlyValue = distanceValue[i];
				victoryTeamIndex.push_back(i + 1);
			}
			else if (nearlyValue == distanceValue[i])
			{
				nearlyValue = distanceValue[i];
				victoryTeamIndex.push_back(i + 1);
			}
		}

		cout << "가장 답에 근접한 팀은 ";
		if (victoryTeamIndex.size() == 1)
			cout << teamWriteValue[victoryTeamIndex[0] - 1] << "을(를) 적은 " << victoryTeamIndex[0] << "번째 팀입니다!!" << endl;
		else
		{
			cout << endl;
			for (int i = 0; i < victoryTeamIndex.size(); i++)
			{
				cout << teamWriteValue[victoryTeamIndex[i] - 1] << "을(를) 적은 " << victoryTeamIndex[i];
				if (i == victoryTeamIndex.size() - 1) break;
				cout << "번째 팀과" << endl;
			}
			cout << "번째 팀입니다!!" << endl << endl;
		}


		cout << "리셋 하시겠습니까?" << endl;
		cout << "예 : 1, 아니오 : 0" << endl;
		cin >> Loop;

		while (Loop != 0 && Loop != 1)
		{
			system("cls");
			cout << "잘못 입력하셨습니다. " << endl << endl;
			cout << "리셋 하시겠습니까?" << endl;
			cout << "1 : 예, 0 : 아니오" << endl;
			cin >> Loop;
		}

		Loop ? bLoop = true : bLoop = false;
	}

	system("pause");
	return 0;
}