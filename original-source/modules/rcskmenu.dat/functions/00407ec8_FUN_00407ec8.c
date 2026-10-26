/*
 * FUN_00407ec8 at 00407ec8
 * undefined __register FUN_00407ec8(int param_1, int * param_2)
 * Address ranges: 00407ec8-00407ef8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407ec8(int param_1,int *param_2)

{
  uint uVar1;
  
  for (uVar1 = FUN_00403dd0(param_1); (0 < (int)uVar1 && (*(byte *)(param_1 + -1 + uVar1) < 0x21));
      uVar1 = uVar1 - 1) {
  }
  FUN_00403fd8(param_1,1,uVar1,param_2);
  return;
}

