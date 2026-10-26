/*
 * FUN_0040310c at 0040310c
 * undefined4 __register FUN_0040310c(int param_1, byte * param_2)
 * Address ranges: 0040310c-00403159
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040310c(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined2 *puVar5;
  int iVar6;
  
  iVar2 = 0;
  iVar6 = 0;
  bVar4 = *param_2;
  while( true ) {
    puVar5 = *(undefined2 **)(param_1 + -0x34);
    if (puVar5 != (undefined2 *)0x0) {
      iVar6 = CONCAT22((short)((uint)iVar6 >> 0x10),*puVar5);
      puVar5 = puVar5 + 1;
      do {
        bVar1 = *(byte *)(puVar5 + 3);
        iVar3 = CONCAT31((int3)((uint)iVar2 >> 8),bVar1);
        if (bVar1 == bVar4) {
          iVar3 = CONCAT22((short)((uint)iVar2 >> 0x10),(ushort)bVar1);
          while (((*(byte *)((int)puVar5 + iVar3 + 6) ^ param_2[iVar3]) & 0xdf) == 0) {
            iVar3 = iVar3 + -1;
            if (iVar3 == 0) {
              return *(undefined4 *)(puVar5 + 1);
            }
          }
          bVar4 = *param_2;
        }
        iVar2 = CONCAT22((short)((uint)iVar3 >> 0x10),*puVar5);
        puVar5 = (undefined2 *)((int)puVar5 + iVar2);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (*(int **)(param_1 + -0x24) == (int *)0x0) break;
    param_1 = **(int **)(param_1 + -0x24);
  }
  return 0;
}

