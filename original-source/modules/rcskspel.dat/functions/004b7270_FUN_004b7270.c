/*
 * FUN_004b7270 at 004b7270
 * undefined FUN_004b7270(void)
 * Address ranges: 004b7270-004b732b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7270(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (DAT_006ab864 == 0) {
    FUN_004afee0(s__s__d____current_ascii_set_not_d_00501038,
                 s_C__libraries_dxdraw_ascii_cpp_00500fac,0xf4);
  }
  if ((param_1 < 0) || (*(int *)(DAT_006ab868 + 100) <= param_1)) {
    FUN_004afee0(s__s__d____index_out_of_mem_image_a_00501004,
                 s_C__libraries_dxdraw_ascii_cpp_00500fac,0xf7,param_1);
  }
  puVar1 = (undefined4 *)(*(int *)(DAT_006ab868 + 0x68) + param_1 * 0xc);
  iVar2 = puVar1[2];
  if (iVar2 == 0) {
    FUN_004afee0(s__s__d____unlocking_ascii_char_th_00501064,
                 s_C__libraries_dxdraw_ascii_cpp_00500fac,0xfc,param_1);
  }
  else {
    if (iVar2 == 1) {
      FUN_004b08a0(*(undefined4 *)*puVar1,param_2);
      return 0;
    }
    if (iVar2 == 2) {
      FUN_004b08a0(*(undefined4 *)(puVar1[1] * 0x20 + 4 + DAT_006ab880),param_2);
      return 0;
    }
  }
  return 0;
}

