/*
 * FUN_004b7e90 at 004b7e90
 * undefined FUN_004b7e90(void)
 * Address ranges: 004b7e90-004b7edb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7e90(int param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 < 0) || (DAT_00501110 <= param_1)) {
    FUN_004afee0(s__s__d____index_out_of_mem_image_a_00501004,
                 s_C__libraries_dxdraw_Sprite_cpp_00501114,0x1ab,param_1);
  }
  puVar1 = (undefined4 *)(DAT_006ab880 + param_1 * 0x20);
  if (puVar1[6] == 2) {
    FUN_004b08a0(puVar1[1],*puVar1);
  }
  return 0;
}

