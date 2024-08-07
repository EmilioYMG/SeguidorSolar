void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  unsigned int xincl_out, yincl_out, zincl_out, supply_out, temp_out;
  //  float ang_x, ang_y, ang_z, vcc, temp;
  String bufer="AT$SF=";
  String bufer2="\n";
  String str1;

  char Mybuffer[40];

  xincl_out=15;
  yincl_out=16;
  zincl_out=17;
  supply_out=18;
  temp_out=19;

  byte* a1 = (byte*) &xincl_out;
  for(int i=0;i<2;i++)
  {
    str1=String(a1[i], HEX);
    if(str1.length()<2)
    {
      bufer+=0+str1;
    }
    else
    {
      bufer+=str1;
    }
  }

  byte* a2 = (byte*) &yincl_out;
  for(int i=0;i<2;i++)
  {
    str1=String(a2[i], HEX);
    if(str1.length()<2)
    {
      bufer+=0+str1;
    }
    else
    {
      bufer+=str1;
    }
  }

  byte* a3 = (byte*) &zincl_out;
  for(int i=0;i<2;i++)
  {
    str1=String(a3[i], HEX);
    if(str1.length()<2)
    {
      bufer+=0+str1;
    }
    else
    {
      bufer+=str1;
    }
  }

  byte* a4 = (byte*) &supply_out;
  for(int i=0;i<2;i++)
  {
    str1=String(a4[i], HEX);
    if(str1.length()<2)
    {
      bufer+=0+str1;
    }
    else
    {
      bufer+=str1;
    }
  }

  byte* a5 = (byte*) &temp_out;
  for(int i=0;i<2;i++)
  {
    str1=String(a5[i], HEX);
    if(str1.length()<2)
    {
      bufer+=0+str1;
    }
    else
    {
      bufer+=str1;
    }
  }
  bufer+=bufer2;
  
  Serial.print("AT\n");
  Serial.print("AT$RC\n");
  Serial.print(bufer);
  
  while(true){}
}
