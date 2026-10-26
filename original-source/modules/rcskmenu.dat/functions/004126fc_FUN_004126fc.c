/*
 * FUN_004126fc at 004126fc
 * undefined __register FUN_004126fc(int param_1)
 * Address ranges: 004126fc-0041276b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004126fc(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x41270e;
  piVar1 = (int *)FUN_0040fa70(DAT_0047d630);
  puStack_18 = &LAB_0041276c;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  iVar3 = piVar1[2] + -1;
  puStack_14 = &stack0xfffffffc;
  if (-1 < iVar3) {
    do {
      piVar2 = (int *)FUN_0040f6b0(piVar1,iVar3);
      if ((piVar2[1] == *(int *)(param_1 + 4)) && (piVar2[3] == *(int *)(param_1 + 0xc))) {
        FUN_00402eac(piVar2);
        FUN_0040f550(piVar1,iVar3);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00412773;
  puStack_18 = (undefined1 *)0x41276b;
  FUN_0040fad4(DAT_0047d630);
  return;
}

