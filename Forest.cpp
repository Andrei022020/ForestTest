#include <iostream>
#include <map>
#include <string>
#include <ostream>

using namespace std;

	string NewNameAnimal()
	{

		string Name;
		cout << "Введите имя" << endl;
		cin >> Name;
		cout << "Выбранное имя- уникально." << endl;
		return Name;

	}

	//*************************** СОЗДАЛА КЛАССЫ ДЛЯ ВСЕХ ТИПОВ ЖИВОТНЫХ	****************
	class Wolf :public Animal
	{
	public:
		Wolf()
		{
			cout << "В вашем лесу поселился волк. Не забудьте его покормить колбасой!" << endl;
		}

		void eat() override
		{
			cout << "Волк жует кусок мяса ";
		}

		~Wolf() override
		{
			cout << "Волк" << "" << Name << "" << "запас кобасы- " << warehouse << " (шт)";
		}
	};

	class Bear :public Animal
	{
	public:
		Bear()
		{
			cout << "В вашем лесу поселился медведь. Не забудьте его покормить медом!" << endl;
		}
		void eat() override
		{
			cout << "Медведь уплетает мед ";
		}
		~Bear() override
		{
			cout << "Медведь" << "" << Name << "" << "запас меда- " << warehouse << " (бан.)";
		}
	};

	class Squirrel :public Animal
	{
	public:
		Squirrel()
		{
			cout << "В вашем лесу поселилась белка. Не забудьте его покормить орешками!" << endl;
		}
		void eat() override
		{
			cout << "Белка засунула за щеку орех ";
		}
		~Squirrel() override
		{
			cout << "Белка" << "" << Name << "" << "запас орешков- " << warehouse << " (шт.)";
		}
	};

	Animal* AddNewAnimal()
	{
		int TypeAnimal;
		do
		{
			cout << "Выберите животное:\n1 - волк\n2 - медведь\n3 - белка\n0 - выход в основное меню" << endl;
			cin >> TypeAnimal;
			switch (TypeAnimal)
			{
			case(1):
				//cout << "В вашем лесу поселился волк\n";
				return (new Wolf);

				break;
			case(2):
				//cout << "В вашем лесу поселился медведь";
				return (new Bear);
				break;
			case(3):
				//cout << "В вашем лесу поселилась белка";
				return (new Squirrel);
				break;
			case(0):

				break;
			default:
				cout << "Ошибка ввода. Сделайте, пожалуйста, правильный выбор.";
				break;
			}
		} while (TypeAnimal < 0 || TypeAnimal>3);

		/*bool UniqueName;
		string NewName;
		do
		{
			cout << "Укажите имя животного";

			for (int i = 0; i < 4; i++)
			{
				UniqueName = true;
				cin >> NewName;
				if (NewName == arrAnimal[i]->Name)
				{
					cout << "Такое имя уже есть. Придумайте другое имя." << endl;
					UniqueName = false;
					break;
				}
			}

		} while (UniqueName == true);
		arrAnimal[i]->Name = NewName*/


	}

	void FeedAnimal()
	{
		cout << "Животное ест вашу еду. Можете покормить еще или выйти в основное меню." << endl;
	}

	void SelectAnimal()
	{

		cout << "Введите имя животного, которое вы хотите выбрать" << endl;

	}

	//*****************************************ФУНКЦИЯ ПЕРВОЕ МЕНЮ**********************************
	void MainMenu()
	{
		cout << "1 - add new animal\n" << "2 - select animal\n" << "0 - close\n";

	}

	void SecondMenu()
	{
		cout << "1 - сделать запас еды\n" << "0 - выйти в основное меню\n";

	}
	//*****************************************РЕАЛИЗАЦИЯ ПРОГРАММЫ*********************************


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
						cout << "Укажите имя животного";
						cin >> NewName;
						UniqueName = true;
						for (int j = 0; j < (i + 1); j++)
						{

							if (arrAnimal[j]->Name == NewName)
							{
								cout << "Такое имя уже есть. Придумайте другое имя." << endl;
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
								cout << "Возможно" << arrAnimal[j]->TypeAnimal << arrAnimal[j]->Name << " хочет кушать" << endl;
								FindName = true;
								break;
							}

						}
						if (!FindName)
						{
							cout << "В лесу нет животного с таким именем! Попробуйте ввести еще раз" << endl;;
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
						cout << "Ошибочный ввод. Сделайте, пожалуйста, правильный выбор" << endl;
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
				cout << "Ошибочный ввод. Сделайте, пожалуйста, правильный выбор" << endl;
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
					cout << "Ошибочный ввод. Сделайте, пожалуйста, правильный выбор" << endl;
					break;

			}
	} while (SecondMenuItem!=0);*/
