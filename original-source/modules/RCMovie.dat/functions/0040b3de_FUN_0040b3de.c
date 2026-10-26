/*
 * FUN_0040b3de at 0040b3de
 * undefined4 __cdecl FUN_0040b3de(undefined4 param_1, UINT param_2, UINT_PTR param_3)
 * Address ranges: 0040b3de-0040b49f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040b3de(undefined4 param_1,UINT param_2,UINT_PTR param_3)

{
  int iVar1;
  UINT_PTR UVar2;
  undefined4 uVar3;
  
  if (DAT_0043d5b4 == 0) {
    FUN_0040187a((byte *)s__s__d____trying_to_reference_uni_004317f0);
  }
  iVar1 = FUN_0040b35b();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____out_of_timer_place_hold_00431840);
  }
  UVar2 = SetTimer(DAT_0043842c,param_3,param_2,(TIMERPROC)0x0);
  *(UINT_PTR *)(DAT_0043d5ac + iVar1 * 0xc) = UVar2;
  if (*(int *)(DAT_0043d5ac + iVar1 * 0xc) == 0) {
    uVar3 = 10000;
  }
  else {
    *(UINT *)(DAT_0043d5ac + 4 + iVar1 * 0xc) = param_2;
    *(undefined4 *)(DAT_0043d5ac + 8 + iVar1 * 0xc) = param_1;
    FUN_004015a6((byte *)s_timer_set____d_00431870);
    uVar3 = 0;
  }
  return uVar3;
}

