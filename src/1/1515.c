#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc_division(int num) {
  	int temp = num;
  	int factor = 10;
  	while (1) {
		if (temp / factor < 1) {
	  		break;
		} 
		else {
	  		factor *= 10;
		}
	}
	return (factor / 10);
}

int main() {
	char line[3001];
	int index = 0, line_len, num = 1, division, temp;
	
	scanf("%s", line);
	line_len = strlen(line);
	
	while (index < line_len) {
		temp = num;
		division = calc_division(temp);
		for (; division >= 1; division /= 10) {
		  	if (temp / division == line[index] - 48) {
				index++;
				if (index == line_len) {
					break;
				}	
		  	}
			temp %= division;
		}
		num++;
  	}

  	printf("%d", num - 1);
}