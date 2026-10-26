/*
 * FUN_0047fe50 at 0047fe50
 * undefined FUN_0047fe50(void)
 * Address ranges: 0047fe50-0047ffde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0047fe50(int *param_1,int param_2,undefined4 param_3,int *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar2 = *(undefined1 **)(param_2 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Enter_DrawImage__s___d__004f95f4,
               s_D__work_rcsk_Code_game_Requester_004f95cc,0x3b0,puVar2,param_3,*param_4,param_4[1],
               param_4[2],param_4[3]);
  *param_1 = *param_1 + 1;
  FUN_004afce0(s__s__d____Getting_surface_004f9650,s_D__work_rcsk_Code_game_Requester_004f9628,0x3b6
              );
  FUN_00480080(param_2);
  puVar3 = (undefined4 *)FUN_00477ab0();
  uVar1 = *puVar3;
  FUN_00480080(param_2);
  uVar4 = FUN_00477a90();
  FUN_004777e0(uVar4);
  FUN_004afce0(s__s__d____blitting_surface_004f9694,s_D__work_rcsk_Code_game_Requester_004f966c,
               0x3ba);
  uVar4 = DAT_006a64a0;
  if (DAT_006abae0 != 0) {
    uVar5 = FUN_00477930((param_1[0x11] * *param_4) / DAT_004fe930,
                         (param_4[1] * param_1[0x12]) / DAT_004fe934,
                         (param_4[2] * param_1[0x11]) / DAT_004fe930,
                         (param_1[0x12] * param_4[3]) / DAT_004fe934,0);
    uVar5 = FUN_00477940(uVar5);
    FUN_004b6ec0(uVar1,uVar4,0,0,uVar5);
  }
  FUN_004afce0(s__s__d____done_blitting_surface_004f96d8,s_D__work_rcsk_Code_game_Requester_004f96b0
               ,0x3d0);
  puVar2 = *(undefined1 **)(param_2 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Leave_DrawImage__s___d__004f9720,
               s_D__work_rcsk_Code_game_Requester_004f96f8,0x3d3,puVar2,param_3,*param_4,param_4[1],
               param_4[2],param_4[3]);
  return;
}

