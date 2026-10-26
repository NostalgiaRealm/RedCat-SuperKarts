/*
 * FUN_0049d3e0 at 0049d3e0
 * undefined FUN_0049d3e0(void)
 * Address ranges: 0049d3e0-0049d4c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049d3e0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined1 **)(param_3 + 0x1c);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_0049f2a0(*(int *)(param_1 + 0x44) == 0,s__s___d__Sound_source_already_cre_004fbd18,
               s_D__work_rcracer_oursoundlib_soun_004fbd4c,0xa3,puVar1);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_3 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_3 + 0x14);
  FUN_00412870(param_3 + 0x18,0,0xffffffff);
  FUN_00412870(param_3 + 0x28,0,0xffffffff);
  FUN_0049f2a0(param_4 != -1,s__s___d__Illegal_value_for_Sound_s_004fbce0,s___csndsrc_h_004fbd0c,
               0xd9);
  *(undefined4 *)(param_1 + 0x54) = param_2;
  *(int *)(param_1 + 0x40) = param_4;
  if (*(int *)(param_1 + 4) != 0) {
    puVar1 = *(undefined1 **)(param_1 + 0x1c);
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_004d2404;
    }
    uVar2 = FUN_004b51e0(puVar1,0);
    *(undefined4 *)(param_1 + 0x38) = uVar2;
  }
  *(undefined4 *)(param_1 + 0x44) = 1;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x10);
  return;
}

