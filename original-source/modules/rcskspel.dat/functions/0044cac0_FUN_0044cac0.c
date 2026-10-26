/*
 * FUN_0044cac0 at 0044cac0
 * undefined FUN_0044cac0(void)
 * Address ranges: 0044cac0-0044cd49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0044cac0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_4;
  
  FUN_0044f110();
  if (*(int *)(param_1 + 0x60) == 0) {
    FUN_004afce0(s_no_mesh_change_____004f078c);
  }
  else {
    FUN_0044f500();
    uVar2 = FUN_0044e960();
    uVar2 = FUN_0044f500(uVar2);
    FUN_004afce0(s_object__d__current_anim__d__curr_004f075c,*(undefined4 *)(param_1 + 0x68),uVar2);
    FUN_0044f500();
    iVar3 = FUN_004906b0(4);
    iVar3 = DAT_006a5c38 + iVar3 * 0xa9;
    FUN_0044f500();
    uVar2 = FUN_0044e960();
    uVar2 = FUN_0044ebb0(uVar2);
    *(undefined4 *)(iVar3 + 0x99) = uVar2;
    iVar3 = FUN_004906b0(4);
    iVar4 = 0;
    iVar3 = *(int *)(DAT_006a5c38 + iVar3 * 0xa9 + 0x99) * 0xbc;
    if (0 < *(int *)(iVar3 + 0x84 + DAT_006a5ee0)) {
      iVar5 = 0;
      do {
        iVar1 = DAT_006a5ee0;
        if (*(int *)(param_1 + 0x70) == -1) {
          uVar2 = FUN_004902c0();
        }
        else {
          FUN_00417e90(*(int *)(param_1 + 0x70));
          iVar1 = DAT_006a5ee0;
          uVar2 = FUN_004902c0();
        }
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*(int *)(iVar1 + iVar3 + 0x80) + 0x10 + iVar5) = uVar2;
        iVar5 = iVar5 + 0x20;
      } while (iVar4 < *(int *)(iVar3 + 0x84 + DAT_006a5ee0));
    }
    iVar3 = 0;
    iStack_4 = 0;
    iVar4 = *(int *)(DAT_006a5c38 +
                     *(int *)(*(int *)(param_1 + 0x68) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x99) *
            0xbc;
    if (0 < *(int *)(iVar4 + 0x84 + DAT_006a5ee0)) {
      do {
        if (*(int *)(param_1 + 0x70) != -1) {
          FUN_00417e90(*(int *)(param_1 + 0x70));
        }
        iVar5 = iVar4 + DAT_006a5ee0;
        uVar2 = FUN_004902c0();
        iVar3 = iVar3 + 0x20;
        *(undefined4 *)(*(int *)(iVar5 + 0x80) + -0x10 + iVar3) = uVar2;
        iStack_4 = iStack_4 + 1;
      } while (iStack_4 < *(int *)(iVar4 + 0x84 + DAT_006a5ee0));
      return;
    }
  }
  return;
}

