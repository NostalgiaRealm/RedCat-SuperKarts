/*
 * FUN_00443590 at 00443590
 * undefined FUN_00443590(void)
 * Address ranges: 00443590-004435f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00443590(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004b8830(&DAT_004ee6a0);
  if (iVar1 != 0) {
    FUN_004afee0(s_not_enough_memory_for_animations_004ee928);
  }
  uVar2 = FUN_004b9af0(&DAT_0053d410,s_rc_img_004ee94c,param_1);
  iVar1 = FUN_004b83b0(uVar2);
  if (iVar1 != 0) {
    FUN_004afee0(s_not_enough_memory_for_animation_d_004ee954,DAT_00501110);
  }
  FUN_004bb690();
  DAT_0053d4d8 = 1;
  return 0;
}

