# -*- coding: utf-8 -*-
import config
import telebot

bot = telebot.TeleBot(config.token)


@bot.message_handler(content_types=["text"])
def repeat_all_messages(message):
    if message.text == "ауе":
        bot.send_message(message.chat.id, text='Ворам свободу')
    elif message.text == "рамси":
        bot.send_message(message.chat.id, text='По фене ботаю - нигде не работаю, по фене брякаю - ебу работу всякую. Ты чё, черт, ахуел? Мусора совсем лагерь перекрасили, и некому разморозить')
    elif message.text == "Положняк":
        bot.send_message(message.chat.id, text='Короче, гребни, здесь новый положняк: кто кальян не помоет за собой, того в жопу драть будем всей хатой! Добра, арестанты.')
    elif message.text == "сам иди":
        bot.send_message(message.chat.id, text='Окей (((')
    else:
        bot.send_message(message.chat.id, text='А шо оно мне надо')


if __name__ == '__main__':
    bot.polling(none_stop=True)
