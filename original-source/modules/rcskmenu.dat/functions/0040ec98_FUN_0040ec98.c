/*
 * FUN_0040ec98 at 0040ec98
 * int __register FUN_0040ec98(int param_1)
 * Address ranges: 0040ec98-0040ed34;0040ed3c-0040ed45
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040ec98(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x40ecae;
  puVar2 = (undefined4 *)FUN_0040fa70(DAT_0047d624);
  puStack_20 = &LAB_0040ed35;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  iVar5 = puVar2[2];
  puStack_1c = &stack0xfffffffc;
  if (-1 < iVar5 + -1) {
    iVar4 = 0;
    puStack_1c = &stack0xfffffffc;
    do {
      iVar3 = FUN_0040f6b0(puVar2,iVar4);
      cVar1 = FUN_00402e0c(iVar3,param_1);
      if (cVar1 != '\0') {
        FUN_004036a4();
        return iVar3;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  iVar5 = (**(code **)(*DAT_0047d628 + 0x50))(DAT_0047d628,param_1);
  if (-1 < iVar5) {
    iVar5 = (**(code **)(*DAT_0047d628 + 0x18))(DAT_0047d628,iVar5);
    FUN_004036a4();
    return iVar5;
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = (undefined1 *)0x40ed3c;
  puStack_20 = (undefined1 *)0x40ed34;
  iVar5 = FUN_0040fad4(DAT_0047d624);
  return iVar5;
}

