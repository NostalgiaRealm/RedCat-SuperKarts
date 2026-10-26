/*
 * FUN_004c29d2 at 004c29d2
 * undefined FUN_004c29d2(void)
 * Address ranges: 004c29d2-004c2a06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c29d2(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    param_1 = FUN_004c217c(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
    param_1 = param_1 & 0xff;
  }
  if (param_1 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}

