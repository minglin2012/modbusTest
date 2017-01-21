#include <stdio.h>
#include <modbus/modbus.h>
void doRtuQuery()
{    
modbus_t *mb;  
    uint16_t tab_reg[32]={0};  
  
    mb = modbus_new_rtu("COM1", 9600, 'N', 8, 1);   //相同的端口只能同时打开一个  
    modbus_set_slave(mb, 1);  //设置modbus从机地址  
  
    modbus_connect(mb);  
  
    struct timeval t;  
    t.tv_sec=0;  
    t.tv_usec=1000000;   //设置modbus超时时间为1000毫秒  
    //modbus_set_response_timeout(mb, &t);  
    modbus_set_response_timeout(mb, t.tv_sec, t.tv_usec);  
  
    int regs=modbus_read_registers(mb, 0, 20, tab_reg);  
  
    modbus_close(mb);  
    modbus_free(mb);  
}

void doTcpQuery()  
{  
    modbus_t *mb;  
    uint16_t tab_reg[32]={0};  
  
    mb = modbus_new_tcp("127.0.0.1", 5101);  //由于是tcp client连接，在同一个程序中相同的端口可以连接多次。  
    modbus_set_slave(mb, 1);  //从机地址  
  
    modbus_connect(mb);  
  
    struct timeval t;  
    t.tv_sec=0;  
    t.tv_usec=1000000;   //设置modbus超时时间为1000毫秒，注意：经测试，如果没有成功建立tcp连接，则该设置无效。  
    modbus_set_response_timeout(mb, t.tv_sec, t.tv_usec);  
  
    int regs=modbus_read_registers(mb, 0, 20, tab_reg);  
  
    modbus_close(mb);  
    modbus_free(mb);  
}  

int main()
{
    doRtuQuery();
}
