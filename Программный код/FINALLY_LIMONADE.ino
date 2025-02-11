

#include <Stepper.h> 

boolean buttonWasUp = true; //для кнопки

Stepper up_dvig(21, 0, 1, 2, 3);
Stepper down_dvig(374, 4, 5, 6, 7);

// можно ли написать еще один степпер с теми же пинами, которые выше???

const int IK1 = 21;
const int IK2 = 20;
const int IK3 = 19;
const int IK4 = 18;
const int water = 8;
const int syrup = 9;
const int juice = 10;
const int recipe_1 = 11;
const int recipe_2 = 12;
const int recipe_3 = 13;
const int recipe_4 = 14;
const int recipe_5 = 15;
const int recipe_6 = 16;
const int start = 17;

const int maxValues = 4;
int button_order[maxValues];
int index = 0;
int len_this_order;

char a = 'a';
char b = 'b';
char c = 'c';
char d = 'd';
char e = 'e';
char f = 'f';

int flag = 0;


void stop_work1() {
  if (flag == 0) {
    while (digitalRead(21) == LOW) {
    }
  }
}

void stop_work2() {
  if (flag == 0) {
    while (digitalRead(20) == LOW) {
    }
  }
}

void stop_work3() {
  if (flag == 0) {
    while (digitalRead(19) == LOW) {
    }
  }
}

void stop_work4() {
  if (flag == 0) {
    while (digitalRead(18) == LOW) {
    }
  }
}


void RECIPE_1() { //алгоритм для разливки первого рецепта

  digitalWrite(water, HIGH);
  delay(4166);
  digitalWrite(water, LOW);
}

void RECIPE_2() { //алгоритм для разливки второго рецепта

  digitalWrite(syrup, HIGH);
  delay(833);
  digitalWrite(syrup, LOW);
}

void RECIPE_3() { //алгоритм для разливки третьего рецепта

  digitalWrite(juice, HIGH);
  delay(3333);
  digitalWrite(juice, LOW);
}

void RECIPE_4() { //алгоритм для разливки четвертого рецепта

  digitalWrite(water, HIGH);
  delay(6666);
  digitalWrite(water, LOW);

  digitalWrite(syrup, HIGH);
  delay(1666);
  digitalWrite(syrup, LOW);
}

void RECIPE_5() { //алгоритм для разливки пятого рецепта

  digitalWrite(water, HIGH);
  delay(6666);
  digitalWrite(water, LOW);

  digitalWrite(syrup, HIGH);
  delay(1666);
  digitalWrite(syrup, LOW);
}

void RECIPE_6() { //алгоритм для разливки шестого рецепта

  digitalWrite(water, HIGH);
  delay(2916);
  digitalWrite(water, LOW);

  digitalWrite(juice, HIGH);
  delay(3750);
  digitalWrite(juice, LOW);

  digitalWrite(syrup, HIGH);
  delay(833);
  digitalWrite(syrup, LOW);
}

void setup() {

attachInterrupt(21, stop_work1 , CHANGE);
attachInterrupt(20, stop_work2 , CHANGE);
attachInterrupt(19, stop_work3 , CHANGE);
attachInterrupt(18, stop_work4 , CHANGE);

up_dvig.setSpeed(30);
down_dvig.setSpeed(30);

  Serial.begin(9600);

  pinMode(IK1, INPUT);  //ИК первый = 21

  pinMode(IK2, INPUT);  //ИК второй = 20
  
  pinMode(IK3, INPUT);  //ИК третий = 19

  pinMode(IK4, INPUT);  //ИК четвертый = 18

  pinMode(water, OUTPUT); //транзистор замыкает насос и соленоид (бутылка с водой)

  pinMode(syrup, OUTPUT); //транзистор замыкает насос и соленоид (бутылка с сиропом)

  pinMode(juice, OUTPUT); //транзистор замыкает насос и соленоид (бутылка с соком)

  pinMode(recipe_1, INPUT_PULLUP); //кнопка 1-го рецепта

  pinMode(recipe_2, INPUT_PULLUP); //кнопка 2-го рецепта

  pinMode(recipe_3, INPUT_PULLUP); //кнопка 3-го рецепта

  pinMode(recipe_4, INPUT_PULLUP); //кнопка 4-го рецепта

  pinMode(recipe_5, INPUT_PULLUP); //кнопка 5-го рецепта

  pinMode(recipe_6, INPUT_PULLUP); //кнопка 6-го рецепта

}

void loop() {

  if (digitalRead(recipe_1) == HIGH) { //если кнопка(рецепт) нажата, записываем ее в очередь
    if (index < maxValues) {
      button_order[index] = 'a';
      index++;
     }
     delay(100); // Задержка для предотвращения многократного срабатывания
   }

  if (digitalRead(recipe_2) == HIGH) {
    if (index < maxValues) {
      button_order[index] = 'b';
      index++;
     }
     delay(100); // Задержка для предотвращения многократного срабатывания
   }
  if (digitalRead(recipe_3) == HIGH) {
    if (index < maxValues) {
      button_order[index] = 'c';
      index++;
     }
     delay(100); // Задержка для предотвращения многократного срабатывания
   }

    // Проверяем второй датчик
  if (digitalRead(recipe_4) == HIGH) {
    if (index < maxValues) {
      button_order[index] = 'd';
      index++;
     }
     delay(100); // Задержка для предотвращения многократного срабатывания
   }

  if (digitalRead(recipe_5) == HIGH) {
    if (index < maxValues) {
      button_order[index] = 'e';
      index++;
     }
     delay(100); // Задержка для предотвращения многократного срабатывания
   }

  if (digitalRead(recipe_6) == HIGH) {
    if (index < maxValues) {
      button_order[index] = 'f';
      index++;
     }
     delay(100); // Задержка для предотвращения многократного срабатывания
   }

   len_this_order = index;

  boolean buttonIsUp = digitalRead(17);

if (buttonWasUp && !buttonIsUp) {
  delay(10);
  buttonIsUp = digitalRead(17);
    if (!buttonIsUp) {

    if (len_this_order = 1) {
      for (int i = 0; i < len_this_order; i++) {
      if (button_order[i] = a) {
        RECIPE_1();
        delay(1000);
      }
      else if (button_order[i] = b) {
        RECIPE_2();
        delay(1000);
      }
      else if (button_order[i] = c) {
        RECIPE_3();
        delay(1000);
      }
      else if (button_order[i] = d) {
        RECIPE_4();
        delay(1000);
      }
      else if (button_order[i] = e) {
        RECIPE_5();
        delay(1000);
      }
      else if (button_order[i] = f) {
        RECIPE_6();
        delay(1000);
      }
      if (i = 1) {
        up_dvig.step(21);
      }
      if (i = 2) {
        up_dvig.step(21);
      }
      if (i = 3) {
        up_dvig.step(21);
      }
      if ((i + 1) == len_this_order) {
        up_dvig.step(-21 * i);
        delay(1000);
        flag ++;
        down_dvig.step(374);
        delay(7000);
        for (int j = 0; j < len_this_order; j++) {
          if (j = 1) {
            down_dvig.step(86);
          }
          if (j = 2) {
            down_dvig.step(86);
          }
          if (j = 3) {
            down_dvig.step(86);
          }
          if ((j + 1) == len_this_order) {
            down_dvig.step(-86 * j);
          }
        }
      }
      flag = 0;
    }
    }

    if (len_this_order = 2) {
      for (int i = 0; i < len_this_order; i++) {
      if (button_order[i] = a) {
        RECIPE_1();
        delay(1000);
      }
      else if (button_order[i] = b) {
        RECIPE_2();
        delay(1000);
     }
       else if (button_order[i] = c) {
        RECIPE_3();
        delay(1000);
      }
      else if (button_order[i] = d) {
        RECIPE_4();
        delay(1000);
      }
      else if (button_order[i] = e) {
        RECIPE_5();
        delay(1000);
      }
      else if (button_order[i] = f) {
        RECIPE_6();
        delay(1000);
      }
      if (i = 1) {
        up_dvig.step(21);
      }
      if (i = 2) {
        up_dvig.step(21);
      }
      if (i = 3) {
        up_dvig.step(21);
      }
      if ((i + 1) == len_this_order) {
        up_dvig.step(-21 * i);
        delay(1000);
        flag ++;
        down_dvig.step(374);
        delay(7000);
        for (int j = 0; j < len_this_order; j++) {
          if (j = 1) {
            down_dvig.step(86);
          }
          if (j = 2) {
            down_dvig.step(86);
          }
          if (j = 3) {
            down_dvig.step(86);
          }
          if ((j + 1) == len_this_order) {
            down_dvig.step(-86 * j);
          }
        }
      }
      flag = 0;
    }
    }

    if (len_this_order = 3) {
      for (int i = 0; i < len_this_order; i++) {
      if (button_order[i] = a) {
        RECIPE_1();
        delay(1000);
      }
      else if (button_order[i] = b) {
        RECIPE_2();
        delay(1000);
     }
       else if (button_order[i] = c) {
        RECIPE_3();
        delay(1000);
      }
      else if (button_order[i] = d) {
        RECIPE_4();
        delay(1000);
      }
      else if (button_order[i] = e) {
        RECIPE_5();
        delay(1000);
      }
      else if (button_order[i] = f) {
        RECIPE_6();
        delay(1000);
      }
      if (i = 1) {
        up_dvig.step(21);
      }
      if (i = 2) {
        up_dvig.step(21);
      }
      if (i = 3) {
        up_dvig.step(21);
      }
      if ((i + 1) == len_this_order) {
        up_dvig.step(-21 * i);
        delay(1000);
        flag ++;
        down_dvig.step(374);
        delay(7000);
        for (int j = 0; j < len_this_order; j++) {
          if (j = 1) {
            down_dvig.step(86);
          }
          if (j = 2) {
            down_dvig.step(86);
          }
          if (j = 3) {
            down_dvig.step(86);
          }
          if ((j + 1) == len_this_order) {
            down_dvig.step(-86 * j);
          }
        }
      }
      flag = 0;
    }
    }

    if (len_this_order = 4) {
      for (int i = 0; i < len_this_order; i++) {
      if (button_order[i] = a) {
        RECIPE_1();
        delay(1000);
      }
      else if (button_order[i] = b) {
        RECIPE_2();
        delay(1000);
     }
       else if (button_order[i] = c) {
        RECIPE_3();
        delay(1000);
      }
      else if (button_order[i] = d) {
        RECIPE_4();
        delay(1000);
      }
      else if (button_order[i] = e) {
        RECIPE_5();
        delay(1000);
      }
      else if (button_order[i] = f) {
        RECIPE_6();
        delay(1000);
      }
      if (i = 1) {
        up_dvig.step(21);
      }
      if (i = 2) {
        up_dvig.step(21);
      }
      if (i = 3) {
        up_dvig.step(21);
      }
      if ((i + 1) == len_this_order) {
        up_dvig.step(-21 * i);
        delay(1000);
        flag ++;
        down_dvig.step(374);
        delay(7000);
        for (int j = 0; j < len_this_order; j++) {
          if (j = 1) {
            down_dvig.step(86);
          }
          if (j = 2) {
            down_dvig.step(86);
          }
          if (j = 3) {
            down_dvig.step(86);
          }
          if ((j + 1) == len_this_order) {
            down_dvig.step(-86 * j);
          }
        }
      }
      flag = 0;
    }
    }
}
}
}
