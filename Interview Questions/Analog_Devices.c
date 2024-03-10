#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t RGB565;


//Write a function to convert RBG888 to RGB565 for compression
uint16_t* rgb888_to_rgb565(uint8_t* data)
{
  // Implement your code here
  int start_bit_Red = 3, start_bit_green = 2,start_bit_blue = 3;
  
  uint8_t masked_bit_blue = (0b11111 << start_bit_blue) & data[0];
  printf("\n\rValue of Blue %u",masked_bit_blue);
  uint8_t masked_bit_green = (0b111111 << start_bit_green) & data[1];
  printf("\n\rValue of Blue %u",masked_bit_green);
  uint8_t masked_bit_red = (0b11111 << start_bit_Red) & data[2];
  printf("\n\rValue of Blue %u",masked_bit_red);
  
  // RGB565 |= (masked_bit_blue >> start_bit_blue);

  // RGB565 |= (masked_bit_green >> start_bit_green);
  
  // RGB565 |= (masked_bit_red >> start_bit_Red);
  RGB565 = ((masked_bit_red >> start_bit_Red) << 11) | ((masked_bit_green >> start_bit_green) << 5) | (masked_bit_blue >> start_bit_blue);
  printf("\n\rValue of New R %u",RGB565);
  
  return &RGB565;
}



int main() 
{
  printf ("RGB888 to RGB565\r\n");
  uint16_t* result;
  uint8_t rgb_data[] = { 0x83, 0xB4, 0xA5 };
  result = rgb888_to_rgb565(rgb_data);
  printf ("\n\rrgb565 value: 0x%x\r\n", *result);
  return 0;
}
