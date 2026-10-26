/*
 * FUN_0049cc90 at 0049cc90
 * undefined FUN_0049cc90(void)
 * Address ranges: 0049cc90-0049cd72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049cc90(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 local_4 [2];
  
  uVar1 = param_2;
  iVar3 = param_1 + 8;
  iVar2 = 4;
  do {
    FUN_004bf930(iVar3 + -8,4,1,uVar1);
    FUN_004bf930(iVar3 + -4,4,1,uVar1);
    FUN_004bf930(iVar3,4,1,uVar1);
    FUN_004bf930(iVar3 + 0x10,4,1,uVar1);
    FUN_004bf930(iVar3 + 0x14,4,1,uVar1);
    if (DAT_00680b74 == -1) {
      FUN_004bf930(&param_2,4,1,uVar1);
      *(uint *)(iVar3 + 8) =
           (uint)CONCAT11((char)param_2,(char)(param_2 >> 8)) << 8 | param_2 >> 0x10 & 0xff;
    }
    iVar3 = iVar3 + 0x20;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar3 = 2;
  puVar4 = (undefined2 *)(param_1 + 0x80);
  do {
    iVar2 = 3;
    do {
      FUN_004bf930(local_4,4,1,uVar1);
      *puVar4 = local_4[0];
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

