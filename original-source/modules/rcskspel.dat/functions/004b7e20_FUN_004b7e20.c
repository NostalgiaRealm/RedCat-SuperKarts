/*
 * FUN_004b7e20 at 004b7e20
 * undefined FUN_004b7e20(void)
 * Address ranges: 004b7e20-004b7e84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7e20(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (DAT_00501110 <= param_1)) {
    FUN_004afee0(s__s__d____index_out_of_mem_image_a_00501004,
                 s_C__libraries_dxdraw_Sprite_cpp_00501114,0x194,param_1);
  }
  param_1 = param_1 * 0x20;
  if (*(int *)(param_1 + 0x18 + DAT_006ab880) == 2) {
    uVar1 = FUN_004b0770(*(undefined4 *)(param_1 + 4 + DAT_006ab880),param_2);
    *(undefined4 *)(param_1 + DAT_006ab880) = uVar1;
    return 0;
  }
  *param_2 = *(undefined4 *)(param_1 + 8 + DAT_006ab880);
  return 0;
}

