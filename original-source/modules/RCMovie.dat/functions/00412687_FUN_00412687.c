/*
 * FUN_00412687 at 00412687
 * int __cdecl FUN_00412687(int param_1, int param_2)
 * Address ranges: 00412687-004126d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00412687(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_0043d858 + 8 + param_1 * 0xc) + 4 + param_2 * 8);
  if ((iVar1 < 0) || (DAT_00431b64 < iVar1)) {
    FUN_0040187a((byte *)s__s__d____control_illegal_frame_i_00434584);
  }
  return iVar1;
}

