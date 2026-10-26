/*
 * FUN_004205f0 at 004205f0
 * undefined FUN_004205f0(void)
 * Address ranges: 004205f0-00420727
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004205f0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  iVar4 = DAT_00508670 * 0x178;
  if (*(int *)(iVar4 + 0x74 + DAT_00680ba0) == 0) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00498a80(&local_18);
    local_24 = *puVar2;
    local_20 = puVar2[1];
    local_1c = puVar2[2];
  }
  if (*(int *)(DAT_00680ba0 + iVar4 + 0x78) == 0) {
    local_14 = 0;
    uVar3 = 0;
    local_18 = 0;
    local_10 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00498b80(local_c);
    local_18 = *puVar2;
    uVar3 = puVar2[1];
    local_10 = puVar2[2];
  }
  uVar1 = *(undefined4 *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
  FUN_00498a50(uVar1,local_24,local_20,local_1c);
  FUN_00498b50(uVar1,local_18,uVar3,local_10);
  FUN_00498c00();
  FUN_0041d6c0(6);
  return;
}

