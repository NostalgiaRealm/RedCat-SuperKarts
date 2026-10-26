/*
 * FUN_0040b8a3 at 0040b8a3
 * undefined1 __thiscall FUN_0040b8a3(void * this, int param_1)
 * Address ranges: 0040b8a3-0040b917
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 __thiscall FUN_0040b8a3(void *this,int param_1)

{
  int iVar1;
  
  if (DAT_0043d6cc == 0) {
    FUN_0040187a((byte *)s__s__d____error_keyboard_device_w_00431aec);
  }
  iVar1 = (**(code **)(*DAT_0043d6c0 + 0x24))(DAT_0043d6c0,0x100,&DAT_0043d5c0,this);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_keyboard_d_00431b2c);
  }
  return (&DAT_0043d5c0)[param_1];
}

