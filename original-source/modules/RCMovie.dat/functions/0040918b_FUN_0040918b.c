/*
 * FUN_0040918b at 0040918b
 * undefined4 __thiscall FUN_0040918b(void * this, float param_1)
 * Address ranges: 0040918b-00409213
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040918b(void *this,float param_1)

{
  int iVar1;
  
  if (DAT_0043d43c != 0) {
    if (param_1 < 0.0) {
      param_1 = 0.0;
    }
    if (10.0 < param_1) {
      param_1 = 10.0;
    }
    iVar1 = (**(code **)(*DAT_0043d408 + 0x3c))(DAT_0043d408,param_1,0,this);
    if (iVar1 != 0) {
      FUN_00405af0(iVar1);
      FUN_0040187a((byte *)s__s__d____error_set_listener_orie_00430bc4);
    }
  }
  return 0;
}

