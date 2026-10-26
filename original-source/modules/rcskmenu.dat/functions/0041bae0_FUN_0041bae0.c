/*
 * FUN_0041bae0 at 0041bae0
 * undefined __register FUN_0041bae0(int param_1)
 * Address ranges: 0041bae0-0041bb4f;0041bb57-0041bb5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bae0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  if (param_1 != 0) {
    puStack_14 = (undefined1 *)0x41baf9;
    puVar1 = (undefined4 *)FUN_0040fa70(DAT_0047b5dc);
    puStack_18 = &LAB_0041bb50;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    iVar3 = puVar1[2] + -1;
    puStack_14 = &stack0xfffffffc;
    if (-1 < iVar3) {
      do {
        piVar2 = (int *)FUN_0040f6b0(puVar1,iVar3);
        if ((piVar2[0x16] != 0) && (*(int *)(*(int *)(piVar2[0x16] + 0x20) + 8) == param_1)) {
          FUN_0041bbc4(piVar2);
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != -1);
    }
    *in_FS_OFFSET = uStack_1c;
    puStack_14 = (undefined1 *)0x41bb57;
    puStack_18 = (undefined1 *)0x41bb4f;
    FUN_0040fad4(DAT_0047b5dc);
    return;
  }
  return;
}

