
#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <exception>
#include <ctime>
#include <iconv.h>
#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;




int32_t time_quantity(int32_t start_time, int32_t now_time)
{
	return now_time - start_time;
}

bool sigintGot = false;
int32_t start_time;

int main() {
	signal(SIGINT, [](int s) {
		printf("SIGINT got");
		sigintGot = true;
	});

	Bot bot("299044462:AAEQ_MEs-cvgCDJHb45fhwIAPItohlQvdS0");

		bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
		bot.getApi().sendMessage(message->chat->id, "Фарта, масти, АУЕ!");
	});



	start_time =  time(NULL);
	


	bot.getEvents().onAnyMessage(
		[&bot](Message::Ptr message) 
	{
		if ( time_quantity(start_time, message->date) > 1 )
		{
			if (StringTools::endsWith(message->text, "off"))
				{exit(1);}	
			
						
			printf("User wrote %s\n", message->text.c_str() );
			bot.getApi().sendMessage(message->chat->id, "Свали отсюда блять " + message->text);
		}
	});





	try {
		printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());

		TgLongPoll longPoll(bot);
		while (!sigintGot) {
			printf("Long poll started\n");
			longPoll.start();
		}
	} catch (exception& e) {
		printf("error: %s\n", e.what());
	}

	return 0;

}



