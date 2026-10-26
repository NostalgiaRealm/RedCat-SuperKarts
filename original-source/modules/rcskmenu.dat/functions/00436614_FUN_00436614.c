/*
 * FUN_00436614 at 00436614
 * undefined __register FUN_00436614(int * param_1)
 * Address ranges: 00436614-0043664f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00436614(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  
  FUN_00414bd8((int)param_1);
  iVar1 = FUN_0043806c((int)param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_0043806c((int)param_1);
    FUN_00403088(param_1,uVar2,CONCAT31((int3)((uint)extraout_ECX >> 8),1));
  }
  if ((char)param_1[0x1a] != '\0') {
    FUN_00436650(param_1);
  }
  return;
}

