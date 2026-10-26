/*
 * FUN_0041c246 at 0041c246
 * undefined4 __cdecl FUN_0041c246(int param_1)
 * Address ranges: 0041c246-0041c2b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041c246(int param_1)

{
  int iVar1;
  
  if (-1 < param_1) {
    iVar1 = FUN_0041289c();
    if (param_1 <= iVar1) goto LAB_0041c272;
  }
  FUN_0040187a((byte *)s__s__d_____get_togglebutton_toggl_00436920);
LAB_0041c272:
  iVar1 = FUN_004128fa(param_1);
  if (iVar1 != 2) {
    FUN_0040187a((byte *)s__s__d_____get_togglebutton_toggl_00436978);
  }
  iVar1 = FUN_00412b70(param_1);
  return *(undefined4 *)(iVar1 + 0x10);
}

