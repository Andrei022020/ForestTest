#include <iostream>
#include <map>
#include <string>
#include <ostream>

using namespace std;

	string NewNameAnimal()
	{

		string Name;
		cout << "������� ���" << endl;
		cin >> Name;
		cout << "��������� ���- ���������." << endl;
		return Name;

	}

	//*************************** ������� ������ ��� ���� ����� ��������	****************
	class Wolf :public Animal
	{
	public:
		Wolf()
		{
			cout << "� ����� ���� ��������� ����. �� �������� ��� ��������� ��������!" << endl;
		}

		void eat() override
		{
			cout << "���� ���� ����� ���� ";
		}

		~Wolf() override
		{
			cout << "����" << "" << Name << "" << "����� ������- " << warehouse << " (��)";
		}
	};

	class Bear :public Animal
	{
	public:
		Bear()
		{
			cout << "� ����� ���� ��������� �������. �� �������� ��� ��������� �����!" << endl;
		}
		void eat() override
		{
			cout << "������� �������� ��� ";
		}
		~Bear() override
		{
			cout << "�������" << "" << Name << "" << "����� ����- " << warehouse << " (���.)";
		}
	};

	class Squirrel :public Animal
	{
	public:
		Squirrel()
		{
			cout << "� ����� ���� ���������� �����. �� �������� ��� ��������� ��������!" << endl;
		}
		void eat() override
		{
			cout << "����� �������� �� ���� ���� ";
		}
		~Squirrel() override
		{
			cout << "�����" << "" << Name << "" << "����� �������- " << warehouse << " (��.)";
		}
	};

	Animal* AddNewAnimal()
	{
		int TypeAnimal;
		do
		{
			cout << "�������� ��������:\n1 - ����\n2 - �������\n3 - �����\n0 - ����� � �������� ����" << endl;
			cin >> TypeAnimal;
			switch (TypeAnimal)
			{
			case(1):
				//cout << "� ����� ���� ��������� ����\n";
				return (new Wolf);

				break;
			case(2):
				//cout << "� ����� ���� ��������� �������";
				return (new Bear);
				break;
			case(3):
				//cout << "� ����� ���� ���������� �����";
				return (new Squirrel);
				break;
			case(0):

				break;
			default:
				cout << "������ �����. ��������, ����������, ���������� �����.";
				break;
			}
		} while (TypeAnimal < 0 || TypeAnimal>3);

		/*bool UniqueName;
		string NewName;
		do
		{
			cout << "������� ��� ���������";

			for (int i = 0; i < 4; i++)
			{
				UniqueName = true;
				cin >> NewName;
				if (NewName == arrAnimal[i]->Name)
				{
					cout << "����� ��� ��� ����. ���������� ������ ���." << endl;
					UniqueName = false;
					break;
				}
			}

		} while (UniqueName == true);
		arrAnimal[i]->Name = NewName*/


	}

	void FeedAnimal()
	{
		cout << "�������� ��� ���� ���. ������ ��������� ��� ��� ����� � �������� ����." << endl;
	}

	void SelectAnimal()
	{

		cout << "������� ��� ���������, ������� �� ������ �������" << endl;

	}

	//*****************************************������� ������ ����**********************************
	void MainMenu()
	{
		cout << "1 - add new animal\n" << "2 - select animal\n" << "0 - close\n";

	}

	void SecondMenu()
	{
		cout << "1 - ������� ����� ���\n" << "0 - ����� � �������� ����\n";

	}
	//*****************************************���������� ���������*********************************


	int main()
	{

		setlocale(LC_ALL, "rus");

		int start;
		Animal* arrAnimal[5];
		int i = 0;
		int j = 0;
		bool UniqueName;
		string NewName;
		string Name;
		bool FindName;
		int SecondMenuItem;

		do
		{
			MainMenu();

			cin >> start;


			switch (start)
			{
			case(1):
			{
				arrAnimal[i] = AddNewAnimal();

				if (start > 0 || start < 4)
				{
					do
					{
						cout << "������� ��� ���������";
						cin >> NewName;
						UniqueName = true;
						for (int j = 0; j < (i + 1); j++)
						{

							if (arrAnimal[j]->Name == NewName)
							{
								cout << "����� ��� ��� ����. ���������� ������ ���." << endl;
								UniqueName = false;
								break;
							}

						}
						if (UniqueName)
						{
							arrAnimal[i]->Name = NewName;
							i++;
						}

					} while (!UniqueName);

					break;
				}
				else
				{
					break;
				}

			}

			case(2):
			{
				SelectAnimal();

				do
				{
					do
					{
						cin >> Name;
						FindName = true;
						for (int j = 0; j < i; j++)
						{

							if (arrAnimal[j]->Name == Name)
							{
								cout << "��������" << arrAnimal[j]->TypeAnimal << arrAnimal[j]->Name << " ����� ������" << endl;
								FindName = true;
								break;
							}

						}
						if (!FindName)
						{
							cout << "� ���� ��� ��������� � ����� ������! ���������� ������ ��� ���" << endl;;
						}

					} while (!FindName);

					SecondMenu();
					cin >> SecondMenuItem;
					switch (SecondMenuItem)
					{
					case(1):
						(arrAnimal[j]->warehouse)++;
						arrAnimal[j]->eat();
						break;

					case(0):
						break;

					default:
						cout << "��������� ����. ��������, ����������, ���������� �����" << endl;
						break;
					}
				} while (SecondMenuItem != 0);
				break;
			}

			case(0):
			{
				break;
			}

			default:
				cout << "��������� ����. ��������, ����������, ���������� �����" << endl;
				break;
			}

		} while (start != 0);

		for (int i = 0; i < 5; i++)
		{
			delete[] arrAnimal[i];

		}
		delete[] arrAnimal[i];
		return 0;
	}

	/*int SecondMenuItem;
	do
	{
		SecondMenu();
		cin >> SecondMenuItem;
			switch (SecondMenuItem)
			{
					case(1):
					FeedAnimal();
					break;

					case(0):
					main ();
					break;

					default:
					cout << "��������� ����. ��������, ����������, ���������� �����" << endl;
					break;

			}
	} while (SecondMenuItem!=0);*/
