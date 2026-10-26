/*
 * FUN_0040b7e0 at 0040b7e0
 * undefined __thiscall FUN_0040b7e0(void * this, uint param_1)
 * Address ranges: 0040b7e0-0040b8a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0040b7e0(void *this,uint param_1)

{
  int iVar1;
  
  if (DAT_0043d6c8 == 0) {
    FUN_0040187a((byte *)s__s__d____error_input_devices_hav_00431a20);
  }
  if ((param_1 & 2) != 0) {
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x40))(DAT_0043d6c0,DAT_0043842c,0,this);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____error_running_keyboard_c_00431a68);
    }
  }
  if ((param_1 & 1) != 0) {
    iVar1 = (**(code **)(*DAT_0043d5b8 + 0x40))(DAT_0043d5b8,DAT_0043842c,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____error_running_mouse_con_00431aac);
    }
  }
  return;
}

