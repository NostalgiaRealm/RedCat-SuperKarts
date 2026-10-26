/*
 * FUN_0044131c at 0044131c
 * undefined __register FUN_0044131c(int * param_1)
 * Address ranges: 0044131c-00441351
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044131c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  
  FUN_00414bd8((int)param_1);
  iVar1 = FUN_0043ea94((int)param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_0043ea94((int)param_1);
    FUN_00403088(param_1,uVar2,CONCAT31((int3)((uint)extraout_ECX >> 8),1));
  }
  FUN_0043ed90((int)param_1);
  return;
}

