 
   #include <DS3231.h>
   #include <Wire.h>
   #include "U8glib.h"
      
   DS3231 Clock;
   bool Century=false;
   bool h12;
   bool PM;
   byte ADay, AHour, AMinute, ASecond, ABits;
   bool ADy, A12h, Apm;

   byte year, month, date, DoW, hour, minute, second;
   
   U8GLIB_ST7920_128X64_1X u8g(6, 5, 4 ,7); 
   int display = 1;  
   
   void setup() 
   {  
    Wire.begin();
    Serial.begin(9600);
  
    if ( u8g.getMode() == U8G_MODE_R3G3B2 )   
    u8g.setColorIndex(255);   
    else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )  
    u8g.setColorIndex(1);     
    else if ( u8g.getMode() == U8G_MODE_BW )  
    u8g.setColorIndex(1);      
    
        /* As linhas abaixo servem para acertar o modulo DS3231
        Para acertar, retire as barras e carregue o programa
        depois recoloque as barras novamente. */

        //Clock.setSecond(30);  // Insira os Segundos 
        //Clock.setMinute(24); // Insira os Minutos 
        //Clock.setHour(17);     // Insira a Hora 
        //Clock.setDoW(4);      // Insira o Dia da da semana dom=1
        //Clock.setDate(16);  // Insira o Dia do Mês
        //Clock.setMonth(12); // Insira o Mês
        //Clock.setYear(15);    // Insira somente os dois ultimos digitos do Ano 
    }  
    
   void ReadDS3231() {
   
   int second,minute,hour,date,month,year,temperature; 
   second=Clock.getSecond();
   minute=Clock.getMinute();
   hour=Clock.getHour(h12, PM);
   date=Clock.getDate();
   month=Clock.getMonth(Century);
   year=Clock.getYear(); 
  
  if(date<10)
  { Serial.print("0"); }
  Serial.print(date,DEC);
  Serial.print(" de ");
  if(month==1)
  { Serial.print("Janeiro"); }
  if(month==2)
  { Serial.print("Fevereiro"); }
  if(month==3)
  { Serial.print("Marco"); }
  if(month==4)
  { Serial.print("Abril"); }
  if(month==5)
  { Serial.print("Maio"); }
  if(month==6)
  { Serial.print("Junho"); }
  if(month==7)
  { Serial.print("Julho"); }
  if(month==8)
  { Serial.print("Agosto"); }
  if(month==9)
  { Serial.print("Setembro"); }
  if(month==10)
  { Serial.print("Outubro"); }
  if(month==11)
  { Serial.print("Novembro"); }
  if(month==12)
  { Serial.print("Dezembro"); }
  Serial.print(" de ");
  Serial.print("20");
  Serial.print(year,DEC);
    
  Serial.print(' ');
  Serial.print('\n');
  if(hour<10)
  { Serial.print("0"); }
  Serial.print(hour,DEC);
  Serial.print(':');
  if(minute<10)
  { Serial.print("0"); }
  Serial.print(minute,DEC);
  Serial.print(':');
  if(second<10)
  { Serial.print("0"); }
  Serial.print(second,DEC);
  Serial.print('\n');
  
  if(Clock.getDoW()==1)
  { Serial.print("Dom"); }
  if(Clock.getDoW()==2)
  { Serial.print("Seg"); }
  if(Clock.getDoW()==3)
  { Serial.print("Ter"); }
  if(Clock.getDoW()==4)
  { Serial.print("Qua"); }
  if(Clock.getDoW()==5)
  { Serial.print("Qui"); }
  if(Clock.getDoW()==6)
  { Serial.print("Sex"); }
  if(Clock.getDoW()==7)
  { Serial.print("Sab"); }
  
  Serial.print('\n');
  Serial.print('\n');
   }  
  
  void u8g_Tela1()  
  {
  int second,minute,hour,date,month,year,temperature; 
  second=Clock.getSecond();
  minute=Clock.getMinute();
  hour=Clock.getHour(h12, PM);
  date=Clock.getDate();
  month=Clock.getMonth(Century);
  year=Clock.getYear(); 
  
  u8g.drawRFrame(0,0,128,64,5);
  u8g.setFont(u8g_font_fub17);
  u8g.setPrintPos(19, 20);
  if (hour < 10)
  { u8g.print("0"); }
  //u8g.setPrintPos(40, 15);
  u8g.print(hour);
  u8g.print(":");
  if (minute < 10)
  { u8g.print("0"); }
    u8g.print(minute);
  u8g.print(":");
  if (second < 10)
  { u8g.print("0"); }
  u8g.print(second);
  
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(9, 37);
  if (date < 10)
  { u8g.print("0"); }
  //u8g.setPrintPos(40, 15);
  u8g.print(date);
  u8g.setFont(u8g_font_04b_03); 
  u8g.print(" de ");
  u8g.setFont(u8g_font_unifont);
  if(month==1)
  { u8g.print("Janeiro"); }
  if(month==2)
  { u8g.print("Fevereiro"); }
  if(month==3)
  { u8g.print("Marco"); }
  if(month==4)
  { u8g.print("Abril"); }
  if(month==5)
  { u8g.print("Maio"); }
  if(month==6)
  { u8g.print("Junho"); }
  if(month==7)
  { u8g.print("Julho"); }
  if(month==8)
  { u8g.print("Agosto"); }
  if(month==9)
  { u8g.print("Setembro"); }
  if(month==10)
  { u8g.print("Outubro"); }
  if(month==11)
  { u8g.print("Novembro"); }
  if(month==12)
  { u8g.print("Dezembro"); }
  u8g.setFont(u8g_font_04b_03);
  u8g.print(" de");
   
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(10, 55); 
  u8g.print("20");
  u8g.print(year);
  u8g.print(" - ");
  if(Clock.getDoW()==1)
  { u8g.print("Domingo"); }
  if(Clock.getDoW()==2)
  { u8g.print("Segunda"); }
  if(Clock.getDoW()==3)
  { u8g.print("Terca"); }
  if(Clock.getDoW()==4)
  { u8g.print("Quarta"); }
  if(Clock.getDoW()==5)
  { u8g.print("Quinta"); }
  if(Clock.getDoW()==6)
  { u8g.print("Sexta"); }
  if(Clock.getDoW()==7)
  { u8g.print("Sabado"); }
  }  
    
  void loop() 
  {   
  ReadDS3231();
  u8g.firstPage();   
  do 
  u8g_Tela1(); 
  while( u8g.nextPage() );  
  }     
