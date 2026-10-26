/*
 * FUN_00412424 at 00412424
 * undefined __register FUN_00412424(int param_1)
 * Address ranges: 00412424-0041249a;004124a2-004124a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412424(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  if (DAT_0047d630 != 0) {
    puStack_18 = (undefined1 *)0x412441;
    piVar1 = (int *)FUN_0040fa70(DAT_0047d630);
    puStack_1c = &LAB_0041249b;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    iVar3 = piVar1[2] + -1;
    puStack_18 = &stack0xfffffffc;
    if (-1 < iVar3) {
      do {
        piVar2 = (int *)FUN_0040f6b0(piVar1,iVar3);
        if (piVar2[1] == param_1) {
          FUN_0040f550(piVar1,iVar3);
          FUN_00402eac(piVar2);
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != -1);
    }
    *in_FS_OFFSET = uStack_20;
    puStack_18 = (undefined1 *)0x4124a2;
    puStack_1c = (undefined1 *)0x41249a;
    FUN_0040fad4(DAT_0047d630);
    return;
  }
  return;
}

