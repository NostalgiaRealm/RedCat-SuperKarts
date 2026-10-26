/*
 * FUN_0040900a at 0040900a
 * undefined4 __thiscall FUN_0040900a(void * this, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6)
 * Address ranges: 0040900a-00409078
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall
FUN_0040900a(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x34))
                        (DAT_0043d408,param_1,param_2,param_3,param_4,param_5,param_6,0,this),
     iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430b1c);
  }
  return 0;
}

