/*
 * FUN_00408d0d at 00408d0d
 * undefined4 __thiscall FUN_00408d0d(void * this, undefined4 * param_1)
 * Address ranges: 00408d0d-00408d77
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00408d0d(void *this,undefined4 *param_1)

{
  int iVar1;
  
  if ((DAT_0043d43c != 0) &&
     (iVar1 = (**(code **)(*DAT_0043d408 + 0x38))
                        (DAT_0043d408,*param_1,param_1[1],param_1[2],0,this), iVar1 != 0)) {
    FUN_00405af0(iVar1);
    FUN_0040187a((byte *)s__s__d____error_set_listener_posi_004309ac);
  }
  return 0;
}

