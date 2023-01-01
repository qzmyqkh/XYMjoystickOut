#ifndef XYMjoystickOut_h
#define XYMjoystickOut_h

#include <Arduino.h>

class XYMjoystickOut
{
private:
  int m_xpin, m_ypin, m_mpin;
  int xyTH; //  摇杆作为上下左右方向按键，偏离判断阈值（threshold）

public:
  int xval, yval, mval, xcenter, ycenter;
  bool upbtn, dwbtn, lfbtn, rgbtn, mbtn;
  bool upbtn_press, dwbtn_press, lfbtn_press, rgbtn_press, mbtn_press;
  bool upbtn_release, dwbtn_release, lfbtn_release, rgbtn_release, mbtn_release;
  bool last_upbtn, last_dwbtn, last_lfbtn, last_rgbtn, last_mbtn;

  XYMjoystickOut(int x, int y, int m) // 构造函数，初始化各输入引脚
  {
    m_xpin = x;
    m_ypin = y;
    m_mpin = m;
    pinMode(m_mpin, INPUT_PULLUP); // 如果按钮没有上拉电阻，则需设置为上拉输出模式。按钮未按下时为高电平，按下为低电平。
  }

  void setxyTH(int th)
  {
    xcenter = analogRead(m_xpin);
    ycenter = analogRead(m_ypin);
    xyTH = th;
  }

  void setDCpin(int vcc, int gnd)
  {
    pinMode(vcc, OUTPUT);
    pinMode(gnd, OUTPUT);
    digitalWrite(vcc, HIGH);
    digitalWrite(gnd, LOW);
  }

  // 获取摇杆的x y数值和按键是否按下
  void get_xym_val()
  {
    xval = analogRead(m_xpin);
    yval = analogRead(m_ypin);
    mval = digitalRead(m_mpin);
  }

  void get_xym_state()
  {
    get_xym_val();
    if (xval > xcenter + xyTH)
    {
      upbtn = true;
    }
    else
    {
      upbtn = false;
    }
    if (xval < xcenter - xyTH)
    {
      dwbtn = true;
    }
    else
    {
      dwbtn = false;
    }
    if (yval < ycenter - xyTH)
    {
      rgbtn = true;
    }
    else
    {
      rgbtn = false;
    }
    if (yval > ycenter + xyTH)
    {
      lfbtn = true;
    }
    else
    {
      lfbtn = false;
    }
    if (mval)
    {
      mbtn = false;
    }
    else
    {
      mbtn = true;
    }
  }

  void get_xym_press_release()
  {
    get_xym_state();
    if (upbtn && upbtn != last_upbtn)
    {
      upbtn_press = true;
    }
    else
    {
      upbtn_press = false;
    }
    if (dwbtn && dwbtn != last_dwbtn)
    {
      dwbtn_press = true;
    }
    else
    {
      dwbtn_press = false;
    }
    if (lfbtn && lfbtn != last_lfbtn)
    {
      lfbtn_press = true;
    }
    else
    {
      lfbtn_press = false;
    }
    if (rgbtn && rgbtn != last_rgbtn)
    {
      rgbtn_press = true;
    }
    else
    {
      rgbtn_press = false;
    }
    if (mbtn && mbtn != last_mbtn)
    {
      mbtn_press = true;
    }
    else
    {
      mbtn_press = false;
    }

    if (!upbtn && upbtn != last_upbtn)
    {
      upbtn_release = true;
    }
    else
    {
      upbtn_release = false;
    }
    if (!dwbtn && dwbtn != last_dwbtn)
    {
      dwbtn_release = true;
    }
    else
    {
      dwbtn_release = false;
    }
    if (!lfbtn && lfbtn != last_lfbtn)
    {
      lfbtn_release = true;
    }
    else
    {
      lfbtn_release = false;
    }
    if (!rgbtn && rgbtn != last_rgbtn)
    {
      rgbtn_release = true;
    }
    else
    {
      rgbtn_release = false;
    }
    if (!mbtn && mbtn != last_mbtn)
    {
      mbtn_release = true;
    }
    else
    {
      mbtn_release = false;
    }
    last_upbtn = upbtn;
    last_dwbtn = dwbtn;
    last_lfbtn = lfbtn;
    last_rgbtn = rgbtn;
    last_mbtn = mbtn;
  }
};

#endif
