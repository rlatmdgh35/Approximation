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

		cout << "�� ���� ���� �ִ��� �Է����ּ���." << endl;
		cin >> teamNum;

		system("cls");

		for (int i = 1; i <= teamNum; i++)
		{
			int preNum = 0;

			cout << i << "��° ���� ���� ���� �־��ּ���." << endl;
			cin >> preNum;
			
			teamWriteValue.push_back(preNum);
		}

		system("cls");

		cout << "������ ���� �Է����ּ���." << endl;
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

		cout << "���� �信 ������ ���� ";
		if (victoryTeamIndex.size() == 1)
			cout << teamWriteValue[victoryTeamIndex[0] - 1] << "��(��) ���� " << victoryTeamIndex[0] << "��° ���Դϴ�!!" << endl;
		else
		{
			cout << endl;
			for (int i = 0; i < victoryTeamIndex.size(); i++)
			{
				cout << teamWriteValue[victoryTeamIndex[i] - 1] << "��(��) ���� " << victoryTeamIndex[i];
				if (i == victoryTeamIndex.size() - 1) break;
				cout << "��° ����" << endl;
			}
			cout << "��° ���Դϴ�!!" << endl << endl;
		}


		cout << "���� �Ͻðڽ��ϱ�?" << endl;
		cout << "�� : 1, �ƴϿ� : 0" << endl;
		cin >> Loop;

		while (Loop != 0 && Loop != 1)
		{
			system("cls");
			cout << "�߸� �Է��ϼ̽��ϴ�. " << endl << endl;
			cout << "���� �Ͻðڽ��ϱ�?" << endl;
			cout << "1 : ��, 0 : �ƴϿ�" << endl;
			cin >> Loop;
		}

		Loop ? bLoop = true : bLoop = false;
	}

	system("pause");
	return 0;
}