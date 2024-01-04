/*CODE FOR 4*4 KEYPAD
Every button consists of pushbutton in it's backside.The rows are considered as defaulty high and columns are considered as low.For eg when we press 1 
the row and column of 1 get shorted.Whenever we press 1 it move row from high to low and the arduino will detect that 1 had been pressed.In 8 pins of 
keypad first 4 pins are for rows and 2nd 4 pins are for columns.*/
#include<Keypad.h>
const char no_of_rows=4;
const char no_of_col=4;
const char row_pins[no_of_rows]={2,3,4,5};
const char col_pins[no_of_col]={6,7,8,9};
//since the keypad is 2*2 matrix 
char key_array[no_of_rows][no_of_col]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
/*Inorder to map the rowspins and column_pins to the key position in the Key_array we are using keypad functionwhich takes 5 arguments 
k->object of keypad */
Keypad k=Keypad(makeKeymap(key_array),row_pins,col_pins,no_of_rows,no_of_col) ;

void setup() {
       Serial.begin(9600);
   
}

void loop() {
  char c=k.getKey();
  if(c)
  Serial.print(c);

}
