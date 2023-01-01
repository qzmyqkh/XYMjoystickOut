#include "XYMjoystickOut.h"

XYMjoystickOut st1(27, 26, 25); // 实例化joystick摇杆对象1
XYMjoystickOut st2(2, 15, 13);  // 实例化joystick摇杆对象2

void setup()
{
  Serial.begin(115200); // 串口输出波特率设置
  st1.setDCpin(14, 12); // 设置st1作为电源的引脚
  st2.setDCpin(0, 4);   // 设置st2作为电源的引脚
  st1.setxyTH(1500);    // 设置st1摇杆作为方向按键使用的触发阈值
  st2.setxyTH(1800);    // 设置st2摇杆作为方向按键使用的触发阈值
  Serial.print("<==手柄初始化完成==>\n请同时向上推两个摇杆已启动设备\nwaiting...\n");
  while (!st1.upbtn || !st2.upbtn)
  {
    st1.get_xym_state();
    st2.get_xym_state();
  }
  Serial.print("\t设备启动\n");
}
void loop()
{
  st1.get_xym_press_release(); // 获取st1摇杆的实时状态
  st2.get_xym_press_release();//获取st2摇杆的实时状态

  /*输出st1摇杆的x、y方向的原始模拟值和中键的原始值*/
  //    Serial.print(st1.xval);
  //    Serial.print(",");
  //    Serial.print(st1.yval);
  //    Serial.print(",");
  //    Serial.print(st1.mval);
  //    Serial.print("; ");

  /*输出st1摇杆作为方向键使用的状态*/
  //    Serial.print(st1.upbtn);
  //    Serial.print(",");
  //    Serial.print(st1.dwbtn);
  //    Serial.print(",");
  //    Serial.print(st1.lfbtn);
  //    Serial.print(",");
  //    Serial.print(st1.rgbtn);
  //    Serial.print(",");
  //    Serial.print(st1.mbtn);
  //    Serial.println();

  /*输出st1摇杆作为按键使用的状态，此值为检测方向键是否按下*/
  if (st1.upbtn_press)
    Serial.println("st1.upbtn_press");
  if (st1.dwbtn_press)
    Serial.println("st1.dwbtn_press");
  if (st1.lfbtn_press)
    Serial.println("st1.lfbtn_press");
  if (st1.rgbtn_press)
    Serial.println("st1.rgbtn_press");
  if (st1.mbtn_press)
    Serial.println("st1.mbtn_press");

  /*输出st1摇杆作为按键使用的状态，此值为检测是否按下后释放*/
  if (st1.upbtn_release)
    Serial.println("st1.upbtn_release");
  if (st1.dwbtn_release)
    Serial.println("st1.dwbtn_release");
  if (st1.lfbtn_release)
    Serial.println("st1.lfbtn_release");
  if (st1.rgbtn_release)
    Serial.println("st1.rgbtn_release");
  if (st1.mbtn_release)
    Serial.println("st1.mbtn_release");

  /*输出st2摇杆作为按键使用的状态，此值为检测方向键是否按下*/
  if (st2.upbtn_press)
    Serial.println("st2.upbtn_press");
  if (st2.dwbtn_press)
    Serial.println("st2.dwbtn_press");
  if (st2.lfbtn_press)
    Serial.println("st2.lfbtn_press");
  if (st2.rgbtn_press)
    Serial.println("st2.rgbtn_press");
  if (st2.mbtn_press)
    Serial.println("st2.mbtn_press");

  /*输出st2摇杆作为按键使用的状态，此值为检测是否按下后释放*/
  if (st2.upbtn_release)
    Serial.println("st2.upbtn_release");
  if (st2.dwbtn_release)
    Serial.println("st2.dwbtn_release");
  if (st2.lfbtn_release)
    Serial.println("st2.lfbtn_release");
  if (st2.rgbtn_release)
    Serial.println("st2.rgbtn_release");
  if (st2.mbtn_release)
    Serial.println("st2.mbtn_release");

}
