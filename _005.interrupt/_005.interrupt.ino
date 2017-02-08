/* Pin13 控制板载 LED L */
const int ledPin = 13;

/* 对于 Arduino Leonardo 板子 int.0 对应的引脚是 Pin3 */
const int buttonPin = 3;

/* 使用 volatile 关键字是防止捕捉到的状态被 C 语言代码优化机制优化 */
volatile int state = LOW;

void setup()
{
  pinMode(ledPin, OUTPUT);

  /* 按键输入引脚需要上拉，不然不稳定 */
  pinMode(buttonPin, INPUT_PULLUP);

  /* 指定 int.0 的中断处理函数为 int0() ，并设置为下降沿出发中断 */
  attachInterrupt(0, int0, FALLING);
}
 
void loop()
{
  digitalWrite(ledPin, state);
}

/* 每按一次按键，便产生一个下降沿，触发一次中断 */
void int0()
{
  state = !state;
}
