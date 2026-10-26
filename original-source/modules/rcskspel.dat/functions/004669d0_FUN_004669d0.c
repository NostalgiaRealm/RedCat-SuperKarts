/*
 * FUN_004669d0 at 004669d0
 * undefined FUN_004669d0(void)
 * Address ranges: 004669d0-00466a14
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004669d0(int param_1,float *param_2)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 == 1) {
    fVar2 = param_2[1];
    param_2[1] = -*param_2;
    *param_2 = fVar2;
  }
  else {
    if (iVar1 == 2) {
      *param_2 = -*param_2;
      param_2[1] = -param_2[1];
      return;
    }
    if (iVar1 == 3) {
      fVar2 = param_2[1];
      param_2[1] = *param_2;
      *param_2 = fVar2;
      return;
    }
  }
  return;
}

