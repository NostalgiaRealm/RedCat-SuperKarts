/*
 * FUN_00409b90 at 00409b90
 * undefined __fastcall FUN_00409b90(undefined4 param_1, uint * param_2)
 * Address ranges: 00409b90-00409bfb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00409b90(undefined4 param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int unaff_EDI;
  
  iVar6 = DAT_0040e9b4;
  DAT_0040e978 = param_2;
  do {
    uVar2 = (short)iVar6 - 1;
    uVar5 = *DAT_0040e978;
    puVar4 = DAT_0040e978;
    cVar3 = DAT_0040e9b0;
    while (((uVar5 & 0xffff) == 0 && (uVar5 = uVar5 >> 0xd & 0xffff8, cVar3 != '\0'))) {
      cVar3 = cVar3 + -1;
      uVar1 = uVar2 & 1;
      uVar2 = uVar2 >> 1;
      if (uVar1 == 0) {
        uVar5 = 4;
      }
      puVar4 = (uint *)((int)puVar4 + uVar5);
      uVar5 = *puVar4;
    }
    *(uint *)(unaff_EDI + -4 + iVar6 * 4) =
         CONCAT31((int3)puVar4 - (int3)_DAT_0040e9a4,-(cVar3 - DAT_0040e9b0));
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}

