/*
 * FUN_0047f5d0 at 0047f5d0
 * undefined FUN_0047f5d0(void)
 * Address ranges: 0047f5d0-0047f6e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047f5d0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_1 + 0x50);
  piVar2 = (int *)*piVar1;
  while (piVar2 != piVar1) {
    iVar5 = piVar2[8];
    puVar3 = (undefined1 *)piVar2[4];
    iVar6 = 0;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____Restoring_surfaces_for___004f9310,
                 s_D__work_rcsk_Code_game_Requester_004f92e8,0x252,puVar3);
    if (iVar5 != piVar2[9]) {
      do {
        puVar3 = (undefined1 *)piVar2[4];
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        FUN_004afce0(s__s__d____Restoring_surface__s__d_004f935c,
                     s_D__work_rcsk_Code_game_Requester_004f9334,0x25a,puVar3,iVar6);
        puVar4 = (undefined4 *)FUN_00477ab0();
        FUN_004b08e0(*puVar4);
        iVar5 = iVar5 + 0x14;
        iVar6 = iVar6 + 1;
      } while (iVar5 != piVar2[9]);
    }
    FUN_0047cf00();
    piVar1 = *(int **)(param_1 + 0x50);
  }
  FUN_004b08e0(DAT_006a64a0);
  FUN_004b08e0(DAT_006a64c0);
  FUN_004b08e0(DAT_006a64bc);
  puVar3 = *(undefined1 **)(param_1 + 0x38);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004b2870(2,puVar3,0x1f);
  FUN_0047f3a0();
  FUN_0047f4b0();
  if (*(code **)(param_1 + 0x98) != (code *)0x0) {
    (**(code **)(param_1 + 0x98))(param_1 + 4,0);
  }
  FUN_0047f6f0();
  return;
}

