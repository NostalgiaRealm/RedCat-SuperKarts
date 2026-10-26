/*
 * FUN_00432394 at 00432394
 * undefined __register FUN_00432394(int param_1)
 * Address ranges: 00432394-0043243d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432394(int param_1)

{
  int *piVar1;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  uint uVar2;
  uint extraout_ECX_03;
  int iVar3;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &stack0xfffffffc;
  *(undefined1 *)(param_1 + 0x95) = 1;
  puStack_10 = &LAB_0043243e;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  local_8 = param_1;
  FUN_00407c70(FUN_004292ac);
  piVar1 = *(int **)(local_8 + 0x38);
  if (piVar1 != (int *)0x0) {
    if (*(int *)PTR_DAT_0047c82c == 3) {
      FUN_0042ca2c(piVar1,2);
      uVar2 = extraout_ECX_00;
      iVar3 = extraout_EDX;
    }
    else {
      iVar3 = *(int *)PTR_DAT_0047c82c + -7;
      uVar2 = extraout_ECX;
      if (iVar3 == 0) {
        *(undefined1 *)((int)piVar1 + 0x213) = 1;
      }
    }
    if (*(char *)(local_8 + 0x4b) != '\0') {
      if (*(char *)((int)*(int **)(local_8 + 0x38) + 0x213) == '\x01') {
        FUN_00431cec(local_8);
        uVar2 = extraout_ECX_01;
        iVar3 = extraout_EDX_00;
      }
      else {
        FUN_0042bbb8(*(int **)(local_8 + 0x38),CONCAT31((int3)((uint)iVar3 >> 8),1),uVar2);
        uVar2 = extraout_ECX_02;
        iVar3 = extraout_EDX_01;
      }
    }
    do {
      FUN_00432200(local_8,iVar3,uVar2);
      uVar2 = extraout_ECX_03;
      iVar3 = extraout_EDX_02;
    } while (*(char *)(local_8 + 0x8c) == '\0');
  }
  *in_FS_OFFSET = uStack_14;
  *(undefined1 *)(local_8 + 0x95) = 0;
  return;
}

