/*
 * FUN_004383d4 at 004383d4
 * undefined __register FUN_004383d4(int * param_1, int param_2)
 * Address ranges: 004383d4-004383fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004383d4(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_004383a0((int)param_1,param_2);
  if (iVar1 == -1) {
    FUN_004358cc((undefined4 *)PTR_PTR_0047c940);
  }
  FUN_004382c0(param_1,iVar1);
  return;
}

