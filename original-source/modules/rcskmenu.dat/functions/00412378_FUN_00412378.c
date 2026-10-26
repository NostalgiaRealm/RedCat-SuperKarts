/*
 * FUN_00412378 at 00412378
 * undefined __register FUN_00412378(int param_1, char * param_2)
 * Address ranges: 00412378-00412412;0041241a-00412420
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412378(int param_1,char *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  if (DAT_0047d630 == 0) {
    return;
  }
  puStack_1c = (undefined1 *)0x41239e;
  piVar1 = (int *)FUN_0040fa70(DAT_0047d630);
  puStack_20 = &LAB_00412413;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  iVar4 = piVar1[2] + -1;
  puStack_1c = &stack0xfffffffc;
  if (-1 < iVar4) {
    do {
      piVar2 = (int *)FUN_0040f6b0(piVar1,iVar4);
      if ((param_1 == 0) || (piVar2[2] == param_1)) {
        if (param_2 != (char *)0x0) {
          uVar3 = FUN_00407d58(param_2,(char *)piVar2[4]);
          if ((char)uVar3 == '\0') goto LAB_004123f5;
        }
        FUN_0040f550(piVar1,iVar4);
        FUN_00402eac(piVar2);
      }
LAB_004123f5:
      iVar4 = iVar4 + -1;
    } while (iVar4 != -1);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = (undefined1 *)0x41241a;
  puStack_20 = (undefined1 *)0x412412;
  FUN_0040fad4(DAT_0047d630);
  return;
}

