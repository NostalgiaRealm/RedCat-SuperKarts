/*
 * FUN_0040d6b0 at 0040d6b0
 * undefined __register FUN_0040d6b0(int * param_1, int param_2, VARIANTARG * param_3)
 * Address ranges: 0040d6b0-0040d6ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d6b0(int *param_1,int param_2,VARIANTARG *param_3)

{
  code *pcVar1;
  VARIANTARG *pVVar2;
  
  pVVar2 = *(VARIANTARG **)(param_2 + 0x10);
  if (*(VARIANTARG **)(param_2 + 0x10) == (VARIANTARG *)0x80000000) {
    pVVar2 = param_3;
  }
  pcVar1 = *(code **)(param_2 + 8);
  if (*(byte *)(param_2 + 0xb) != 0xff) {
    if (0xfd < *(byte *)(param_2 + 0xb)) {
      (**(code **)((int)(short)pcVar1 + *param_1))();
      return;
    }
    (*pcVar1)(param_1,pVVar2);
    return;
  }
  FUN_0040d69c((VARIANT *)((int)param_1 + ((uint)pcVar1 & 0xffffff)),param_3);
  return;
}

