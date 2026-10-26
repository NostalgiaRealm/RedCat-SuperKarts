/*
 * FUN_0044cfe0 at 0044cfe0
 * undefined FUN_0044cfe0(void)
 * Address ranges: 0044cfe0-0044d0f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044d08f) */
/* WARNING: Removing unreachable block (ram,0x0044d065) */
/* WARNING: Removing unreachable block (ram,0x0044d066) */
/* WARNING: Removing unreachable block (ram,0x0044d074) */

void __fastcall FUN_0044cfe0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004afce0(s_GO_ANIMOBJECTS_004f0884);
  FUN_004afce0(s__s__d____Game_etappe_id_before_a_004f08b8,
               s_D__work_rcsk_Code_game_msh_Main__004f0894,0x1c,DAT_0053b9b4);
  iVar2 = *(int *)(param_1 + 0x14);
  local_8 = 0;
  if (iVar2 == 0) {
LAB_0044d031:
    iVar2 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 0x18) - iVar2 >> 2;
    if (0x9c3 < uVar1) {
      if (0x9c4 < uVar1) {
        *(int *)(param_1 + 0x18) = iVar2 + 10000;
      }
      goto LAB_0044d07f;
    }
    if (iVar2 == 0) goto LAB_0044d031;
    iVar2 = *(int *)(param_1 + 0x18) - iVar2 >> 2;
  }
  FUN_00459170(*(undefined4 *)(param_1 + 0x18),0x9c4 - iVar2,&local_8);
LAB_0044d07f:
  local_8 = 0;
  local_4 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
  FUN_00459170(*(undefined4 *)(param_1 + 0x14),0x9c4,&local_8);
  FUN_004afce0(s__s__d____Game_etappe_id_after_as_004f0910,
               s_D__work_rcsk_Code_game_msh_Main__004f08ec,0x22,DAT_0053b9b4);
  FUN_0044d100();
  FUN_004afce0(s_END_ANIMOBJECTS_004f0944);
  return;
}

