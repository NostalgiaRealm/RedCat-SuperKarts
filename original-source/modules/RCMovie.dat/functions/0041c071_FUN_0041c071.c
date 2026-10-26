/*
 * FUN_0041c071 at 0041c071
 * undefined __cdecl FUN_0041c071(int param_1)
 * Address ranges: 0041c071-0041c0c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041c071(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  FUN_00412b01(*(int *)(param_1 + 0x14));
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_areabutton__no_va_004368cc);
  }
  FUN_00404a0d();
  FUN_00404b2d();
  FUN_00404a81();
  return;
}

