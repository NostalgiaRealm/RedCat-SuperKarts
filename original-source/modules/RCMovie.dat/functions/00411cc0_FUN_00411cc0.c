/*
 * FUN_00411cc0 at 00411cc0
 * undefined4 __cdecl FUN_00411cc0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 00411cc0-00411d4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_00411cc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00412a9d(param_1);
  iVar1 = *(int *)(DAT_0043d850 + 8 + iVar1 * 0x1c);
  if ((iVar1 == -1) || ((&DAT_0043db90)[iVar1 * 0x1c] == '\0')) {
    FUN_0040187a((byte *)s__s__d_____dispatch_form_message__0043401c);
  }
  else if (*(int *)(&DAT_0043dba8 + iVar1 * 0x1c) != 0) {
    uVar2 = (**(code **)(&DAT_0043dba8 + iVar1 * 0x1c))(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 0;
}

