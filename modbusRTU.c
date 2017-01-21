/****Linux下modbusRTU测试程序****/

#include<stdio.h>
#include<stdlib.h>
#include"modbus.h"

int main(void)
{
  modbus_t *mb;
  uint16_t tab_reg[32]={0};
  mb = modbus_new_rtu("/dev/ttySAC2",19200,'N',8,1);//open port
  modbus_set_slave(mb,1);//set slave address

  modbus_connect(mb);

  struct timeval t;
  t.tv_sec=0;
  t.tv_usec=1000000;//set modbus time 1000ms
  //modbus_set_response_timeout(mb,&t);
  modbus_set_response_timeout(mb,t.tv_sec, t.tv_usec);

  int regs=modbus_read_registers(mb, 0, 20, tab_reg); 

  printf("%d %d %d %d %d\n",regs,tab_reg[0],tab_reg[1],tab_reg[2],tab_reg[3]);
  modbus_close(mb);  
  modbus_free(mb);
  return 0;
}
