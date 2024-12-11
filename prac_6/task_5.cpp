#include <iostream>
#include <windows.h>

using namespace std;


class Computer{
	public:
		Computer() {};
		void build() {
			cout << "Начинаем собираться" << endl;
			motherboard.init();
			powerUnit.connect();
			cout << "Компьютер собран ( хоть и не из всех комплектующих )" << endl;
		}	
			
		void start() {
			cout << "Запуск компьютера"<<endl;
		}

	private:
		class Motherboard {
			public:
				void init() {
					cout << "Подключаем комплектующие к материнской плате" << endl;
					processor.setup();
					ram.setup();
					videoCard.setup();
					cout << "Всё подключено к материнской плате" << endl;

				}

			private:
				class CPU {
					public:
						void setup() {
							cout << "Процессор установлен." << endl;
						}
					private:

				};	
			class RAM {
					public:
						void setup() {
							cout << "Оперативная память установлена." << endl;
						}
					private:

			};
			class VideoСard
			{
			public:
				void setup() {
					cout << "Видеокарта установлена." << endl;
				}

			private:

			};
				CPU processor;
				RAM ram;
				VideoСard videoCard;

		};		
		class PowerUnit
		{
			public:
				void connect() {
					cout << "Подключаем комплектующие к блоку питания." << endl;
				}

			private:

		};

	
		Motherboard motherboard;
		PowerUnit powerUnit;
		
};


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Computer pc;

	pc.build();
	pc.start();

	return 0;
}