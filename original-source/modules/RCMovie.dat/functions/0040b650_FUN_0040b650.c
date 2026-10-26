/*
 * FUN_0040b650 at 0040b650
 * undefined4 __thiscall FUN_0040b650(void * this, undefined4 param_1, uint param_2)
 * Address ranges: 0040b650-0040b7df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040b650(void *this,undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = DirectInputCreateA(param_1,0x500,&DAT_0043d6c4,0,this);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____failed_to_create_direct_0043188c);
  }
  if ((param_2 & 1) != 0) {
    FUN_0040187a((byte *)s__s__d____not_yet_implemented_004318d0);
  }
  if ((param_2 & 2) != 0) {
    iVar1 = (**(code **)(*DAT_0043d6c4 + 0xc))(DAT_0043d6c4,&DAT_00429500,&DAT_0043d6c0,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_create_keyboa_004318fc);
    }
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x2c))(DAT_0043d6c0,&DAT_0041e410);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_data_form_0043193c);
    }
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x34))(DAT_0043d6c0,DAT_0043842c,6);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_set_coop_leve_0043198c);
    }
    iVar1 = (**(code **)(*DAT_0043d6c0 + 0x1c))(DAT_0043d6c0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____failed_to_Acquire_the_k_004319dc);
    }
    DAT_0043d6cc = 1;
  }
  DAT_0043d6c8 = 1;
  return 0;
}

