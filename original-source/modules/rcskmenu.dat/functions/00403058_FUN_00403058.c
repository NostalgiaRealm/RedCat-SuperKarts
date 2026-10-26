/*
 * FUN_00403058 at 00403058
 * undefined __register FUN_00403058(int param_1)
 * Address ranges: 00403058-00403085
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403058(int param_1)

{
  uint uVar1;
  ushort unaff_BX;
  ushort *puVar2;
  bool bVar3;
  
  do {
    puVar2 = *(ushort **)(param_1 + -0x30);
    if (puVar2 != (ushort *)0x0) {
      uVar1 = (uint)*puVar2;
      bVar3 = puVar2 + 1 == (ushort *)0x0;
      puVar2 = puVar2 + 1;
      do {
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        bVar3 = unaff_BX == *puVar2;
        puVar2 = puVar2 + 1;
      } while (!bVar3);
      if (bVar3) {
        return;
      }
    }
    if (*(int **)(param_1 + -0x24) == (int *)0x0) {
      return;
    }
    param_1 = **(int **)(param_1 + -0x24);
  } while( true );
}

