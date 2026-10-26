/*
 * FUN_0040eb20 at 0040eb20
 * undefined FUN_0040eb20(void)
 * Address ranges: 0040eb20-0040eb82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0040eb20(int *param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  
  if ((&DAT_00503ef4)[*param_1 * 0x47] != param_2) {
    iVar1 = FUN_00410120();
    fVar2 = (float10)FUN_0048f4d0();
    param_1[1] = param_2;
    param_1[2] = (int)(float)(fVar2 + (float10)((double)iVar1 * 0.001));
  }
  return;
}

