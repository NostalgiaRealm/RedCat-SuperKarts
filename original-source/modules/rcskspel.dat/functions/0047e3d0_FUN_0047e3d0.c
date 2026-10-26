/*
 * FUN_0047e3d0 at 0047e3d0
 * undefined FUN_0047e3d0(void)
 * Address ranges: 0047e3d0-0047e609
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047e3d0(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  undefined1 uStack_35;
  undefined1 auStack_30 [5];
  undefined1 uStack_2b;
  undefined4 *puStack_28;
  undefined1 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d1140;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004afce0(s__s__d____Clearing_image_list_004f88bc,s_D__work_rcsk_Code_game_Requester_004f8894,
               0x7c);
  piVar3 = *(int **)(param_1 + 0x50);
  piVar4 = (int *)*piVar3;
  while (piVar4 != piVar3) {
    iVar8 = piVar4[8];
    puVar7 = (undefined1 *)piVar4[4];
    iVar9 = 0;
    if (puVar7 == (undefined1 *)0x0) {
      puVar7 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____Releasing_surfaces_for___004f8904,
                 s_D__work_rcsk_Code_game_Requester_004f88dc,0x88,puVar7);
    if (iVar8 != piVar4[9]) {
      do {
        puVar7 = (undefined1 *)piVar4[4];
        if (puVar7 == (undefined1 *)0x0) {
          puVar7 = &DAT_004d2404;
        }
        FUN_004afce0(s__s__d____Releasing_surface__s__d_004f8950,
                     s_D__work_rcsk_Code_game_Requester_004f8928,0x90,puVar7,iVar9);
        puVar6 = (undefined4 *)FUN_00477ab0();
        (**(code **)(*(int *)*puVar6 + 8))((int *)*puVar6);
        iVar8 = iVar8 + 0x14;
        iVar9 = iVar9 + 1;
      } while (iVar8 != piVar4[9]);
    }
    puVar7 = (undefined1 *)piVar4[4];
    if (puVar7 == (undefined1 *)0x0) {
      puVar7 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____Clearing__s___004f899c,s_D__work_rcsk_Code_game_Requester_004f8974,0x9a,
                 puVar7);
    uStack_18 = piVar4[8];
    uStack_4 = 0xffffffff;
    piVar4[8] = 0;
    uStack_14 = piVar4[9];
    piVar4[9] = 0;
    uStack_10 = piVar4[10];
    piVar4[10] = 0;
    FUN_004bc150(uStack_18);
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_10 = 0;
    FUN_0047cf00();
    piVar3 = *(int **)(param_1 + 0x50);
  }
  FUN_004afce0(s__s__d____Clearing_image_list_004f89dc,s_D__work_rcsk_Code_game_Requester_004f89b4,
               0xa3);
  uStack_2b = uStack_35;
  uStack_24 = 0;
  FUN_00480390();
  uVar1 = *(undefined1 *)(param_1 + 0x4d);
  *(undefined1 *)(param_1 + 0x4d) = uStack_2b;
  puVar6 = *(undefined4 **)(param_1 + 0x50);
  *(undefined4 **)(param_1 + 0x50) = puStack_28;
  uVar2 = *(undefined1 *)(param_1 + 0x54);
  *(undefined1 *)(param_1 + 0x54) = uStack_24;
  uVar5 = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x58) = uStack_20;
  uStack_4 = 0xffffffff;
  uStack_2b = uVar1;
  puStack_28 = puVar6;
  uStack_24 = uVar2;
  uStack_20 = uVar5;
  FUN_0047c850(auStack_30,*puVar6,puVar6);
  FUN_004bc150(puStack_28);
  DAT_00544fb4 = DAT_00544fb4 + -1;
  puStack_28 = (undefined4 *)0x0;
  uStack_20 = 0;
  if (DAT_00544fb4 == 0) {
    FUN_004bc150(DAT_00544fb0);
    DAT_00544fb0 = 0;
  }
  FUN_004afce0(s__s__d____Done_clearing_image_lis_004f8a24,
               s_D__work_rcsk_Code_game_Requester_004f89fc,0xa6);
  ExceptionList = pvStack_c;
  return;
}

