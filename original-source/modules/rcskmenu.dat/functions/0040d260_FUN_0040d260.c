/*
 * FUN_0040d260 at 0040d260
 * int __register FUN_0040d260(int param_1, int param_2)
 * Address ranges: 0040d260-0040d2a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040d260(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  if (param_2 != 0) {
    iVar2 = **(int **)(param_1 + 0xb + (uint)*(byte *)(param_1 + 1));
    uVar3 = (uint)*(byte *)(iVar2 + 1);
    puVar4 = (undefined1 *)(iVar2 + 0xf + uVar3);
    piVar1 = (int *)(iVar2 + 7 + uVar3);
    iVar2 = 0;
    do {
      uVar3 = CONCAT31((int3)(uVar3 >> 8),*puVar4);
      if (uVar3 == *(uint *)(param_2 + -4)) {
        while (((*(byte *)(param_2 + -1 + uVar3) ^ puVar4[uVar3]) & 0xdf) == 0) {
          uVar3 = uVar3 - 1;
          if (uVar3 == 0) {
            return iVar2;
          }
        }
        uVar3 = CONCAT31((int3)(uVar3 >> 8),*puVar4);
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + uVar3 + 1;
    } while (iVar2 <= *piVar1);
  }
  return -1;
}

