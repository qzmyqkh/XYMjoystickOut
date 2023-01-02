/*
 * 2023.1.1
 * 用于自制双joystick的输出原始值和作为按键输出
 * https://github.com/qzmyqkh/XYMjoystickOut
 */
 
#include <XYMjoystickOut.h>

XYMjoystickOut st1(27, 26, 25); // 实例化joystick摇杆对象1，定义x轴、y轴、中间按键引脚
XYMjoystickOut st2(2, 15, 13);  // 实例化joystick摇杆对象2，定义x轴、y轴、中间按键引脚

void setup()
{
  Serial.begin(115200); // 串口输出波特率设置
  st1.setDCpin(14, 12); // 设置st1作为摇杆模块供电的引脚
  st2.setDCpin(0, 4);   // 设置st2作为摇杆模块供电的引脚
  st1.setxyTH(700);     // 设置st1摇杆作为方向按键使用的触发偏离阈值
  st2.setxyTH(1800);    // 设置st2摇杆作为方向按键使用的触发偏离阈值
  Serial.print("<==手柄初始化完成==>\n请两个摇杆同时向上推使设备启用\nwaiting...\n");
  while (!st1.upbtn || !st2.upbtn)
  {
    st1.data_update(); // 获取st1摇杆的实时状态
    st2.data_update(); // 获取st2摇杆的实时状态
  }
  Serial.print("设备启用...\n");
}
void loop()
{
  st1.data_update(); // 获取st1摇杆的实时状态
  st2.data_update(); // 获取st2摇杆的实时状态

  /*输出st1摇杆的x、y、中键原始值*/
  Serial.print("st1.x轴: ");
  Serial.print(st1.xval);
  Serial.print("\tst1.y轴: ");
  Serial.print(st1.yval);
  Serial.print("\tst1.中键: ");
  Serial.println(st1.mval);

  /*输出st1摇杆作为方向键的实时状态*/
  // if (st1.upbtn)
  //   Serial.println("st1.upbtn");
  // if (st1.dwbtn)
  //   Serial.println("st1.dwbtn");
  // if (st1.lfbtn)
  //   Serial.println("st1.lfbtn");
  // if (st1.rgbtn)
  //   Serial.println("st1.rgbtn");
  // if (st1.mbtn)
  //   Serial.println("st1.mbtn");

  /*输出st1摇杆作为按键使用的按下情况*/
  // if (st1.upbtn_press)
  //   Serial.println("st1.upbtn_press");
  // if (st1.dwbtn_press)
  //   Serial.println("st1.dwbtn_press");
  // if (st1.lfbtn_press)
  //   Serial.println("st1.lfbtn_press");
  // if (st1.rgbtn_press)
  //   Serial.println("st1.rgbtn_press");
  // if (st1.mbtn_press)
  //   Serial.println("st1.mbtn_press");

  /*输出st1摇杆作为按键使用的释放情况*/
  // if (st1.upbtn_release)
  //   Serial.println("st1.upbtn_release");
  // if (st1.dwbtn_release)
  //   Serial.println("st1.dwbtn_release");
  // if (st1.lfbtn_release)
  //   Serial.println("st1.lfbtn_release");
  // if (st1.rgbtn_release)
  //   Serial.println("st1.rgbtn_release");
  // if (st1.mbtn_release)
  //   Serial.println("st1.mbtn_release");
}
