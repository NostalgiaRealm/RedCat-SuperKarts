/*
 * FUN_0042209f at 0042209f
 * undefined __cdecl FUN_0042209f(uint param_1, int * param_2, int * param_3)
 * Address ranges: 0042209f-004220d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0042209f(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_00422168(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
    uVar2 = param_1 & 0xff;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}

