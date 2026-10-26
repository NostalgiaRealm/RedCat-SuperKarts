/*
 * FUN_00408e3c at 00408e3c
 * undefined4 __thiscall FUN_00408e3c(void * this, undefined4 param_1)
 * Address ranges: 00408e3c-00408e94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00408e3c(void *this,undefined4 param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x24))(DAT_0043d408,param_1,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_velocity___00430a48);
  }
  return 0;
}

