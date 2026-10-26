/*
 * FUN_004c11fe at 004c11fe
 * undefined FUN_004c11fe(void)
 * Address ranges: 004c11fe-004c1221
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c11fe(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (-1 < *piVar1) {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
    return param_1 & 0xff;
  }
  uVar2 = FUN_004c217c(param_1,param_2);
  return uVar2;
}

