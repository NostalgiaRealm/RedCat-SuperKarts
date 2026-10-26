/*
 * FUN_0041c2b4 at 0041c2b4
 * undefined __cdecl FUN_0041c2b4(int param_1, int param_2)
 * Address ranges: 0041c2b4-0041c368
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041c2b4(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (-1 < param_1) {
    iVar1 = FUN_0041289c();
    if (param_1 <= iVar1) goto LAB_0041c2e0;
  }
  FUN_0040187a((byte *)s__s__d_____set_togglebutton_toggl_004369d4);
LAB_0041c2e0:
  iVar1 = FUN_004128fa(param_1);
  if (iVar1 != 2) {
    FUN_0040187a((byte *)s__s__d_____get_togglebutton_toggl_00436a2c);
  }
  piVar2 = (int *)FUN_00412b70(param_1);
  if (*(int *)(DAT_0043d858 + *piVar2 * 0xc) / 2 < param_2) {
    FUN_0040187a((byte *)s__s__d_____set_togglebutton_toggl_00436a88);
  }
  piVar2[4] = param_2;
  return;
}

