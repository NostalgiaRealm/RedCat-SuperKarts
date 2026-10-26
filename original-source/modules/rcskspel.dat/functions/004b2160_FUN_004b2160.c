/*
 * FUN_004b2160 at 004b2160
 * undefined FUN_004b2160(void)
 * Address ranges: 004b2160-004b221f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b2160(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_006ab46c == 0) {
    DAT_006ab468 = LocalAlloc(0x40,0x400);
    if (DAT_006ab468 == (HLOCAL)0x0) {
      FUN_004afee0(s__s__d____error_not_enough_memory_004ffd58,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x25);
    }
    if (8 < DAT_004fe938) {
      FUN_004afce0(s__s__d____16_bit_screen_mode__>_i_004ffd28,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x2a);
      DAT_006ab470 = 1;
      return 0;
    }
    iVar1 = (**(code **)(*DAT_006a649c + 0x14))(DAT_006a649c,0x44,DAT_006ab468,&DAT_006ab464,0);
    if (iVar1 != 0) {
      uVar2 = FUN_004b0190(iVar1);
      FUN_004afee0(s__s__d____could_not_create_a_pale_004ffcfc,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x31,uVar2);
    }
    DAT_006ab46c = 1;
    FUN_004b2220(0);
    FUN_004b2220(1);
    FUN_004b2220(2);
  }
  return 0;
}

