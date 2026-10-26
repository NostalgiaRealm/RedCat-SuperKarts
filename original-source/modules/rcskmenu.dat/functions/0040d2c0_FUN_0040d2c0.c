/*
 * FUN_0040d2c0 at 0040d2c0
 * undefined __register FUN_0040d2c0(int param_1, undefined1 * param_2)
 * Address ranges: 0040d2c0-0040d32b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d2c0(int param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  byte bVar5;
  undefined1 *puVar4;
  undefined2 uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  
  puVar4 = param_2;
  if (param_2 != (undefined1 *)0x0) {
    puVar4 = (undefined1 *)(CONCAT11(*param_2,param_2[-4]) & 0xdfff);
  }
  while( true ) {
    iVar1 = param_1 + 2 + (uint)*(byte *)(param_1 + 1);
    uVar7 = (uint)*(byte *)(iVar1 + 10);
    uVar10 = (uint)*(ushort *)(iVar1 + 0xb + uVar7);
    if (uVar10 != 0) {
      iVar2 = iVar1 + 0xd + uVar7;
      do {
        puVar8 = (undefined1 *)
                 (CONCAT22((short)(uVar7 >> 0x10),*(undefined2 *)(iVar2 + 0x1a)) & 0xffffdfff);
        if (puVar8 == puVar4) {
          iVar9 = CONCAT22((short)((uint)puVar8 >> 0x10),(ushort)(byte)puVar8);
          while( true ) {
            uVar6 = (undefined2)((uint)puVar4 >> 0x10);
            uVar3 = SUB41(puVar4,0);
            bVar5 = param_2[iVar9 + -1] ^ *(byte *)(iVar2 + 0x1a + iVar9);
            puVar4 = (undefined1 *)CONCAT22(uVar6,CONCAT11(bVar5,uVar3));
            if ((bVar5 & 0xdf) != 0) break;
            iVar9 = iVar9 + -1;
            if (iVar9 == 0) {
              return;
            }
          }
          puVar4 = (undefined1 *)(CONCAT22(uVar6,CONCAT11(*param_2,uVar3)) & 0xffffdfff);
          puVar8 = (undefined1 *)CONCAT31((int3)((uint)iVar9 >> 8),*(undefined1 *)(iVar2 + 0x1a));
        }
        uVar7 = CONCAT22((short)((uint)puVar8 >> 0x10),(ushort)(byte)puVar8);
        uVar10 = uVar10 - 1;
        iVar2 = iVar2 + 0x1b + uVar7;
      } while (uVar10 != 0);
    }
    if (*(int **)(iVar1 + 4) == (int *)0x0) break;
    param_1 = **(int **)(iVar1 + 4);
  }
  return;
}

