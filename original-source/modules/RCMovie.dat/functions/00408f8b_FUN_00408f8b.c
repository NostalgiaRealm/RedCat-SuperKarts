/*
 * FUN_00408f8b at 00408f8b
 * undefined4 __thiscall FUN_00408f8b(void * this, undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 00408f8b-00409009
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00408f8b(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x34))
                        (DAT_0043d408,*param_1,param_1[1],param_1[2],*param_2,param_2[1],param_2[2],
                         0,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430ae4);
  }
  return 0;
}

