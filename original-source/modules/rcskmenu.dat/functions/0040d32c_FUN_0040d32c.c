/*
 * FUN_0040d32c at 0040d32c
 * undefined __register FUN_0040d32c(int param_1, undefined4 * param_2)
 * Address ranges: 0040d32c-0040d37f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d32c(int param_1,undefined4 *param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = param_2;
  for (uVar3 = (uint)*(ushort *)(param_1 + 10 + (uint)*(byte *)(param_1 + 1)); uVar3 != 0;
      uVar3 = uVar3 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  while( true ) {
    iVar1 = param_1 + 2 + (uint)*(byte *)(param_1 + 1);
    uVar3 = (uint)*(ushort *)(iVar1 + 0xb + (uint)*(byte *)(iVar1 + 10));
    if (uVar3 != 0) {
      iVar5 = iVar1 + 0xd + (uint)*(byte *)(iVar1 + 10);
      do {
        bVar2 = *(byte *)(iVar5 + 0x1a);
        if (param_2[*(ushort *)(iVar5 + 0x18)] == 0) {
          param_2[*(ushort *)(iVar5 + 0x18)] = iVar5;
        }
        iVar5 = iVar5 + 0x1b + (uint)bVar2;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    if (*(int **)(iVar1 + 4) == (int *)0x0) break;
    param_1 = **(int **)(iVar1 + 4);
  }
  return;
}

