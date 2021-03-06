#include <stdio.h>
#include "time.h"

void initTime(Time *time) {
	time -> hour = 0;
	time -> minute = 0;
	time -> second = 0;

	return;
}

void setTime(Time *time, int hour, int minute, int second) {
	time -> hour = hour;
	time -> minute = minute;
	time -> second = second;

	return;
}

void addTime(Time *time, int hour, int minute, int second) {
	time -> second += second;
	time -> minute += (minute + time -> second / 60);
	time -> hour += (hour + time -> minute / 60);

	time -> second %= 60;
	time -> minute %= 60;
	time -> hour %= 24;

	return;
}

void printTime(Time *time) {
	#ifdef H24
		printf("%02d:%02d:%02d\n", time -> hour, time -> minute, time -> second);
	#else
		if (time -> hour > 0 && time -> hour < 12)
			printf("%02dam:%02d:%02d\n", time -> hour, time -> minute, time -> second);
		else if (time -> hour == 12)
			printf("%02dpm:%02d:%02d\n", 12, time -> minute, time -> second);
		else if (time -> hour > 12 && time -> hour < 24)
			printf("%02dpm:%02d:%02d\n", time -> hour - 12, time -> minute, time -> second);
		else
			printf("%02dam:%02d:%02d\n", 12, time -> minute, time -> second);
	#endif

	return;
}