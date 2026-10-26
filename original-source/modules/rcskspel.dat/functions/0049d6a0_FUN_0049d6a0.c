/*
 * FUN_0049d6a0 at 0049d6a0
 * undefined FUN_0049d6a0(void)
 * Address ranges: 0049d6a0-0049d773
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049d6a0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  FUN_0049f2a0(*(int *)(param_1 + 0x54) != 0,s__s___d__Sound_engine_not_yet_att_004fbd90,
               s___csndsrc_h_004fbd0c,0xc4);
  uVar1 = FUN_0049d520((*(int *)(*(int *)(param_1 + 0x54) + 0x270) * *(int *)(param_1 + 0x48)) / 100
                      );
  puVar2 = *(undefined1 **)(param_1 + 0x1c);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  uVar1 = FUN_004b4fa0(puVar2,uVar1,param_2 != 0);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  FUN_0049f2a0(*(int *)(param_1 + 0x40) != -1,s__s___d__ID_not_set_for_this_soun_004fbdc8,
               s_D__work_rcracer_oursoundlib_soun_004fbd4c,400);
  FUN_004b53b0(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x40));
  FUN_004b47c0(*(undefined4 *)(param_1 + 0x38),0);
  uVar1 = FUN_004b4880(*(undefined4 *)(param_1 + 0x38));
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  FUN_0049d650(*(undefined4 *)(param_1 + 0x50));
  FUN_0049d5e0(*(undefined4 *)(param_1 + 0x4c));
  return;
}

