#include <stdio.h>
#include <stdint.h>
#include <math.h>

//void task6_6() {
//	uint8_t mas[] = { 0,1,2,3,4,5,6,7,8 };
//	int i = 0;
//
//	/*for (; i < sizeof(mas) / sizeof(mas[0]); i++) {
//		unsigned tmp = mas[i];
//		printf("%d %x\n", (tmp & (tmp - 1))==0, (tmp & (tmp - 1))==0);
//	}*/
//	
//	/*for (; i < sizeof(mas) / sizeof(mas[0]); i++) {
//		unsigned tmp = mas[i];
//		printf("%d %x\n", (tmp & (-tmp)) == 0, (tmp & (-tmp)) == 0);
//	}*/
//
//	i = 0;
//	uint8_t r = 1;
//
//	for (; i < (1<<sizeof(uint8_t)<<8); i++) {
//		unsigned tmp = i;
//		/*printf("%d %x\n", (tmp & (tmp - 1)) == 0, (tmp & (tmp - 1)) == 0);*/
//		uint8_t y = (tmp & (tmp - 1)) == 0;
//		
//		if (r == tmp) {
//			printf("power of 2");
//			r *= 2;
//
//			if (y == 1) {
//				printf(" and y too\n");
//			}
//			else {
//				printf(" wrong ");
//			}
//		}
//		else {
//			if (y == 1) {
//				printf("hypotese is wrong ");
//			}
//		}
//		
//	}
//
//	for (; i < (1 << sizeof(uint8_t) << 8); i++) {
//		unsigned tmp = i;
//		/*printf("%d %x\n", (tmp & (tmp - 1)) == 0, (tmp & (tmp - 1)) == 0);*/
//		uint8_t y = (tmp & (-tmp));
//
//		int k = 1;
//		int j = 0;
//		
//		while (tmp % k == 0) {
//			k << 1; 
//			j++;
//		}
//		if (y != (1 << j)) {
//			printf("we are wrong! for %d", i);
//		}
//
//	}
//}

int main() {
	/*task6_6();*/
}