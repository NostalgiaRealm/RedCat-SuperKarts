/*
 * FUN_00408c47 at 00408c47
 * undefined4 __thiscall FUN_00408c47(void * this, undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00408c47-00408ca9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall
FUN_00408c47(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x38))(DAT_0043d408,param_1,param_2,param_3,0,this),
     iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_posi_00430944);
  }
  return 0;
}

