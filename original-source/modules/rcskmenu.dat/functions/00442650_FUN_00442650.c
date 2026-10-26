/*
 * FUN_00442650 at 00442650
 * undefined __register FUN_00442650(int param_1, int param_2)
 * Address ranges: 00442650-0044268b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442650(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x134);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = puVar1[2];
  }
  if (param_2 < iVar2) {
    FUN_0040f6b0(puVar1,param_2);
  }
  else {
    FUN_0040f6b0(*(undefined4 **)(param_1 + 0x180),param_2 - iVar2);
  }
  return;
}

