#include <curses.h>
#include "mainMenu.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "Cls.h"
int mainMenu() {
	

	

	int userChoice = 0;
	do {
		std::cout << R"(
 $$$$$$\                                                $$\   $$\           $$\ $$\       
$$  __$$\                                               $$ |  $$ |          $$ |$$ |      
$$ /  \__| $$$$$$\   $$$$$$\   $$$$$$$\  $$$$$$\        $$ |  $$ |$$\   $$\ $$ |$$ |  $$\ 
\$$$$$$\  $$  __$$\  \____$$\ $$  _____|$$  __$$\       $$$$$$$$ |$$ |  $$ |$$ |$$ | $$  |
 \____$$\ $$ /  $$ | $$$$$$$ |$$ /      $$$$$$$$ |      $$  __$$ |$$ |  $$ |$$ |$$$$$$  / 
$$\   $$ |$$ |  $$ |$$  __$$ |$$ |      $$   ____|      $$ |  $$ |$$ |  $$ |$$ |$$  _$$<  
\$$$$$$  |$$$$$$$  |\$$$$$$$ |\$$$$$$$\ \$$$$$$$\       $$ |  $$ |\$$$$$$  |$$ |$$ | \$$\ 
 \______/ $$  ____/  \_______| \_______| \_______|      \__|  \__| \______/ \__|\__|  \__|
          $$ |                                                                            
          $$ |                                                                            
          \__|                                                                                                                                                                                                                                
)" << std::endl;
		std::cout << "1.Start" << std::endl;
		std::cout << "2.Load" << std::endl;
		std::cout << "3.About" << std::endl;
		std::cout << ">";
		std::cin >> userChoice;
		if (userChoice < 1 || userChoice > 3) {
			std::cout<< "Invalid input" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cls();
			continue;
		}
		else {
			switch (userChoice) {
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			}
		}
	} while (true);
	
                                                                                                                                                 






	return(0);
}